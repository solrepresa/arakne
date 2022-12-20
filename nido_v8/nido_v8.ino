/// Circuito entero


///Dependencias WiFiUdp.h
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WiFiUdp.h>


//Definimos la RED y la contraseña que luego los clientes van a necesitar conectarse

const char *ssid = "Arakne";
const char *password = "12345678";

const char * udpAddress1 = "192.168.4.21";   //Definimos las IPs de los cliente
const char * udpAddress2 = "192.168.4.22";
const int udpPort = 3333;

WiFiUDP udp;



//Pines del sensor
const int pin_ultrasonico_echo = 14;
const int pin_ultrasonico_trigger = 12;
long duracion;
int distancia;
const int dist_maxima = 2000;     //cm

// Pines LED
const int led_b1 = 23;
const int led_b2 = 22;
const int led_b3 = 5;
const int led_b4 = 19;
const int led_b5 = 18;
const int led_col1 = 21;
const int led_col2 = 17;
const int led_estrobo = 16;


//Variables de control
String estadoObra = "0";
//double tiempoEstado2 = 2000;///cuanto queres que dure el estado 2, en milisegundos
double cuandoCambio = 0;



void setup() {

  Serial.begin(115200);
  delay(2000);

  // Sensor
  pinMode(pin_ultrasonico_echo, INPUT);
  pinMode(pin_ultrasonico_trigger, OUTPUT);

  // LED
  pinMode(led_b1, OUTPUT);
  pinMode(led_b2, OUTPUT);
  pinMode(led_b3, OUTPUT);
  pinMode(led_b4, OUTPUT);
  pinMode(led_b5, OUTPUT);
  pinMode(led_col1, OUTPUT);
  pinMode(led_col2, OUTPUT);
  pinMode(led_estrobo, OUTPUT);

  // WIFI
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);

  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);


/**
  //envio varias veces el estado de inicio de la obra -- por las dudas
  estadoObra = "0";
  for (int i = 0; i < 10; i++) {
    envioInfo(estadoObra);
    delay(500);
  }
**/

}



void loop() {

  
  if (estadoObra == "0") {//-----------------------------------------------------------------------
    //aca va lo que hace la obra en estado 0

    Serial.println("Estado 0");
    //Serial.println(estadoObra);


    // NIDO - INACTIVO
    digitalWrite(led_b1, HIGH);
    digitalWrite(led_b2, HIGH);
    digitalWrite(led_b3, HIGH);
    digitalWrite(led_b4, HIGH);
    digitalWrite(led_b5, HIGH);
    digitalWrite(led_col1, HIGH);
    digitalWrite(led_col2, HIGH);
    digitalWrite(led_estrobo, LOW);

   delay(5000);
   
    //LEER DISTANCIA
    Serial.println(distancia);

    leeSensor();
    if (distancia < dist_maxima) {
    //  cuandoCambio = millis();
      estadoObra = "1";
      envioInfo(estadoObra);

    }

      Serial.println(estadoObra);

  } else if (estadoObra == "1") {//-----------------------------------------------------------------------
    //aca va lo que hace la obra en estado 1

    Serial.println("Estado 1");
    //    Serial.println(estadoObra);

    // NIDO - ACTIVO
    digitalWrite(led_b1, LOW);
    digitalWrite(led_b2, LOW);
    digitalWrite(led_b3, LOW);
    digitalWrite(led_b4, LOW);
    digitalWrite(led_b5, LOW);
    digitalWrite(led_col1, LOW);
    digitalWrite(led_col2, LOW);

    for (int t = 0; t <= 140; t++) {       //// ¿cuanto tiempo queremos que se sostenga el tiempo de activacion? tiempo en mseg /100
      digitalWrite(led_estrobo, HIGH);
      delay(50);
      digitalWrite(led_estrobo, LOW);
      delay(50);
    }

    estadoObra = "2";
    envioInfo(estadoObra);

  } else if (estadoObra == "2") {//-----------------------------------------------------------------------
    //aca va lo que hace la obra en estado 2

    Serial.println("Estado 2");

    // NIDO - INACTIVO
    digitalWrite(led_b1, HIGH);
    digitalWrite(led_b2, HIGH);
    digitalWrite(led_b3, HIGH);
    digitalWrite(led_b4, HIGH);
    digitalWrite(led_b5, HIGH);
    digitalWrite(led_col1, HIGH);
    digitalWrite(led_col2, HIGH);
    digitalWrite(led_estrobo, LOW);


    delay(38000); // Duracion Audio 3

   estadoObra = "0";  //vuelve a estado 0  para iniciar nuevamente, a la espera de alguien
  envioInfo(estadoObra);

  }

}
