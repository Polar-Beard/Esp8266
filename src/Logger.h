#include "Stream.h"
#include <Arduino.h>

class Logger {
  public:
    Logger(Stream *loggingPort);
    void log(const __FlashStringHelper* message);
  private:
    Stream *loggingPort;
};
