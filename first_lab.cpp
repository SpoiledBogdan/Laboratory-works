#include <iostream>
#include <conio.h>

using namespace std;

class Paral {
public:
    float m_height;
    float m_length;
    float m_width;


    Paral(float height, float length, float width) {
        m_height = height;
        m_length = length;
        m_width = width;
        cout << "\n����������� ������������� ������.\n";
    }

    Paral() : m_height(1.3f), m_length(2.2f), m_width(7.1f)        // ����������� ��� ����������
    {
        cout << "\n����������� ��� ���������� ������.\n";
    }

    Paral(const Paral& other) : m_height(other.m_height), m_length(other.m_length), m_width(other.m_width)
    {
        cout << "\n����������� ����������� ������.\n";
    }

    ~Paral() {
        cout << "\n���������� ������� ������.\n";
    }

    float find_square() {
        float m_square = 2 * m_length * m_width + 2 * m_width * m_height + 2 * m_length * m_height;
        cout << "\n������� ����������� �����: " << m_square << " ��3.\n";
        return m_square;
    }
    float find_edge_sum() {
        float m_edges_sum = 4 * (m_height + m_length + m_width);
        cout << "\n����� ���� ����� �����: " << m_edges_sum << " ��3.\n";
        return m_edges_sum;
    }


};


void info_view(Paral& figure)
{
    cout <<"\n������ ������ Paral:"
        << "\n������ �����: " << figure.m_height << " ��."
        << "\n����� �����: " << figure.m_length << " ��."
        << "\n������ �����: " << figure.m_width << " ��.\n";
}



int main() {
    setlocale(LC_ALL, "Russian");

    // �������� ���� ��������
    Paral object1;
    Paral object2(5.0f, 5.0f, 5.0f);
    Paral object3(object1);

    // ��������� �� �������
    Paral* pointer1 = &object1;
    Paral* pointer2 = &object2;
    Paral* pointer3 = &object3;

    // ������� ���������� �������
    info_view(object1);
    info_view(object2);
    info_view(object3);

    // ������ ��������
    object1.find_edge_sum();
    object1.find_square();

    object2.find_edge_sum();
    object2.find_square();

    object3.find_edge_sum();
    object3.find_square();

    // ������ � ����� ������
    object1.m_height = 3.4f;
    object2.m_length = 3.4f;
    object3.m_width = 3.4f;


    return 0;
}