#include <iostream>
#include <windows.h>

using namespace std;

class Field {
public:
	string m_name;  
	double m_r;		  //��� ��������� �����
	double m_S;		  //������� � ��

	double harvested; //������

	Field() {
		m_name = "NULL";
		m_r = 0;
		m_S = 0;
		harvested = 0;
	}

	Field(string name, double r, double S) {
		m_name = name;
		m_r = r;
		m_S = S;
	}

	~Field() {
		cout << "���������� Field ������" << endl;
	}

	void harvest(double k){		//k - ���������� 
		harvested = k * m_r;
		cout << "������ ����� " << harvested << "\n" << endl;
	}

	void info_Field() {
		cout << " *����* "			<< endl;
		cout << "������������ ����: "   << m_name << endl;
		cout << "��� ��������� �����: " << m_r << endl;
		cout << "������� ���� � ��: "   << m_S << endl;
	}
};

class Farmers : public Field {  //������������ ������� Farmers ���������� ������ Field
public:
	double m_m;					//���������� ��������� ��������� 
	double f_harvested;		    //������� ������ � ������ 0.001*m

	Farmers() {
		m_name = "NULL";
		m_r = 0;
		m_S = 0;

		m_m = 0;

		f_harvested = 0;
	}

	Farmers(string name, double r, double S, double m) {
		m_name = "NULL";
		m_r = 0;
		m_S = 0;

		m_m = m;
	}

	~Farmers() {
		cout << "���������� Farmers ������" << endl;
	}

	void farm_harvest() {
		f_harvested = (m_S * 0.001 * m_m) + harvested;
		cout << "������ � ������ ����� " << f_harvested << "\n" << endl;
	}

	void info_Farmers() {
		cout << " *���������� ����* " << endl;
		cout << "������������ ����: " << m_name << endl;
		cout << "��� ��������� �����: " << m_r << endl;
		cout << "������� ���� � ��: " << m_S << endl;
		cout << "���������� ��������� ���������: " << m_m << endl;
	}
};

class Fazenda : public Field {
public:
	//����� ������
	string m_date1 = "������";
	string m_date2 = "�������";
	string m_date3 = "�������";

	double faz_harvested;       //������ ��� ������ Fazenda

	Fazenda() {
		m_name = "NULL";
		m_r = 0;
		m_S = 0;

		faz_harvested = 0;
	}

	Fazenda(string name, double r, double S) {
		m_name = name;
		m_r = r;
		m_S = S;
	}

	~Fazenda() {
		cout << "���������� Fazenda ������" << endl;
	}

	void fazenda_harvest(string date) {

		if (date == m_date1) {
			faz_harvested = harvested * (100.0 + 10.0) / 100.0;		//+10% ��� �������
			cout << "������ � ������ ������� ����� " << faz_harvested << "\n" << endl;
		}

		else if (date == m_date3) {
			faz_harvested = harvested * (100.0 - 5.0) / 100.0;		//-5% ��� ��������
			cout << "������ � ������� ������� ����� " << faz_harvested << "\n" << endl;
		}

		else {
			faz_harvested = harvested;
			cout << "������ � ������� ����� " << faz_harvested << "\n" << endl;
		}
	}

	void info_Fazenda() {
		cout << " *������������ ����* " << endl;
		cout << "������������ ����: " << m_name << endl;
		cout << "��� ��������� �����: " << m_r << endl;
		cout << "������� ���� � ��: " << m_S << endl;
		cout << "����� ������: " << m_date1 << ", " << m_date2 << ", " << m_date3 << ", " << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	cout << "---�������� �������� � �����������---\n" << endl;

	Field Meadow1("Pole1", 3, 4);
	Meadow1.info_Field();
	Meadow1.harvest(4);

	Farmers Meadow2("Pole2", 4, 1, 4);
	Meadow2.info_Farmers();
	Meadow2.farm_harvest();

	Fazenda Meadow3("Pole3", 4, 5);
	Meadow3.info_Fazenda();
	Meadow3.fazenda_harvest("������");

	cout << "---�������� �������� ��� ����������---\n" << endl;

	Field _Meadow1;
	_Meadow1.info_Field();
	_Meadow1.harvest(4);

	Farmers _Meadow2;
	_Meadow2.info_Farmers();
	_Meadow2.farm_harvest();

	Fazenda _Meadow3;
	_Meadow3.info_Fazenda();
	_Meadow3.fazenda_harvest("0");

	return 0;
}