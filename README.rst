Nanoshield_Termopar
===================

This is the Arduino software library to access the Termopar Nanoshield, a thermocouple interface module using the MAX31856 IC from Maxim Integrated. It can read several types of thermocouples: K, J, N, R, S, T, E, and B.

* Source code: https://github.com/circuitar/Nanoshield_Termopar
* Documentation: http://nanoshield-termopar.readthedocs.org/
* Reference board: `Termopar Nanoshield`_ from Circuitar_

Library features include:

* Get external temperature (hot junction)
* Get internal temperature (cold junction)
* Thermocouple type selection
* Continuous conversion mode
* Enable/disable averaging of 2, 4, 8 or 16 samples
* Error checking: open circuit, under/overvoltage and temperature out of range

To install, just click **Download ZIP** and install it using **Sketch > Include Library... > Add .ZIP Library** in the Arduino IDE.

The following examples_ are provided:

- SerialThermometer_: simple serial port thermometer application.
- MultiThermometer_: read temperature from multiple Termopar Nanoshields, with different thermocouple types.
- MultiThermometerCSV_: read temperature from multiple Termopar Nanoshields, generating a CSV output.
- LcdThermometer_: thermometer application using the `LCD Nanoshield`_ to display the data.
- RawVoltage_: measure raw thermocouple voltage and cold junction temperature.
- TemperatureDatalogger_: read temperature from multiple Termopar Nanoshields and log it into an SD card.
- OpenCircuitDetection_: disable the open circuit detection mode or change its parameters. Might be useful when using long thermocouple wires.

.. _`Termopar Nanoshield`: https://www.circuitar.com/nanoshields/modules/termopar/
.. _Circuitar: https://www.circuitar.com/
.. _examples: https://github.com/circuitar/Nanoshield_Termopar/tree/master/examples
.. _SerialThermometer: https://github.com/circuitar/Nanoshield_Termopar/blob/master/examples/SerialThermometer/SerialThermometer.ino
.. _MultiThermometer: https://github.com/circuitar/Nanoshield_Termopar/blob/master/examples/MultiThermometer/MultiThermometer.ino
.. _MultiThermometerCSV: https://github.com/circuitar/Nanoshield_Termopar/blob/master/examples/MultiThermometerCSV/MultiThermometerCSV.ino
.. _LcdThermometer: https://github.com/circuitar/Nanoshield_Termopar/blob/master/examples/LcdThermometer/LcdThermometer.ino
.. _`LCD Nanoshield`: https://www.circuitar.com/nanoshields/modules/lcd/
.. _RawVoltage: https://github.com/circuitar/Nanoshield_Termopar/blob/master/examples/RawVoltage/RawVoltage.ino
.. _TemperatureDatalogger: https://github.com/circuitar/Nanoshield_Termopar/blob/master/examples/TemperatureDatalogger/TemperatureDatalogger.ino
.. _OpenCircuitDetection: https://github.com/circuitar/Nanoshield_Termopar/blob/master/examples/OpenCircuitDetection/OpenCircuitDetection.ino

----

Copyright (c) 2015 Circuitar  
All rights reserved.

This software is released under an MIT license. See the attached LICENSE file for details.
