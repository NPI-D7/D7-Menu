#pragma once

#include "common.hpp"
#include <vector>

class MainMenu : public RenderD7::Scene {
public:
  void Draw(void) const override;
  void Logic(u32 hDown, u32 hHeld, u32 hUp, touchPosition touch) override;

private:
  int Selection = 0;
  std::vector<RenderD7::TLBtn> MMButtons = {
      {50, 40, 220, 40},
      {50, 100, 220, 40},
      {50, 160, 220, 40},
  };
};
