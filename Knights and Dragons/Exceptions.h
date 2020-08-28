#pragma once
#include <exception>
#include <string>

class Exceptions : public std::exception
{
private:
	int line;
	std::string file;

public:
	Exceptions(int line, const char* file) noexcept;
	const char* what() const noexcept override;

	//getters
	virtual const char* getType() const noexcept { return "Custom Exception"; }
	int getLine() const noexcept { return line; }
	const std::string& getFile() const noexcept { return file; };
	std::string getOriginString() const noexcept;

protected:
	mutable std::string whatBuffer;

};