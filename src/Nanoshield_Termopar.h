/**
 * @file Nanoshield_Termopar.h
 * This is the library to access the Termopar Nanoshield version 2
 * 
 * Copyright (c) 2015 Circuitar
 * This software is released under the MIT license. See the attached LICENSE file for details.
 */

#ifndef NANOSHIELD_TERMOPAR_h
#define NANOSHIELD_TERMOPAR_h

#include "Arduino.h"
#include <SPI.h>

enum TcType {
    TC_TYPE_B,
    TC_TYPE_E,
    TC_TYPE_J,
    TC_TYPE_K,
    TC_TYPE_N,
    TC_TYPE_R,
    TC_TYPE_S,
    TC_TYPE_T,
    TC_TYPE_VOLTAGE_GAIN_8 = 0x8,
    TC_TYPE_VOLTAGE_GAIN_32 = 0xC
};

enum TcAveraging {
    TC_AVG_OFF,
    TC_AVG_2_SAMPLES,
    TC_AVG_4_SAMPLES,
    TC_AVG_8_SAMPLES,
    TC_AVG_16_SAMPLES
};

enum TcOcd {
    TC_OCD_OFF,
    TC_OCD_15_MS,
    TC_OCD_37_MS,
    TC_OCD_125_MS
};

class Nanoshield_Termopar {
  public:
    /**
     * @brief Constructor.
     * 
     * Creates an object to access one Termopar Nanoshield.
     * 
     * @param cs Chip select pin to access Termopar Nanoshield.
     * @param type Thermocouple type.
     * @param avg Averaging mode.
     * @param ocd Open circuit detection mode.
     */
    Nanoshield_Termopar(uint8_t cs = 8, TcType type = TC_TYPE_K, TcAveraging avg = TC_AVG_OFF, TcOcd ocd = TC_OCD_15_MS);

    /**
     * @brief Initializes the module.
     * 
     * Initializes SPI and CS pin.
     */
    void begin();

    /**
     * @brief Reads all temperatures.
     * 
     * @see getInternal()
     * @see getExternal()
     * @see hasError()
     */
    void read();

    /**
     * @brief Gets the last external temperature reading (hot junction).
     * 
     * @return The last external temperature reading.
     * @see read()
     */
    double getExternal();

    /**
     * @brief Gets the last internal temperature reading (cold junction).
     * 
     * @return The last internal temperature reading.
     * @see read()
     */
    double getInternal();

    /**
     * @brief Checks if external temperature is out of range.
     * 
     * @return True if external temperature (hot junction) is out of range.
     */
    bool isExternalOutOfRange();

    /**
     * @brief Checks if internal temperature is out of range.
     * 
     * @return True if internal temperature (cold junction) is out of range.
     */
    bool isInternalOutOfRange();

    /**
     * @brief Checks for overvoltage or undervoltage.
     * 
     * @return True if there is overvoltage or undervoltage on the thermocouple inputs.
     */
    bool isOverUnderVoltage();

    /**
     * @brief Checks if thermocouple circuit is open.
     * 
     * @return True if thermocouple circuit is open.
     */
    bool isOpen();

    /**
     * @brief Checks if there are errors.
     * 
     * @return True if any of the following errors is detected: open circuit, overvoltage, undervoltage,
     *         internal temperature out of range or external temperatur out of range.
     * @see isExternalOutOfRange()
     * @see isInternalOutOfRange()
     * @see isOverUnderVoltage()
     * @see isOpen()
     */
    bool hasError();

  private:
    static SPISettings spiSettings;

    uint8_t cs;
    TcType type;
    TcAveraging avg;
    TcOcd ocd;
    double internal;
    double external;
    uint8_t fault;
};

#endif