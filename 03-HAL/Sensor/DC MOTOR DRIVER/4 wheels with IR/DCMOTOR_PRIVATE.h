
#ifndef DCMOTOR_PRIVATE_H_
#define DCMOTOR_PRIVATE_H_

//define logic voltages
#define HIGH 1
#define LOW 0

//define wanted states
#define STOP 0
#define CLK_WISE 1
#define ANTI_CLK_WISE 2

//define PORT
#define PORTA 0
#define PORTB 1
#define PORTC 2


//define DCMOTOR1 for UPPER left wheel pins
#define DC_MOTOR_PORT PORTA
#define DC_MOTOR_PIN1 1
#define DC_MOTOR_PIN2 2
//define DCMOTOR2 for UPPER right wheel pins
#define DC_MOTOR_PIN3 3
#define DC_MOTOR_PIN4 4

//define DCMOTOR1 for LOWER left wheel pins
#define DC_MOTOR_PORT PORTA
#define DC_MOTOR_PIN5 5
#define DC_MOTOR_PIN6 6
//define DCMOTOR2 for LOWER right wheel pins
#define DC_MOTOR_PIN7 7
#define DC_MOTOR_PIN8 8




#endif /* DCMOTOR_PRIVATE_H_ */
