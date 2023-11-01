
#pragma once
#include "Header.h"
#include "hero.h"
extern Hero hero;
//��ǥ XYZ / ������ / ���� 

class Room
{
	glm::mat4 Change;
	int AnimalRoom;
	float PositionX;
	float PositionZ;
	float PositionY;
public:

	Room(int room);

	~Room();
	void Update();
	void Draw();
	float getLeft();
	float getRight();
	float getBehind();
	float getFront();
	friend void Catroomtest();
	friend void Dogroomtest();
	friend void Bearroomtest();
	friend void HeroVSDog();
	friend void HeroVSBear();
	friend void HeroVSCat();
};


