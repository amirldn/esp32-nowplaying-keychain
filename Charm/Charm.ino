#include "BLEDevice.h"
#include "BLEServer.h"
#include "BLEClient.h"

#define BT_NAME "AmirBLETest"

// Service UUIDs
BLEUUID keyboardUUID("00001812-0000-1000-8000-00805f9b34fb");
BLEUUID amsUUID("89D3502B-0F36-433A-8EF4-C502AD55F8DC");

// Characteristic UUIDs
BLEUUID remoteCommandUUID("9B3C81D8-57B1-4A8A-B8DF-0E56F7CA51C2");
BLEUUID entityUpdateUUID("2F7CABCE-808D-411F-9A0C-BB92BA96C102");
BLEUUID entityAttributeUUID("C6B2F38C-23AB-46D8-A6AB-A3A870BBD5D7");


bool bleServerConnected = false;
bool bleClientConnected = false;

class ServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    Serial.println("Client connected");
    bleServerConnected = true;
    BLEAddress address = BLEDevice::getAddress();
    Serial.println(address.toString().c_str());
  }
};

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting!");
  BLEDevice::init(BT_NAME);
  startBLEServer();
}

void startBLEServer()
{
  Serial.println("Beginning startBLEServer");
  

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new ServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(keyboardUUID);

  // Start the service
  pService->start();

  // Start advertising the service
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(keyboardUUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  
  BLEDevice::startAdvertising();
  Serial.println("Service has started");
}

void startBLEClient()
{
  Serial.println("Beginning startBLEServer");
  BLEClient *pClient = BLEDevice::createClient();
  Serial.println("Created client");
}

// void onHIDConnect {
//   BLEDevice::getAddress()
// }

void loop() {
  delay(2000);
};