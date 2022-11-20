# esp32-bt-serial
ESP32 bluetooth to serial bridge.

Can be used when you need bidirectional bridge for Bluetooth to serial port.

I am using it for MavLink connection to my quadcopter, running ardupilot.

The main difference from the code that you can find on the Internet is sending data by packets with MAX length of 300 bytes. It dramatically improves communication speed.
