#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; x++)
	{
		for (int y = -999; y <= 999; y++)
		{
			if ((a * x + b * y == c) && (d * x + e * y == f))
			{
				cout << x << " " << y;
				return 0;
			}
		}
	}

	/*
	
	int nums[6];
	for (int i = 0; i < 6; i++)
	{
		int num;
		cin >> num;
		nums[i] = num;
	}

		1) adx + bdy = cd      // ax + by = c 식에 d 곱하기
	-	2) adx + aey = af	   // dx + ey = f 식에 a 곱하기
	-------------------------
		   (bd - ae)y = cd - af
			-> y = (cd - af) / (bd - ae)


	int denominator = (nums[1] * nums[3] - nums[0] * nums[4]);
	int y = ((nums[2] * nums[3]) - (nums[0] * nums[5])) / denominator;

	x = (c - by) / a
		int x = (nums[2] - nums[1] * y) / nums[0];

	cout << x << " " << y;
	return 0;
	*/
}