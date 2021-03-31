#include <iostream>
using namespace std;

class studentScore
{
public:
	//member attribute
	int chineseScore;
	int mathScore;
	int englishScore;
	//member behavior
	void determinetheScore()
	{
		cout << "您的语文成绩：";
		if (chineseScore >= 60)
			cout << "及格" << endl;
		else
			cout << "不及格" << endl;
		cout << "您的数学成绩：";
		if (mathScore >= 60)
			cout << "及格" << endl;
		else
			cout << "不及格" << endl;
		cout << "您的英语成绩：";
		if (englishScore >= 60)
			cout << "及格" << endl;
		else
			cout << "不及格" << endl;
	}
};
int main()
{
	/*
	cout << "hehe" << endl;
	//99乘法表
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i << '*' << j << '=' << i * j<<'\t';
		}
		cout << '\n';
	}
	*/
	//复数
	//猜数字
	studentScore s1;
	s1.chineseScore = 60;
	s1.englishScore = 59;
	s1.mathScore = 120;
	s1.determinetheScore();
	//
	studentScore s2;
	//cout<<"您的"
	cin >> s2.chineseScore;
	return 0;
}
