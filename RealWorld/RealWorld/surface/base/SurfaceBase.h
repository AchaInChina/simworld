#pragma once
#include <string>
#include <vector>

enum PhysicsType
{
	Solid,
	Liquid,
	Gas
};

class CSurfaceBase
{
public:
	CSurfaceBase();
	~CSurfaceBase();


	std::string Name() const { return m_Name; }
	void Name(std::string val) { m_Name = val; }
	PhysicsType Type() const { return m_Type; }
	void Type(PhysicsType val) { m_Type = val; }

	virtual void Init() = 0;
private:
	std::string m_Name;
	PhysicsType m_Type;
};

