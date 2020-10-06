/*
*   This file is part of Universal-Core-Example
*   Copyright (C) 2020 SuperSaiyajinStackie
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

// Screens.


#include "mainMenu.hpp"
#include "gameManagement.hpp"
#include "titleManagement.hpp"
#include "colors.hpp"
#include "utils.hpp"
#include "gamecard.hpp"
#include "nand.hpp"
#include "sdmenuv2.hpp"


#include "msg.hpp"


#include <unistd.h>
#include <iostream>

extern bool touching(touchPosition touch, Structs::ButtonPos button);
extern bool exiting;




void MainMenu::Draw(void) const {
	
	GFX::DrawTop();
	GFX::DrawBetteryTop();
	Gui::DrawString(0, 2 , 0.8f, WHITE, timeStr());
	Gui::DrawStringCentered(0, 2, 0.8f, WHITE, "D7-Menu->MainMenu", 400);
	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/
	
	
	


	GFX::DrawBottom();
	
	

	Gui::DrawString(37, 214, 0.8f, WHITE, "Hold \uE046 to show controols!");
	// Draw Buttons. ;P

	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect

}


void MainMenu::Logic(u32 hDown, u32 hHeld, touchPosition touch) {



	if (hDown & KEY_START) {
		fadecolor = 0;
		fadeout = true;
		exiting = true;
	}
	if (hHeld & KEY_SELECT){
		GFX::DrawTopSP();
		Gui::DrawString(1, 30, 0.8f, WHITE, "\uE000: Start");
		Gui::DrawString(1, 60, 0.8f, WHITE, "\uE07B / \uE07C: Navigate");
		Gui::DrawString(1, 90, 0.8f, WHITE, "Press \uE045 to exit!");
		GFX::DrawBottomSP();
	}
	if (hDown & KEY_L){

		Gui::setScreen(std::make_unique<SDMenu>(), true, false);
		
		
	}
	if (hDown & KEY_R){
			Gui::setScreen(std::make_unique<gamecard>(), true, false);
	}
	

	

	// Press Down to go one entry down. - 1 -> Because we don't want to go one Entry after the actual Buttons.
	
}
