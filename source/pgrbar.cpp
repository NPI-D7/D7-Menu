#include "progressbar.hpp"

void PGRBar::DrawPGRBar(u64 currentProgress, u64 totalProgress){
    RenderD7::DrawRect(30, 120, 340, 30, BLACK);
	RenderD7::DrawRect(31, 121, (int)(((float)currentProgress / (float)totalProgress) * 338.0f), 28, WHITE);
}
