# esp32-bt-serial
ESP32 bluetooth to serial bridge.

Can be used when you need bidirectional bridge for Bluetooth to serial port and vise versa.

I am using it for MavLink connection to my quadcopter, running ardupilot.

The main difference from the code that you can find on the Internet (send char by char) is sending data by packets with MAX length of 300 bytes. It dramatically improves communication speed.

Usage:

1. Connect RX/TX of your ESP32 to your serial port. (ESP32 RX goest to port TX and so on). 

2. Define it in your telemetry output. Like "arducopter -D /dev/ttyO5". Baudrate is 57600

3. At your laptop discover Bluetooth device "ESP32test"

4. Pair it to your laptop. Ater pairing you will discover a new bluetooth serial port (or few ports). 

5. Connect your mission planner or other software to this port with 57600 baudrate.

6. Enjoy.
