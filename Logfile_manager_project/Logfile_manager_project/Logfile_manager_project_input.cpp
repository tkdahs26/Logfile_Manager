#include "Logfile_manager_project.h"  

int main() {



    LogFileManager manager;

 
    manager.openLogFile("error.log");
    manager.openLogFile("debug.log");
    manager.openLogFile("info.log");

    manager.writeLog("error.log", "Database connection failed");
    manager.writeLog("debug.log", "User login attempt");
    manager.writeLog("info.log", "Server started successfully");

    std::vector<std::string> errorLogs = manager.readLogs("error.log");

    if (!errorLogs.empty()) {
        std::cout << "errorLogs[0] = \"" << errorLogs[0] << "\"" << std::endl;
    }
    
 

    return 0;
}
