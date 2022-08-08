#pragma once
#include <string>

// Pattern studies: factory

class Logger {
public:
	virtual ~Logger() {};
	virtual void log(std::string msg) const = 0;
};

class ConsoleLogger : public Logger {
public:
	void log(std::string msg) const override {
		std::cout << "To console:";
		std::cout << msg;
	}
};

class FileLogger : public Logger {
public:
	void log(std::string msg) const override {
		std::cout << "To file:";
		std::cout << msg;
	}
};

class LoggerFactory {
private:
	// here it's hardcoded, but imagine we are reading this from database
	std::string logOutput = "console";

public:
	Logger* getLogger() {
		if (logOutput == "console") {
			return new ConsoleLogger;
		}
		else {
			return new FileLogger;
		}
	}
};