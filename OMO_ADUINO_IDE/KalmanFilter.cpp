// kalmanFilter1D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef int measureType;
typedef unsigned char uint8;

measureType kalmanFilter1D(measureType input);
void printMeasurement(measureType filtered, measureType raw);
void multiplyMatrix(const uint8 sizeofRow1, const uint8 sizeofColumn1,
	const uint8 sizeofRow2, const uint8 sizeofColumn2,
	uint8 matrix1[][2], uint8 matrix2[][2], uint8 result[][2]);

int _tmain(int argc, _TCHAR* argv[])
{
	measureType measurements_1[] = { 350, 340, 345, 340, 345, 348, 352, 355, 358, 352 };
	measureType measurements_2[] = { 10, 15, 20, 15, 18, 22, 25, 20, 17, 19, 23, 25, 29, 30, 35, 32};
	measureType tempMeasure = 0;
	const int SIZE_OF_ARRAY = sizeof(measurements_2) / sizeof(measureType);
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		tempMeasure = kalmanFilter1D(measurements_2[i]);
		printMeasurement(tempMeasure, measurements_2[i]);
	}
	return 0;
}

#define INITIAL_X 0
#define INITIAL_X_CHANGE 0
#define R 5

measureType kalmanFilter1D(measureType Z)
{
	static uint8 X[2][1] = { { INITIAL_X }, { INITIAL_X_CHANGE } };
	uint8 H[1][2] = { 1, 0 };
	uint8 U[] = { 1, 1 };
	uint8 F[2][2] = { { 1, 1 }, { 0, 1 } };
	uint8 temp1x1_[1][1] = { 0 };
	uint8 temp2x1_[2][1] = { { 0 }, { 0 } };
	uint8 temp1x2_[1][2] = { 0, 0 };
	uint8 temp2x2_[2][2] = { { 0, 0 }, { 0, 0 } };
	uint8 temp2x2_2[2][2] = { { 0, 0 }, { 0, 0 } };
	static uint8 P[2][2] = { { 0, 0 }, { 0, 1000 } };
	static uint8 S = 0;
	static uint8 y = 0;
	static uint8 k[2][1];

	//X = (F * X) + U
	temp2x1_[0][0] = F[0][0] * X[0][0] + F[0][1] * X[1][0] + U[0];
	temp2x1_[1][0] = F[1][0] * X[0][0] + F[1][1] * X[1][0] + U[1];

	X[0][0] = temp2x1_[0][0];
	X[1][0] = temp2x1_[1][0];
	
	//P = F * P * Ft
	{
		temp2x2_[0][0] = F[0][0] * P[0][0] + F[0][1] * P[1][0];
		temp2x2_[1][0] = F[1][0] * P[0][0] + F[1][1] * P[1][0];
		temp2x2_[0][1] = F[0][0] * P[0][1] + F[0][1] * P[1][1];
		temp2x2_[1][1] = F[1][0] * P[0][1] + F[1][1] * P[1][1];

		P[0][0] = F[0][0] * temp2x2_[0][0] + F[0][1] * temp2x2_[0][1];
		P[1][0] = F[0][0] * temp2x2_[1][0] + F[0][1] * temp2x2_[1][1];
		P[0][1] = F[1][0] * temp2x2_[0][0] + F[1][1] * temp2x2_[0][1];
		P[1][1] = F[1][0] * temp2x2_[1][0] + F[1][1] * temp2x2_[1][1];
	}

	//y = Zt - (H * X)
	{
		y = Z - (X[0][0] * H[0][0] + X[0][1] * H[1][0]);
	}

	//S = H * P * Ht + R
	{
		temp1x2_[0][0] = P[0][0] * H[0][0] + P[1][0] * H[0][1];
		temp1x2_[0][1] = P[0][1] * H[0][0] + P[1][1] * H[0][1];
		S = temp1x2_[0][0] * H[0][0] + temp1x2_[0][1] * H[0][1] + R;
	}

	//k = P * Ht * S^-1
	{
		if (S == 0)
		{
			k[0][0] = (P[0][0] * H[0][0] + P[0][1] * H[0][1]);
			k[1][0] = (P[1][0] * H[0][0] + P[1][1] * H[0][1]);
		}
		else
		{
			k[0][0] = (P[0][0] * H[0][0] + P[0][1] * H[0][1]) * (1/S);
			k[1][0] = (P[1][0] * H[0][0] + P[1][1] * H[0][1]) * (1/S);
		}
	}

	//X = X + K * Y
	{
		X[0][0] += (k[0][0] * y);
		X[1][0] += (k[1][0] * y);
	}
	
	//P = ( I - (K*H))*P
	{
		temp2x2_[0][0] = 1 - (k[0][0] * H[0][0]);
		temp2x2_[0][1] = k[0][0] * H[0][1];
		temp2x2_[1][0] = k[1][0] * H[0][0];
		temp2x2_[1][1] = 1 - k[1][0] * H[0][1];

		temp2x2_2[0][0] = P[0][0] * temp2x2_[0][0] + P[1][0] * temp2x2_[0][1];
		temp2x2_2[0][1] = P[0][1] * temp2x2_[0][0] + P[1][1] * temp2x2_[0][1];
		temp2x2_2[1][0] = P[0][0] * temp2x2_[1][0] + P[0][1] * temp2x2_[1][0];
		temp2x2_2[1][1] = P[0][1] * temp2x2_[1][0] + P[1][1] * temp2x2_[1][1];

		P[0][0] = temp2x2_2[0][0];
		P[1][0] = temp2x2_2[1][0];
		P[0][1] = temp2x2_2[0][1];
		P[1][1] = temp2x2_2[1][1];
	}
	
	return (measureType)X[0][0];
}

void printMeasurement(measureType filtered, measureType raw)
{
	cout << "Raw: " << raw << "     filtered: " << filtered << endl;
}

void multiplyMatrix(const uint8 sizeofRow1, const uint8 sizeofColumn1,
	const uint8 sizeofRow2, const uint8 sizeofColumn2,
	uint8 matrix1[][2], uint8 matrix2[][2], uint8 result[][2])
{

	// Multiplying matrix a and b and storing in array mult.

	//return result;
}
