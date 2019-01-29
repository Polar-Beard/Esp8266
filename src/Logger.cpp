#include "Logger.h"

Logger::Logger(Stream *loggingPort) : loggingPort(loggingPort) {}

void Logger::log(const __FlashStringHelper* message) {
  loggingPort -> print(F("[ESP8266]"));
  loggingPort -> println(message);
}
