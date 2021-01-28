

#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "common.hpp"
#include "structs.hpp"
#include "TitleManager.hpp"


#include <vector>


class MainMenu : public Screen {
public:
	void Draw(void) const override;
	void Logic(u32 hDown, u32 hHeld, touchPosition touch) override;
	
	
private:

	int Selection = 0;
	std::vector<Structs::ButtonPos> MMButtons = {
        {50, 40, 220, 40},
        {50, 100, 220, 40},
        {50, 160, 220, 40},
       
	};
	
};


#endif
