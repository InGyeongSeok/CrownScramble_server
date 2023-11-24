#include "Head.h"

Head::Head()
{
}

Head::Head(glm::vec3 Color, int monster) : monster{ monster }
{
	this->Color = Color;
	update();
}

Head::~Head()
{
}

void Head::update()
{
	if (monster == 3) {
		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.025, 0.03, 0.025));	//�Ӹ������� 0.1

		Change = Scale * Trans;		//���� �ø��� ���

		Trans = glm::translate(Unit, glm::vec3(0, 0.5, 0));
		Change = Trans * Change;	//�ٸ� ���� �÷���

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);
		Change = Trans * Change;	// �� ���������� �̵�
	}
	else {
		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.08, 0.08, 0.08));	//�Ӹ������� 0.1

		Change = Scale * Trans;		//���� �ø��� ���

		Trans = glm::translate(Unit, glm::vec3(0, 0.45, 0));
		Change = Trans * Change;	//�ٸ� ���� �÷���

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);
		Change = Trans * Change;	// �� ���������� �̵�
	}
	
}


void Head::BindVAO()
{
	if (monster == 3) {
		glBindVertexArray(sphereVAO);
	}
	else 
		glBindVertexArray(VAO);
}


void Head::DrawArrays()
{
	
	if (monster == 3) {
		glDrawArrays(GL_TRIANGLES, 0, vertex2.size() * 3);
	}
	else
		glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);
}