Simple LED strip controller
=========================

This project is a simple LED strip controller using an Arduino Nano.

The LED strip is dimmable and warm white, so only brightness can be adjusted.

This will be a offline light and the brightness is controlled by a potentiometer.

Because of the high current of the ca. 1 meter LED strip, the strip is controlled through a IRLZ34N MOSFET, using PWM for the brightness.

The LED strip is dimmable and warm white, so only brightness can be adjusted via PWM through a MOSFET. (connected to ledPin)

Problems
--------------------------
Unfortunately the potentiometer did not supply stable values, resulting in a flickering LED strip.

After a capacitor on the poti did not help, I introduced some simple logic to stabilize the brightness.

Probably not the best solution but it does the job for my use case...
