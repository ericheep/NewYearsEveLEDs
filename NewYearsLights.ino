#include "Tlc5940.h"
int time = 1000;

void setup() {
  Serial.begin(9600);
  Tlc.init();
}

void loop() {
  Tlc.clear();
  color(0, "red");
  Tlc.update();
  delay(time);
  Tlc.clear();
  color(1, "redorange");
  Tlc.update();
  delay(time);
  Tlc.clear();
  color(2, "orange");
  Tlc.update();
  delay(time);
  Tlc.clear();
  color(3, "yelloworange");
  Tlc.update();
  delay(time);
  Tlc.clear();
  color(4, "green");
  Tlc.update();
  delay(time);
  Tlc.clear();
  color(5, "greenblue");
  Tlc.update();
  delay(time);
  Tlc.clear();
  color(6, "blue");
  Tlc.update();
  delay(time);
  Tlc.clear();
  color(7, "blueviolet");
  Tlc.update();
  delay(time);
  Tlc.clear();
  color(8, "violet");
  Tlc.update();
  delay(time);
  Tlc.clear();
  color(9, "white");  
  Tlc.update();
  delay(time);
}

void color(int ledNum, String color) {
  int num = ledNum * 3;
  if (color == "red") {
    Tlc.set(num,4000);
    Tlc.set(num + 1, 0);  
    Tlc.set(num + 2, 0);
  }
  if (color == "redorange" || color == "orangered") {
    Tlc.set(num,4000);
    Tlc.set(num + 1, 0);  
    Tlc.set(num + 2, 0);
  }
  if (color == "orange") {
    Tlc.set(num, 3500);
    Tlc.set(num + 1, 2500);
    Tlc.set(num + 2, 1000);
  }
  if (color == "orangeyellow" || color == "yelloworange") {
    Tlc.set(num, 3500);
    Tlc.set(num + 1, 2500);
    Tlc.set(num + 2, 1000);
  }
  if (color == "yellow") {
    Tlc.set(num, 0);
    Tlc.set(num + 1, 0);
    Tlc.set(num + 2, 0);
  }
  if (color == "yellowgreen" || color == "greenyellow") {
    Tlc.set(num, 0);
    Tlc.set(num + 1, 4000);  
    Tlc.set(num + 2, 0);
  }
  if (color == "green") {
    Tlc.set(num, 0);
    Tlc.set(num + 1, 4000);  
    Tlc.set(num + 2, 0);
  }
  if (color == "greenblue" || color == "bluegreen") {
    Tlc.set(num, 0);
    Tlc.set(num + 1, 0);  
    Tlc.set(num + 2, 4000);
  }
  if (color == "blue") {
    Tlc.set(num, 0);
    Tlc.set(num + 1, 0);  
    Tlc.set(num + 2, 4000);
  }
  if (color == "blueviolet" || color == "violetblue") {
    Tlc.set(num, 0);
    Tlc.set(num + 1, 0);  
    Tlc.set(num + 2, 4000);
  }
  if (color == "violet") {
    Tlc.set(num, 4000);
    Tlc.set(num + 1, 0);
    Tlc.set(num + 2, 4000);
  }
  if (color == "white") {
    Tlc.set(num, 4000);
    Tlc.set(num + 1, 4000);  
    Tlc.set(num + 2, 4000);
  }
}

void color(int ledNum, int r, int g, int b) {
  if(r > 255 || g > 255 || b > 255) {
    Serial.print("Exceeds expected RGB values");
  }
  else {
    int num = ledNum * 3;
    Tlc.set(num, r*16);
    Tlc.set(num + 1, g*16);
    Tlc.set(num + 2, b*16);
  }
}


