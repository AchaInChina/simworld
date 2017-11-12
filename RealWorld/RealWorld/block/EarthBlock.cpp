#include "EarthBlock.h"
#include "..\surface\EarthSurface.h"

EarthBlock::EarthBlock()
{
}

EarthBlock::~EarthBlock()
{
}

void EarthBlock::Init()
{
	Name("earth");
	Type(Solid);
	Up(std::make_shared<CEarthSurface>());
	Down(std::make_shared<CEarthSurface>());
	Left(std::make_shared<CEarthSurface>());
	Right(std::make_shared<CEarthSurface>());
	Front(std::make_shared<CEarthSurface>());
	Behind(std::make_shared<CEarthSurface>());
}


