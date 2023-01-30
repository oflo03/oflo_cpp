#include <iostream>
#include <random>

std::random_device rd;
std::default_random_engine dre{ rd() };
std::uniform_int_distribution<int> uid{ 0,3 };

char char_table[]{ '@', '%', '#', '.' };

const int max_size = 60;

int main()
{
	char* sentence = new char(max_size);
	std::cout << "�ִ� " << max_size << "���� ������ �Է��ϼ���: ";
	std::cin >> std::noskipws;
	char temp = NULL;
	for (int i = 0; i < max_size; ++i)
	{
		std::cin >> sentence[i];
		if (' ' == temp && ' ' == sentence[i])
			--i;
		temp = sentence[i];
		if ('\n' == sentence[i])
		{
			sentence[i] = NULL;
			break;
		}
	}
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
			case 'e':
			case 'E':
				word_start = 0;
				for (int i = 0; NULL != sentence[i]; ++i)
				{
					if ('e' == sentence[i] || 'E' == sentence[i])
						to_upper = true;
					if ((' ' == sentence[i] || NULL == sentence[i + 1]) && to_upper)
					{
						if (NULL == sentence[i + 1])
							++i;
						for (int j = word_start; j < i; ++j)
						{
							if (islower(sentence[j]))
								sentence[j] -= 32;
						}
						
						word_start = i + 1;
						to_upper = false;
					}
				}
				break;
			case 'f':
			case 'F':
				for (int i = 0; NULL != sentence[i]; ++i)
				{
					if (' ' == sentence[i])
					{
						sentence[i] = char_table[uid(dre)];
					}
				}
				break;
			case 'l':
			case 'L':
				word_num = 1;
				for (int i = 0; NULL != sentence[i]; ++i)
				{
					if (' ' == sentence[i])
					{
						++word_num;
					}
				}
				std::cout << "Result: " << word_num << " words" << std::endl;
				system("pause");
				break;
			case 'c':
			case 'C':
				for (int i = 0; NULL != sentence[i]; ++i)
				{
					if (islower(sentence[i]))
						sentence[i] -= 32;
					else if (isupper(sentence[i]))
						sentence[i] += 32;
				}
				break;
			case 'a':
			case 'A':
				temp = sentence[0];
				for (int i = 1; NULL != sentence[i]; ++i)
				{
					sentence[i - 1] = sentence[i];
					if (NULL == sentence[i + 1])
						sentence[i] = temp;
				}
				break;
			case 'q':
			case 'Q':
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