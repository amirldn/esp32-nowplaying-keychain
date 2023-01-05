#include "BLEDevice.h"
#include "BLEServer.h"
#include "BLEClient.h"

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting!");
  startBLE();
}

void startBLE()
{
  Serial.println("Beginning startBLE");
  BLEDevice::init("AmirBLETest");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();

  // Create the BLE Service

  // AMS GUID (did not display in settings)
  // BLEUUID serviceUUID("89D3502B-0F36-433A-8EF4-C502AD55F8DC");

  // HID Keyboard GUID
  BLEUUID serviceUUID("00001812-0000-1000-8000-00805f9b34fb");
  BLEService *pService = pServer->createService(serviceUUID);

  // Start the service
  pService->start();



  // Start advertising the service
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();

  BLEAdvertisementData *pAdvertisementData = new BLEAdvertisementData();
  pAdvertisementData->setFlags(0x06);
  pAdvertisementData->setCompleteServices(BLEUUID(serviceUUID));
  pAdvertising->setAdvertisementData(*pAdvertisementData);
  
  pAdvertising->addServiceUUID(serviceUUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  // pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Service has started");
  
}

// void onHIDConnect {
//   BLEDevice::getAddress()
// }

void loop() {
  delay(2000);
};