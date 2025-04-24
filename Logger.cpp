#include "Logger.h"
#include<iostream>

void Logger::logAttempt(const std::string& password) {
    log.push_back({password, static_cast<int>(log.size() + 1)});
}

void Logger::printLog(int limit) const {
    int start = (limit == -1 || limit >= log.size()) ? 0 : log.size() - limit;
    for (int i = start; i < log.size(); i++) {
        std::cout << "Attempt #" << log[i].attemptNumber << "; " << log[i].password << "\n";
    }
}
