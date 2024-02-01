using namespace std;

#include "Arduino.h"
#include "FirstOrderIIR.h"
#include "MovingAverage.h"

#define JOYSTICK_LX 32
#define JOYSTICK_LY 33
#define JOYSTICK_RX 35
#define JOYSTICK_RY 34

#define B0_COEFF 0.00001f
#define B1_COEFF 0.0f
#define A1_COEFF 1.001f
#define ORDER 20

FirstOrderIIRFilter filter1 = FirstOrderIIRFilter(B0_COEFF, B1_COEFF, A1_COEFF, 0);

void setup() {
  // put your setup code here, to run once:
  setCpuFrequencyMhz(10);
  pinMode(JOYSTICK_LX, INPUT);
  pinMode(JOYSTICK_LY, INPUT);
  pinMode(JOYSTICK_RX, INPUT);
  pinMode(JOYSTICK_RY, INPUT);
  Serial.begin(112500);
  Serial.println("Start!");
  Serial.printf("CPU is running at %d MHz", getCpuFrequencyMhz());
  vTaskDelay(2000/portTICK_RATE_MS);
}

void loop() {
  // put your main code here, to run repeadtedly:
  char msg[30];
  uint16_t ana_LX = analogRead(JOYSTICK_LX);
  uint16_t ana_LX_filtered = (uint16_t)filter1.Update(ana_LX);
  sprintf(msg, "%04d %04d\n", ana_LX, ana_LX_filtered);
  Serial.print(msg);
  vTaskDelay(10/portTICK_RATE_MS);
}
