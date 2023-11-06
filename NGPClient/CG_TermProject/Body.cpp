#include "Body.h"

Body::Body()
{
}

Body::Body(glm::vec3 Color, int monster) : monster{ monster }
{
	this->Color = Color;
	update();
}

Body::~Body()
{
}

void Body::update()
{
	if (monster == 3) {
		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.035, 0.05, 0.035));	//������� 0.3, �ʺ� 0.15
		//Scale = glm::scale(Unit, glm::vec3(0.1, 0.15, 0.1));
		Change = Scale * Trans;		//���� �ø��� ���
		
		Trans = glm::translate(Unit, glm::vec3(0, 0.2, 0));
		Change = Trans * Change;	//�ٸ� ���� �÷���

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);
		Change = Trans * Change;	// �� ���������� �̵�
	}
	else if (monster == 4) {
		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.02, 0.027, 0.02));	//������� 0.3, �ʺ� 0.15
		//Scale = glm::scale(Unit, glm::vec3(0.1, 0.15, 0.1));
		Change = Scale * Trans;		//���� �ø��� ���

		Trans = glm::translate(Unit, glm::vec3(0, 0.23, 0.1));
		Change = Trans * Change;	//�ٸ� ���� �÷���

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);
		Change = Trans * Change;	// �� ���������� �̵�
	}
	else {
		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.13, 0.15, 0.13));	//������� 0.3, �ʺ� 0.15
		//Scale = glm::scale(Unit, glm::vec3(0.1, 0.15, 0.1));
		Change = Scale * Trans;		//���� �ø��� ���

		Trans = glm::translate(Unit, glm::vec3(0, 0.15, 0));
		Change = Trans * Change;	//�ٸ� ���� �÷���

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);
		Change = Trans * Change;	// �� ���������� �̵�
	}
}


void Body::BindVAO()
{
	if (monster == 3 || monster ==4) {
		glBindVertexArray(sphereVAO);
	}
	else
		glBindVertexArray(VAO);
}

void Body::DrawArrays()
{
	
	if (monster == 3||monster ==4) {
		glDrawArrays(GL_TRIANGLES, 0, vertex2.size() * 3);
	}
	else
		glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);
}
