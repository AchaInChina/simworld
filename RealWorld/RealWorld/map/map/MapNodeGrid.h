#pragma once
#include <vector>
#include <memory>
#include <map>
#include <string>

#include "..\node\nodebase\NodeBase.h"

std::string FromatXY(double x, double y);

class NodeBase;

class MapNodeGrid
{
public:
	MapNodeGrid();
	~MapNodeGrid();

	int Z();

	void Z(int value);

	void AddNode(NodeBase* node);

	NodeBase* GetNode(double x, double y);

	void Init(int x, int y, NodeBase* upper = nullptr);

	void Release();

	NodeBase* GetFist();

	uint32_t GetSize();

	int X() const;
	void X(int val);
	int Y() const;
	void Y(int val);
private:
	int m_Z;

	int m_X;

	int m_Y;


	NodeBase** m_NodeArray;
};

