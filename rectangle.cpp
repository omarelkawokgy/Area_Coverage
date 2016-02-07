#include <iostream>

#include "rectangle.h"
#include "CONF.h"

using namespace std;

#ifdef RECTANGLE
Rectangle::Rectangle(RectSize rectsize)
{
	RectangleSize.Y_Dist = rectsize.Y_Dist;
	RectangleSize.X_Dist = rectsize.X_Dist;

	rect = new uint8*[(uint32)RectangleSize.Y_Dist];
	for (uint8 count = 0; count < RectangleSize.X_Dist; count++)
	{
		rect[count] = new uint8[(uint32)RectangleSize.X_Dist];
	}
}

void Rectangle::init(void)
{
	for (uint32 i = 0; i < RectangleSize.Y_Dist; i++)
	{
		for (uint32 j = 0; j < RectangleSize.X_Dist; j++)
		{
			rect[i][j] = UNCOVERED;
		}
	}
}
#if 0
RectSize Rectangle::CalcRectPos(uint8 diagonalsAngle, uint16 diagonal)
{
	RectSize rectsize;

	rectsize.X_Dist = 0;
	rectsize.Y_Dist = 0;

	switch (diagonalsAngle)
	{
	case SCAN_0_ANGLE:
		/*y = sin(180)*HYP;*/
		/*x = cos(180)*HYP;*/
		/*do nothing on vertical scan*/
		break;
	case SCAN_30_ANGLE:
		/*x = sin(30)*HYP; 0.5*/
		rectsize.X_Dist = (0.5)*diagonal;
		/*y = cos(30)*HYP; 0.866*/
		rectsize.Y_Dist = (0.866)*diagonal;
		break;
	case SCAN_60_ANGLE:
		/*x = sin(60)*HYP; 0.866*/
		rectsize.X_Dist = (0.866)*diagonal;
		/*y = cos(60)*HYP; 0.5*/
		rectsize.Y_Dist = (0.5)*diagonal;
		break;
	case SCAN_90_ANGLE:
		/*y = sin(90)*HYP; 1*/
		/*x = cos(90)*HYP; 0*/
		/*do nothing on horizontal scan*/
		break;
	case SCAN_120_ANGLE:
		/*x = sin(-60)*HYP; 0.866 cal from vertical line to button angle*/
		rectsize.X_Dist = (0.866)*diagonal;
		/*y = cos(-60)*HYP; 0.5 cal from vertical line to button angle*/
		rectsize.Y_Dist = (0.5)*diagonal;
		break;
	case SCAN_150_ANGLE:
		/*x = sin(-30)*HYP; 0.5 cal from vertical line to button angle*/
		rectsize.X_Dist = (0.5)*diagonal;
		/*y = cos(-30)*HYP; 0.866 cal from vertical line to button angle*/
		rectsize.Y_Dist = (0.866)*diagonal;
		break;
	default:
		/*do Nothing*/;
		break;
	};

	return rectsize;
}
#endif

RectSize Rectangle::CalcRobPosRect(L_R_Dist diagonals, uint8 Angle, RobotPos* robPosInRect)
{
	RectSize rectsize;
	rectsize.X_Dist = 0;
	rectsize.Y_Dist = 0;

	switch (Angle)
	{
	case SCAN_0_ANGLE:
		/*y = sin(180)*HYP;*/
		/*x = cos(180)*HYP;*/
		/*do nothing on vertical scan*/
		break;
	case SCAN_30_ANGLE:
		if (diagonals.L_Distance != 0)
		{
			/*x = sin(30)*HYP; 0.5*/
			robPosInRect->X_pos = (int)(0.866)*diagonals.L_Distance;
			/*y = cos(30)*HYP; 0.866*/
			robPosInRect->Y_pos = (int)(0.5)*diagonals.R_Distance;
		}
		else
		{
			/*x = sin(30)*HYP; 0.5*/
			robPosInRect->X_pos = (int)(0.866)*diagonals.L_Distance;
			/*y = cos(30)*HYP; 0.866*/
			robPosInRect->Y_pos = (int)(0.5)*diagonals.R_Distance;
		}
		/*x = sin(30)*HYP; 0.5*/
		rectsize.X_Dist = (0.866)*(diagonals.L_Distance + diagonals.R_Distance);
		/*y = cos(30)*HYP; 0.866*/
		rectsize.Y_Dist = (0.5)*(diagonals.L_Distance + diagonals.R_Distance);
		break;
	case SCAN_60_ANGLE:
		if (diagonals.L_Distance != 0)
		{
			/*x = sin(30)*HYP; 0.5*/
			robPosInRect->X_pos = (int)(0.5)*diagonals.L_Distance;
			/*y = cos(30)*HYP; 0.866*/
			robPosInRect->Y_pos = (int)(0.866)*diagonals.R_Distance;
		}
		else
		{
			/*x = sin(30)*HYP; 0.5*/
			robPosInRect->X_pos = (int)(0.5)*diagonals.L_Distance;
			/*y = cos(30)*HYP; 0.866*/
			robPosInRect->Y_pos = (int)(0.866)*diagonals.R_Distance;
		}
		/*x = sin(60)*HYP; 0.866*/
		rectsize.X_Dist = (0.5)*(diagonals.L_Distance + diagonals.R_Distance);
		/*y = cos(60)*HYP; 0.5*/
		rectsize.Y_Dist = (0.866)*(diagonals.L_Distance + diagonals.R_Distance);
		break;
	case SCAN_90_ANGLE:
		/*y = sin(90)*HYP; 1*/
		/*x = cos(90)*HYP; 0*/
		/*do nothing on horizontal scan*/
		break;
	case SCAN_120_ANGLE:
		if (diagonals.L_Distance != 0)
		{
			/*x = sin(30)*HYP; 0.5*/
			robPosInRect->X_pos = (int)(0.866)*diagonals.L_Distance;
			/*y = cos(30)*HYP; 0.866*/
			robPosInRect->Y_pos = (int)(0.5)*diagonals.R_Distance;
		}
		else
		{
			/*x = sin(30)*HYP; 0.5*/
			robPosInRect->X_pos = (int)(0.866)*diagonals.L_Distance;
			/*y = cos(30)*HYP; 0.866*/
			robPosInRect->Y_pos = (int)(0.5)*diagonals.R_Distance;
		}
		/*x = sin(-60)*HYP; 0.866 cal from vertical line to button angle*/
		rectsize.X_Dist = (0.866)*(diagonals.L_Distance + diagonals.R_Distance);
		/*y = cos(-60)*HYP; 0.5 cal from vertical line to button angle*/
		rectsize.Y_Dist = (0.5)*(diagonals.L_Distance + diagonals.R_Distance);
		break;
	case SCAN_150_ANGLE:
		if (diagonals.L_Distance != 0)
		{
			/*x = sin(30)*HYP; 0.5*/
			robPosInRect->X_pos = (int)(0.5)*diagonals.L_Distance;
			/*y = cos(30)*HYP; 0.866*/
			robPosInRect->Y_pos = (int)(0.866)*diagonals.R_Distance;
		}
		else
		{
			/*x = sin(30)*HYP; 0.5*/
			robPosInRect->X_pos = (int)(0.5)*diagonals.L_Distance;
			/*y = cos(30)*HYP; 0.866*/
			robPosInRect->Y_pos = (int)(0.866)*diagonals.R_Distance;
		}
		/*x = sin(-30)*HYP; 0.5 cal from vertical line to button angle*/
		rectsize.X_Dist = (0.5)*(diagonals.L_Distance + diagonals.R_Distance);
		/*y = cos(-30)*HYP; 0.866 cal from vertical line to button angle*/
		rectsize.Y_Dist = (0.866)*(diagonals.L_Distance + diagonals.R_Distance);
		break;
	default:
		/*do Nothing*/;
		break;
	};
	return rectsize;
}

return_type Rectangle::ConstructRect(L_R_Dist* diagonalList, RectSize* rectsize,Robot rob, RobotPos* robPosInRect)
{
	uint8 diagonals_index = 0;
	uint16 max_diagonal = 0;
	uint8 angleCounter = 0;
	return_type ret = RET_NOT_OK;

	for (diagonals_index = 0; diagonals_index < FULL_SCAN_NUM; diagonals_index++)
	{
		if ((diagonalList[diagonals_index].L_Distance + diagonalList[diagonals_index].R_Distance) > max_diagonal)
		{
			max_diagonal = diagonalList[diagonals_index].L_Distance + diagonalList[diagonals_index].R_Distance;
			angleCounter = diagonals_index;
		}
	}

	if (max_diagonal == 0)
	{
		ret = RET_NOT_OK;
	}
	else if ((angleCounter == SCAN_0_ANGLE) || (angleCounter == SCAN_90_ANGLE))
	{
		ret = RET_NOT_OK;
	}
	else
	{
		/*-----TODO: merge CalcRectPos with CalcRobPosRect they are very similar*/
		/*getting robot position to know where is the robot located in the rectangle*/
		rob.GetRobotPosition(robPosInRect);
		
		*rectsize = CalcRobPosRect(diagonalList[angleCounter], angleCounter, robPosInRect);
		rectsize->X_Dist = (uint32)(rectsize->X_Dist / ROBOT_SIZE);
		rectsize->Y_Dist = (uint32)(rectsize->Y_Dist / ROBOT_SIZE);
		
#ifdef DEBUG
		cout << "rect. size X_Dist: " << (rectsize->X_Dist) << endl;
		cout << "CalcRect diagonals_index: " << ((int)diagonals_index) << endl;
#endif

		/*if the space is less than the robot size (less than one block) then assume its 1 block*/
		if (rectsize->X_Dist < 1)
		{
			rectsize->X_Dist = 1;
		}

		/*if the space is less than the robot size (less than one block) then assume its 1 block*/
		if (rectsize->Y_Dist < 1)
		{
			rectsize->Y_Dist = 1;
		}
		ret = RET_OK;
	}

	return ret;
}

void Rectangle::UpdateRectangle(Coordinates position, CELL_STATE state)
{
	rect[position.X_Column][position.Y_Row] = state;
}

void Rectangle::getRectSize(RectSize* rectsize)
{
	rectsize->X_Dist = RectangleSize.X_Dist;
	rectsize->Y_Dist = RectangleSize.Y_Dist;
}

void Rectangle::updateRectSize(RectSize rectsize)
{
	RectangleSize.X_Dist = rectsize.X_Dist;
	RectangleSize.Y_Dist = rectsize.Y_Dist;
}
#endif
