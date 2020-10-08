#include "musicselector.hpp"
#include "mainMenu.hpp"

extern bool touching(touchPosition touch, Structs::ButtonPos button);

MusicSel::MusicSel() {
	// Put stuff, which we need to initialize this screen here.
	for (int i = 0; i < 7; i++) {
		this->exampleVector.push_back({"Entry" + std::to_string(i)});
	}
}

void MusicSel::Draw(void) const {
	std::string MusicSel;
	GFX::DrawFileBrowseBG();
	Gui::DrawStringCentered(0, 2, 0.8f, WHITE, "Universal-Core Example -> MusicSel", 400);

	for (int i = (this->Selection<5) ? 0 : this->Selection-5;i< (int)this->exampleVector.size() && i <((this->Selection<5) ? 6 : this->Selection+1);i++) {
		if (i == this->Selection) {
			MusicSel += "> " + this->exampleVector[i] + "\n\n";
		} else {
			MusicSel += this->exampleVector[i] + "\n\n";
		}
	}
	for (int i=0;i<(((int)this->exampleVector.size()<6) ? 6-(int)this->exampleVector.size() : 0);i++) {
		MusicSel += "\n\n";
	}
	Gui::DrawString(26, 32, 0.52f, WHITE, MusicSel, 360);
	Gui::DrawStringCentered(0, 216, 0.8f, WHITE, "Entry Amount: " + std::to_string((int)exampleVector.size()), 400);
	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 400, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect
	GFX::DrawFileBrowseBG(false);
	if (fadealpha > 0) Gui::Draw_Rect(0, 0, 320, 240, C2D_Color32(fadecolor, fadecolor, fadecolor, fadealpha)); // Fade in/out effect
}


void MusicSel::Logic(u32 hDown, u32 hHeld, touchPosition touch) {
	if (hDown & KEY_B) {
		Gui::setScreen(std::make_unique<MainMenu>(), true, false);
	}

	if (hDown & KEY_DOWN) {
		if (this->Selection < (int)this->exampleVector.size()-1)	this->Selection++;
	}
	if (hDown & KEY_UP) {
		if (this->Selection > 0)	this->Selection--;
	}
}