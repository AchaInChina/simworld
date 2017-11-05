#pragma once
#include "../base/SurfaceBase.h"

class SolidSurface:public CSurfaceBase
{
public:
	SolidSurface();
	~SolidSurface();

	PhysicsType InhalationType() const { return m_InhalationType; }
	void InhalationType(PhysicsType val) { m_InhalationType = val; }
	PhysicsType StickType() const { return m_StickType; }
	void StickType(PhysicsType val) { m_StickType = val; }
private:
	PhysicsType m_InhalationType;
	PhysicsType m_StickType;
};

