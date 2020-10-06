#include "HP.h"
float hpcalculate(float damage, float total_hp)
{
	
	total_hp = total_hp - damage;
	return total_hp;

}