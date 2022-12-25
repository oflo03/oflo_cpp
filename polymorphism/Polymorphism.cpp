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
		std::cout << "도형 관리자 생성 [1]" << std::endl;
		std::cout << "도형 관리자 불러오기 [2]" << std::endl;
		std::cout << "프로그램 끝내기 [3]" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cin >> input;

		system("cls");
		switch (input)
		{

		case 1:
			std::cout << "관리할 도형의 최대 개수를 입력하세요 : ";
			std::cin >> input;
			sm = new ShapeManager(input);
			sm->manage();
			break;
		case 2:
		{
			std::string input;
			std::cout << "불러올 도형 관리자의 이름을 입력하세요 : ";
			std::cin >> input;
			std::ifstream in{ input };
			if (!in)
			{
				std::cout << "파일 불러오기에 실패하였습니다." << std::endl;
				system("pause");
				break;
			}
			sm = new ShapeManager;
			in >> *sm;
			sm->manage();
			break;
		}
		case 3:
			std::cout << "프로그램을 종료합니다" << std::endl;
			system("pause");
			return 0;
		default:
			std::cout << "잘못된 입력입니다!" << std::endl;
			system("pause");
			break;
		}
	}
}