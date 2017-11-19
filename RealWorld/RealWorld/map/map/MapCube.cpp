#include "MapCube.h"

MapCube::MapCube()
{
}

MapCube::~MapCube()
{
}

void MapCube::Init(int x, int y, int z)
{
	for (int i = 0; i < z; i++)
	{
		MapNodeGrid* grid = new MapNodeGrid();
		NodeBase* nodeptr = nullptr;
		if (GetGridLevel() > 0)
		{
			nodeptr = GetNodeGrid(GetGridLevel()-1)->GetFist();
		}
		grid->Init(x, y, nodeptr);
		AddGrid(grid);
	}
}

void MapCube::Release()
{
	auto it = m_GridList.begin();
	while (it != m_GridList.end())
	{
		(*it)->Release();
		it++;
	}
}

void MapCube::AddGrid(MapNodeGrid* ptr)
{
	m_GridList.push_back(ptr);
}

uint32_t MapCube::GetGridLevel()
{
	return m_GridList.size();
}

MapNodeGrid* MapCube::GetNodeGrid(uint32_t z)
{
	if (z <= m_GridList.size()-1)
	{
		return m_GridList[z];
	}
	return nullptr;
}

