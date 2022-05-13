#include "mainMenu.hpp"

#include "colors.hpp"
#include "utils.hpp"

#include "sdmenuv2.hpp"

#include <unistd.h>
#include <iostream>

void MainMenu::Draw(void) const {
	
	RenderD7::OnScreen(Top);
	
	RenderD7::DrawRect(0, 0, 400, 240, COOLWHITE);
	RenderD7::DrawRect(0, 0, 400, 30, COOLDARK);
	RenderD7::DrawTextCentered(0, 2, 0.8f, COOLWHITE, "D7-Menu", 400);
	D7TM::CardLoop();
	RenderD7::DrawText(2, 50, 0.7f, RenderD7::Color::Hex("#111111"), "State: " + CardStatus);
	RenderD7::OnScreen(Bottom);
	RenderD7::DrawRect(0, 0, 320, 240, COOLWHITE);
	RenderD7::DrawRect(0, 0, 320, 30, COOLDARK);
	
	for (int i = 0; i < (int)this->MMButtons.size(); i++) {
		if (this->Selection == i) {
			RenderD7::DrawRect(this->MMButtons[i].x-2, this->MMButtons[i].y-2, this->MMButtons[i].w+4, this->MMButtons[i].h+4, BUTTONSELECTCOLOR);
			RenderD7::DrawRect(this->MMButtons[i].x, this->MMButtons[i].y, this->MMButtons[i].w, this->MMButtons[i].h, BUTTONUNSELECTCOLOR);
		} else {
			RenderD7::DrawRect(this->MMButtons[i].x, this->MMButtons[i].y, this->MMButtons[i].w, this->MMButtons[i].h, BUTTONUNSELECTCOLOR);
		}
	}
	RenderD7::DrawTextCentered(0, MMButtons[0].y+10, 0.6f, BLACK, "SDCard");
	RenderD7::DrawTextCentered(0, MMButtons[1].y+10, 0.6f, BLACK, "Nand");
	RenderD7::DrawTextCentered(0, MMButtons[2].y+10, 0.6f, BLACK, "Exit");


	RenderD7::DrawText(37, 214, 0.8f, BLACK, "Hold \uE046 to show controols!");
}


void MainMenu::Logic(u32 hDown, u32 hHeld, u32 hUp, touchPosition touch) {



	if (hDown & KEY_START) {
		RenderD7::ExitApp();
	}
	if (hHeld & KEY_SELECT){
		RenderD7::OnScreen(Top);
		RenderD7::DrawText(1, 30, 0.8f, BLACK, "\uE000: Start");
		RenderD7::DrawText(1, 60, 0.8f, BLACK, "\uE07B / \uE07C: Navigate");
		RenderD7::DrawText(1, 90, 0.8f, BLACK, "Press \uE045 to exit!");
		RenderD7::OnScreen(Bottom);
	}
	
	if (hDown & KEY_A) {
		if (this->Selection == 0) {
			RenderD7::Scene::Load(std::make_unique<SDMenu>());
		} else if (this->Selection == 1) {
			RenderD7::LoadSettings();
		} else if (this->Selection == 2) {
           RenderD7::ExitApp();
                
        }
     
	}
	if (d7_hDown & KEY_TOUCH && RenderD7::touchTLBtn(d7_touch, MMButtons[0]))
	{
		RenderD7::Scene::Load(std::make_unique<SDMenu>());
	}
	if (d7_hDown & KEY_TOUCH && RenderD7::touchTLBtn(d7_touch, MMButtons[1]))
	{
		RenderD7::LoadSettings();
	}
	if (d7_hDown & KEY_TOUCH && RenderD7::touchTLBtn(d7_touch, MMButtons[2]))
	{
		RenderD7::ExitApp();
	}
	if (hDown & KEY_DOWN) {
		if (this->Selection < (int)this->MMButtons.size() - 1)	this->Selection++;
	}

	if (hDown & KEY_UP) {
		if (this->Selection > 0)	this->Selection--;
	}
}
