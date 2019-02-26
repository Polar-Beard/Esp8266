#include <Stream.h>
#include <Arduino.h>

class Logger {
  public:
    Logger(Stream *loggingPort);
    void log(String message);
  private:
    Stream *loggingPort;
};
