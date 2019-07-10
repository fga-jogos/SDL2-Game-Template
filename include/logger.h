#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
public:

	static const void logError(std::string errorModule, std::string errorDescription);
	
	static const void logInfo(std::string info);

private:

};

#endif