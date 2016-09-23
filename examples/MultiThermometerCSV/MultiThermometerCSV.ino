/**
 * @file MultiThermometerCSV.ino
 * Read temperatures from multiple Termopar Nanoshields and generate a CSV output.
 * 
 * Copyright (c) 2016 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */
#include <SPI.h>
#include "Nanoshield_Termopar.h"

// Create an array of five type K thermocouples
Nanoshield_Termopar tc[] = {
  Nanoshield_Termopar(4, TC_TYPE_K),  // Jumper on D4
  Nanoshield_Termopar(7, TC_TYPE_K),  // Jumper on D7
  Nanoshield_Termopar(8, TC_TYPE_K),  // Jumper on D8
  Nanoshield_Termopar(10, TC_TYPE_K), // Jumper on D10
  Nanoshield_Termopar(A3, TC_TYPE_K)  // Jumper on A3
};

const int numModules = sizeof(tc) / sizeof(Nanoshield_Termopar);

void setup()
{
  Serial.begin(9600);

  // Initialize each Termopar Nanoshield
  for(int i = 0; i < numModules; i++) {
    tc[i].begin();
  }
}

void loop()
{
  for(int i = 0; i < numModules; i++) {
    // Read thermocouple data
    tc[i].read();
    
    // Print temperature in the serial port
    if (!tc[i].hasError()) {
      if (i > 0) {
        Serial.print(',');
      }
      Serial.print(tc[i].getExternal());
    }
  }
  Serial.println();

  // Wait for next second
  delay(1000);
}
