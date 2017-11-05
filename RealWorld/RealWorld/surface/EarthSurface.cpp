#include "EarthSurface.h"



CEarthSurface::CEarthSurface()
{
}


CEarthSurface::~CEarthSurface()
{
}

void CEarthSurface::Init()
{
	Name("earthSurface");
	Type(Solid);
	InhalationType(Liquid);
	StickType(Solid);
}

