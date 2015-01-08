/*
 Sketch to test your Ex-Link connection to a Samsung
 Smart TV. Connect the Serial 2 port of your Arduino
 Mega to the EX-Link port on your Samsung TV, enable
 the UART mode and load this sketch onto your board.

 This sketch presents a small terminal interface on the
 programming port. Use the single-letter commands to
 verify that you can control the input, power state and
 volume of your TV.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see http://www.gnu.org/licenses/.
*/

void setup() {
  // put your setup code here, to run once:
    pinMode(13, OUTPUT);
    Serial2.begin(9600);
    Serial.begin(9600);
    delay(1000);
    digitalWrite(13, HIGH);
    Serial.println("Init complete\n");
    Serial.print("ex-link> ");
}

byte pwron[] =    { 0x00,0x00,0x00,0x02,0xD4 };
byte pwroff[] =   { 0x00,0x00,0x00,0x01,0xD5 };
byte vol50[] =    { 0x01,0x00,0x00,0x32,0xA3 };
byte vol8[] =     { 0x01,0x00,0x00,0x08,0xCD };
byte vgain[] =    { 0x0a,0x00,0x04,0x00,0xc8 };
byte compin[] =   { 0x0a,0x00,0x03,0x00,0xC9 };
byte hdmiin[] =   { 0x0a,0x00,0x05,0x00,0xC7 };
byte svidin[] =   { 0x0a,0x00,0x02,0x00,0xCA };
byte mute[] =     { 0x02,0x00,0x00,0x00,0xD4 };

// Samsung EX-link command header
byte ex_pre[] =   { 0x08,0x22 };

void ex_command(byte *command) {
  byte buffer[8];
  memcpy(buffer, ex_pre, 2);
  memcpy(buffer+2, command, 5);
  Serial2.write( buffer, 7 );
}

void loop() {
  if(Serial.available() ) {
      switch (Serial.read()) {
          case 'P':
              ex_command(pwron);
              Serial.println("Power on");
              break;
          case 'p':
              ex_command(pwroff);
              Serial.println("Power off");
              break;
          case 'V':
              ex_command(vol50);
              Serial.println("Volume: 50");
              break;
          case 'v':
              ex_command(vol8);
              Serial.println("Volume: 8");
              break;
          case 'h':
              ex_command(hdmiin);
              Serial.println("Input: HDMI");
              break;
          case 'c':
              ex_command(compin);
              Serial.println("Input: Component");
              break;
          case 'r':
              ex_command(vgain);
              Serial.println("Input: VGA");
              break;
          case 's':
              ex_command(svidin);
              Serial.println("Input: S-Video");
              break;
          case 'm':
              ex_command(mute);
              Serial.println("Mute");
              break;
          default:
              Serial.print("Commands:\n"
                "P - power on\n"
                "p - power off\n"
                "V - Volume to 50\n"
                "v - Volume to 8\n"
                "m - Mute\n"
                "h - HDMI\n"
                "c - Component\n"
                "r - VGA / PC\n"
                "s - S-Video\n\n");
              break;
      }
      Serial.print("ex-link> ");
  }
}
