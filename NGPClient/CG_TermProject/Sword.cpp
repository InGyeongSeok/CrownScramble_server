#include "Sword.h"

Sword::Sword()
{
}

Sword::Sword(glm::vec3 Color, int i, int monster) : i(i), rotate(0.f), isrotDirec(false), monster{monster}
{
	this->Color = Color;
	update();
}


Sword::~Sword()
{
}

void Sword::update()
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
		Scale = glm::scale(Unit, glm::vec3(0.037, 0.15, 0.037));

		Change = Scale * Trans;		// ���� �ø��� ���

		Rotate = glm::rotate(Unit, glm::radians(80.f), glm::vec3(1, 0, 0));
		Change = Rotate * Change;				//ȸ�� �ֱ� 

		Trans = glm::translate(Unit, glm::vec3(0, -0.15, 0));
		Change = Trans * Change;	//�� �����ֱ����� ������ �����ְ�

		Rotate = glm::rotate(Unit, glm::radians(30.f), glm::vec3(0, 0, i * 1.f));
		Change = Rotate * Change;	//�����ش�.

		Rotate = glm::rotate(Unit, glm::radians(rotate), glm::vec3(i * 1.f, 0, 0));
		Change = Rotate * Change;	//�� ���� ��ǵ� ����

		Trans = glm::translate(Unit, glm::vec3(0, 0.15, 0));
		Change = Trans * Change;	//�ٽ� ����ġ �����ְ�

		Trans = glm::translate(Unit, glm::vec3(0, 0.19, 0));
		Change = Trans * Change;	// ���ϴ� ����

		Trans = glm::translate(Unit, glm::vec3(i * 0.17, 0, 0));
		Change = Trans * Change;	// ���� ���ϴ� ��ġ(���� ������)

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
		Scale = glm::scale(Unit, glm::vec3(0.037, 0.15, 0.037));

		Change = Scale * Trans;		// ���� �ø��� ���

		Rotate = glm::rotate(Unit, glm::radians(80.f), glm::vec3(1, 0, 0));
		Change = Rotate * Change;				//ȸ�� �ֱ� 

		Trans = glm::translate(Unit, glm::vec3(0, -0.15, 0));
		Change = Trans * Change;	//�� �����ֱ����� ������ �����ְ�

		Rotate = glm::rotate(Unit, glm::radians(30.f), glm::vec3(0, 0, i * 1.f));
		Change = Rotate * Change;	//�����ش�.

		Rotate = glm::rotate(Unit, glm::radians(rotate), glm::vec3(i * 1.f, 0, 0));
		Change = Rotate * Change;	//�� ���� ��ǵ� ����

		Trans = glm::translate(Unit, glm::vec3(0, 0.15, 0));
		Change = Trans * Change;	//�ٽ� ����ġ �����ְ�

		Trans = glm::translate(Unit, glm::vec3(0, 0.25, 0));
		Change = Trans * Change;	// ���ϴ� ����

		Trans = glm::translate(Unit, glm::vec3(i * 0.15, 0, 0));
		Change = Trans * Change;	// ���� ���ϴ� ��ġ(���� ������)

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);		// �� �̵���ġ�� ����
		Change = Trans * Change;
	}
}


void Sword::BindVAO()
{
	glBindVertexArray(pyramidVAO);
}

void Sword::DrawArrays()
{
	glDrawArrays(GL_TRIANGLES, 0, vertex3.size() * 3);

}