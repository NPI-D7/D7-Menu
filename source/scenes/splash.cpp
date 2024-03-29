#include "splash.hpp"
#include "mainMenu.hpp"
#include "utils.hpp"


extern RenderD7::Sheet sprites;

void Stack::Draw(void) const {
  RenderD7::OnScreen(Top);
  RenderD7::Draw::Rect(0, 0, 400, 30, COOLDARK);
  RenderD7::Draw::Rect(0, 30, 400, 210, COOLWHITE);

  RenderD7::Draw::TextCentered(0, 2, 0.8f, WHITE, "D7-Menu", 400);
  RenderD7::Draw::TextCentered(
      0, 40, 0.8f, BLACK,
      "DSGameCards ar not supported yet.\n\nBefore removing a gamecard\n\ngo "
      "back to the MainMenu.\nPress Y to get Rd7 Settings",
      400);
  RenderD7::Draw::TextCentered(0, 214, 0.8, BLACK, "NPI-D7, Tobi", 400);
  RenderD7::OnScreen(Bottom);
  RenderD7::Draw::Rect(0, 0, 320, 240, COOLWHITE);
}

void Stack::Logic(u32 hDown, u32 hHeld, u32 hUp, touchPosition touch) {
  this->delay++;
  // If the delay is larger than 130 -> Switch screen.
  if (this->delay > 130) {
    RenderD7::Scene::Load(std::make_unique<MainMenu>());
  }
}
