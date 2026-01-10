#ifndef LOGFILE_MANAGER_PROJECT_H
#define LOGFILE_MANAGER_PROJECT_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <fstream>

class LogFileManager {
public:
    LogFileManager() = default;
    ~LogFileManager() = default;
     
    LogFileManager(const LogFileManager&) = delete;
    LogFileManager& operator=(const LogFileManager&) = delete;

  
    void openLogFile(const std::string& filename);
    void writeLog(const std::string& filename, const std::string& message);
    std::vector<std::string> readLogs(const std::string& filename);
    void closeLogFile(const std::string& filename);

private:
    std::map<std::string, std::unique_ptr<std::fstream>> logFiles;

};

#endif