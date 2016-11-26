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
	measureType measurements[] = { 350, 340, 345, 340, 345, 348, 352, 355, 358, 352 };
	measureType tempMeasure = 0;
	const int SIZE_OF_ARRAY = sizeof(measurements) / sizeof(measureType);
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		tempMeasure = kalmanFilter1D(measurements[i]);
		cout << endl;
		//printMeasurement(tempMeasure, measurements[i]);
	}
	return 0;
}

#define INITIAL_X 0
#define INITIAL_X_CHANGE 0
#define R 0

measureType kalmanFilter1D(measureType input)
{
	int X[2][1] = {{ INITIAL_X }, { INITIAL_X_CHANGE }};
	int H[1][2] = { 1, 0 };
	uint8 U[] = { INITIAL_X, INITIAL_X_CHANGE };
	int F[2][2] = { {1, 1}, {0, 1} };
	int temp2x1_[2][1] = { { 0 }, { 0 } };
	int temp1x2_[1][2] = { 0, 0 };
	int temp2x2_[2][2] = { { 0, 0 }, {0, 0} };
	int temp2x2_2[2][2] = { { 0, 0 }, { 0, 0 } };
	uint8 P[2][2] = { { 1000, 0 }, {0, 0} };
	int S;

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

		temp2x2_2[0][0] = F[0][0] * temp2x2_[0][0] + F[0][1] * temp2x2_[0][1];
		temp2x2_2[1][0] = F[0][0] * temp2x2_[1][0] + F[0][1] * temp2x2_[1][1];

		temp2x2_2[0][1] = F[1][0] * temp2x2_[0][0] + F[1][1] * temp2x2_[0][1];
		temp2x2_2[1][1] = F[1][0] * temp2x2_[1][0] + F[1][1] * temp2x2_[1][1];
	}

	//y = Z - (H * X)
	{
		int y = 0;
		y = input - (X[0][0] * H[0][0] + X[0][1] * H[1][0]);
	}

	//S = H * P * Ht + R
	{
		
		temp1x2_[0][0] = P[0][0] * H[0][0] + P[1][0] * H[0][1];
		temp1x2_[0][1] = P[0][1] * H[0][0] + P[1][1] * H[0][1];
		S = temp1x2_[0][0] * H[0][0] + temp1x2_[0][1] * H[0][1] + R;
	}

	//k = P * Ht * S^-1
	{
		int k[2][1];

		k[0][0] = (P[0][0] * H[0][0] + P[0][1] * H[0][1]) * S;
		k[1][0] = (P[1][0] * H[0][0] + P[1][1] * H[0][1]) * S;
	}
	cout << temp2x2_2[0][0];
	cout << " " << temp2x2_2[1][0] << endl;

	cout << temp2x2_2[0][1];
	cout << " " << temp2x2_2[1][1] << endl;

	return input;
}

void printMeasurement(measureType filtered, measureType raw)
{
	cout << "Raw: " << filtered << "     filtered: " << raw <<endl;
}

void multiplyMatrix(const uint8 sizeofRow1, const uint8 sizeofColumn1,
	const uint8 sizeofRow2, const uint8 sizeofColumn2,
	uint8 matrix1[][2], uint8 matrix2[][2], uint8 result[][2])
{
	
	// Multiplying matrix a and b and storing in array mult.

	//return result;
}
