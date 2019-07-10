#include "logger.h"
#include <iostream>

const void Logger::logError(std::string errorModule, std::string errorDescription)
{
	std::cout << " [ ERROR ] " << errorModule <<std::endl;
	std::cout << " ==> " << errorDescription << std::endl;
}

const void Logger::logInfo(std::string info)
{
	std::cout<<" [ INFO ] " << info << std::endl;
}