#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Robot.h"
#include "CONF.h"



class Rectangle
{
	#ifdef RECTANGLE
private:
	uint8** rect;
	RectSize RectangleSize;
	static RectSize CalcRectPos(uint8 diagonals_index, uint16 diagonal);
	void updateRectSize(RectSize rectsize);
	static RectSize CalcRobPosRect(L_R_Dist diagonals, uint8 angle, RobotPos* robPos);
public:
	Rectangle(){}

	Rectangle(RectSize rectsize);

	void init(void);

	static return_type ConstructRect(L_R_Dist* diagonalList, RectSize* rectsize, Robot rob, RobotPos* robPosInRect);

	void UpdateRectangle(Coordinates position, CELL_STATE state);

	void getRectSize(RectSize* rectsize);
#endif
};

#endif
