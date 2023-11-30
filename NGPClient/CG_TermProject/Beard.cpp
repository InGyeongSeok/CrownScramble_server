#include "Beard.h"

Beard::Beard()
{
}

Beard::Beard(glm::vec3 Color, int i, int pos, int monster) :i{ i }, pos{ pos }, monster{ monster }
{
	this->Color = Color;
	update();
}

Beard::~Beard()
{
}



void Beard::update()
{
	if (monster == 1) {
		Scale = glm::scale(Unit, glm::vec3(0.033, 0.0025, 0.002));	//������ �ñ⶧���� �����غ����� y �÷���
		Change = Scale;

		if (pos == 1) {
			Rotate = glm::rotate(Unit, glm::radians(30.f), glm::vec3(0, 0, 1));
			Change = Rotate * Change;
		}
		else if (pos == 2) {
			Rotate = glm::rotate(Unit, glm::radians(0.f), glm::vec3(0, 0, 1));
			Change = Rotate * Change;
		}
		else if (pos == 3) {
			Rotate = glm::rotate(Unit, glm::radians(-30.f), glm::vec3(0, 0, 1));
			Change = Rotate * Change;
		}

		if (i == -1) {
			Rotate = glm::rotate(Unit, glm::radians(180.f), glm::vec3(0, 1, 0));
			Change = Rotate * Change;
		}

		if (pos == 1) {
			Trans = glm::translate(Unit, glm::vec3(0, 0.535, 0));
			Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.082));
			Change = Trans * Change;	//���ϴ� ��ġ�� �̵�
		}
		else if (pos == 2) {
			Trans = glm::translate(Unit, glm::vec3(0, 0.51, 0));
			Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.082));
			Change = Trans * Change;	//���ϴ� ��ġ�� �̵�
		}
		else if (pos == 3) {
			Trans = glm::translate(Unit, glm::vec3(0, 0.485, 0));
			Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.082));
			Change = Trans * Change;	//���ϴ� ��ġ�� �̵�
		}

		Trans = glm::translate(Unit, glm::vec3(i * 0.07, 0, 0));
		Change = Trans * Change;	// ���� ���ϴ� ��ġ(���� ������)


		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);
		Change = Trans * Change;	// �� ���������� �̵�
	}
	else if (monster == 2) {
		if (pos == 1) { //����

			Scale = glm::scale(Unit, glm::vec3(0.015, 0.0025, 0.002));
			Change = Scale;
		}
		else if (pos == 2) { //���� 
			Scale = glm::scale(Unit, glm::vec3(0.033, 0.0025, 0.002));	//������ �ñ⶧���� �����غ����� y �÷���
			Change = Scale;
		}

		if (pos == 1) { //����

			Rotate = glm::rotate(Unit, glm::radians(90.f), glm::vec3(0, 0, 1));
			Change = Rotate * Change;
		}
		else if (pos == 2) { //���� 
			Rotate = glm::rotate(Unit, glm::radians(0.f), glm::vec3(0, 0, 1));
			Change = Rotate * Change;
		}

		if (pos == 1) {
			Trans = glm::translate(Unit, glm::vec3(0, 0.51, 0));
			Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.082));
			Change = Trans * Change;	//���ϴ� ��ġ�� �̵�
		}
		else if (pos == 2) {
			Trans = glm::translate(Unit, glm::vec3(0, 0.49, 0));
			Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.082));
			Change = Trans * Change;	//���ϴ� ��ġ�� �̵�
		}

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);
		Change = Trans * Change;	// �� ���������� �̵�
	}
	else if (monster == 3) {  

		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.005, 0.0008, 0.0003));	//������ �ñ⶧���� �����غ����� y �÷���
		Change = Scale; //���� �ø��� ���

		Rotate = glm::rotate(Unit, glm::radians(0.f), glm::vec3(0, 0, 1));
		Change = Rotate * Change;

		if (pos == 1) { //����

			Rotate = glm::rotate(Unit, glm::radians(-30.f), glm::vec3(0, 0, 1));
			Change = Rotate * Change;
		}
		else if (pos == 2) { //���� 
			Rotate = glm::rotate(Unit, glm::radians(30.f), glm::vec3(0, 0, 1));
			Change = Rotate * Change;
		}

		Trans = glm::translate(Unit, glm::vec3(0, 0.61, 0));
		Trans = Trans * glm::translate(Unit, glm::vec3(0, 0, 0.1));
		Change = Trans * Change;		//���ϴ� ��ġ�� �̵�

		Trans = glm::translate(Unit, glm::vec3(i * 0.05, 0, 0));
		Change = Trans * Change;	// ���� ���ϴ� ��ġ(���� ������)

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));
		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);
		Change = Trans * Change;	// �� ���������� �̵�



	}
}


void Beard::BindVAO()
{
	if (monster == 3) {
		glBindVertexArray(sphereVAO);
	}
	else
		glBindVertexArray(VAO);
}

void Beard::DrawArrays()
{
	if (monster == 3) {
		glDrawArrays(GL_TRIANGLES, 0, vertex2.size() * 3);
	}
	else
		glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);
}