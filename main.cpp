#include <iostream>
using namespace std;

class University {
public:
	string name_university; //�������� ������������ 
	float freshman;			//freshman - ������������; ���������� �������������� 
	float graduate;			//���������� ����������� 
	float Q;				//�������� �������

	University() {
		name_university = "NULL";
		freshman = 0;
		graduate = 0;
		Q = 0;
	}

	University(string _name_university, float _freshman, float _graduate) {
		name_university = _name_university;
		freshman = _freshman;
		graduate = _graduate;
	}

	virtual void quality() {  //���������� ����� ��� �����������
		Q = graduate / freshman;
		cout << "��������� Q �����: " << Q << "\n" << endl;
	}

	void University_info() {
		cout << "�������� ������������: "     << name_university << endl;
		cout << "���������� ��������������: " << freshman << endl;
		cout << "���������� �����������: "    << graduate << endl;
	}
};

class University_extend : public University {
public:
	float P;  //������� �����������, ���������� �� ������������� 
	float Qp; //�������� ������� 2 ������

	University_extend() {
		Q = 0;
		P = 0;
		Qp = 0;
	}

	University_extend(string _name_university, float _freshman, float _graduate, float _P) {
		name_university = _name_university;
		freshman = _freshman;
		graduate = _graduate;
		P = _P;
	}

	//��������������� ����� ��� � �������� ������
	void quality() override {  
		/*override : ��� ������� �������� ��������� ������
		��������: ������ ����� �������� int quality(), 
		���������� ����� ��� ������������ ��� ��������� �����
		���������������� ����� ������ ����� ��� ������������� ��������
		� �������� ����� ��, ��� � � ������������ ������
		*/

		Q = graduate / freshman;
		Qp = P * Q;
		cout << "��������� Qp �����: " << Qp << "\n" << endl;
	}

	void University_extend_info() {
		cout << "�������� ������������: " << name_university << endl;
		cout << "���������� ��������������: " << freshman << endl;
		cout << "���������� �����������: " << graduate << endl;
		cout << "������� �����������, ���������� �� �������������: " << P << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	University technical("BSUT", 100, 200);
	technical.University_info();
	technical.quality();

	University_extend medical("GSMU", 200, 300, 100);
	medical.University_extend_info();
	medical.quality();


	return 0;
}