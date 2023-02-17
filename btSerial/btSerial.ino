#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

#define BUFFER_SIZE 1000 // max of 1 K

#define RXD2 16
#define TXD2 17

uint8_t bufRecv[BUFFER_SIZE];
uint8_t bufSend[BUFFER_SIZE];

void setup() {
  Serial2.begin(115200);
  SerialBT.begin("BT-serial"); //Bluetooth device name
  Serial2.println("The device started, now you can pair it with bluetooth!");
}

void loop() 
{
  //sending to BT

  int bytesInSerial = Serial2.available();
  if (bytesInSerial) 
  {
    int bytesRead = Serial2.readBytes(bufSend, bytesInSerial);

    if(bytesRead)
    {
      //send data to radio
      SerialBT.write(bufSend, bytesRead);
    }
  }

  //receiving from BT
  if (SerialBT.available()) 
  {
    //Serial2.write(SerialBT.read());
    size_t bufSize = 0;
    while (SerialBT.available() && bufSize < BUFFER_SIZE) 
    {
      bufRecv[bufSize] = SerialBT.read();
      bufSize++;
    }
    Serial2.write(bufRecv, bufSize);
  }
}
