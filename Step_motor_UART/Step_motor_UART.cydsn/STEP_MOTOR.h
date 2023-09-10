/*
As an example of a stepper motor, here we use the 28BYJ-48 which can 
be found in many starter kits. This small
unipolar stepper motor additionally has a gear unit with a 63.68395:1
reduction ratio. The motor has a step size of 11.25°, so the number
of steps for a full rotation of the gear unit output shaft is 2037.8864,
or approximately 2038 steps per rotation (rounded up). Five wires
are needed to connect the motor: A, B, C, D, and the supply voltage.
*/

#include "project.h"

//De la tabla
/*
    
    1
    2
    3
    4
    5
    6
    7
    8

*/
uint8_t steps[] = {
    0x08,
    0x0C,
    0x04,
    0x06,
    0x02,
    0x03,
    0x01,
    0x09
};