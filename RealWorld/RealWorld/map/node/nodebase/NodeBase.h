#pragma once
#include <memory>



class NodeBase
{
public:
	NodeBase();
	~NodeBase();
	NodeBase* Down();

	void Down(NodeBase* value);

	NodeBase* Up();

	void Up(NodeBase* value);

	NodeBase* Left();

	void Left(NodeBase* value);

	NodeBase* Right();

	void Right(NodeBase* value);

	NodeBase* Front();

	void Front(NodeBase* value);

	NodeBase* Back();

	void Back(NodeBase* value);

	int X();

	void X(int value);

	int Y();

	void Y(int value);

	int Z();

	void Z(int value);

private:
	NodeBase* m_Down;
	NodeBase* m_Up;
	NodeBase* m_Left;
	NodeBase* m_Right;
	NodeBase* m_Front;
	NodeBase* m_Back;

	int m_X;
	int m_Y;
	int m_Z;
};

