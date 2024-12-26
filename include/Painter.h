#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Toolbar.h"
#include "TextureManager.h"


class Painter
{
public:
	Painter() = default;
	void run();
	

private:
	const unsigned int m_PixelSize = 50;
	TextureManager m_texture;
	ToolBar m_toolBar;
};

