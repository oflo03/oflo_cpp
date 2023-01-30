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
		std::cout << "현재 문장: " << sentence << std::endl << std::endl;
		std::cout << "사용할 명령어를 입력하세요" << std::endl;
		std::cout << "	-e/E: 단어에 e 또는 E자가 있는 경우에는 그 단어를 모두 대문자로 변환" << std::endl;
		std::cout << "	-f/F: 모든 공백에 랜덤한 문자 (@, %, # 또는 .)를 삽입" << std::endl;
		std::cout << "	-l/L: 단어의 개수를 출력" << std::endl;
		std::cout << "	-c/C: 대문자는 소문자로, 소문자는 대문자로 변환" << std::endl;
		std::cout << "	-a/A: 문장의 문자를 좌측/우측으로 한 문자씩 이동" << std::endl;
		std::cout << "	-q/Q: 프로그램을 종료" << std::endl;
		char input;
		if (std::cin >> input && '\n' != input)
		{
			switch (input)
			{
			default:
				std::cout << "입력된 명령어가 올바르지 않습니다" << std::endl;
				system("pause");
				break;
			}
		}
	}
	std::cout << "프로그램이 종료되었습니다." << std::endl;
}