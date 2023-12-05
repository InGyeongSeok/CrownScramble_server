
#pragma once
#include "Header.h"
#include "hero.h"
extern Hero hero[3];
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
	friend void CatAndRoomCollision();
	friend void DogAndRoomCollision();
	friend void Bearroomtest();
	friend void HeroVSDog();
	friend void HeroVSBear();
	friend void HeroVSCat();
};


