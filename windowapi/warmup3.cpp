#include <iostream>
#include <random>
#include <windows.h>

std::random_device rd;
std::default_random_engine dre(rd());
std::uniform_int_distribution<int> uid(0, 9);
std::uniform_int_distribution<int> ucd(0, 4);

char image_table[] = { 'O','X','#','@','*' };

struct stone
{
	size_t x, y;
	char image;
	stone(char image) :image(image) {}
	void random_locate()
	{
		x = uid(dre);
		y = uid(dre);
	}
	void change_image();
};


stone p1('O');
stone p2('X');
stone* players[]{ &p1,&p2 };
char map[10][10];
int turn;

void stone::change_image()
{
	char temp = image;
	image = image_table[ucd(dre)];
	while (p1.image == p2.image || temp == image)
		image = image_table[ucd(dre)];
}


void start_game()
{
	p1.random_locate();
	p2.random_locate();
	while (p1.x == p2.x && p1.y == p2.y)
		p2.random_locate();
	for (int i = 0; i < 10; ++i)
	{
		for (int j = -0; j < 10; ++j)
		{
			if (i == p1.x && j == p1.y)
				map[i][j] = p1.image;
			else if (i == p2.x && j == p2.y)
				map[i][j] = p2.image;
			else
				map[i][j] = ' ';
		}
	}
	turn = 0;
}

void print_map()
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << "-----------------------------------------" << std::endl;
		for (int j = 0; j < 10; ++j)
		{
			std::cout << "| " << map[i][j] << ' ';
		}
		std::cout << '|' << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
}

void move(int player, int dir)
{
	if (player != turn % 2)
	{
		std::cout << "�÷��̾� 1�� ���� �ƴմϴ�!" << std::endl;
		system("pause");
		return;
	}
	if (p1.x != p2.x || p1.y != p2.y)
		map[players[player]->x][players[player]->y] = ' ';

	if (1 == dir % 2)
	{
		players[player]->x += dir - 2;
		if (players[player]->x < 0 || players[player]->x>9)
		{
			players[player]->x += 10;
			players[player]->x %= 10;
			players[player]->change_image();
		}
	}
	else
	{
		players[player]->y += dir - 3;
		if (players[player]->y < 0 || players[player]->y>9)
		{
			players[player]->y += 10;
			players[player]->y %= 10;
			players[player]->change_image();
		}
	}
	map[players[player]->x][players[player]->y] = players[player]->image;
	if (p1.x == p2.x && p1.y == p2.y)
		Beep(392, 500);
	++turn;
}

int main()
{
	start_game();
	bool running = true;
	char input;
	while (running)
	{
		system("cls");
		print_map();
		std::cout << "���� ��: " << turn / 2 + 1 << ", �÷��̾� " << turn % 2 + 1 << "�� ����" << std::endl;
		std::cin >> input;
		switch (input)
		{
		case 'w':
			move(0, 1);
			break;
		case 'a':
			move(0, 2);
			break;
		case 's':
			move(0, 3);
			break;
		case 'd':
			move(0, 4);
			break;
		case 'i':
			move(1, 1);
			break;
		case 'j':
			move(1, 2);
			break;
		case 'k':
			move(1, 3);
			break;
		case 'l':
			move(1, 4);
			break;
		case 'r':
			start_game();
			break;
		case 'q':
			running = false;
			break;
		default:
			break;
		}
	}
	std::cout << "���α׷��� �����մϴ�." << std::endl;
	system("pause");
}