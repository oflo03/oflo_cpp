#include <iostream>
#include <fstream>
#include "ShapeManager.h"
#include "Point.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

ShapeManager::ShapeManager(size_t n)
{
	nShape = 0;
	capacity = n;
	shapes = new Shape * [capacity];
}

std::ostream& operator <<(std::ostream& os, const ShapeManager& sm)
{
	os << sm.nShape << " " << sm.capacity << " ";
	for (int i = 0; i < sm.nShape; ++i)
		os << *sm.shapes[i];
	return os;
}
std::istream& operator >>(std::istream& is, ShapeManager& sm)
{
	is >> sm.nShape >> sm.capacity;
	sm.shapes = new Shape * [sm.capacity];
	for (int i = 0; i < sm.nShape; ++i)
	{
		std::string input;
		is >> input;
		if ("Circle" == input)
			sm.shapes[i] = new Circle;
		if ("Triangle" == input)
			sm.shapes[i] = new Triangle;
		if ("Rectangle" == input)
			sm.shapes[i] = new Rectangle;
		is >> **(sm.shapes + i);
	}
	return is;
}

ShapeManager::~ShapeManager()
{
	for (int i = 0; i < nShape; ++i)
	{
		delete shapes[i];
	}
	delete[] shapes;
}

void ShapeManager::manage()
{
	int input{ 0 };
	bool end{ false };
	while (!end)
	{
		system("cls");
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "원하는 도형 추가 [1]" << std::endl;
		std::cout << "원하는 도형 삭제 [2]" << std::endl;
		std::cout << "전체 도형을 그리기 [3]" << std::endl;
		std::cout << "도형 관리자 저장 [4]" << std::endl;
		std::cout << "도형 관리 끝내기 [5]" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cin >> input;

		system("cls");
		switch (input)
		{
		case 1:
			while (!end)
			{
				system("cls");
				std::cout << "---------------------------------------------" << std::endl;
				std::cout << "[원하는 도형 추가]" << std::endl;
				std::cout << "원 [1]" << std::endl;
				std::cout << "삼각형 [2]" << std::endl;
				std::cout << "사각형 [3]" << std::endl;
				std::cout << "돌아가기 [4]" << std::endl;
				std::cout << "---------------------------------------------" << std::endl;
				std::cin >> input;

				system("cls");
				switch (input)
				{
				case 1:
				{
					Point center;
					double rad;
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << "[원 그리기]" << std::endl;
					std::cout << "원의 중심 좌표 : ";
					std::cin >> center.x;
					std::cin >> center.y;
					std::cout << "원의 반지름 길이 : ";
					std::cin >> rad;
					this->insert(new Circle(center, rad));
					std::cout << "원 그리기 완료!" << std::endl;
					system("pause");
					break;
				}
				case 2:
				{
					Point p1, p2, p3;
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << "[삼각형 그리기]" << std::endl;
					std::cout << "삼각형의 첫 번째 꼭지점 좌표 : ";
					std::cin >> p1.x;
					std::cin >> p1.y;
					std::cout << "삼각형의 두 번째 꼭지점 좌표 : ";
					std::cin >> p2.x;
					std::cin >> p2.y;
					std::cout << "삼각형의 세 번째 꼭지점 좌표 : ";
					std::cin >> p3.x;
					std::cin >> p3.y;
					this->insert(new Triangle(p1, p2, p3));
					std::cout << "삼각형 그리기 완료!" << std::endl;
					system("pause");
					break;
				}
				case 3:
				{
					Point p1, p2;
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << "[사각형 그리기]" << std::endl;
					std::cout << "사각형의 첫 번째 꼭지점 좌표 : ";
					std::cin >> p1.x;
					std::cin >> p1.y;
					std::cout << "사각형의 두 번째 꼭지점 좌표 : ";
					std::cin >> p2.x;
					std::cin >> p2.y;
					this->insert(new Rectangle(p1, p2));
					std::cout << "사각형 그리기 완료!" << std::endl;
					system("pause");
					break;
				}
				case 4:
					end = true;
					break;
				default:
					std::cout << "잘못된 입력입니다!" << std::endl;
					system("pause");
					break;
				}
			}
			end = false;
			break;
		case 2:
			while (!end)
			{
				system("cls");
				std::cout << "---------------------------------------------" << std::endl;
				std::cout << "[원하는 도형 삭제]" << std::endl;
				std::cout << "번호로 삭제 [1]" << std::endl;
				std::cout << "도형 종류로 삭제 [2]" << std::endl;
				std::cout << "돌아가기 [3]" << std::endl;
				std::cout << "---------------------------------------------" << std::endl;
				std::cin >> input;

				system("cls");
				switch (input)
				{
				case 1:
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << "[번호로 삭제]" << std::endl;
					std::cout << "삭제할 도형의 번호를 입력하세요 : ";
					std::cin >> input;
					this->eliminate(input);
					break;
				case 2:
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << "[도형 종류로 삭제]" << std::endl;
					std::cout << "원 [1]" << std::endl;
					std::cout << "삼각형 [2]" << std::endl;
					std::cout << "사각형 [3]" << std::endl;
					std::cout << "---------------------------------------------" << std::endl;
					std::cin >> input;
					switch (input)
					{
					case 1:
						for (int i = nShape - 1; i >= 0; --i)
						{
							if (typeid(*shapes[i])==(typeid(Circle)))
							{
								this->eliminate(i);
							}
						}
						break;
					case 2:
						for (int i = nShape - 1; i >= 0; --i)
						{
							if (typeid(*shapes[i])==(typeid(Triangle)))
							{
								this->eliminate(i);
							}
						}
						break;
					case 3:
						for (int i = nShape - 1; i >= 0; --i)
						{
							if (typeid(*shapes[i])==(typeid(Rectangle)))
							{
								this->eliminate(i);
							}
						}
						break;
					default:
						break;
					}

					break;
				case 3:
					end = true;
					break;
				default:
					std::cout << "잘못된 입력입니다!" << std::endl;
					system("pause");
					break;
				}
			}
			end = false;
			break;
		case 3:
			this->draw();
			system("pause");
			break;
		case 4:
		{
			std::string input;
			std::cout << "도형 관리자를 저장할 이름을 입력하세요: ";
			std::cin >> input;
			std::ifstream in{ input };
			if (in)
			{
				std::cout << "해당 이름의 파일이 이미 존재합니다!" << std::endl;
				system("pause");
				break;
			}
			std::ofstream out{ input };
			out << *this;
			break;
		}
		case 5:
			std::cout << "도형관리를 종료합니다" << std::endl;
			system("pause");
			end = true;
			break;
		default:
			std::cout << "잘못된 입력입니다!" << std::endl;
			system("pause");
			break;
		}
	}
}


void ShapeManager::insert(Shape* a)
{
	if (nShape == capacity)
	{
		Shape** temp = shapes;
		shapes = new Shape * [capacity + 1];
		for (int i = 0; i < capacity; ++i)
		{
			shapes[i] = temp[i];
		}
		delete[] temp;
		++capacity;
	}
	shapes[nShape] = a;
	++nShape;
}

void ShapeManager::eliminate(size_t idx)
{
	delete shapes[idx];
	for (int i = idx; i < nShape - 1; ++i)
	{
		shapes[i] = shapes[i + 1];
	}
	shapes[nShape] = nullptr;
	--nShape;
}

void ShapeManager::draw() const
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "관리하는 모든 도형을 그립니다" << std::endl;
	std::cout << "최대 " << capacity << "개의 도형을 담을 수 있습니다" << std::endl;
	std::cout << "모두 " << nShape << "개의 도형이 있습니다" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < nShape; ++i)
	{
		std::cout << "[" << i << "]  ";
		shapes[i]->draw();
	}
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "그리기를 마칩니다" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}