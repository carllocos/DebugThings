#include <serial/serialib.h>
// #include <iostream>
#include <stdio.h>
#include <unistd.h>

int main(/*int argc, char *argv[]*/) {

  // std::cout << "hello world\n";
  //Serial object 
  serialib serial;

  const char *serialPort = "/dev/ttyUSB0";
  const unsigned int baud = 115200;
  // Connection to serial port
  char errorOpening = serial.openDevice(serialPort, baud);

  // If connection fails, return the error code otherwise, display a success
  // message
  if (errorOpening != 1) {
    printf("unsuccesfull port operning %s\n", serialPort);
    return errorOpening;
  }
  // if (errorOpening != 1)
  //   return errorOpening;
  printf("Successful connection to %s\n", serialPort);

  // Display ASCII characters (from 32 to 128)
  for (int c = 32; c < 128; c++) {
    serial.writeChar(c);
    usleep(10000);
  }

  // Close the serial device
  serial.closeDevice();

  return 0;
}
