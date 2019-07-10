#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
public:
	static void logError(std::string errorModule, std::string errorDescription, std::string sdlError = "");

	static const void logInfo(std::string info);

private:

};

#endif