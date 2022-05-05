#include "mainMenu.hpp"

#include "colors.hpp"
#include "utils.hpp"

#include "sdmenuv2.hpp"
#include "screenshot.h"



//#include "msg.hpp"


#include <unistd.h>
#include <iostream>

//extern bool touching(u32 hDown, u32 hHeld, u32 hUp, touchPosition touch);
extern bool exiting;




void MainMenu::Draw(void) const {
	
	RenderD7::OnScreen(Top);
	
	//GFX::DrawBetteryTop();
	
	RenderD7::DrawTextCentered(0, 2, 0.8f, BLACK, "D7-Menu", 400);

	//if (fadealpha > 0) RenderD7::DrawRect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/
	 


	
	


	//GFX::DrawBottom();
	
	
	for (int i = 0; i < (int)this->MMButtons.size(); i++) {
		if (this->Selection == i) {
			RenderD7::DrawRect(this->MMButtons[i].x, this->MMButtons[i].y, this->MMButtons[i].w, this->MMButtons[i].h, BUTTONSELECTEDT);
		} else {
			RenderD7::DrawRect(this->MMButtons[i].x, this->MMButtons[i].y, this->MMButtons[i].w, this->MMButtons[i].h, BUTTONT);
		}
	}
	RenderD7::DrawTextCentered(0, MMButtons[0].y+10, 0.6f, BLACK, "SDCard");
	RenderD7::DrawTextCentered(0, MMButtons[1].y+10, 0.6f, BLACK, "GameCard");
	RenderD7::DrawTextCentered(0, MMButtons[2].y+10, 0.6f, BLACK, "???");


	RenderD7::DrawText(37, 214, 0.8f, BLACK, "Hold \uE046 to show controols!");
	// Draw Buttons. ;P

	//if (fadealpha > 0) RenderD7::DrawRect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect

}


void MainMenu::Logic(u32 hDown, u32 hHeld, u32 hUp, touchPosition touch) {



	if (hDown & KEY_START) {
		fadecolor = 0;
		fadeout = true;
		exiting = true;
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
			
		} else if (this->Selection == 2) {
                   
                        
                }
     
	}

	// Touch the button to enter example screen.
	/*if (hDown & KEY_TOUCH) {
		if (touching(touch, this->MMButtons[0])) {
			RenderD7::Scene::Load(std::make_unique<SDMenu>());
		} else if (touching(touch, this->MMButtons[1])) {
			
		} else if (touching(touch, this->MMButtons[2])) {
        
                }
	}*/
     //   
	// Press Down to go one entry down. - 1 -> Because we don't want to go one Entry after the actual Buttons.
	if (hDown & KEY_DOWN) {
		if (this->Selection < (int)this->MMButtons.size() - 1)	this->Selection++;
	}

	// Press Up to go one entry up.
	if (hDown & KEY_UP) {
		if (this->Selection > 0)	this->Selection--;
	}
	

	// Press Down to go one entry down. - 1 -> Because we don't want to go one Entry after the actual Buttons.
	
}
