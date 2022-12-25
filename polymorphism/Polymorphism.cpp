#include <iostream>
#include <fstream>
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "ShapeManager.h"


int main()
{
	ShapeManager* sm;
	int input{ 0 };
	while (1)
	{
		system("cls");
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "���� ������ ���� [1]" << std::endl;
		std::cout << "���� ������ �ҷ����� [2]" << std::endl;
		std::cout << "���α׷� ������ [3]" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cin >> input;

		system("cls");
		switch (input)
		{

		case 1:
			std::cout << "������ ������ �ִ� ������ �Է��ϼ��� : ";
			std::cin >> input;
			sm = new ShapeManager(input);
			sm->manage();
			break;
		case 2:
		{
			std::string input;
			std::cout << "�ҷ��� ���� �������� �̸��� �Է��ϼ��� : ";
			std::cin >> input;
			std::ifstream in{ input };
			if (!in)
			{
				std::cout << "���� �ҷ����⿡ �����Ͽ����ϴ�." << std::endl;
				system("pause");
				break;
			}
			sm = new ShapeManager;
			in >> *sm;
			sm->manage();
			break;
		}
		case 3:
			std::cout << "���α׷��� �����մϴ�" << std::endl;
			system("pause");
			return 0;
		default:
			std::cout << "�߸��� �Է��Դϴ�!" << std::endl;
			system("pause");
			break;
		}
	}
}