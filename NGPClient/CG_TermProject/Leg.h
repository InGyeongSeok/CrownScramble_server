#pragma once
#include "Animals.h"

class Leg :public Animals
{
private:
	int i;
	int monster;
	float rotate;
	bool isrotDirec;
public:
	Leg();
	Leg(glm::vec3 Color, int i, int monster);    //i�� ��ġ
	~Leg();

	void update() override;
	void BindVAO() override;
	void DrawArrays() override;

};