# ArduinoHDXController

This is a set of Arduino sketches for controlling a Samsung Smart TV via the EX-Link port.
This port is a 3.5mm 3-conductor jack found on most Samsung Smart TV models that can be put into a mode to
provide an RS-232 serial port to control most of the TV's functions.

To connect to the EX-Link port, you need a TTL-to-RS232 level shifter (MAX3232 or equivalent) and a
serial-to-3.5mm cable wired to connect...  I use a cable part number XXXX from Aurora Multimeda.

(Sorry - I don't have the exact details of the connection right now as I'm typing this README.
I will update it later.)

EXLinkTest
----------

EXLinkTest is a sketch for verifying proper control of your TV via the EX-Link port.
It is designed for Arduino Mega and uses the 2 hardware serial ports; Serial provides
a terminal interface to the sketch, Serial2 connects to the EX-Link port on the TV.

Using a serial terminal on your computer, you can use the menu interface to send
a selection of test commands to your TV to verify yor serial connection.
