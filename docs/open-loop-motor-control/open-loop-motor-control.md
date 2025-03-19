Introduction  
This report’s purpose is to discuss open-loop motor control with pulse width modulation (PWM). In the lab, the buggy was assessed at three different speeds, and to assess if the buggy will veer to the left or right. By evaluating the mismatches and variety of the motor discrepancies, the drawbacks of keeping a straight line while using open-loop motor control without feedback control.

Experiment  
The experiment was to test the buggy’s accuracy at different speeds in an open-loop control system. The buggy was evaluated at 4 different PWM values on each motor, which were then recorded, with the direction the buggy drove. Next, the ‘slower’ motor, had its PWM increased until the buggy drove in a straight line.

Results  

|Experiment No.|	PWM Values (PWM) |	Direction the buggy steers|
|---|---|---|
|1|	Left: 200, Right: 200 |Most Left| 
|2|	Left: 150, Right: 150 	|Left|
|3|	Left: 100, Right: 100 |Least Left|


|Experiment No.|	PWM Values (PWM) |	Metres per second (ms-1)|
|---|---|---|
|1|	Left: 255, Right: 255 |0.32| 
|2|	Left: 230, Right: 200 	|0.225|
|3|	Left: 125, Right: 100 |0.1|
|4|	Left: 50, Right: 50  |0|

The first table clearly shows that the higher the PWM, the greater turning circle the buggy will veer off to. The left motor was adjusted to be slightly higher than the right motor, to correspond with the issue of the buggy steering left. To fix the uneven steering of the buggy, the left motor PWM was increased by higher increments when the overall PWM increases. However, there was an anomaly, where the buggy moved straight with both motors at 255 PWM. Excluding the anomaly, the second table suggests that there is a mismatch of around 15-25%, as the overall PWM increases. There are a few reasons as to which the motors are performing unevenly, including an imbalance in motor rpm, but as well as uneven wheel friction, as one wheel was wobbling more than the other, which could lead to a difference in friction. A fourth test was conducted to see whether at 50 PWM if the buggy will move at all, for both motors. This proved that the motors need a certain PWM value to be able to create enough friction to start moving.

Conclusion  
The purpose of this experiment was to evaluate the variations in motor mismatch in relation to PWM in an open-loop system. The results found that with the higher the PWM the greater the buggy would steer away from its original path, with around 5-10% of a deficit on the left motor. For the buggy to be autonomous by itself, it must be exact, so without feedback control, motor mismatches would increasingly reduce accuracy of the buggy which is a major issue.

