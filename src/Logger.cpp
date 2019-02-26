#include <Logger.h>

Logger::Logger(Stream *loggingPort) : loggingPort(loggingPort) {}

void Logger::log(String message) {
  loggingPort -> print(F("[ESP8266]"));
  loggingPort -> println(message);
}
