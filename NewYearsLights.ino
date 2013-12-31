#include "Tlc5940.h"
#include "colors.h"

int time = 1;
int debug = 1;
int h = 0;

#define NUM_LEDS 21
int LEDS[NUM_LEDS][3] = {
  {0, 1, 2},
  {3, 4, 5},
  {6, 7, 8},
  {9, 10, 11},
  {12, 13, 14},
  {15, 17, 18},
  {19, 20, 21},
  {22, 23, 24},
  {25, 26, 27},
  {28, 29, 30},
  {31, 32, 33},
  {34, 35, 36},
  {37, 38, 39},
  {40, 41, 42},
  {43, 44, 45},
  {46, 47, 48},
  {49, 50, 51},
  {52, 53, 54},
  {55, 56, 57},
  {58, 59, 60},
  {61, 62, 63},
};


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


void setColor(int ledNum, LedRGB lrgb) {
    int red_pin = LEDS[ledNum][0];
    int green_pin = LEDS[ledNum][1];
    int blue_pin = LEDS[ledNum][2];

    Tlc.set(red_pin, lrgb.r);
    Tlc.set(green_pin, lrgb.g);
    Tlc.set(blue_pin, lrgb.b);
}

void setColor(int ledNum, RGB rgb) {
    LedRGB lrgb = RGBtoLED(rgb);
    setColor(ledNum, lrgb);
}

void setColor(int ledNum, HSV hsv) {
    RGB rgb = HSVtoRGB(hsv);
    setColor(ledNum, rgb);
}

LedRGB RGBtoLED(RGB rgb) {
  if(rgb.r > 1 || rgb.g > 1 || rgb.b > 1) {
    Serial.print("Exceeds expected RGB values");
  }
  else {
    LedRGB lrgb = {rgb.r*4000, rgb.g*4000, rgb.b*4000};
    return lrgb;
  }
}


RGB HSVtoRGB(HSV hsv) {
  // algorithm from http://en.wikipedia.org/wiki/HSL_and_HSV#Converting_to_RGB
  RGB rgb;
  RGB rgb_p;

  float chroma = hsv.v * hsv.s;
  float sector = float(hsv.h) / 60.0;
  // remainder is sector mod 2 in the real number sense
  float remainder = sector - ((int(sector) / 2) * 2) ;
  float x = chroma * (1 - abs(remainder - 1));
  switch(int(sector)) {
    case 0:
      rgb_p = (RGB){chroma, x, 0};
      break;
    case 1:
      rgb_p = (RGB){x, chroma, 0};
      break;
    case 2:
      rgb_p = (RGB){0, chroma, x};
      break;
    case 3:
      rgb_p = (RGB){0, x, chroma};
      break;
    case 4:
      rgb_p = (RGB){x, 0, chroma};
      break;
    case 5:
      rgb_p = (RGB){chroma, 0, x};
      break;
    default:
      rgb_p = (RGB){0, 0, 0};
  }

  float m = hsv.v - chroma;
  rgb = (RGB){rgb_p.r + m, rgb_p.g + m, rgb_p.b + m};

  if(debug){
    Serial.println("HSV:");
    Serial.println(hsv.h);
    Serial.println(hsv.s);
    Serial.println(hsv.v);
    Serial.println("RGB:");
    Serial.println(rgb.r);
    Serial.println(rgb.g);
    Serial.println(rgb.b);
    Serial.println("-----");
  }

  return rgb;
}


void setup() {
  Serial.begin(9600);
  Tlc.init();
}


void loop() {
  for(int n = 0; n < NUM_LEDS; n++) {
    Tlc.clear();
    RGB rgb = {MAROON};

    float s = float(n) / float(NUM_LEDS);

    HSV hsv = {h, 1, .1};
    h++;
    if(h > 360){
      h = 0;
    }

    setColor(3, hsv);
    Tlc.update();
    delay(time);
  }
}
