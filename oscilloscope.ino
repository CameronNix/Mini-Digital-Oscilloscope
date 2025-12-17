/*
 Mini Digital Oscilloscope (ESP32)
 Author: Cameron Nix
 Description:
  - Samples analog voltage using ESP32 ADC
  - Buffers data and renders waveforms on OLED
  - Adjustable time-base control via potentiometer
*/
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI   23
#define OLED_CLK    18
#define OLED_DC     25
#define OLED_CS     27
#define OLED_RESET  16

#define ADC_PIN 34
#define TIME_PIN 35

int samples[128];


Adafruit_SH1106G display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  OLED_MOSI,
  OLED_CLK,
  OLED_DC,
  OLED_RESET,
  OLED_CS
);

void setup() {
  Serial.begin(9600);
  display.begin();
pinMode(ADC_PIN, INPUT);
ledcAttach(26, 2, 8);   // GPIO26 outputs 2 Hz PWM, 8-bit resolution
ledcWrite(26, 128);     // 50% duty cycle


}
void loop() {
for (int i = 0; i < 128; i++) {
int adc = analogRead(ADC_PIN);
samples[i] = adc;
int pot = analogRead(TIME_PIN);
int sampleDelay = map(pot, 0, 4095, 1, 20);
delay(sampleDelay);
}

display.clearDisplay();

for (int i = 1; i < 128; i++) {
  int x1 = i - 1;
  int x2 = i;

  int y1 = map(samples[i - 1], 0, 4095, 63, 0);
  int y2 = map(samples[i],     0, 4095, 63, 0);

  y1 = constrain(y1, 0, 63);
  y2 = constrain(y2, 0, 63);

  display.drawLine(x1, y1, x2, y2, SH110X_WHITE);
}


display.display();
delay(50);
}
