#include <iostream>
#include <string>
using namespace std;

//
//upgrade-class
class upgradeGetline
{
public:
	//menber attribute
	string name;
	char sex;
	int age;
	//member behavior
	void printInformation()
	{
		cout << name << ' ' << sex << ' ' << age << endl;
		//cout << age << endl;
	}
};

//string:getline----------------------------------------------
//输入一行，按下返回键则输出这一行
int main()
{
	/*
	string line;
	while (getline(cin, line))                //getline
	{
		cout << line << endl;
	}*/
	//upgrade
	//创建一个类，将输入的值存在类里，然后输出
	upgradeGetline u1[11];
	
	for (int i = 0; i < 11; i++)//初始化
	{
		u1[i].name = "abcd";
		u1[i].sex = ' ';
		u1[i].age = 0;
	}
	int j = 0;
	do
	{
		cout << "请输入姓名:";
		cin >> u1[j].name;
		//if(u1[j].name.compare(' '))
		if (strcmp(u1[j].name.c_str(), u1[j + 1].name.c_str()) == 0)
			break;
		else
		{
			cout << "请输入性别:";
			cin >> u1[j].sex;
			cout << "请输入年龄:";
			cin >> u1[j].age;
			cout << "计数 " << j + 1;
			cout << endl;
			j++;
		}
		
	} while (j<10);
	//for (int i = 0; i < 10; i++)
	//{
	//	
		//cout << "请输入姓名:";
		//cin >> u1[i].name;
		//cout << "请输入性别:";
		//cin >> u1[i].sex;
		//cout << "请输入年龄:";
		//cin >> u1[i].age;
		//cout << "计数 " << i + 1;
		//cout << endl;
		//if (u1[i].age == 0)
		//	break;
		//else
		//	continue;
	//	
	//}
	for (int i = 0; i < 10; i++)
	{
		u1[i].printInformation();
		if (u1[i+1].age == 0)
			break;
		else
			continue;
	}
	return 0;
}
//------------------------------------------------------------
