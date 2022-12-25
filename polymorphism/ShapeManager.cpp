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
		std::cout << "���ϴ� ���� �߰� [1]" << std::endl;
		std::cout << "���ϴ� ���� ���� [2]" << std::endl;
		std::cout << "��ü ������ �׸��� [3]" << std::endl;
		std::cout << "���� ������ ���� [4]" << std::endl;
		std::cout << "���� ���� ������ [5]" << std::endl;
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
				std::cout << "[���ϴ� ���� �߰�]" << std::endl;
				std::cout << "�� [1]" << std::endl;
				std::cout << "�ﰢ�� [2]" << std::endl;
				std::cout << "�簢�� [3]" << std::endl;
				std::cout << "���ư��� [4]" << std::endl;
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
					std::cout << "[�� �׸���]" << std::endl;
					std::cout << "���� �߽� ��ǥ : ";
					std::cin >> center.x;
					std::cin >> center.y;
					std::cout << "���� ������ ���� : ";
					std::cin >> rad;
					this->insert(new Circle(center, rad));
					std::cout << "�� �׸��� �Ϸ�!" << std::endl;
					system("pause");
					break;
				}
				case 2:
				{
					Point p1, p2, p3;
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << "[�ﰢ�� �׸���]" << std::endl;
					std::cout << "�ﰢ���� ù ��° ������ ��ǥ : ";
					std::cin >> p1.x;
					std::cin >> p1.y;
					std::cout << "�ﰢ���� �� ��° ������ ��ǥ : ";
					std::cin >> p2.x;
					std::cin >> p2.y;
					std::cout << "�ﰢ���� �� ��° ������ ��ǥ : ";
					std::cin >> p3.x;
					std::cin >> p3.y;
					this->insert(new Triangle(p1, p2, p3));
					std::cout << "�ﰢ�� �׸��� �Ϸ�!" << std::endl;
					system("pause");
					break;
				}
				case 3:
				{
					Point p1, p2;
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << "[�簢�� �׸���]" << std::endl;
					std::cout << "�簢���� ù ��° ������ ��ǥ : ";
					std::cin >> p1.x;
					std::cin >> p1.y;
					std::cout << "�簢���� �� ��° ������ ��ǥ : ";
					std::cin >> p2.x;
					std::cin >> p2.y;
					this->insert(new Rectangle(p1, p2));
					std::cout << "�簢�� �׸��� �Ϸ�!" << std::endl;
					system("pause");
					break;
				}
				case 4:
					end = true;
					break;
				default:
					std::cout << "�߸��� �Է��Դϴ�!" << std::endl;
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
				std::cout << "[���ϴ� ���� ����]" << std::endl;
				std::cout << "��ȣ�� ���� [1]" << std::endl;
				std::cout << "���� ������ ���� [2]" << std::endl;
				std::cout << "���ư��� [3]" << std::endl;
				std::cout << "---------------------------------------------" << std::endl;
				std::cin >> input;

				system("cls");
				switch (input)
				{
				case 1:
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << "[��ȣ�� ����]" << std::endl;
					std::cout << "������ ������ ��ȣ�� �Է��ϼ��� : ";
					std::cin >> input;
					this->eliminate(input);
					break;
				case 2:
					std::cout << "---------------------------------------------" << std::endl;
					std::cout << "[���� ������ ����]" << std::endl;
					std::cout << "�� [1]" << std::endl;
					std::cout << "�ﰢ�� [2]" << std::endl;
					std::cout << "�簢�� [3]" << std::endl;
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
					std::cout << "�߸��� �Է��Դϴ�!" << std::endl;
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
			std::cout << "���� �����ڸ� ������ �̸��� �Է��ϼ���: ";
			std::cin >> input;
			std::ifstream in{ input };
			if (in)
			{
				std::cout << "�ش� �̸��� ������ �̹� �����մϴ�!" << std::endl;
				system("pause");
				break;
			}
			std::ofstream out{ input };
			out << *this;
			break;
		}
		case 5:
			std::cout << "���������� �����մϴ�" << std::endl;
			system("pause");
			end = true;
			break;
		default:
			std::cout << "�߸��� �Է��Դϴ�!" << std::endl;
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
	std::cout << "�����ϴ� ��� ������ �׸��ϴ�" << std::endl;
	std::cout << "�ִ� " << capacity << "���� ������ ���� �� �ֽ��ϴ�" << std::endl;
	std::cout << "��� " << nShape << "���� ������ �ֽ��ϴ�" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < nShape; ++i)
	{
		std::cout << "[" << i << "]  ";
		shapes[i]->draw();
	}
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "�׸��⸦ ��Ĩ�ϴ�" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}