Writeup Report

PID Controller Project
(Note - Hi , The visualization for the simulator on my machine is available at - https://youtu.be/UUwrmQ3Z-GM).

The goals / steps of this project are the following:
  1. Tune the PID controller hyperparameters.
  2. Test the result on the simulator.
  3. Play around with the throttle.

## PID Controller
#### 1. Student describes the effect of the P, I, D component of the PID algorithm in their implementation.
The PID controller basically is made up of three components :
The proportional term (P term) - It produces a value that is proportional to the given cross track error value (CTE). The output is a proportional gain(Kp) multiplied by the CTE i.e. (Kp*CTE).
The Differential factor - obtained by multiplying the differential change in the CTE Error with time with the differential gain (Kd*E). Here we consider the difference in two time steps as one so the change of CTE with time is (CTE - CTE(at t-1)).
The Integral factor- obtained by multiplying the Steady state Error with the Integral gain (Ki*S)
For the purpose of the project, I began by began with the values for Kp, Kd and Ki, as given in the PID implementation lesson of the classroom - 0.2 , 3.0 and 0.004 . Interestingly, these values in themselves produced quite a decent result, but it is a bit jerky and the car drives off on the sharp turns.
To further tune the parameters, I initially thought of using twiddle, but once i actually opened the simulator I saw that there wasn't really a headless/manual mode where twiddle could tune the hyper parameters . Thus, I decided to manually adjust the values to improve the result.
Now, as the environmental factors are mostly negligible I kept the integral gain very low, at around 0.002. I kept the proportional gain at 0.16. I have slightly increased the value of the differential gain from the value given in the classroom so that the jerkiness can be controlled especially at sharp turns . This I think is because the higher the derivative gain, more is the resistance towards changing the current trajectory too quick/suddenly, hence the decrease in jerkiness. I didn't increase it beyond the given value so as to avoid the system getting over damped and taking too long to correct itself. Moreover reducing the value of the proportional gain also helped in reducing the jerkiness.  
## Discussion
#### 1. Briefly discuss what could you do to make the implementation more robust?
The result has a room for improvement . At 1 or 2 place s in the video where there are sharp turns the vehicle tends to go the end of the road but recovers. This behavior of the car can be improved by further tuning the hyper parameters. There are a couple of hyper parameter tuning algorithms , which I'd like to try out (once I understand them better) to make the solution robust and make the control as smooth as possible. I feel that manual tuning is really not the best of the ways for implementation even though it is a bit intuitive.
