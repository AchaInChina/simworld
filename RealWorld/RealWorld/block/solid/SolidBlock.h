#pragma once
#include "../base/AtomBlockBase.h"
#include "../../surface/solid/SolidSurface.h"
#include <memory>

class SolidBlock:public CAtomBlockBase
{
public:
	SolidBlock();
	~SolidBlock();

	std::shared_ptr<SolidSurface> Up() const { return m_Up; }
	void Up(std::shared_ptr<SolidSurface> val) { m_Up = val; }
	std::shared_ptr<SolidSurface> Down() const { return m_Down; }
	void Down(std::shared_ptr<SolidSurface> val) { m_Down = val; }
	std::shared_ptr<SolidSurface> Left() const { return m_Left; }
	void Left(std::shared_ptr<SolidSurface> val) { m_Left = val; }
	std::shared_ptr<SolidSurface> Right() const { return m_Right; }
	void Right(std::shared_ptr<SolidSurface> val) { m_Right = val; }
	std::shared_ptr<SolidSurface> Front() const { return m_Front; }
	void Front(std::shared_ptr<SolidSurface> val) { m_Front = val; }
	std::shared_ptr<SolidSurface> Behind() const { return m_Behind; }
	void Behind(std::shared_ptr<SolidSurface> val) { m_Behind = val; }
private:
	std::shared_ptr<SolidSurface> m_Up;
	std::shared_ptr<SolidSurface> m_Down;
	std::shared_ptr<SolidSurface> m_Left;
	std::shared_ptr<SolidSurface> m_Right;
	std::shared_ptr<SolidSurface> m_Front;
	std::shared_ptr<SolidSurface> m_Behind;
};



