#include <iostream>
int main()
{
	int i, & ri = i;
	i = 5;
	ri = 10;
	std::cout << i << ' ' << ri << std::endl;
	//int i = 0, & r1 = i;
	//double d = 0, & r2 = d;
	//if (r2 == 3.14159)
	//	std::cout << 'A' << std::endl;
	//if (r2 == r1)
	//	std::cout << 'B' << std::endl;
	//if (i == r2)
	//	std::cout << 'C' << std::endl;
	//if (r1 == d)
	//	std::cout << 'D' << std::endl;
	//std::cout << "结束" << std::endl;
	/*int& refval4 = 10;
	double dval = 3.15;
	int& refval5 = dval;*/
	/*int i = 1024, i2 = 2048;
	int& r = i, r2 = i2;
	int i3 = 1024, & ri = i3;
	int& r3 = i3, & r4 = i2;*/
	/*int ival = 1024;
	int& refVal = ival;
	refVal = 2;
	int ii = refVal;
	std::cout << ival << ' ' << ii << std::endl;*/
	//int& refVal2;
	/*int i = 100, sum = 0;
	for (int i = 0; i != 10; ++i)
	{
		sum += i;
	}
	std::cout << i << ' ' << sum << std::endl;*/
	return 0;
}
//int i = 42;
//int main()
//{
//	int i = 1000;
//	int j = i;
//	std::cout << j << std::endl;
//	return 0;
//}
//int refused = 42;
//int main()
//{
//	int unique = 0;
//	std::cout << refused << ' ' << unique << std::endl;
//	int refused = 0;
//	std::cout << refused << ' ' << unique << std::endl;
//	std::cout << ::refused << ' ' << unique << std::endl;
//	return 0;
//}
////double selcet(double x, double y);
//std::string global_str;
//int global_int;
//int main()
//{
//	extern int j;
//	extern double p = 3.14;
//	int j;
//	int local_int;
//	std::string local_str;
//	std::cout << local_int << local_str << std::endl;
//	double price = 109.9, count = price * 9;
//	//double ret = selcet(price, count);
//	int units_sold = 0;
//	int units_sold = { 0 };
//	int units_sold{ 0 };
//	int units_sold(0);
//	long double ld = 3.1415926;
//	int a{ ld }, b{ ld };
//	int c(ld), d = ld;
//	int sum = 0, value,
//		unites_old = 0;
//	return 0;
//}
