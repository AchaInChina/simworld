#include "MapNodeGrid.h"



MapNodeGrid::MapNodeGrid()
{
}


MapNodeGrid::~MapNodeGrid()
{
}

std::string FromatXY(double x, double y)
{
	std::string str;

	char buff[1024] = { 0 };
	sprintf_s(buff, "%f,%f", x, y);
	str = buff;

	return str;
}
