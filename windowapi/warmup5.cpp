#include <iostream>

int main()
{
	double nums[6]{};
	int oper_riv[6]{};
	char oper[5]{};
	char input;
	std::cout << "계산을 원하는 식을 공백 없이 입력하시오 (소괄호 사용 가능)" << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		if ('(' == std::cin.peek() && i < 4)
		{
			std::cin >> input;
			for (int j = i; j < 4; ++j)
				oper_riv[j + 1] += 2;
			--i;
			continue;
		}
		std::cin >> nums[i];

		while (')' == std::cin.peek())
		{
			std::cin >> input;
			for (int j = i; j < 4; ++j)
				oper_riv[j + 1] -= 2;
		}
		if (i < 4)
		{
			std::cin >> oper[i];
			if ('*' == oper[i] || '/' == oper[i])
				++oper_riv[i + 1];
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = oper_riv[i]; j < oper_riv[i + 1]; j += 2)
			std::cout << '(';
		std::cout << nums[i];

		for (int j = oper_riv[i]; j > oper_riv[i + 1]; j -= 2)
			std::cout << ')';
		if (i < 4)
			std::cout << oper[i];
	}

	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if (oper_riv[j + 1] == 9 - i)
			{
				switch (oper[j])
				{
				case '+':
					nums[j] += nums[j + 1];
					for (int k = j + 1; k < 5; ++k)
					{
						nums[k] = nums[k + 1];
						oper[k - 1] = oper[k];
						oper_riv[k] = oper_riv[k + 1];
					}
					--j;
					break;
				case '-':
					nums[j] -= nums[j + 1];
					for (int k = j + 1; k < 5; ++k)
					{
						nums[k] = nums[k + 1];
						oper[k - 1] = oper[k];
						oper_riv[k] = oper_riv[k + 1];
					}
					--j;
					break;
				case '*':
					nums[j] *= nums[j + 1];
					for (int k = j + 1; k < 5; ++k)
					{
						nums[k] = nums[k + 1];
						oper[k - 1] = oper[k];
						oper_riv[k] = oper_riv[k + 1];
					}
					--j;
					break;
				case '/':
					if (0 == nums[j + 1])
					{
						std::cout << "0으로 나눌 수 없습니다" << std::endl;
						return 0;
					}
					nums[j] /= nums[j + 1];
					for (int k = j + 1; k < 5; ++k)
					{
						nums[k] = nums[k + 1];
						oper[k - 1] = oper[k];
						oper_riv[k] = oper_riv[k + 1];
					}
					--j;
					break;
				default:
					break;
				}
			}
		}
	std::cout <<'=' << nums[0];
}