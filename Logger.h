#ifndef LOGGER_H
#define LOGGER_H

#include<vector>
#include<string>

struct LogEntry {
    std::string password;
    int attemptNumber;
};

class Logger {
private:
    std::vector<LogEntry> log;
public:
    void logAttempt(const std::string& password);
    void printLog(int limit = -1) const;
};

#endif