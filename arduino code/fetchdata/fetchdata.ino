#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
 
#define FIREBASE_HOST "home-automation-76c1f-default-rtdb.firebaseio.com" // Firebase host
#define FIREBASE_AUTH "PB9lCgZGYBiwy5xfPXCekID9LmcCKze3Oo9sAYlZ" //Firebase Auth code
#define WIFI_SSID "Infinix NOTE 7" //Enter your wifi Name
#define WIFI_PASSWORD "12345678" // Enter your password

uint8_t Relay1 = D1;
uint8_t Relay2 = D2;
uint8_t Relay3 = D3;
uint8_t Relay4 = D4;


int fireStatus;
int fireStatus1;
int fireStatus2;
int fireStatus3;
int firebaseEstate;
int val;
String valString;

 
void setup() {
  Serial.begin(9600);
  pinMode(Relay1, OUTPUT);  digitalWrite(Relay1, HIGH);
  pinMode(Relay2, OUTPUT);  digitalWrite(Relay2, HIGH);
  pinMode(Relay3, OUTPUT);  digitalWrite(Relay3, HIGH);
  pinMode(Relay4, OUTPUT);  digitalWrite(Relay4, HIGH);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected.");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("LED_STATUS", 0);
}
 
void loop() {
  fireStatus = Firebase.getInt("Lights/switch status/switch1");
  if (fireStatus == 0) {
    Serial.println("D1 Led Turned OFF");
    digitalWrite(Relay1, HIGH);
  }
  else if (fireStatus == 1) {
    Serial.println("D1 Led Turned ON");
    digitalWrite(Relay1, LOW);
  }
  else {
    Serial.println("Command Error! Please send 0/1");
  }

  fireStatus1 = Firebase.getInt("Lights/switch status/switch2");
  if (fireStatus1 == 0) {
    Serial.println("D2 Led Turned OFF");
    digitalWrite(Relay2, HIGH);
  }
  else if (fireStatus1 == 1) {
    Serial.println("D2 Led Turned ON");
    digitalWrite(Relay2, LOW);
  }
  else {
    Serial.println("Command Error! Please send 0/1");
  }
  fireStatus2 = Firebase.getInt("Lights/switch status/switch3");
  if (fireStatus2 == 0) {
    Serial.println("D3 Led Turned OFF");
    digitalWrite(Relay3, HIGH);
  }
  else if (fireStatus2 == 1) {
    Serial.println("D3 Led Turned ON");
    digitalWrite(Relay3, LOW);
  }
  else {
    Serial.println("Command Error! Please send 0/1");
  }

  fireStatus3 = Firebase.getInt("Lights/switch status/switch4");
  if (fireStatus3 == 0) {
    Serial.println("D4 Led Turned OFF");
    digitalWrite(Relay4, HIGH);
  }
  else if (fireStatus3 == 1) {
    Serial.println("D4 Led Turned ON");
    digitalWrite(Relay4, LOW);
  }
  else {
    Serial.println("Command Error! Please send 0/1");
  }

//  Reading Relay Estate and update on Firebase
//  Relay1 Estate
  val = digitalRead(Relay1);
  Serial.println(val);
  if (val == 1) {
    Serial.println("Relay1 is OFF");
  }
  else {
    Serial.println("Relay1 one is ON");
  }
  valString = String(val);
  Firebase.setString("Switch Estate/Relay1",valString);
//  Relay2 Estate
  val = digitalRead(Relay2);
  Serial.println(val);
  if (val == 1) {
    Serial.println("Relay2 is OFF");
  }
  else {
    Serial.println("Relay2 one is ON");
  }
  valString = String(val);
  Firebase.setString("Switch Estate/Relay2",valString);
  
  //  Relay3 Estate
  val = digitalRead(Relay3);
  Serial.println(val);
  if (val == 1) {
    Serial.println("Relay3 is OFF");
  }
  else {
    Serial.println("Relay3 one is ON");
  }
  valString = String(val);
  Firebase.setString("Switch Estate/Relay3",valString);
  
  //  Relay4 Estate
  val = digitalRead(Relay4);
  Serial.println(val);
  if (val == 1) {
    Serial.println("Relay4 is OFF");
  }
  else {
    Serial.println("Relay4 one is ON");
  }
  valString = String(val);
  Firebase.setString("Switch Estate/Relay4",valString);    
} 
