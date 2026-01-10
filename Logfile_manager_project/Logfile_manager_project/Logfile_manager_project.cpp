#include "Logfile_manager_project.h"  
#include <iomanip>
#include <chrono>
#include <ctime>

void LogFileManager::openLogFile(const std::string& filename) {
    if (logFiles.find(filename) == logFiles.end()) {
        logFiles[filename] = std::make_unique<std::fstream>(filename, std::ios::in | std::ios::out | std::ios::app);
        std::cout << "파일을 열었습니다: " << filename << std::endl;
    }
}

void LogFileManager::writeLog(const std::string& filename, const std::string& message) {
    auto it = logFiles.find(filename); 

    if (it != logFiles.end()) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        struct tm timeinfo;
        localtime_s(&timeinfo, &now_c);
      
        *(it->second) << "[" << std::put_time(&timeinfo, "%Y-%m-%d %H:%M:%S") << "] " << message << std::endl;
    }
}

std::vector<std::string> LogFileManager::readLogs(const std::string& filename) {
    std::vector<std::string> logs;  //vector[] = 자바의 arraylist[]
    std::ifstream file(filename); // ifstream생성자호출 filename열기

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            logs.push_back(line);
        }
        file.close();
    }
    return logs;
}

void LogFileManager::closeLogFile(const std::string& filename) {
    if (logFiles.erase(filename)) {
        std::cout << "[시스템] 파일을 닫았습니다: " << filename << std::endl;
    }
}