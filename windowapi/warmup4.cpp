#include <iostream>
#include <format>

std::string days[] = { "Sunday","Monday","Tuesday" ,"Wednesday", "Thursday", "Friday", "Saturday" };

int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int day_day(int yyyy, int mm, int dd)
{
	int day = 3;
	for (int i = 2020; i < yyyy; ++i)
	{
		day += ((0 == i % 4 && i % 100) || 0 == i % 400) ? 366 : 365;
	}
	for (int i = 1; i < mm; ++i)
	{
		day += months[i - 1];
		if (((0 == yyyy % 4 && yyyy % 100) || 0 == yyyy % 400) && 2 == i)
			++day;
	}
	day += dd - 1;
	return day % 7;
}


void print_day(int yyyy, int mm, int dd)
{
	std::cout << yyyy << '/' << mm << '/' << dd << ": " << days[day_day(yyyy, mm, dd)] << std::endl;
	std::cout << yyyy << '-' << mm << std::endl;
	for (std::string& day : days)
		std::cout << std::format("{:12s}", day);
	std::cout << std::endl;
	for (int i = 1 - day_day(yyyy, mm, 01); i <= months[mm - 1]; ++i)
	{
		if (i > 0)
			std::cout << std::format("{:<12d}", i);
		else
			std::cout << std::format("{:12c}", ' ');
		if ((7 - day_day(yyyy, mm, 01)) % 7 == i % 7)
			std::cout << std::endl;
	}
}

int main()
{
	bool running = true;
	char input;
	int year, month, day;
	print_day(2022, 03, 01);
	while (running)
	{
		std::cout << std::endl;
		std::cout << "명령어 : c/C - 요일 계산기 로드" << std::endl;
		std::cout << "명령어 : f/F - 13일의 금요일 출력" << std::endl;
		std::cin >> input;
		if ('c' == input || 'C' == input)
		{
			std::cout << "계산할 년, 월, 일을 입력하세요" << std::endl;
			std::cout << "(2020 01 01 ~ 2030 12 31)" << std::endl;
			std::cin >> year;
			std::cin >> month;
			std::cin >> day;
			if (year < 2020 || year>2030 || month < 1 || month>12 || day<1 || day>months[month-1] + ((0 == year % 4 && year % 100) || 0 == year % 400) ? 1 : 0)
			{
				std::cout << "올바르지 않은 날짜를 입력하였습니다" << std::endl;
				system("pause");
				system("cls");
				print_day(2022, 03, 01);
			}
			else
			{
				system("cls");
				print_day(year, month, day);
			}
		}
		else if ('f' == input || 'F' == input)
		{
			int cnt = 0;
			for (int i = 2020; i < 2031; ++i)
				for (int j = 1; j < 13; ++j)
					if (5 == day_day(i, j, 13))
					{
						std::cout << i << '-' << std::format("{:2d}", j) << "-13  ";
						++cnt;
						if (0 == cnt % 6)
							std::cout << std::endl;
					}
			system("pause");
			system("cls");
			print_day(2022, 03, 01);
		}
	}
}