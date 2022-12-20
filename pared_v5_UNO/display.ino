byte zeta [8] = {
  B00000000,
  B01000010,
  B01100010,
  B01010010,
  B01001010,
  B01000110,
  B01000010,
  B00000000
};

byte igriega [8] = {
  B00000000,
  B01000000,
  B00100000,
  B00011110,
  B00011110,
  B00100000,
  B01000000,
  B00000000
};

byte equis [8] = {
  B00000000,
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B00000000
};

byte ce [8] = {
  B00000000,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00111100,
  B00000000
};
byte ve [8] = {
  B00000000,
  B01111000,
  B00000100,
  B00000010,
  B00000010,
  B00000100,
  B01111000,
  B00000000
};
byte nada [8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};



void mostrarZ () {
  for (int i = 0; i < 8 ; i++)
  {
    lc0.setRow (0, i , zeta [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc1.setRow (0, i , zeta [i]);
  }

  for (int i = 0; i < 8 ; i++)
  {
    lc2.setRow (0, i , zeta [i]);
  }
}
void mostrarY () {
  for (int i = 0; i < 8 ; i++)
  {
    lc0.setRow (0, i , igriega [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc1.setRow (0, i , igriega [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc2.setRow (0, i , igriega [i]);
  }
}
void mostrarX () {
  for (int i = 0; i < 8 ; i++)
  {
    lc0.setRow (0, i , equis [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc1.setRow (0, i , equis [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc2.setRow (0, i , equis [i]);
  }
}
void mostrarC () {
  for (int i = 0; i < 8 ; i++)
  {
    lc0.setRow (0, i , ce [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc1.setRow (0, i , ce [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc2.setRow (0, i , ce [i]);
  }
}
void mostrarV () {
  for (int i = 0; i < 8 ; i++)
  {
    lc0.setRow (0, i , ve [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc1.setRow (0, i , ve [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc2.setRow (0, i , ve [i]);
  }
}
void mostrarNada () {
  for (int i = 0; i < 8 ; i++){
    lc0.setRow (0, i , nada [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc1.setRow (0, i , nada [i]);
  }
  for (int i = 0; i < 8 ; i++)
  {
    lc2.setRow (0, i , nada [i]);
  }
}
