// RealWorld.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>

#include <iostream>

#include "..\RealWorld\map\map\MapNodeGrid.h"


int main()
{
	MapNodeGrid testMapGrid;
	testMapGrid.Init(1024, 1024);

	std::cout << "node size is :" <<sizeof(NodeBase)<< std::endl;

	std::cout<< "cur grid size is : " <<testMapGrid.GetSize() <<std::endl ;

	::system("Pause");
    return 0;
}

