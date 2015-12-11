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
* Error checking: open circuit and under/overvoltage

To install, just click **Download ZIP** and install it using **Sketch > Include Library... > Add .ZIP Library** in the Arduino IDE.

The following examples_ are provided:

- MultiThermometer_ read temperature from multiple Termopar Nanoshields, with different thermocouple types.
- SimpleThermometer_ simple serial port thermometer application for a K-type thermocouple (the default type).

.. _`Termopar Nanoshield`: https://www.circuitar.com/nanoshields/modules/termopar/
.. _Circuitar: https://www.circuitar.com/
.. _examples: https://github.com/circuitar/Nanoshield_Termopar/tree/master/examples
.. _MultiThermometer: https://github.com/circuitar/Nanoshield_Termopar/blob/master/examples/MultiThermometer/MultiThermometer.ino
.. _SimpleThermometer: https://github.com/circuitar/Nanoshield_Termopar/blob/master/examples/SimpleThermometer/SimpleThermometer.ino

----

Copyright (c) 2015 Circuitar  
All rights reserved.

This software is released under an MIT license. See the attached LICENSE file for details.
