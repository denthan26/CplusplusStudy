#include <iostream>
#include <string>
using namespace std;
class Sale_data
{
public:
	//Member attribute
	string serialNumber;
	int number = 0;
	double price = 0.0;

	//Members behavior
	//
};

//string:empty and size

//string:getline----------------------------------------
//输入一行，按下返回键则输出这一行
int main()
{
	string line;
	while (getline(cin, line))
	{
		cout << line << endl;
	}
	return 0;
}



int main2()
{
	Sale_data data1, data2;
	string is;
	string s = "abcdefg";
	//is << s;
	//cout << is<<s;

	cout << "输入1号商品编号，数量，价格" << endl;
	cin >> data1.serialNumber >> data1.number >> data1.price;
	cout << "输入2号商品编号，数量，价格" << endl;
	cin >> data2.serialNumber >> data2.number >> data2.price;
	if (data1.serialNumber == data2.serialNumber)
	{
		cout << data1.number * data1.price + data2.number * data2.price << endl;
		cout << "这两个商品的总价格是" 
			<< data1.number * data1.price + data2.number * data2.price 
			<< endl;
	}
	else
	{
		cout << "错误" << endl;
	}
	return 0;
}
