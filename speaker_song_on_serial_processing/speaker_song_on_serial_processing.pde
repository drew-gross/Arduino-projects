//imported libraries
import processing.serial.*;

//window size
int windowWidth = 800;
int windowHeight = 100;

//box info
int boxSize = 100;
int boxX = 0;
int boxY = 0;
int boxColor = 0;

//music info
int numNotes = 8;

//serial port info
Serial port;

void drawBox(int boxWidth, int boxHeight, int boxX, int boxY, int boxDrawColor) {
  stroke(boxDrawColor);
  fill(boxDrawColor);
  rect(boxX, boxY, boxSize, boxSize);
}

boolean isMouseOverBox(int boxWidth, int boxHeight, int boxX, int boxY) {
  return (mouseX > boxX - boxWidth && 
          mouseX < boxX + boxWidth &&
          mouseY > boxY - boxHeight &&
          mouseY < boxY + boxHeight);
}

void setup() {
  //create the box
  size(windowWidth, windowHeight);
  rectMode(RADIUS);
  //show available serial ports, choose one
  println(Serial.list());
  port = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  background(0);
  //draw the box
  if (isMouseOverBox(boxSize, boxSize, (int)(windowWidth/2.0), (int)(windowHeight/2.0))) {
    stroke(153);
    fill(153);
    port.write(1);
  } else {
    stroke(100);
    fill(100);
    port.write(0);
  }
  rect(boxX, boxY, boxSize, boxSize);
}

