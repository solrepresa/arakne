void leeSensor() {
  digitalWrite(pin_ultrasonico_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pin_ultrasonico_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_ultrasonico_trigger, LOW);
  
duracion = pulseIn(pin_ultrasonico_echo, HIGH);

  distancia = duracion * 0.034 / 2;

  delay(500);
}
