#pragma once
#include "Animals.h"
class Sword : public Animals
{
private:
    int i;
    int monster;
    float rotate;
    bool isrotDirec;
public:
    Sword();
    Sword(glm::vec3 Color, int i, int monster);    //i�� ����
    ~Sword();
    void update() override;
    void BindVAO() override;
    void DrawArrays() override;
};

