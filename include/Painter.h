#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Toolbar.h"
#include "TextureManager.h"

const float PixelSize = 50;

class Painter
{
public:
	Painter() = default;
	void run();
	
private:
	void updateTexture();
	TextureManager m_texture;
	ToolBar m_toolBar;
};

