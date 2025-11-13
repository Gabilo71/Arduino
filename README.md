# Arduino
This is a short guide on how the project is giong to be built. it also contains the elementary structure of coding to ensure it is easier to undersatand.

The main objective is to create a feeder for industry. In our case, it feeds steel sheets which have an exact width. To activate the feeder we will use a controller by buttons. The controller will share the data via digital pins. The project is suposed to be done with ArduinoUno, so the langauge program is Arduino. The hardware will consist of 3 motors to move the feeder and an electromagnet. The types of sensors we will use are both analogics and digitals. Some of they are limit switches, laser sensor, buttons (pull-down)...etc. The rest will be explained on the way along.

Notice that width could be changed by adding some serail monitor. (some coding will be at the end, if you wish this option just go and a replace the original function for the one you prefer ___).

---BULDING THE STRUCTURE---

The project needs a base to support the feeder and it has to be able to go up and down in a determinante positions. We will call the position 1 when the feeder sheet.

Image position 1

The position 2 will be when sheet is elevated to the top.

image position 2

Position 3 will be when the horizontal move ends and is supposed to go down.

image position 3

Last position is when the feeder lay down the sheet.

image position 4

So
