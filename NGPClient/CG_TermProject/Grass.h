
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

class Grass
{
	glm::mat4 Change;
	float Xpos;
	float Ypos;
	float Zpos;
	int Grassnum;
	float Direction;
	int randN;
public:

	Grass();

	~Grass();
	void Update();
	void Draw();

};

