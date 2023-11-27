#include "pch.h"

#include <random>
extern vector<Hero> heroes; //���ΰ� ���� �ϴ� �������� ���߿� ������ ���� �� �ּ� �����ּ���. 

extern Attack catattack[AnimalMax];
extern Attack dogattack[AnimalMax];
extern Attack bearattack;
extern int AnimalCnt;


Animal::Animal(int type, int id) : AnimalType(type),Index(id)
{

	random_device rd;
	default_random_engine dre(rd());
	if (type == Cat) {
		uniform_real_distribution<float> urdX{ -104,-97 };
		uniform_real_distribution<float> urdZ{ -3, 3 };
		PosX = urdX(dre);
		PosY = -1.0f;
		PosZ = urdZ(dre);
		HP = 20;
		Attack = 10;	
		if (AnimalCnt == AnimalMax) { // ����̴� 6������ �����߰�, 6���� ��� ID�ο��� �� ��� ���� ID�ο����ִ� ���� 0���� �ʱ�ȭ�Ѵ�.
			AnimalCnt = 0;
		}

	}
	else if (type == Dog) {
		uniform_real_distribution<float> urdX{ 97, 103 };
		uniform_real_distribution<float> urdZ{ -3, 3 };
		PosX = urdX(dre);
		PosY = -1.0f;
		PosZ = urdZ(dre);
		HP = 40;
		Attack = 20;
		if (AnimalCnt == AnimalMax) { // ����̴� 6������ �����߰�, 6���� ��� ID�ο��� �� ��� ���� ID�ο����ִ� ���� 0���� �ʱ�ȭ�Ѵ�.
			AnimalCnt = 0;
		}
	}
	else if (type == Bear) {
		PosX = 0;
		PosY = -1.0f;
		PosZ = -100.f;
		HP = 100;
		Attack = 30;
	}
	Direction = 0.f;
	AnimalCrushHero = false;


}


void Animal::update()
{


	//����� ���� - ���ΰ� ������� �˰��� ���� ����� �ַ� ������ �ʿ��մϴ�. 
	heroes[0].location();
	float dz = HeroLocationZ - PosZ;
	float dx = HeroLocationX - PosX;

	Direction = atan2(dx, dz);

	closelineX = HeroLocationX - PosX;
	closelineZ = HeroLocationZ - PosZ;

	if ((catlive && !herodead && AnimalType == Cat) || (doglive && !herodead && AnimalType == Dog) ||
		(bearlive && !herodead && AnimalType == Bear)) {

		if (!(closelineX <= 0.5 && closelineX >= -0.5)) {

			if (closelineX >= 0.5) {
				closelineX -= 0.01;
				PosX += 0.1;
			}
			if (closelineX < -0.5) {
				closelineX += 0.01;
				PosX -= 0.1;
			}
		}

		if (!(closelineZ <= 0.5 && closelineZ >= -0.5)) {
			if (closelineZ > 0.5) {
				closelineZ -= 0.01;
				PosZ += 0.1;
			}
			if (closelineZ < -0.5) {
				closelineZ += 0.01;
				PosZ -= 0.1;
			}

		}

	}

	/*if ((closelineX <= 0.5 && closelineX >= -0.5) && (closelineZ <= 0.5 && closelineZ >= -0.5)) {
		if (AnimalType == Cat) {
			AnimalCrushHero = true;
			catattack[Index].Activate = true;
			++catattack[Index].AttackCount;
		}
		if (AnimalType == Dog) {
			AnimalCrushHero = true;
			dogattack[Index].Activate = true;
			++dogattack[Index].AttackCount;
		}
		if (AnimalType == Bear) {
			AnimalCrushHero = true;
			bearattack.Activate = true;
			++(bearattack.AttackCount);
		}
	}
	else {
		if (AnimalType == Cat) {
			AnimalCrushHero = false;
			catattack[Index].Activate = false;
		}
		if (AnimalType == Dog) {
			AnimalCrushHero = false;
			dogattack[Index].Activate = false;
		}
		if (AnimalType == Bear) {
			AnimalCrushHero = false;
			bearattack.Activate = false;
		}
	}*/

}


Animal::~Animal()
{

}


void Animal::damage()
{
	HP -= 10;

}

float Animal::getLeft()
{
	return PosX - 0.12f;
}

float Animal::getRight()
{
	return PosX + 0.12f;
}

float Animal::getBehind()
{
	return PosZ - 0.12f;
}

float Animal::getFront()
{
	return PosZ + 0.12f;
}

float Animal::getBottom()
{
	return PosY;
}

float Animal::getTop()
{
	return 0.0f;
}

void Animal::initCat()
{
	if (AnimalType == Cat) {
		HP = 20;
		Attack = 10;
	}
	if (AnimalType == Dog) {
		HP = 20;
		Attack = 10;
	}
	AnimalCrushHero = false;
}
