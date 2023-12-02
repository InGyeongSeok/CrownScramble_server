#include "Nose.h"

Nose::Nose()
{
}

Nose::Nose(glm::vec3 Color, int monster) :monster{ monster }
{
	this->Color = Color;
	update();
}

Nose::~Nose()
{
}

void Nose::update()
{
	if (monster == 3) {
		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.003, 0.003, 0.003));	//������ �ñ⶧���� �����غ����� y �÷���
		Change = Scale * Trans;		//���� �ø��� ���

		Trans = glm::translate(Unit, glm::vec3(0, 0.55, 0));
		Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.12));
		Change = Trans * Change;	//���ϴ� ��ġ�� �̵�

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);
		Change = Trans * Change;	// �� ���������� �̵�
	}
	else {
		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.003, 0.003, 0.003));	//������ �ñ⶧���� �����غ����� y �÷���
		Change = Scale * Trans;		//���� �ø��� ���

		Trans = glm::translate(Unit, glm::vec3(0, 0.53, 0));
		Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.075));
		Change = Trans * Change;	//���ϴ� ��ġ�� �̵�

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);
		Change = Trans * Change;	// �� ���������� �̵�
	}
}


void Nose::BindVAO()
{
	glBindVertexArray(sphereVAO);
}

void Nose::DrawArrays()
{
	glDrawArrays(GL_TRIANGLES, 0, vertex2.size() * 3);

}
