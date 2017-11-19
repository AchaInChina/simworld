#pragma once
#include "MapNodeGrid.h"

class MapCube
{
public:
	MapCube();
	~MapCube();

	void Init(int x, int y, int z);

	void Release();

	void AddGrid(MapNodeGrid* ptr);

	uint32_t GetGridLevel();

	MapNodeGrid* GetNodeGrid(uint32_t z);

private:
	std::vector<MapNodeGrid*> m_GridList;

};




