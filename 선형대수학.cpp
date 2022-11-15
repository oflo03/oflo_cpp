#include <iostream>
#include <math.h>

class Point {
public:
	int x, y;
	Point(int pos_x, int pos_y)
	{
		x = pos_x;
		y = pos_y;
	}
};

class Mxplusn
{
public:
	double m, n, x;
};

class Geometry {
public:
	Geometry() {
		num_points = 0;
	}

	Point PrintPoint(int num)
	{
		return *point_array[num];
	}
	// x, y값을 입력받아 새로운 점을 생성하는 함수
	void AddPoint();

	// 모든 점들 간의 거리를 출력하는 함수
	void PrintDistance();

	// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수
	// 참고적으로 임의의 두 점을 잇는 직선의 방정식을 y=f(x) = mx + n
	// (x1, y1) 과 (x2, y2) 기준으로 m = (y2 - y1) / (x2 - x1), n = -1 * m * x1 + y1
	// 두 직선의 m(기울기)가 같으면 평행, n(y절편)까지 같으면 동일
	// 평행하지 않는 직선의 수를 t, 한 직선에 대해 평행하지만 동일하지 않는 직선의 수 v
	// 교점 개수 = t * (t - 1) * (v1 + 1) * (v2 + 1) * (v3 + 1) * ... * (vn + 1)
	void PrintNumMeets();

	// 입력된 점 수를 반환하는 함수
	int NumPoints()
	{
		return num_points;
	}

private:
	// 점 100 개를 보관하는 배열.
	Point* point_array[100];
	int num_points;
};

void Geometry::AddPoint() {
	int pos_x, pos_y;
	std::cout << "x값 입력";
	std::cin >> pos_x;
	while (getchar() != '\n');
	std::cout << "y값 입력";
	std::cin >> pos_y;
	while (getchar() != '\n');
	point_array[num_points++] = new Point(pos_x, pos_y);
}

void Geometry::PrintDistance()
{
	for (int i = 0; i < num_points; i++)
	{
		for (int j = 0; j < num_points; j++)
		{
			if (i == j) break;
			std::cout << j + 1 << "번째 점과" << i + 1 << "번째 점의 거리는" << pow(pow(point_array[j]->x - point_array[i]->x, 2) + pow(point_array[j]->y - point_array[i]->y, 2), 0.5) << "입니다" << std::endl;
		}
	}
}

void Geometry::PrintNumMeets()
{
	int numMeet = 1;
	Mxplusn** Mx = new Mxplusn * [num_points];
	for (int i = 0; i < num_points; i++)
		Mx[i] = new Mxplusn[num_points];
	for (int i = 0; i < num_points; i++)
	{
		for (int j = 0; j < num_points; j++)
		{
			if (i >= j) continue;
			Mx[i][j].m = (point_array[i]->y - point_array[j]->y) / (double)(point_array[i]->x - point_array[j]->x);
			Mx[i][j].n = Mx[i][j].m * point_array[i]->x * -1 + point_array[i]->y;
			Mx[i][j].x = 1;//이미 계산된 점을 배제하기 위한 판별값
		}
	}
	int t = 0, u = 0;
	for (int i1 = 0; i1 < num_points; i1++)
	{
		for (int j1 = i1 + 1; j1 < num_points; j1++)
		{
			if (Mx[i1][j1].x == 0) continue;
			int v = 0;
			for (int i2 = i1; i2 < num_points; i2++)
			{
				for (int j2 = i2 + 1; j2 < num_points; j2++)
				{
					if (i1 == i2 && j1 >= j2) continue;
					u++;
					if (Mx[i1][j1].m != Mx[i2][j2].m) t++;
					else
					{
						Mx[i2][j2].x = 0;
						if (Mx[i1][j1].n != Mx[i2][j2].n) v++;
					}
				}
			}
			numMeet *= v + 1;
		}
	}
	numMeet *= t - (num_points * (num_points - 2));
	std::cout << u << "교점의 개수: " << numMeet << std::endl;
}

int main()
{
	Geometry GM;
	int end = 1;
	while (end && GM.NumPoints() < 100)
	{
		int cho;
		std::cout << std::endl;
		std::cout << "사용할 기능 선택" << std::endl;
		std::cout << "벡터 추가:1" << std::endl;
		std::cout << "벡터 출력:2" << std::endl;
		std::cout << "거리 출력:3" << std::endl;
		std::cout << "교점 출력:4" << std::endl;
		std::cin >> cho;
		while (getchar() != '\n');
		switch (cho)
		{
		case 1:
			GM.AddPoint();
			break;
		case 2:
			for (int i = 0; i < GM.NumPoints(); i++)
				std::cout << i + 1 << "번째 벡터의 x: " << GM.PrintPoint(i).x << " y: " << GM.PrintPoint(i).y << std::endl;
			break;
		case 3:
			GM.PrintDistance();
			break;
		case 4:
			GM.PrintNumMeets();
			break;
		default:
			std::cout << "Error" << std::endl;
			break;
		}
	}
	return 0;
}