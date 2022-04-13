#pragma once

#include "common.hpp"

class Stack : public RenderD7::Scene {
public:
	void Draw(void) const override;
	void Logic(u32 hDown, u32 hHeld, u32 hUp, touchPosition touch) override;
private:
	int delay = 0;
};

#endif