#include "logger.h"

Logger::Logger()
{
    QDate *currentDay = new QDate;

    std::string nameFile =  "log_" +
            std::to_string(currentDay->currentDate().year()) +
            std::to_string(currentDay->currentDate().month()) +
            std::to_string(currentDay->currentDate().day())
            + ".txt";

    _logFile.open(nameFile, std::ios::app);

    delete currentDay;
}

void Logger::closeLogFile()
{
    _logFile.close();
}

void Logger::writeLog(std::string newLog)
{
    int hour = _currentTime.currentDateTime().time().hour();
    int minute = _currentTime.currentDateTime().time().minute();
    int second = _currentTime.currentDateTime().time().second();

    _logFile << std::endl
            << hour << ":" << minute << ":" << second << " | "
            << newLog;
}
