# Amulet Serial Communication Library#

  
Arduino Library: Brian Deters  Feb 2017

Port to Particle: Johnny Gohata Mar 2017 

## Introduction ##

The Amulet UART communication library for Particle is a simple port of the existing Arduino library found on [Github](http://github.com/amulettechnologies/AmuletLCD). The library greatly simplifies the communication between Particle and any of the Amulet display modules. 

Amulet has developed it's own CRC based full-duplex serial communication protocol.  A typical message packet looks like:

![](http://www.amulettechnologies.com/images/jdownloads/downloadimages/Protocol.jpg)


The library abstracts out the having to learn the details of this protocol, including various opcodes, the complexity of packetizing the communication and calculation of CRC. With this library, Particle just needs to assign certain Amulet defined variables, and the variables will be read by the Amulet display automatically.  A Serial.Event call is used to call the library, so when there is communication on the serial BUS, the library does its "magic". 

If you want to know in detail how the Amulet protocol works, you can look at the source in the library.  The code is well documented with comments, to make it easy to understand. 

"Amulet Serial Communication Library" is licensed under Lesser General Public License 
 [(LGPL Version 2.1)](http://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html).

## Installation ##
In the Particle Web IDE, click the libraries tab, find Amulet Serial Communication Library, and choose "Include in App"

## Examples ##
The following examples are included with the **Amulet communication library**:
###  Blinky_GUI  

Values passed from the display can  control the blink rate of the onboard LED of the Photon.  A slider GUI can be used to control the value of the variable, AmuletWords[0]. The Photon updates AmuletWords[0] as the slider changes.

    void loop() {
		interval = AmuletWords[0];		//slider value from display 
		digitalWrite(D7, HIGH);  		// set the LED on
		delay(interval);              	// wait for interval sec.
		digitalWrite(D7, LOW);    		// set the LED off
		delay(interval);              	// wait for interval sec.
	}
  
###  Button_GUI  

A check box GUI on the Amulet display in the form of an on/off switch controls the state of the onboard LED of the Photon. The byte value, either 0x00 (off) or 0x01 (on) gets communicated to the Photon, within the variable, AmuletBytes[0]. 

    void loop() {
       	value = AmuletBytes[0];
    	digitalWrite(D7, value);
      	delay(100);
    } 
  

###  ReadPOT_GUI  

The values of a POT is read by the Photon using the analog pin 0 (A0) and this value is communicated to the Amulet display by the assignment of AmuletWords[0]. The value can be displayed by a numeric field or use many of the gauges that come with Amulet's IDE.


    void loop() {
       	AmuletWords[0] = analogRead(A0);
     	 delay(100);
    }

The AmuletWords variable is used rather than AmuletBytes because the POT value goes above 256.


## GEMstudio Software ##
Amulet offers free software to program the Amulet modules. The software says it is a trial version, but for GUI projects under 5 pages, the software is full featured. You just need to register on their website.   [Free GEMstudio](http://www.amulettechnologies/index.php/sales/try-software).  GEMstudio includes a GUI simulator which communicates out the serial COM port.  So even without an actual Amulet's smart display module, you can see your design interact with the Particle through the USB cable. 