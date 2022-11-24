#pragma once

#include "common.hpp"

#define BLACK C2D_Color32(0, 0, 0, 255)
#define WHITE C2D_Color32(255, 255, 255, 255)
#define RED C2D_Color32(255, 0, 0, 255)
#define GREEN C2D_Color32(0, 255, 0, 255)
#define BLUE C2D_Color32(0, 0, 255, 255)

#define BARCOLOR C2D_Color32(0, 0, 180, 255)
#define BGCOLOR C2D_Color32(0, 0, 0, 255)
#define BUTTONSELECTCOLOR C2D_Color32(61, 61, 61, 255)
#define BUTTONUNSELECTCOLOR C2D_Color32(61, 61, 61, 255)

#define BUTTONSELECTED RenderD7::Color::Hex("#222222")
#define BUTTON RenderD7::Color::Hex("#111111")

// 2.0XD
#define BLACKT C2D_Color32(0, 0, 0, 150)
#define WHITET C2D_Color32(255, 255, 255, 150)
#define REDT C2D_Color32(255, 0, 0, 150)
#define GREENT C2D_Color32(0, 255, 0, 150)
#define BLUET C2D_Color32(0, 0, 255, 150)

#define BARCOLORT C2D_Color32(0, 0, 180, 150)
#define BGCOLORT C2D_Color32(0, 0, 0, 150)

#define BUTTONSELECTEDT C2D_Color32(255, 255, 255, 150)
#define BUTTONT C2D_Color32(255, 255, 100, 150)

// 3.0
#define COOLDARK RenderD7::Color::Hex("#111111")
#define COOLWHITE RenderD7::Color::Hex("#eeeeee")

typedef u32 Color;
