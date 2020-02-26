#include "gameField.h"
#include "fieldGenerator.h"


GameField::GameField(unsigned int x, unsigned int y)
{
	FieldGenerator fieldGenerator(x,y);
}
