#include <LedControl.h>

LedControl lc0 = LedControl(2, 3, 4, 1);//din,clk,sc
LedControl lc1 = LedControl(5, 6, 7, 1);//din,clk,sc
LedControl lc2 = LedControl(8, 9, 10, 1);//din,clk,sc

#define demora 100

int pinEsp = A0;
boolean estado = false;
 
void setup() {
  lc0.shutdown(0, false);
  lc0.setIntensity(0, 10); //hasta 0,15
  lc0.clearDisplay(0);

  lc1.shutdown(0, false);
  lc1.setIntensity(0, 10); //hasta 0,15
  lc1.clearDisplay(0);

  lc2.shutdown(0, false);
  lc2.setIntensity(0, 10); //hasta 0,15
  lc2.clearDisplay(0);
}



void loop() {
  if (estado)mostrarZ();
  espera (demora);
  if (estado)mostrarY ();
  espera (demora);
  if (estado)mostrarX ();
  espera (demora);
  if (estado)mostrarC ();
  espera (demora);
  if (estado)mostrarV ();
  espera (demora);
}



void espera(int _t) {
  for (int i = 0; i < _t; i++) {
    if (leePin() == false)
    { i = _t + 1;
      mostrarNada();
    }
    delay(1);
  }
}

boolean leePin() {
  int aux = analogRead(pinEsp);
  estado = false;
  if (aux > 500) estado = true;
  return estado;
}
