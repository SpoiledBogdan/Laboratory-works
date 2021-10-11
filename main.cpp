#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class University {
public:
	string name_university; //�������� ������������ 
	float freshman;			//freshman - ������������; ���������� �������������� 
	float graduate;			//���������� ����������� 

	University() {
		name_university = "NULL";
		freshman = 0;
		graduate = 0;
	}

	University(string _name_university, float _freshman, float _graduate) {
		name_university = _name_university;
		freshman = _freshman;
		graduate = _graduate;
	}

	float quality() {
		return graduate / freshman;
	}

	void University_info() {
		cout << "�������� ������������: " << endl;
		cout << "���������� ��������������: " << freshman << endl;
		cout << "���������� �����������: " << graduate << endl;
	}
};

class University_extend : public University {
public:
	string name_university;
	float freshman;
	float graduate;
	float P;

	University_extend() {
		freshman = 0;
		graduate = 0;
		P = 0;
	}

	University_extend(string _name_university, float _freshman, float _graduate, float _P) {
		name_university = _name_university;
		freshman = _freshman;
		graduate = _graduate;
		P = _P;
	}

	//��������������� ����� ��� � �������� ������
	float quality() {
		return University::quality() * P;
	}

	void University_extend_info() {
		cout << "�������� ������������: " << endl;
		cout << "���������� ��������������: " << freshman << endl;
		cout << "���������� �����������: " << graduate << endl;
		cout << "������� �����������, ���������� �� �������������: " << P << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	University_extend list[5];
	for (int i = 0; i < 5; i++) {
		cout << "������� �������� ������������� �" << i + 1 << "\n";
		cin >> list[i].name_university;

		cout << "������� ���������� �������������� �" << i + 1 << "\n";
		cin >> list[i].freshman;

		cout << "������� ���������� ����������� �" << i + 1 << "\n";
		cin >> list[i].graduate;

		cout << "������� ������� �����������, ���������� �� �������������:  �" << i + 1 << "\n";
		cin >> list[i].P;
	}

	string strlist[5];
	for (int i = 0; i < 5; i++) {
		ostringstream Str;
		Str << list[i].name_university << " " << list[i].freshman << " " << list[i].graduate << " " << list[i].P;
		strlist[i] = Str.str();
	}

	ofstream out;
	out.open("in.txt");
	for (int i = 0; i < 5; i++) {
		out << strlist[i] << endl;
	}


	//����������
	for (int j = 0; j < 16; j++) {
		for (int i = 0; i < 4; i++) {
			if (list[i].name_university > list[i + 1].name_university) {
				swap(strlist[i], strlist[i + 1]);
				swap(list[i], list[i + 1]);
			}
		}
	}

	ofstream out2;
	out2.open("out.txt");
	for (int i = 0; i < 5; i++) {
		out2 << strlist[i] << endl;
	}
	return 0;
}