
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

class Crown
{
	glm::mat4 Change;
	float Xpos;
	float Ypos;
	float Zpos;

public:

	Crown();

	~Crown();
	void Update();
	void Draw();

	void initCrown();

};


