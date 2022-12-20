void envioInfo(String _estado) {
  udp.beginPacket(udpAddress1, udpPort);
  udp.print(_estado); //Valor a enviar
  udp.endPacket();

  udp.beginPacket(udpAddress2, udpPort);
  udp.print(_estado); //Valor a enviar
  udp.endPacket();
}
