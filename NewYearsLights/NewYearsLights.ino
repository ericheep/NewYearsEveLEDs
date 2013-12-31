#include "Tlc5940.h"
int time = 1000;

#define NUM_LEDS 21
int LEDS[NUM_LEDS][3] = {
  {0, 1, 2},
  {3, 4, 5},
  {6, 7, 8},
  {9, 10, 11},
  {12, 13, 14},
  {15, 16, 17},
  {18, 19, 20},
  {21, 22, 23},
  {24, 25, 26},
  {27, 28, 29},
  {30, 31, 32},
  {33, 34, 35},
  {36, 37, 38},
  {39, 40, 41},
  {42, 43, 44},
  {45, 46, 47},
  {48, 49, 50},
  {51, 52, 53},
  {54, 55, 56},
  {57, 58, 59},
  {60, 61, 62},
};

void setup() {
  Serial.begin(9600);
  Tlc.init();
}

void loop() {
  for(int n = 0; n < NUM_LEDS; n++) {
    Tlc.clear();
    setColorByLED(n, 4000, 4000, 4000);
    Tlc.update();
    delay(time);
  }
}

/*void setColorByRGB(int ledNum, int r, int g, int b) {*/
  /*if(r > 255 || g > 255 || b > 255) {*/
    /*Serial.print("Exceeds expected RGB values");*/
  /*}*/
  /*else {*/
    /*setColorByLED(ledNum, r*16, g*16, b*16);*/
  /*}*/
/*}*/


void setColorByLED(int ledNum, int led_red, int led_green, int led_blue) {
    int red_pin = LEDS[ledNum][0];
    int green_pin = LEDS[ledNum][1];
    int blue_pin = LEDS[ledNum][2];

    Tlc.set(red_pin, led_red);
    Tlc.set(green_pin, led_green);
    Tlc.set(blue_pin, led_blue);
}
