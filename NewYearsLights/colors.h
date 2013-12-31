struct RGB {
  int r;
  int g;
  int b;
};

struct LedRGB {
  int r;
  int g;
  int b;
};

LedRGB RGBtoLED(RGB rgb);
void setColor(int ledNum, RGB rgb);
