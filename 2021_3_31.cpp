#pragma once
#include <iostream>
using namespace std;
#ifndef _COMPLEX_
#define _COMPLEX_


//复数
class complex 
{
public:
	//构造函数
	complex(double r=0,double i=0)
		:re(r),im(i)
	{ }
	double real()
		const
	{
		return re;
	}
	double imag()
		const
	{
		return im;
	}
private:
	double re, im;

};


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
#endif;
