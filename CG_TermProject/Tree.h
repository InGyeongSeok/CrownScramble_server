
#pragma once
#include "Header.h"

//��ǥ XYZ / ������ / ���� 

class Tree
{
	glm::mat4 Change;
	float Xpos;
	float Ypos;
	float Zpos;
	int Treenum;
	float Direction;
	int randN;
public:

	Tree();

	~Tree();
	void Update();
	void Draw();

};

