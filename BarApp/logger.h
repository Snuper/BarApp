#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <QDate>
#include <QDateTime>
#include <string>

class Logger
{
public:
    Logger();

    void writeLog(std::string);
    void closeLogFile();

private:
    QDateTime _currentTime;
    std::ofstream _logFile;
};

#endif // LOGGER_H
