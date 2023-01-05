#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include "lib/GxEPD2_display_selection_new_style.h"
#include "lib/GxEPD2_display_selection.h"

#include "BLEDevice.h"
#include "BLEServer.h"


// #define SERVICE_UUID 0x1800


void setup()
{
  Serial.begin(115200);
  Serial.println("Starting!");
  display.init(115200);
  startBLE();
  Serial.println("Starting helloWorld");
  // helloWorld();
  clearScreen();
  display.hibernate();
}

void startBLE()
{
  Serial.println("Beginning startBLE");
  BLEDevice::init("AmirBLETest");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();

  // Create the BLE Service
  BLEUUID serviceUUID("89D3502B-0F36-433A-8EF4-C502AD55F8DC");
  BLEService *pService = pServer->createService(serviceUUID);

  // Start the service
  pService->start();

  // Start advertising the service
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(serviceUUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();


  Serial.println("Service has started");
  
}

const char HelloWorld[] = "Connected to Amir's iPhone";

void helloWorld()
{
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center the bounding box by transposition of the origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print(HelloWorld);
  }
  while (display.nextPage());
}



void clearScreen()
{
  Serial.println("clearing screen");
  display.setRotation(1);
  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_BLACK);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(HelloWorld, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center the bounding box by transposition of the origin:
  uint16_t x = ((display.width() - tbw) / 2) - tbx;
  uint16_t y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(x, y);
    display.print("");
  }
  while (display.nextPage());
}

void loop() {

};