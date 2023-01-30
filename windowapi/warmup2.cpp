#include <iostream>
#include <format>
#include <random>

std::random_device rd;
std::default_random_engine dre{ rd() };
std::uniform_int_distribution<int> uid{ 1, 50 };

int matrix[4][5];

void print_matrix()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			std::cout << std::format("{:4f}", matrix[i][j]);
		}

	}
}

int main()
{
	char sentence[] = "asda";
	bool running = true;
	int word_num;
	bool to_upper = false;
	int word_start;
	while (running)
	{
		system("cls");
		std::cout << "���� ����: " << sentence << std::endl << std::endl;
		std::cout << "����� ��ɾ �Է��ϼ���" << std::endl;
		std::cout << "	-e/E: �ܾ e �Ǵ� E�ڰ� �ִ� ��쿡�� �� �ܾ ��� �빮�ڷ� ��ȯ" << std::endl;
		std::cout << "	-f/F: ��� ���鿡 ������ ���� (@, %, # �Ǵ� .)�� ����" << std::endl;
		std::cout << "	-l/L: �ܾ��� ������ ���" << std::endl;
		std::cout << "	-c/C: �빮�ڴ� �ҹ��ڷ�, �ҹ��ڴ� �빮�ڷ� ��ȯ" << std::endl;
		std::cout << "	-a/A: ������ ���ڸ� ����/�������� �� ���ھ� �̵�" << std::endl;
		std::cout << "	-q/Q: ���α׷��� ����" << std::endl;
		char input;
		if (std::cin >> input && '\n' != input)
		{
			switch (input)
			{
			default:
				std::cout << "�Էµ� ��ɾ �ùٸ��� �ʽ��ϴ�" << std::endl;
				system("pause");
				break;
			}
		}
	}
	std::cout << "���α׷��� ����Ǿ����ϴ�." << std::endl;
}