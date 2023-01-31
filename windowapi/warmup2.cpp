#include <iostream>
#include <format>
#include <random>
#include <algorithm>

std::random_device rd;
std::default_random_engine dre{ rd() };
std::uniform_int_distribution<int> uid{ 1, 50 };

int matrix[4][5];

void print_matrix()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 5; ++j)
			std::cout << std::format("{:4d}", matrix[i][j]);
		std::cout << std::endl;
	}
}

void input_matrix()
{
	for (int i = 0; i < 20; ++i)
		(*matrix)[i] = uid(dre);
}

void trade(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	input_matrix();
	bool running = true;
	while (running)
	{
		system("cls");
		std::cout << "���� ���: " << std::endl;
		print_matrix();
		std::cout << std::endl;
		std::cout << "����� ��ɾ �Է��ϼ���" << std::endl;
		std::cout << "	-a: 1��1���� �������� ���� ���� ������������ ����" << std::endl;
		std::cout << "	-d: 1��5���� �������� ���� ���� ������������ ����" << std::endl;
		std::cout << "	-e: ¦���� ����ϱ�" << std::endl;
		std::cout << "	-o: Ȧ���� ����ϱ�" << std::endl;
		std::cout << "	-m: �ִ밪 ���" << std::endl;
		std::cout << "	-n: �ּҰ� ���" << std::endl;
		std::cout << "	-p: �� ���� ���� ��� ���� �� ���� 1���� ����" << std::endl;
		std::cout << "	-r: �����ϰ� ������" << std::endl;
		std::cout << "	-s: �ٽ� �Է¹ޱ� ����" << std::endl;
		std::cout << "	-q: ���α׷� ����" << std::endl;
		char input;
		int max = 0;
		size_t maxindex = 0;
		int min = 51;
		size_t minindex = 0;
		if (std::cin >> input && '\n' != input)
		{
			switch (input)
			{
			case 'a':
				qsort(matrix[0], 20, 4,
					[](const void* a, const void* b)
					{
						return *(int*)a - *(int*)b;
					});
				break;
			case 'd':
				for (int i = 0; i < 19; ++i)
					for (int j = i + 1; j < 20; ++j)
						if (matrix[i % 4][4 - i / 4] < matrix[j % 4][4 - j / 4])
							trade(matrix[i % 4] + 4 - i / 4, matrix[j % 4] + 4 - j / 4);
				break;
			case 'e':
				for (int i = 0; i < 4; ++i)
				{
					for (int j = 0; j < 5; ++j)
						if (0 == matrix[i][j] % 2)
							std::cout << std::format("{:4d}", matrix[i][j]);
						else
							std::cout << std::format("{:4d}", 0);
					std::cout << std::endl;
				}
				system("pause");
				break;
			case 'o':
				for (int i = 0; i < 4; ++i)
				{
					for (int j = 0; j < 5; ++j)
						if (1 == matrix[i][j] % 2)
							std::cout << std::format("{:4d}", matrix[i][j]);
						else
							std::cout << std::format("{:4d}", 0);
					std::cout << std::endl;
				}
				system("pause");
				break;
			case 'm':
				for (int i = 0; i < 20; ++i)
					if ((*matrix)[i] > max)
					{
						max = (*matrix)[i];
						maxindex = i;
					}
				for (int i = 0; i < 4; ++i)
				{
					for (int j = 0; j < 5; ++j)
						if (maxindex == i * 5 + j)
							std::cout << std::format("{:4d}", matrix[i][j]);
						else
							std::cout << std::format("{:4d}", 0);
					std::cout << std::endl;
				}
				system("pause");
				break;
			case 'n':
				for (int i = 0; i < 20; ++i)
					if ((*matrix)[i] < min)
					{
						min = (*matrix)[i];
						minindex = i;
					}
				for (int i = 0; i < 4; ++i)
				{
					for (int j = 0; j < 5; ++j)
						if (minindex == i * 5 + j)
							std::cout << std::format("{:4d}", matrix[i][j]);
						else
							std::cout << std::format("{:4d}", 0);
					std::cout << std::endl;
				}
				system("pause");
				break;
			case 'p':
				for (int i = 0; i < 4; ++i)
				{
					int sum = 0;
					for (int j = 0; j < 5; ++j)
					{
						sum += matrix[i][j];
					}
					matrix[i][0] += sum;
				}
				break;
			case 'r':
				qsort(matrix[0], 20, 4,
					[](const void* a, const void* b)
					{
						return uid(dre) - 26;
					});
				break;
			case 's':
				input_matrix();
				break;
			case 'q':
				running = false;
				break;
			default:
				std::cout << "�Էµ� ��ɾ �ùٸ��� �ʽ��ϴ�" << std::endl;
				system("pause");
				break;
			}
		}
	}
	std::cout << "���α׷��� ����Ǿ����ϴ�." << std::endl;
}