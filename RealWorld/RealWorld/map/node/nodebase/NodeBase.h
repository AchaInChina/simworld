#pragma once
#include <memory>



class NodeBase
{
public:
	NodeBase();
	~NodeBase();
	std::shared_ptr<NodeBase> Down()
	{
		return m_Down;
	}

	void Down(std::shared_ptr<NodeBase> value)
	{
		m_Down = value;
	}

	std::shared_ptr<NodeBase> Up()
	{
		return m_Up;
	}

	void Up(std::shared_ptr<NodeBase> value)
	{
		m_Up = value;
	}

	std::shared_ptr<NodeBase> Left()
	{
		return m_Left;
	}

	void Left(std::shared_ptr<NodeBase> value)
	{
		m_Left = value;
	}

	std::shared_ptr<NodeBase> Right()
	{
		return m_Right;
	}

	void Right(std::shared_ptr<NodeBase> value)
	{
		m_Right = value;
	}

	std::shared_ptr<NodeBase> Front()
	{
		return m_Front;
	}

	void Front(std::shared_ptr<NodeBase> value)
	{
		m_Front = value;
	}

	std::shared_ptr<NodeBase> Back()
	{
		return m_Back;
	}

	void Back(std::shared_ptr<NodeBase> value)
	{
		m_Back = value;
	}

	double X()
	{
		return m_X;
	}

	void X(double value)
	{
		m_X = value;
	}

	double Y()
	{
		return m_Y;
	}

	void Y(double value)
	{
		m_Y = value;
	}

	double Z()
	{
		return m_Z;
	}

	void Z(double value)
	{
		m_Z = value;
	}

private:
	std::shared_ptr<NodeBase> m_Down;
	std::shared_ptr<NodeBase> m_Up;
	std::shared_ptr<NodeBase> m_Left;
	std::shared_ptr<NodeBase> m_Right;
	std::shared_ptr<NodeBase> m_Front;
	std::shared_ptr<NodeBase> m_Back;

	double m_X;
	double m_Y;
	double m_Z;
};

