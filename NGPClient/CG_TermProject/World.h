
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

class World
{
	glm::mat4 Change;
	float Xpos;
	float Ypos;
	float Zpos;

public:

	World();

	~World();
	void Update();
	void Draw();

};


