#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

#define BUFFER_SIZE 1000 // max of 1 K

uint8_t bufRecv[BUFFER_SIZE];
uint8_t bufSend[BUFFER_SIZE];

void setup() {
  Serial.begin(57600);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() 
{
  //sending to BT

  int bytesInSerial = Serial.available();
  if (bytesInSerial) 
  {
    int bytesRead = Serial.readBytes(bufSend, bytesInSerial);

    if(bytesRead)
    {
      //send data to radio
      SerialBT.write(bufSend, bytesRead);
    }
  }

  //receiving from BT
  if (SerialBT.available()) 
  {
    //Serial.write(SerialBT.read());
    size_t bufSize = 0;
    while (SerialBT.available() && bufSize < BUFFER_SIZE) 
    {
      bufRecv[bufSize] = SerialBT.read();
      bufSize++;
    }
    Serial.write(bufRecv, bufSize);
  }
}
