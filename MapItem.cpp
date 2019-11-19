#include "MapItem.h"

//void MapItem::increaseHappiness(double amount)
//{
//	if(m_happiness<=100)
//		m_happiness += amount ;
//}

int MapItem::getMoney()
{
	int m = m_price;
	m_price =0;
	return m;
}

void MapItem::changeAnimation(size_t index)
{

}

void MapItem::stopAnimation()
{
}

void MapItem::startAnimation()
{
}
