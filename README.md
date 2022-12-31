# esp32-nowplaying-keychain

Code for ESP32 Devkit to display currently playing song on a bluetooth connected device via an e-ink display

### Instructions

1. Set up ESP32 Dev Module in Arduino IDE using this [guide](https://www.az-delivery.uk/en/blogs/azdelivery-blog-fur-arduino-und-raspberry-pi/esp32-jetzt-mit-boardverwalter-installieren)
2. [Drivers](http://esp32.net/usb-uart/#:~:text=CP2102N%20Porting%20Guide-,WCH,-WinChipHead%20/%20Jiangsu%20Qinheng) for MacOS (for CH340 USB Chip)
3. Install GxEPD2 Library to use the e-ink display
4. Set up the WaveShare e-Ink 2.9" display with the ESP32 Board using the following mapping
   | Display Pin | ESP32 Pin |
   | ----------- | --------- |
   | BUSY | 4 |
   | RST | 16 |
   | DC | 17 |
   | CS | 5 |
   | CLK | 18 |
   | DIN | 23 |
   | GND | GND |
   | 3.3V | 3.3V |

5. Using Git, clone the repo and push arduino.ino to your ESP32
