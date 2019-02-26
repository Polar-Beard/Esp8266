#include <Logger.h>

class EspDriver {
  public:
    EspDriver(Logger *logger);
    bool ping();
  private:
    Logger *logger;
};
