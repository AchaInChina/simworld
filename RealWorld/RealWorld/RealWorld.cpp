// RealWorld.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>

#include <iostream>

#include "..\RealWorld\map\map\MapCube.h"


int main()
{

	std::cout<< "mapnode size si "<< sizeof(NodeBase) <<std::endl;
	MapCube cube;
	cube.Init(1024, 1024, 1);
	::system("Pause");
	cube.Release();
	::system("Pause");

    return 0;
}

