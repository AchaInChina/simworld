#pragma once
#include <string>
#include "../../surface/base/SurfaceBase.h"


class CAtomBlockBase
{
public:
	CAtomBlockBase();
	~CAtomBlockBase();


	std::string Name() const { return m_Name; }
	void Name(std::string val) { m_Name = val; }
	PhysicsType Type() const { return m_Type; }
	void Type(PhysicsType val) { m_Type = val; }

	virtual void Init() = 0;
private:
	std::string m_Name;
	PhysicsType m_Type;
};

