#include "Exceptions.h"
#include <sstream>


//empty constructor
Exceptions::Exceptions(int line, const char* file) noexcept 
	:
	line(line),
	file(file)
{}

//figures out what happened and adds it to the buffer
const char* Exceptions::what() const noexcept {
	
	std::ostringstream output;
	output << getType() << std::endl << getOriginString();
	whatBuffer = output.str();
	return whatBuffer.c_str();
}

//records where the error took place (file and line)
std::string Exceptions::getOriginString() const noexcept {

	std::ostringstream output;
	output << "FILE: " << file << std::endl << "LINE: " << line << std::endl;
	return output.str();
}