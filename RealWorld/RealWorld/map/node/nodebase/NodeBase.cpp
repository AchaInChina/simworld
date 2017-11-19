#include "NodeBase.h"



NodeBase::NodeBase()
{
	Up(0);
	Down(0);
	Left(0);
	Right(0);
	Front(0);
	Back(0);
}


NodeBase::~NodeBase()
{
}

NodeBase* NodeBase::Down()
{
	return m_Down;
}

void NodeBase::Down(NodeBase* value)
{
	m_Down = value;
}

NodeBase* NodeBase::Up()
{
	return m_Up;
}

void NodeBase::Up(NodeBase* value)
{
	m_Up = value;
}

NodeBase* NodeBase::Left()
{
	return m_Left;
}

void NodeBase::Left(NodeBase* value)
{
	m_Left = value;
}

NodeBase* NodeBase::Right()
{
	return m_Right;
}

void NodeBase::Right(NodeBase* value)
{
	m_Right = value;
}

NodeBase* NodeBase::Front()
{
	return m_Front;
}

void NodeBase::Front(NodeBase* value)
{
	m_Front = value;
}

NodeBase* NodeBase::Back()
{
	return m_Back;
}

void NodeBase::Back(NodeBase* value)
{
	m_Back = value;
}

int NodeBase::X()
{
	return m_X;
}

void NodeBase::X(int value)
{
	m_X = value;
}

int NodeBase::Y()
{
	return m_Y;
}

void NodeBase::Y(int value)
{
	m_Y = value;
}

int NodeBase::Z()
{
	return m_Z;
}

void NodeBase::Z(int value)
{
	m_Z = value;
}
