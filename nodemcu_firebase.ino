#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

//#include <ESP8266WiFi.h> //https://github.com/esp8266/Arduino
//needed for library
//#include <FirebaseArduino.h>

#define FIREBASE_HOST "web-app-947f4.firebaseio.com"
//This is your Firebase Hostname which can be found in the Firebase console.
#define FIREBASE_AUTH "GyTBA4E7wUw9bzOkNkyE26gDZztGdm11uti5ZmS3"
//This is the database secret(legacy), not firebase service or web key.
#define WIFI_SSID "Hacker.net"
//SSID of your ruter.
#define WIFI_PASSWORD "megamind"

int ledPin =14;
int ledPin1 =12;
//int data=1;

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");

while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}

//if you get here you have connected to the WiFi
 Serial.println("connected…yeey :)");

Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Firebase.set("redlight", 0);

pinMode(ledPin, OUTPUT); digitalWrite(ledPin, LOW);
pinMode(ledPin1, OUTPUT); digitalWrite(ledPin1, LOW);

}
void loop() {
// put your main code here, to run repeatedly:
digitalWrite(ledPin, Firebase.getInt("led1"));
Serial.print("Led1");
Serial.println(Firebase.getInt("led1"));

digitalWrite(ledPin1, Firebase.getInt("led2"));
Serial.print("Led2");
Serial.println(Firebase.getInt("led2"));

if (Firebase.failed()) {
Serial.println(Firebase.error());
}

delay(500);

}
