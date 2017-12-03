// RealWorld.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

#include <iostream>

#include "..\RealWorld\map\map\MapCube.h"

#include "gui\\winmod\WindowModule.h"

#undef main 

int main()
{

	std::cout<< "mapnode size si "<< sizeof(NodeBase) <<std::endl;
	MapCube cube;
	cube.Init(1024, 1024, 1);
	::system("Pause");
	cube.Release();
	::system("Pause");

	WindowModule sdltest;
	sdltest.Init();
	sdltest.OpenWindow("helloworld", 1024, 1024);
	sdltest.EnableGL();

	sdltest.ShowRed();
	sdltest.UpdateShow();
	sdltest.ShowDelay(1000);
	sdltest.ShowGreen();
	sdltest.UpdateShow();
	sdltest.ShowDelay(1000);
	sdltest.ShowBlue();
	sdltest.UpdateShow();
	sdltest.ShowDelay(1000);

	sdltest.ReleaseGL();
	sdltest.CloseWindow();
	sdltest.Release();

    return 0;
}

