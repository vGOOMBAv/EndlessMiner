#pragma once

class WorldElem {
public:
	unsigned int elemHealth = 3;
	unsigned int droppedAmmountOfRes = 3;
	void elemHit();
	bool canWalkThrough = 1;
	unsigned int type = -1;
	//0-soil
	//1-grass
	//3-rock
	//2-tree
};
