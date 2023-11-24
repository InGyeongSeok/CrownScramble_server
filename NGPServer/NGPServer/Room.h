
#pragma once
//��ǥ XYZ / ������ / ���� 

class Room
{
public:

	int AnimalRoom;
	float PositionX;
	float PositionZ;
	float PositionY;
	Room(int room);

	~Room();
	float getLeft();
	float getRight();
	float getBehind();
	float getFront();
	friend void CatAndRoomCollision();
	friend void DogAndRoomCollision();
	friend void BearAndRoomCollision();
	friend void HeroVSDog();
	friend void HeroVSBear();
	friend void HeroVSCat();
};


