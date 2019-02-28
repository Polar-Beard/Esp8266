#include <Logger.h>
#include <Stream.h>

class EspDriver {
  public:
    EspDriver(Logger* logger, Stream* espStream);
    bool ping();
    void read();
  private:
    Logger* logger;
    Stream* espStream;
    char* logBuffer;
    int logBufferCount;
    void log(char c);
    void addToLogBuffer(char c);
    void flushLogBuffer();
    void emptyLogBuffer();
};
