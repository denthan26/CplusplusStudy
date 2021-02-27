//C++
//
#include <iostream>
int main()
{
	const double pi = 3.14;
	const double* cptr = &pi;
	double dval = 3.14;
	cptr = &dval;
	dval = 3.1415;
	std::cout << pi << ' '
		<< dval << ' '
		<< *cptr << std::endl;
	const double pi = 3.14;
	double* ptr = &pi;
	const double* cptr = &pi;
	*cptr = 42;
	int i = 42;
	int& r1 = i;
	const int& r2 = i;
	r1 = 0;
	std::cout << i << ' ' << r1 << ' ' << r2 << std::endl;
	const int temp = dval;
	const int& ri = temp;
	int i = 42;
	const int& r1 = i;
	const int& r2 = 42;
	const int& r1 * 2;
	int& r4 = r1 * 2;
	const int ci = 1024;
	const int& r1 = ci;
	r1 = 42;
	int& r2 = ci;
	return 0;
}
#include <stdio.h>
void collect(int* p);
void collect(int* p)
{
	int temp1, temp2, temp3;
	int arr[3];//用来存放收集的数
	temp1 = *p;
	temp2 = *(p + 1);
	temp3 = *(p + 2);
	if (temp1 == temp2 && temp2 == temp3)
		;
	else if (temp1 == temp2 || temp1 == temp3 || temp2 == temp3)
	{
		if (temp1 == temp2)//如果1、2数相等，比较3数与1数
		{
			if (temp1 < temp3)
				;//输出1<2<3
			else//1>3  1=2>3 将1与3对调
			{
				int temp = 0;
				temp = *p;
				*p = *(p + 2);
				*(p + 2) = temp;
			}//1<2=3
		}
		else if (temp1 == temp3)
		{
			if (temp2 < temp3)//2<1=3  1与2对调
			{
				int temp = 0;
				temp = *p;//5     255
				*p = *(p + 1);//2
				*(p + 1) = temp;//5
			}
			else//1=3<2   将2与3对调
			{
				int temp = 0;
				temp = *(p + 1);
				*(p + 1) = *(p + 2);
				*(p + 2) = temp;
			}
		}
		else//2=3
		{
			if (temp1 < temp3)
				;//1<2=3  
			else//2=3<1   将1与3对调
			{
				int temp = 0;
				temp = *p;
				*p = *(p + 2);
				*(p + 2) = temp;
			}
		}

	}
	else
	{
		if (temp1 > temp2 && temp1 > temp3)
		{
			if (temp2 > temp3)//3<2<1  1 3调换
			{
				int temp = 0;
				temp = *p;
				*p = *(p + 2);
				*(p + 2) = temp;
			}
			else//2<3<1       
			{
				*p = temp2;
				*(p + 1) = temp3;
				*(p + 2) = temp1;
			}
		}
		else if (temp2 > temp1 && temp2 > temp3)
		{
			if (temp1 > temp3)//3<1<2
			{
				*p = temp3;
				*(p + 1) = temp1;
				*(p + 2) = temp2;
			}
			else//1<3<2   2  3对调
			{
				int temp = 0;
				temp = *(p + 1);
				*(p + 1) = *(p + 2);
				*(p + 2) = temp;
			}
		}
		else//3最大
		{
			if (temp1 > temp2)//2<1<3
			{
				*p = temp2;
				*(p + 1) = temp1;
			}
			else//1<2<3
				;
		}
	}
}
int main()
{
	int arr[13] = { 1,3,5,7,9,10,25,26,30,35 };
	int i, j, min, max, count;
	int letin[3];

	for (i = 0; i < 10; i++)
	{
		printf("%4d", arr[i]);
	}
	printf("请输入你要添得3个数：>");
	//scanf("%d", &number);//8
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &letin[i]);
	}
	collect(letin);//将插入的数进行排序
	min = letin[0];
	max = letin[2];
	//输入的最小值>原数列的最大值
	//输入的最大值<原数列的最小值
	//直接输出
	if (min > 35 || min == 35)
	{
		arr[10] = letin[0];
		arr[11] = letin[1];
		arr[12] = letin[2];
	}
	else if (max < 1)//先定义一个新数组接收，在将arr重置
	{
		int newarr[13];
		for (i = 0; i < 3; i++)
		{
			newarr[i] = letin[i];
		}
		for (j = 3; j < 13; j++)
		{
			newarr[j] = arr[j - 3];
		}
		for (i = 0; i < 13; i++)
		{
			arr[i] = newarr[i];
		}
	}
	else//分两种情况：第一种letin3个数在arr中两个数之间；第二种无序
	{
		int newletin[3], m, n;
		int newarr[13];
		i = 0;
		while ( i < 10)
		{

			if (arr[i]<min && arr[i + 1]>max)//arr[i]<min<max<arr[i+1]
			{//1 3 5 7 9 10 25       11 12 13(9)  ,26,30,35
				int newarr[13], k, m, n;
				for (j = 0; j <= i; j++)
				{
					newarr[j] = arr[j];
				}
				for (j = i + 1; j <= i + 3; j++)
				{//7     6  7                    7-7 7-6 7-5
					newarr[j] = letin[j - i - 1];//7  0
				}
				for (j = i + 4; j < 13; j++)
				{//      10          7
					newarr[j] = arr[j - 3];//26
				}
				for (n = 0; n < 13; n++)
				{
					arr[n] = newarr[n];

				}
				//break;
			}
			i++;
		}
		count = 0;
		for (j = 0; j < 3; j++)//无序
		{
			for (i = 0; i < 10; i++)
			{//1,3,5,7,9,10,25,26,30,35       4 8 11
				if (arr[i] > letin[j])
				{
					newletin[j] = i;//2  4  6
					break;
				}
			}         //  0,1,2,3,4,5,6, 7, 8, 9,10,11,12  
		}//               1,3,4,5,7,8,9,10,11,25,26,30,35       
		for (m = 0; m < newletin[0]; m++)//[0,2)
		{
			newarr[m] = arr[m];//0 1->1 3                                                         1  3
		}
		newarr[newletin[0]] = letin[0];//  2  ///////////////////////////////////////////////           4
		for (m = newletin[0]+1; m <= newletin[1]; m++)//[3,4)
		{/////////[3,4]     2,3
			newarr[m] = arr[m-1];//1,3,5,7,9,10,25,26,30,35
		}                        //0,1,2,3,4, 5, 6, 7, 8, 9
		newarr[newletin[1]+1] = letin[1];//5   8
		for (m = newletin[1]+2; m <= newletin[2]+1; m++)//[5,6)
		{///////m=6  m=7
			newarr[m] = arr[m-2];
		}
		newarr[newletin[2]+2] = letin[2];//8
		for (m = newletin[2]+3; m < 13; m++)//[7,13)
		{///m=9 m<13
			newarr[m] = arr[m-3];
		}
		//newarr存有全部元素
		for (i = 0; i < 13; i++)
			arr[i] = newarr[i];
	}
	for (i = 0; i < 13; i++)
		printf("%d ", arr[i]);
	return 0;


}


纸牌游戏–小猫钓鱼
#include <stdio.h>
#include <stdlib.h>
struct queue {
	int head;
	int tail;
	int data[1000];
};
struct stack {
	int top;
	int data[10];
};
int main()
{
	int i, t;
	struct queue q1, q2;
	struct stack s;
	int book[10];

	q1.head = 1; q1.tail = 1;
	q2.head = 1; q2.tail = 1;

	s.top = 0;
	for (i = 1; i <= 9; i++)
		book[i] = 0;

	for (i = 1; i <= 6; i++) {
		scanf("%d", &q1.data[q1.tail]);
		q1.tail++;
	}
	for (i = 1; i <= 6; i++) {
		scanf("%d", &q2.data[q2.tail]);
		q2.tail++;
	}
	while (q1.head < q1.tail && q2.head < q2.tail)
	{
		t = q1.data[q1.head];
		if (book[t] == 0) {
			q1.head++;//q1出牌，即出队列，头指针+1
			s.top++;//桌面上的牌为栈，仅有头指针操作 
			s.data[s.top] = t;
			book[t] = 1;
		}
		else {
			q1.head++;
			q1.data[q1.tail] = t;
			q1.tail++;
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--;
			}
		}
		t = q2.data[q2.head];
		if (book[t] == 0)
		{
			q2.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		}
		else
		{
			q2.head++;
			q2.data[q2.tail] = t;
			q2.tail++;
			while (s.data[s.top] != t)
			{
				q2.data[q2.tail] = s.data[s.top];
				book[s.data[s.top]] = 0;
				q2.tail++;
				s.top--;
			}
		}
	}
	if (q2.head == q2.tail)
	{
		printf("q1 win\n");
		for (i = q1.head; i < q1.tail; i++)//tail始终指向结尾的下一个位置
			printf("%d ", q1.data[i]);
	}
	else
	{
		printf("q2 win\n");
		for (i = q2.head; i < q2.tail; i++)
			printf("%d ", q2.data[i]);
	}
	return 0;
}

