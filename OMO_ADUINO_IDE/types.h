#ifndef TYPES_FILE
#define TYPES_FILE
#include "Arduino.h"
/*---------------------TYPES--------------------------
This area includes all standard PIN numbers needed for the project
most probably it will be included in all modules
-----------------------------------------------------*/
/*status of the slots on the map*/
#define BUSY_SLOT 0xFF
#define VACUMMED_SLOT 0xF0
#define UNDEFINED_SLOT 0x00

/*pins of the sensors*/
#define FRONT_SENSOR_INTERRUPT_NUMBER 0
#define RIGHT_SENSOR_PIN 8
#define LEFT_SENSOR_PIN 7
#define ENCODER_INTERRUPT_NUMBER 1

/*pins of the motors*/
#define RIGHT_MOTOR_POSITIVE_PIN 6
#define RIGHT_MOTOR_GROUND_PIN 5

#define LEFT_MOTOR_POSITIVE_PIN 10
#define LEFT_MOTOR_GROUND_PIN 9

#define HIGH_PWM 127
#define LOW_PWM 0

/*standard distances for empty and busy*/
#define SIZE_OF_SLOT 20

#define TRUE 1
#define FALSE 0

#define UINT_SNA 0

/*------------Macro functions definition-------------*/
#define VAR(type, Name_of_Module) type
#define P2VAR(type, Name_of_Module) type*
#define CONSTVAR(type, Name_of_Module) const type
#define P2CONSTVAR(type, Name_of_Module) const type*
#define CONSTP2VAR(type, Name_of_Module) type* const

/*-----------------Type definitions------------------*/
typedef unsigned char uint8;
typedef uint8 Boolean;
typedef uint8 return_type;
typedef signed char int8;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned int uint32;
typedef signed int int32;
typedef unsigned long long uint64;
typedef signed long long int64;
typedef float fint32;

typedef struct
{
	uint8 X_Column;
	uint8 Y_Row;
}Coordinates;

/*----------------OBJD TYPES----------------*/
typedef Coordinates PointPos;

typedef struct
{
	PointPos start;
	PointPos end;
}StraightLinePos;
#if 0
typedef struct
{
	Point L_Point;
	Point R_Point;
}L_R_Points;
#endif
/*-------------Robot types---------------*/
#if 0 
typedef struct
{
	uint8 Direction;
	uint16 Target;
}Heading;
#endif
typedef struct
{
	uint8 X_pos;
	uint8 Y_pos;
	uint16 theta;
}RobotPos;

#if 0
typedef struct
{
	fint32 X_Dist;
	fint32 Y_Dist;
}RectSize;
#endif

/*-----------------Global Variables------------------*/
//uint8 isrFrontSensorFlag;
#endif
