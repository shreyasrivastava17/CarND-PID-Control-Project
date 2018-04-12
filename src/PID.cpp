#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init() {
    Kp = 0.16;
    Ki = 0.0002;
    Kd = 3.1;
    p_error = 0.0;
    d_error = 0.0;
    i_error = 0.0;
    
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    return -(Kp*p_error + Kd*d_error + Ki*i_error);
}

