// Prueba con MP3


/// WIFI
#include <WiFiUdp.h>
#include <WiFi.h>  // ESP32
//#include <ESP8266WiFi.h>  //ESP8266
#define UDP_PORT 3333

const char* ssid     = "Arakne";
const char* password = "12345678";

IPAddress local_IP(192, 168, 4, 21);   //21 para el dispositivo 1 y 22 para el dispositivo 2
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8); //optional
IPAddress secondaryDNS(8, 8, 4, 4); //optional

WiFiUDP UDP;

char packet[255];
char reply[] = "Packet received!";

/// LED UV
const int led_uv = 22;
const int pinDisplay = 20;
const int led1 = 19;
const int led2 = 18 ;


// Control obra
int estadoObra = 99;
int estadoAnt = 101;

void setup() {
  btStop(); // turn off bluetooth
  Serial.begin(9600);

  // WIFI
  conecta_wifi();

  // LED UV
  pinMode(led_uv, OUTPUT);
  pinMode(pinDisplay, OUTPUT);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);

}
//////////////////////////////////////////////////////////////////////////////////



void loop() {

  // Si se recibe un paquete....
  
  int packetSize = UDP.parsePacket();

  if (packetSize) {
    int len = UDP.read(packet, 255);
    if (len > 0)
    {
      packet[len] = '\0';
    }

    if (strstr(packet, "0")) { //-----------------------------------
      digitalWrite(led_uv, LOW);   // LED APAGADO
      digitalWrite(pinDisplay, LOW);   // DISPLAY APAGADO
       digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      estadoObra = 0;
     
    } else if (strstr(packet, "1")) { //-----------------------------------
      digitalWrite(led_uv, LOW);   // LED  APAGADO
      digitalWrite(pinDisplay, LOW);   // DISPLAY APAGADO
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      estadoObra = 1;
      
    } else if (strstr(packet, "2")) { //-----------------------------------
      digitalWrite(led_uv, HIGH);   // LED ENCENDIDO
      digitalWrite(pinDisplay, HIGH);   // DISPLAY ENCENDIDOS
       digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      estadoObra = 2;
      
    }
  }

  if(estadoAnt != estadoObra){
    Serial.write(estadoObra);
  //  Serial.parseInt(estadoObra);

    }
  estadoAnt = estadoObra;
  
}
