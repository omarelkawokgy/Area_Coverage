// kalmanFilter1D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define INITIAL_X 0
#define INITIAL_X_CHANGE 1

#define MEASUREMENT_NOISE 1

//P
#define P00 1000
#define P10 0
#define P01 0
#define P11 1000

//U
#define U00 0
#define U01 0

//F
#define F00 1
#define F10 0
#define F01 1
#define F11 1

//H
#define H00 1
#define H01 0

//K
#define k00 0
#define k10 0

//Q
#define Q00 11
#define Q10 11
#define Q01 11
#define Q11 11 

#define PI 3.1416 
#define FROM_DEGREE_TO_RADIAN (PI/180)
#define FROM_RADIAN_TO_DEGREE (180/PI)


typedef double measureType;
typedef unsigned char uint8;

typedef struct
{
	measureType x;
	measureType p;
}X_and_P_T;

measureType kalmanFilter1D(measureType input);
measureType kalmanFilter0D(measureType Z);
void printMeasurement(measureType filtered, measureType raw);

int _tmain(int argc, _TCHAR* argv[])
{
	measureType measurements_1[] = { 350, 340, 345, 0, 345, 348, 352, 355, 358, 357, 355, 356, 358, 360, 0, 1, 5, 3, 5, 6, 0, 7, 8};
	measureType measurements_2[] = { 8, 0, 0, 20, 21, 23, 21, 23, 27, 30, 32, 35, 37, 40, 39, 39, 42 };
	measureType measurements_3[] = { -190, -188, -185, -182, -184, -181, -180, -178, -175, -171, 0, -169, -168, 0, -166, -164, -163, -162, -159, -158, -159, -156 };
	measureType tempMeasure;
#define TEST_LIST measurements_1
	const int SIZE_OF_ARRAY = sizeof(TEST_LIST) / sizeof(measureType);
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		//TEST_LIST[i] = TEST_LIST[i] * FROM_DEGREE_TO_RADIAN;

		tempMeasure = kalmanFilter0D(TEST_LIST[i]);
		printMeasurement(tempMeasure, TEST_LIST[i]);
		//cout << endl;
	}			
	return 0;
}

#define PROCESS_NOISE 2.5
#define MEASUREMENTS_NOISE 1.2

measureType kalmanFilter0D(measureType Z)
{
	static measureType X = 0;
	static measureType P = 1000;
	static measureType K = 0;

	if ((X > 350) && (Z < 10))
	{
		X = 0;
		K = 0;
		P = 1000;
	}

	X = X;
	P = P * PROCESS_NOISE;

	K = P / (P + MEASUREMENTS_NOISE);
	X = X + K * (Z - X);
	P = (1 - K) * P;

	return (X);
}

measureType kalmanFilter1D(measureType Z)
{
	static measureType X[2][1] = { { INITIAL_X }, { INITIAL_X_CHANGE } };
	static measureType H[1][2] = { H00, H01 };
	static measureType U[2] = { U00, U01 };
	static measureType F[2][2] = { { F00, F01 }, { F10, F11 } };
	measureType temp1x1_[1][1] = { 0 };
	measureType temp2x1_[2][1] = { { 0 }, { 0 } };
	measureType temp1x2_[1][2] = { 0, 0 };
	measureType temp2x2_[2][2] = { { 0, 0 }, { 0, 0 } };
	static measureType P[2][2] = { { P00, P10 }, { P01, P11 } };
	static measureType S = 0.0;
	static measureType y = 0.0;
	static measureType k[2][1] = { {k00}, {k10} };
	static measureType processNoise[2][2] = { { Q00, Q10 }, { Q01, Q11 } };

	//y = Zt - (H * X)
	{
		y = Z - (X[0][0] * H[0][0] + X[0][1] * H[1][0]);
	}

	//S = H * P * Ht + R
	{
		temp1x2_[0][0] = P[0][0] * H[0][0] + P[1][0] * H[0][1];
		temp1x2_[0][1] = P[0][1] * H[0][0] + P[1][1] * H[0][1];
		S = temp1x2_[0][0] * H[0][0] + temp1x2_[0][1] * H[0][1] + MEASUREMENT_NOISE;
	}

	//k = P * Ht * S^-1
	{
		if (S <= 0)
		{
			k[0][0] = (P[0][0] * H[0][0] + P[0][1] * H[0][1]);
			k[1][0] = (P[1][0] * H[0][0] + P[1][1] * H[0][1]);
		}
		else
		{
			k[0][0] = (P[0][0] * H[0][0] + P[0][1] * H[0][1]) * (1 / S);
			k[1][0] = (P[1][0] * H[0][0] + P[1][1] * H[0][1]) * (1 / S);
		}
	}

	//measurement update
	//X = X + K * Y
	{
		X[0][0] += (k[0][0] * y);
		X[1][0] += (k[1][0] * y);
	}
	
	//P = ( I - (K*H))*P
	{
		temp2x2_[0][0] = P[0][0] * (1 - (k[0][0] * H[0][0])) + P[1][0] * (k[0][0] * H[0][1]);
		temp2x2_[0][1] = P[0][1] * (1 - (k[0][0] * H[0][0])) + P[1][1] * (k[0][0] * H[0][1]);
		temp2x2_[1][0] = P[0][0] * (k[1][0] * H[0][0]) + P[0][1] * (k[1][0] * H[0][0]);
		temp2x2_[1][1] = P[0][1] * (k[1][0] * H[0][0]) + P[1][1] * (1 - k[1][0] * H[0][1]);

		P[0][0] = temp2x2_[0][0];
		P[1][0] = temp2x2_[1][0];
		P[0][1] = temp2x2_[0][1];
		P[1][1] = temp2x2_[1][1];
	}
	//cout << "P: " << k[0][0] << "   "<< /*P[0][1] <<*/ endl 
	//	<< "   "<< k[1][0] << "   " <</* P[1][1] <<*/ endl;
	//Prediction
	//X = (F * X) + U
	{
		temp2x1_[0][0] = F[0][0] * X[0][0] + F[0][1] * X[1][0] + U[0];
		temp2x1_[1][0] = F[1][0] * X[0][0] + F[1][1] * X[1][0] + U[1];

		X[0][0] = temp2x1_[0][0];
		X[1][0] = temp2x1_[1][0];
	}
	
	//P = F * P * Ft + processNoise
	{
		temp2x2_[0][0] = F[0][0] * P[0][0] + F[0][1] * P[1][0];
		temp2x2_[1][0] = F[1][0] * P[0][0] + F[1][1] * P[1][0];
		temp2x2_[0][1] = F[0][0] * P[0][1] + F[0][1] * P[1][1];
		temp2x2_[1][1] = F[1][0] * P[0][1] + F[1][1] * P[1][1];

		P[0][0] = F[0][0] * temp2x2_[0][0] + F[0][1] * temp2x2_[0][1] + processNoise[0][0];
		P[1][0] = F[0][0] * temp2x2_[1][0] + F[0][1] * temp2x2_[1][1] + processNoise[1][0];
		P[0][1] = F[1][0] * temp2x2_[0][0] + F[1][1] * temp2x2_[0][1] + processNoise[0][1];
		P[1][1] = F[1][0] * temp2x2_[1][0] + F[1][1] * temp2x2_[1][1] + processNoise[1][1];
	}


	return (measureType)X[0][0];
}

void printMeasurement(measureType filtered, measureType raw)
{
	double difference = 0;
	difference = raw - filtered;

	cout << "Raw: " << raw << "      filtered: " << filtered << "      Difference: " << difference << endl;
}

void multiplyMatrix(const uint8 sizeofRow1, const uint8 sizeofColumn1,
	const uint8 sizeofRow2, const uint8 sizeofColumn2,
	uint8 matrix1[][2], uint8 matrix2[][2], uint8 result[][2])
{

	// Multiplying matrix a and b and storing in array mult.

	//return result;
}
