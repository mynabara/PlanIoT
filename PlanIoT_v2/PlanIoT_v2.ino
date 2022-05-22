/***************************************************

  PlanIoT Project
  Written by Myna Obara

  Using Adafruit MQTT Library Ethernet Example written by Alec Moore
  Derived from the code written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license
  
 ****************************************************/
//Arduino pins
#define pinAnalog 0
#define pinRelay 7
#define pinDigital 13

//Adafruit MQTT
#include <SPI.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#include <Ethernet.h>
#include <EthernetClient.h>
#include <Dns.h>
#include <Dhcp.h>

/************************* Ethernet Client Setup *****************************/

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

//Uncomment the following, and set to a valid ip if you don't have dhcp available.
//IPAddress iotIP (192, 168, 0, 42);
//Uncomment the following, and set to your preference if you don't have automatic dns.
//IPAddress dnsIP (8, 8, 8, 8);
//If you uncommented either of the above lines, make sure to change "Ethernet.begin(mac)" to "Ethernet.begin(mac, iotIP)" or "Ethernet.begin(mac, iotIP, dnsIP)"

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "mynabara"
#define AIO_KEY         "aio_GHjZ6479Lvoclhkjx7CnmoV4ntyC"

/************ Global State (you don't need to change this!) ******************/

//Set up the ethernet client
EthernetClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

// You don't need to change anything below this line!
#define halt(s) { Serial.println(F( s )); while(1);  }

/****************************** Feeds ***************************************/

// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish umidity = Adafruit_MQTT_Publish(&mqtt,  AIO_USERNAME "/feeds/umidity");

// Setup a feed called 'onoff' for subscribing to changes.
Adafruit_MQTT_Subscribe onoffbutton = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/onoff");

/*************************** Sketch Code ************************************/

/*//WiFi Shield
#include <WiFi.h>
char ssid[] = "2.4GHz_OBARA";     //  your network SSID (name) 
char pass[] = "brasiliaamarela2021";    // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status*/

//Arduino pins
float analogOutput = 0;
float gauge = 0;
int soilSensor = 0;

  /*//WiFi Shield
  // attempt to connect using WPA2 encryption:
  Serial.println("Attempting to connect to WPA network...");
  status = WiFi.begin(ssid, pass);

  // if you're not connected, stop here:
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    while(true);
  } 
  // if you are connected, print out info about the connection:
  else {
    Serial.println("Connected to network");
  }*/

void setup() {
  
  //Adafruit MQTT
  Serial.begin(115200);
  Serial.println(F("Adafruit MQTT demo"));

  // Initialise the Client
  Serial.print(F("\nInit the Client..."));
  Ethernet.begin(mac);
  delay(1000); //give the ethernet a second to initialize

  mqtt.subscribe(&onoffbutton);

  //Serial.begin(9600);

  //Arduino pins
  pinMode(pinDigital, INPUT);
  pinMode(pinRelay, OUTPUT);
}

void loop() {

  //MQTT
  MQTT_connect();

  // this is our 'wait for incoming subscription packets' busy subloop
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(1000))) {
    if (subscription == &onoffbutton) {
      Serial.print(F("Got: "));
      Serial.println((char *)onoffbutton.lastread);
    }
  }

  //PlanIoT
  soilSensor = digitalRead(pinDigital);
  analogOutput = analogRead(pinAnalog);
  gauge = map(analogOutput, 325, 1023, 100, 0); // valores convertidos para % e ajustados com base na saída do "Valor sensor"
 
  Serial.println("Necessidade de água");
  Serial.println(soilSensor);
  Serial.println("% Umidade");
  Serial.println(gauge);
  Serial.println("Valor sensor");
  Serial.println(analogOutput);

//  if (soilSensor == HIGH) { // soilSensor == HIGH = 1 -> sem umidade
//    digitalWrite(pinRelay, LOW); // pinRelay, LOW -> vazão de água aberta
//    delay(5000); // 5000 = 5seg -> tempo para irrigar e fazer a próxima leitura
//  }
//  else { // soilSensor == LOW = 0 -> com umidade
//    digitalWrite(pinRelay, HIGH); // pinRelay, HIGH -> vazão de água fechada
//    delay(15000); // ideal 900000 = 15min; teste 150000 = 15seg -> pode-se esperar mais para a próxima leitura pois já há umidade    
//  }

  
  // Now we can publish stuff!
  uint32_t x = 0;
  Serial.print(F("\nSending umidity value"));
  Serial.print(x);
  Serial.print("...");
  if (! umidity.publish(x++)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }

  // ping the server to keep the mqtt connection alive
  if (! mqtt.ping()) {
    mqtt.disconnect();
  }
}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
  }
  Serial.println("MQTT Connected!");
}
