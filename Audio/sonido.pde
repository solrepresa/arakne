import ddf.minim.*;
import ddf.minim.effects.*;

Minim minim;
AudioPlayer groove1;
AudioPlayer groove2;
AudioPlayer groove3;

import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port

void setup()
{
  size(200, 200);
  println(Serial.list());
  String portName = Serial.list()[2];//orden de los com
  myPort = new Serial(this, portName, 9600);

  minim = new Minim(this);
  groove1 = minim.loadFile("001.mp3", 2048);
  groove2 = minim.loadFile("002.mp3", 2048);
  groove3 = minim.loadFile("003.mp3", 2048);
}

void draw() {


  while ( myPort.available() > 0) {  // If data is available,
    int v = myPort.read();         // read it and store it in val
    print("LLego: ");
    println(v);

    groove1.play();

    if (v==0) {
      groove1.rewind();
      groove2.rewind();
      groove3.rewind();
      groove1.loop();
    } else if (v==1) {

      groove1.rewind();
      groove2.rewind();
      groove3.rewind();
      groove1.pause();
      groove2.play();
    } else if (v==2) {

      groove1.rewind();
      groove2.rewind();
      groove3.rewind();
      groove2.pause();
      groove3.play();
    } else {

      //   groove0.rewind();
      //   groove1.rewind();
      //  groove2.rewind();
      groove1.pause();
      groove2.pause();
      groove3.pause();
    }
  }
}
