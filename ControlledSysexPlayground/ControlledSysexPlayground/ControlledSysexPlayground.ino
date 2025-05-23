// ControlledSysexPlayground.ino
#include "Screen.hpp"
#include "Pixies.hpp"
#include "ControlSurfaceSingleton.h"

void setup() {
  initPixies();
  Serial.begin(115200);
  delay(1000);
  Serial.println("Strarting control surface");
    // Initialize the Control Surface through the singleton
  // ControlSurfaceSingleton::getInstance().begin();
  //Serial.println("Hi");
  //initDisplays();
  Serial.print("Free heap: ");
  Serial.println(ESP.getFreeHeap());

}

void loop() {

  updatePixies();
  ControlSurfaceSingleton::getInstance().loop();
  ControlSurfaceSingleton::getInstance().getStatus();
  //updateDisplays();
  //Serial.println("Hi");
}
