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

	double Z()
	{
		return m_Z;
	}

	void Z(double value)
	{
		m_Z = value;
	}

	void AddNode(std::shared_ptr<NodeBase> node)
	{
		//m_Nodes.push_back(node);
		//std::string key = FromatXY(node->X(), node->Y());
		//m_NodesMap.insert(std::pair<std::string, std::shared_ptr<NodeBase>>(key, node));
	}

	std::shared_ptr<NodeBase> GetNode(double x, double y)
	{
		std::string key = FromatXY(x, y);
		auto it = m_NodesMap.find(key);
		if (it != m_NodesMap.end())
			return it->second;
		return nullptr;
	}

	void Init(int x, int y, std::shared_ptr<NodeBase> upper = nullptr)
	{
		std::shared_ptr<NodeBase> matrixnode = std::make_shared<NodeBase>();
		if (upper)
		{
			matrixnode->Up(upper);
			upper->Down(matrixnode);
		}
		std::shared_ptr<NodeBase> firstdnode = matrixnode;
		std::shared_ptr<NodeBase> secondnode = nullptr;
		firstdnode->X(0);
		firstdnode->Y(0);
		AddNode(firstdnode);
		for (int i = 0; i < x; i++)
		{
			if (i != 0)
			{
				firstdnode = std::make_shared<NodeBase>();
				firstdnode->Back(matrixnode);
				matrixnode->Front(firstdnode);
				matrixnode = firstdnode;
				firstdnode->X(i);
				firstdnode->Y(0);
				AddNode(firstdnode);
			}
			for (int j = 0; j < y - 1; j++)
			{
				secondnode = std::make_shared<NodeBase>();
				secondnode->Left(firstdnode);
				firstdnode->Right(secondnode);
				if (firstdnode->Back()&& firstdnode->Back()->Right())
				{
					secondnode->Back(firstdnode->Back()->Right());
					firstdnode->Back()->Right()->Front(secondnode);
				}
				firstdnode = secondnode;
				firstdnode->X(i);
				firstdnode->Y(j+1);
				AddNode(firstdnode);
			}
		}
	}


	std::shared_ptr<NodeBase> GetFist()
	{
		auto it = m_Nodes.begin();
		if (it != m_Nodes.end())
		{
			return *it;
		}
		return nullptr;
	}

	uint32_t GetSize()
	{
		return m_Nodes.size();
	}

private:
	double m_Z;

	std::vector<std::shared_ptr<NodeBase>> m_Nodes;
	std::map<std::string, std::shared_ptr<NodeBase>> m_NodesMap;
};

