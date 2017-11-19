#include "MapNodeGrid.h"



MapNodeGrid::MapNodeGrid()
{
	m_NodeArray = 0;
}


MapNodeGrid::~MapNodeGrid()
{
}

int MapNodeGrid::Z()
{
	return m_Z;
}

void MapNodeGrid::Z(int value)
{
	m_Z = value;
}

void MapNodeGrid::AddNode(NodeBase* node)
{
	m_NodeArray[node->X()*X()+node->Y()] = node;
}

NodeBase* MapNodeGrid::GetNode(double x, double y)
{

	return nullptr;
}

void MapNodeGrid::Init(int x, int y, NodeBase* upper /*= nullptr*/)
{
	X(x);
	Y(y);
	m_NodeArray = new NodeBase*[X()*Y()];

	NodeBase* matrixnode = new NodeBase();
	if (upper)
	{
		matrixnode->Up(upper);
		upper->Down(matrixnode);
	}
	NodeBase* firstdnode = matrixnode;
	NodeBase* secondnode = nullptr;
	firstdnode->X(0);
	firstdnode->Y(0);
	AddNode(firstdnode);
	for (int i = 0; i < x; i++)
	{
		if (i != 0)
		{
			firstdnode = new NodeBase();
			firstdnode->Back(matrixnode);
			matrixnode->Front(firstdnode);
			if (matrixnode->Up() && matrixnode->Up()->Front())
			{
				firstdnode->Up(matrixnode->Up()->Front());
				matrixnode->Up()->Front()->Down(firstdnode);
			}
			matrixnode = firstdnode;
			firstdnode->X(i);
			firstdnode->Y(0);
			AddNode(firstdnode);
		}
		for (int j = 0; j < y - 1; j++)
		{
			secondnode = new NodeBase();
			secondnode->Left(firstdnode);
			firstdnode->Right(secondnode);
			if (firstdnode->Back() && firstdnode->Back()->Right())
			{
				secondnode->Back(firstdnode->Back()->Right());
				firstdnode->Back()->Right()->Front(secondnode);
			}
			if (firstdnode->Up() && firstdnode->Up()->Right())
			{
				secondnode->Up(firstdnode->Up()->Right());
				firstdnode->Up()->Right()->Down(secondnode);
			}
			firstdnode = secondnode;
			firstdnode->X(i);
			firstdnode->Y(j + 1);
			AddNode(firstdnode);
		}
	}
}

void MapNodeGrid::Release()
{
	for (int i = 0; i < X(); i++)
	{
		for (int j = 0; j < Y(); j++)
		{
			if (m_NodeArray[i * X() +j] != nullptr)
			{
				delete m_NodeArray[i * X() + j];
			}
		}
	}
}

NodeBase* MapNodeGrid::GetFist()
{
	return m_NodeArray[0];
}

uint32_t MapNodeGrid::GetSize()
{
	return X()*Y();
}

int MapNodeGrid::X() const
{
	return m_X;
}

void MapNodeGrid::X(int val)
{
	m_X = val;
}

int MapNodeGrid::Y() const
{
	return m_Y;
}

void MapNodeGrid::Y(int val)
{
	m_Y = val;
}

std::string FromatXY(double x, double y)
{
	std::string str;

	char buff[1024] = { 0 };
	sprintf_s(buff, "%f,%f", x, y);
	str = buff;

	return str;
}
