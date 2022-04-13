#include "mainMenu.hpp"
#include "splash.hpp"
#include "sprites.h"
#include "ptmu_x.h"
#include "utils.hpp"

extern RenderD7::Sheet sprites;

void Stack::Draw(void) const {
	RenderD7::OnScreen(Top);
	RenderD7::DrawRect(0, 0, 400, 30, COOLDARK);
	RenderD7::DrawRect(0, 30, 400, 210, COOLWHITE);
	 
	RenderD7::DrawTextCentered(0, 2, 0.8f, WHITE, "D7-Menu", 400);
	RenderD7::DrawTextCentered(0, 40, 0.8f, BLACK, "DSGameCards ar not supported yet.\n\nBefore removing a gamecard\n\ngo back to the MainMenu.", 400);
	RenderD7::DrawTextCentered(0, 214, 0.8, BLACK, "Universal-Team, Tobi", 400);
	//if (fadealpha > 0) Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect
	GFX::DrawBottom();
	RenderD7::DrawRect(0, 0, 320, 240, COOLWHITE);
	//Gui::DrawSprite(sprites, sprites_ulogo_idx, -10, 20, 0.65, 0.65);
	
	
	//if (fadealpha > 0) Gui::Draw_Rect(0, 0, 320, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect
}


void Stack::Logic(u32 hDown, u32 hHeld, u32 hUp, touchPosition touch) {
	this->delay++;
	// If the delay is larger than 130 -> Switch screen.
	if (this->delay > 130) {
		RenderD7::Scene::Load(std::make_unique<MainMenu>());
	}
}
