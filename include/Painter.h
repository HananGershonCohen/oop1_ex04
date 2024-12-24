#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Toolbar.h"

const float PixelSize = 50;

class Painter
{
public:
	Painter() = default;
	void run();
	
private:
	
	ToolBar m_toolBar;
};

