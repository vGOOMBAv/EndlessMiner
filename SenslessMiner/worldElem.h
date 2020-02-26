#pragma once

class WorldElem {
public:
	unsigned int elemHealth = 3;
	unsigned int droppedAmmountOfRes = 3;
	void elemHit();
	unsigned int type = 0;
};
