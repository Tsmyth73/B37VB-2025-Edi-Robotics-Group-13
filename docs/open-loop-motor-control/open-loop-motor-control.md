Open loop motor control lab report
B37VB
Fraser Rillie, Taylor Smyth

Abstract:
The main objective of this experiment was to measure and demonstrate the effects of a Buggy's speed and direction using open loop motor control. We measured pwm inputs, direction of buggy, speed, static friction threshold. The conclusion of open loop motor control in respect to the buggy is: it would be very hard to achieve anything with open loop control as even in lab conditions it can come off course, this makes closed loop motor control almost necessary

Introduction:
This report’s purpose is to discuss open-loop motor control with pulse width modulation (PWM). In the lab, the buggy was assessed at three different speeds, and assessed if the buggy veered to the left or right. By evaluating the tolerance and effect of the motor discrepancies, we are able to quantify how these tolerances of components effects the open loop circuit control of the buggy

Method:
The experiments method of measuring how pwm effects the pwm on the speed and direction of the motor was the change the value of the pwn input in the Arduino file and record the results, for gathering the static  friction threshold of the buggy we lowered the pwm input of both motors till they didn't have enough power to over come the friction of the gearbox of the motors

Results:

|Experiment No.1|	PWM Values (PWM) |	Direction the buggy steers|
|---|---|---|
|1|	Left: 200, Right: 200 |Most Left| 
|2|	Left: 150, Right: 150 	|Left|
|3|	Left: 100, Right: 100 |Least Left|


|Experiment No.2|	PWM Values (PWM) |	Metres per second (ms-1)|
|---|---|---|
|1|	Left: 255, Right: 255 |0.32| 
|2|	Left: 230, Right: 200 	|0.225|
|3|	Left: 125, Right: 100 |0.1|
|4|	Left: 50, Right: 50  |0|

The first table clearly shows that the higher the PWM, the greater turning circle the buggy will veer off to. The left motor was adjusted to be slightly higher than the right motor, to correspond with the issue of the buggy steering left. To fix the uneven steering of the buggy, the left motor PWM was increased by higher increments when the overall PWM increases. However, there was an anomaly, where the buggy moved straight with both motors at 255 PWM. Excluding the anomaly, the second table suggests that there is a mismatch of around 15-25%, as the overall PWM increases.

 There are a few reasons as to which the motors are performing unevenly, including an imbalance in motor rpm, but as well as differing gearbox friction. this plays a part in the power needed to sustain speed and the static friction threshold discussed earlier. A fourth test was conducted to see whether at 50 PWM if the buggy will move at all, for both motors. This proved that the motors need a certain PWM value to be able to create enough friction to start moving.

Conclusion  
The purpose of this experiment was to evaluate the variations in motor mismatch in relation to PWM in an open-loop system. The results found that with the higher the PWM the greater the buggy would steer away from its original path, with around 5-10% of a deficit on the left motor. For the buggy to be autonomous by itself, it must be exact, so without feedback control, motor mismatches would increasingly reduce accuracy of the buggy which is a major issue.
