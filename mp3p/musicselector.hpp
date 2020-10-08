#include "common.hpp"


#include "common.hpp"
#include "structs.hpp"

#include <vector>

class MusicSel : public Screen {
public:
	void Draw(void) const override;
	void Logic(u32 hDown, u32 hHeld, touchPosition touch) override;
	MusicSel();
private:
	int Selection = 0;
	std::vector<std::string> exampleVector;
};