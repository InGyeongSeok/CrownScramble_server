#include "Arm.h"

Arm::Arm()
{
}

Arm::Arm(glm::vec3 Color, int i, int monster) : i(i), rotate(0.f), isrotDirec(false), monster(monster)
{
	this->Color = Color;
	update();
}


Arm::~Arm()
{
}

void Arm::update()
{
	if (monster == 3) {
		if (isrotDirec) {
			rotate += 2.5f;
			if (rotate > 30.f) {
				isrotDirec = false;
				if (bearattack.Activate) {
					++bearattack.AttackCount;
				}
			}
			
		}
		else {
			rotate -= 2.5f;
			if (rotate < -30.f)
				isrotDirec = true;
			if (bearattack.Activate) {
				++bearattack.AttackCount;
			}
		}

		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.01, 0.03, 0.01));

		Change = Scale * Trans;		// ���� �ø��� ���

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

		Trans = glm::translate(Unit, glm::vec3(i * 0.13, 0, 0));
		Change = Trans * Change;	// ���� ���ϴ� ��ġ(���� ������)

		Rotate = glm::rotate(Unit,Direction, glm::vec3(0, 1, 0));
		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);		// �� �̵���ġ�� ����
		Change = Trans * Change;
	}
	else {
		if (isrotDirec) {
			rotate += 2.5f;
			if (rotate > 30.f) {
				isrotDirec = false;
				for (int i = 0; i < 6; ++i) {
					if (catattack[i].Activate) {
						++catattack[i].AttackCount;
					}
					if (dogattack[i].Activate) {
						++dogattack[i].AttackCount;
					}
				}
			}


		}
		else {
			rotate -= 2.5f;
			if (rotate < -30.f) {
				isrotDirec = true;
				for (int i = 0; i < 6; ++i) {
					if (catattack[i].Activate) {
						++catattack[i].AttackCount;
					}
					if (dogattack[i].Activate) {
						++dogattack[i].AttackCount;
					}
				}
			}

		}

		Trans = glm::translate(Unit, glm::vec3(0, 1.f, 0));
		Scale = glm::scale(Unit, glm::vec3(0.03, 0.075, 0.03));

		Change = Scale * Trans;		// ���� �ø��� ���

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

		Trans = glm::translate(Unit, glm::vec3(i * 0.13, 0, 0));
		Change = Trans * Change;	// ���� ���ϴ� ��ġ(���� ������)

		Rotate = glm::rotate(Unit, Direction, glm::vec3(0, 1, 0));

		Change = Rotate * Change;	//ĳ���� �����ֱ�

		Trans = glm::translate(Unit, Position);		// �� �̵���ġ�� ����
		Change = Trans * Change;
	}
}


void Arm::BindVAO()
{
	if (monster == 3) {
		glBindVertexArray(sphereVAO);
	}
	else
		glBindVertexArray(VAO);
}

void Arm::DrawArrays()
{
	if (monster == 3) {
		glDrawArrays(GL_TRIANGLES, 0, vertex2.size() * 3);
	}
	else
		glDrawArrays(GL_TRIANGLES, 0, vertex1.size() * 3);
	

}