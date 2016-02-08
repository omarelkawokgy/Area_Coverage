#ifndef TYPES_FILE
#define TYPES_FILE

/*---------------------TYPES--------------------------
This area includes all standard PIN numbers needed for the project
most probably it will be included in all modules
-----------------------------------------------------*/
/*status of the slots on the map*/
#define BUSY_SLOT 0xFF
#define VACUMMED_SLOT 0xF0
#define UNDEFINED_SLOT 0x00

/*pins of the sensors*/
#define FRONT_SENSOR_PIN 3
#define RIGHT_SENSOR_PIN 8
#define LEFT_SENSOR_PIN 9
#define ENCODER_PIN 0

/*pins of the motors*/
#define RIGHT_MOTOR_POSITIVE_PIN 5
#define RIGHT_MOTOR_GROUND_PIN 4

#define LEFT_MOTOR_POSITIVE_PIN 6
#define LEFT_MOTOR_GROUND_PIN 7

/*standard distances for empty and busy*/
#define SIZE_OF_SLOT 20

/*------------Macro functions definition-------------*/
#define VAR(type, Name_of_Module) type
#define P2VAR(type, Name_of_Module) type*
#define CONSTVAR(type, Name_of_Module) const type
#define P2CONSTVAR(type, Name_of_Module) const type*
#define CONSTP2VAR(type, Name_of_Module) type* const

/*-----------------Type definitions------------------*/
typedef unsigned char uint8;
typedef signed char int8;
typedef unsigned short uint16;
typedef signed short int16;
typedef unsigned int uint32;
typedef signed int int32;
typedef unsigned long long uint64;
typedef signed long long int64;
typedef uint8 return_type;
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
