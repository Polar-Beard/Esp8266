#include "EspDriver.h"

EspDriver::EspDriver(Logger *l, Stream* s){
  logger = l;
  espStream = s;
  logBuffer = new char[64];
  logBufferCount = 0;
} 
	
bool EspDriver::ping() {
	read();
  return false;
}

void EspDriver::read() {
  char c;
  while (espStream -> available() > 0) { //while there are bytes in the serial buffer
    c = (char) espStream -> read();
    log(c);
  }
  
  flushLogBuffer();
}

void EspDriver::log(char c) {
  addToLogBuffer(c);

  bool isNewLine = c == '\n' || c == '\r';
  bool bufferIsFull = logBufferCount >= 64; 

  if (isNewLine || bufferIsFull) {
    flushLogBuffer();
  };
}

void EspDriver::addToLogBuffer(char c) {
  logBuffer[logBufferCount] = c;
  logBufferCount++;
}

void EspDriver::flushLogBuffer() {
  logger -> log(logBuffer);
  emptyLogBuffer();
}

void EspDriver::emptyLogBuffer(){
  memset(logBuffer, 0, 64);
  logBufferCount = 0;
}

