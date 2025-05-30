#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 16x16 binary image (example: a heart shape)
const uint8_t myBitmap[] PROGMEM = {
 // 'final-image', 128x64px
// 'final-image', 128x64px
  // 'final-image (1)', 128x64px
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xe0, 0x8b, 0xcf, 0xff, 0x00, 0x7f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x23, 0xfd, 0x00, 0x7f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x7e, 0x87, 0x7f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x7f, 0xdf, 0xff, 0xff, 
  0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 
  0xff, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x05, 0x03, 0xff, 0xff, 
  0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 
  0xfe, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 
  0xff, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 
  0xfe, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 
  0xff, 0xe0, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 
  0xff, 0xfc, 0x07, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x07, 0xff, 0xff, 0x00, 0x00, 0x00, 0x0f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x0f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 
  0xbf, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xfe, 0x01, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 
  0x3f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x01, 0xfc, 0x00, 0x1f, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xf1, 0x80, 0x0f, 0xff, 0xff, 0x00, 0x00, 0x1f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 0x80, 0x0f, 0xc0, 0x00, 0xc0, 0x00, 0x1f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x4f, 0xff, 0x00, 0x0f, 0x80, 0x00, 0x30, 0x00, 0x3f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x80, 0x00, 0x18, 0x00, 0x3f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x90, 0x00, 0x18, 0x00, 0x1f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x3c, 0x00, 0x00, 0x21, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xf8, 0x7f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xf8, 0x00, 0x7f, 0xff, 0xf0, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xfc, 0x00, 0x00, 0x7f, 0xff, 0xf0, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf0, 0x00, 0x00, 0x7f, 0xff, 0xe1, 0x80, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xe7, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xcf, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xff, 0xfc, 0x07, 0xff, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0x87, 0xff, 0x87, 0xfe, 0x00, 0x00, 0x00, 0x00, 
  0x0f, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xe0, 0x7f, 0xfe, 0x0f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 
  0x1b, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
  0x21, 0xff, 0xff, 0xff, 0xff, 0x83, 0xf0, 0x0f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x01, 0x3f, 0xff, 0xbf, 0xff, 0xc7, 0xfc, 0x03, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xf8, 0x0f, 0xff, 0x8f, 0xfc, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xff, 0xc0, 0x83, 0xff, 0xbf, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xff, 0xfc, 0x01, 0xc1, 0xff, 0xbf, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 
  0xff, 0xc0, 0x00, 0x00, 0xff, 0xb7, 0xff, 0xf0, 0x00, 0x00, 0x38, 0x08, 0x38, 0x00, 0x00, 0x00, 
  0xfd, 0x80, 0x00, 0x00, 0xc0, 0x61, 0xff, 0xfe, 0x00, 0x00, 0x38, 0x06, 0x1e, 0x00, 0x00, 0x00, 
  0xfc, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3f, 0xff, 0xf8, 0x01, 0xf2, 0x03, 0x0e, 0xc0, 0x00, 0x00, 
  0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfe, 0x7f, 0xff, 0xe6, 0x01, 0x87, 0x1f, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x03, 0x8c, 0x98, 0x01, 0xc7, 0x23, 0xfc, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x3c, 0x00, 0x00, 0x01, 0xe7, 0x08, 0xff, 0xf0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xf3, 0x02, 0x1f, 0xfc, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x00, 0x03, 0xfe, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xf7, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xc0, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1040)

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1040)

// Array of all bitmaps for convenience. (Total bytes used to store images in PROGMEM = 1040)


void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();

  // Draw bitmap at (x, y), width = 16, height = 16
  display.drawBitmap(0, 0, myBitmap, 128 , 64, WHITE);

  display.display();
}

void loop() {
  // Nothing here
}
