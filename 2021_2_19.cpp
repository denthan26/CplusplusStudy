//#include <iostream>
//int main()
//{
//	std::cout << "Enter two numbers:" << std::endl;
//	int v1, v2;
//	std::cin >> v1 >> v2;
//	std::cout << "The sum of " << v1;
//	          << " and " << v2;
//			  << " is " << v1 + v2;
//			  << std::endl;
//	/*std::cout << "The sum of" << v1 << " and " << v2 
//		  << " is " << v1 + v2 << std::endl;*/
//
//	return 0;
//}
//#include <iostream>
//int main()
//{
//	std::cout << "Hello,world!!!" << std::endl;
//	return 0;
//}
//#include <iostream>
//int main()
//{
//	int sum = 0, val = 1;
//	while (val <= 10)
//	{
//		sum += val;
//		val++;
//	}
//	std::cout << "1+2+3+4+5+6+7+8+9+10=";
//	std::cout << sum << std::endl;
//	return 0;
//}
//#include <iostream>
//int main()
//{
//	int a, b, up, low;
//	std::cout << "请输入两个值：>";
//	std::cin >> a >> b;
//	if (a > b)
//	{
//		up = a;
//		low = b;
//	}
//	else
//	{
//		up = b;
//		low = a;
//	}
//	int sum = 0;
//	for (int i = low; i <= up; ++i)
//	{
//		sum += i;
//	}
//	std::cout << "这两个值有小到大之后之间的和是" << sum << std::endl;
//	return 0;
//}
#include <iostream>
int main()
{
	
	int sum = 0, value;
	//std::cout << "请输入你要求和的数";
	while (std::cin >> value)
	{
		sum += value;
	}
	std::cout << "这些数的和是 " << sum << std::endl;
	return 0;
}
