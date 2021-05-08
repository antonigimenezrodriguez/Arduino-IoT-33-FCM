#include <WiFiNINA.h>
#include <FirebaseArduino.h>


char ssid[] = "TP-Link_0846";        // your network SSID (name)
char pass[] = "24398006";    // your network password (use for WPA, or use as key for WEP)
WiFiClient wifiClient;


#define FIREBASE_HOST "example.firebaseio.com" 
#define FIREBASE_AUTH "token_or_secret" 


void setup() {
  // put your setup code here, to run once:

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    // failed, retry
    Serial.print(".");
    delay(5000);
  }

  Serial.println("You're connected to the network");
  Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:

}
