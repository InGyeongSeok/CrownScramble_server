#include "Leg.h"

Leg::Leg() : i(i)
{

}

Leg::Leg(glm::vec3 Color, int i, int monster) : i(i), rotate(0.f), isrotDirec(false), monster{monster}
{
	this->Color = Color;
	update();
}

Leg::~Leg()
{

}

void Leg::update()
{
	if (monster == 3) {
		if (isrotDirec) {
			rotate += 2.5f;
			if (rotate > 30.f)
				isrotDirec = false;
		}

		else {
			rotate -= 2.5f;
			if (rotate < -30.f)
				isrotDirec = true;
		}

		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.01, 0.03, 0.01));	//�ٸ����� 0.15

		Change = Scale * Trans;		// ���� �ø��� ���

		Trans = glm::translate(Unit, glm::vec3(0, -0.15, 0));
		Change = Trans * Change;	//�ٸ� ���� ���� ������ �����ְ�

		Rotate = glm::rotate(Unit, glm::radians(rotate), glm::vec3(i * -1.f, 0, 0));
		Change = Rotate * Change;	//�ٸ� ���� ��� ����

		Trans = glm::translate(Unit, glm::vec3(0, 0.15, 0));
		Change = Trans * Change;	//�ٽ� ����ġ �����ְ�

		Trans = glm::translate(Unit, glm::vec3(i * 0.07, 0, 0));
		Change = Trans * Change;	// ���� ���ϴ� ��ġ(���� ������

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);		// �� �̵���ġ�� ����
		Change = Trans * Change;
	}
	else {
		if (isrotDirec) {
			rotate += 2.5f;
			if (rotate > 30.f)
				isrotDirec = false;
		}
		else {
			rotate -= 2.5f;
			if (rotate < -30.f)
				isrotDirec = true;
		}

		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.04, 0.075, 0.04));	//�ٸ����� 0.15
		Change = Scale * Trans;		// ���� �ø��� ���
		
		Trans = glm::translate(Unit, glm::vec3(0, -0.15, 0));
		Change = Trans * Change;	//�ٸ� ���� ���� ������ �����ְ�

		Rotate = glm::rotate(Unit, glm::radians(rotate), glm::vec3(i * -1.f, 0, 0));
		Change = Rotate * Change;	//�ٸ� ���� ��� ����

		Trans = glm::translate(Unit, glm::vec3(0, 0.15, 0));
		Change = Trans * Change;	//�ٽ� ����ġ �����ְ�

		Trans = glm::translate(Unit, glm::vec3(i * 0.07, 0, 0));
		Change = Trans * Change;	// ���� ���ϴ� ��ġ(���� ������

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);		// �� �̵���ġ�� ����
		Change = Trans * Change;
	}
}

void Leg::BindVAO() 
{
	if (monster == 3) {
		glBindVertexArray(sphereVAO);
	}
	else
		glBindVertexArray(VAO);
}


void Leg::DrawArrays()
{
	
	if (monster == 3) {
		glDrawArrays(GL_TRIANGLES, 0, vertex2.size() * 3);
	}
	else
		glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);
}
