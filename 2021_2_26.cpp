#include <iostream>
extern const int bufSize;
void get_size;
void fcn();
int main()
{
	
	extern const int bufSize = fcn();
	int i = 42;
	const int ci = i;
	int j = ci;
	const int bufSize = 512;
	const int i = get_size();
	const int j = 42;
	const int k;
	bufSize = 512;
	int i = 42;
	int* p;
	int*& r = p;
	r = &i;
	*r = 0;
	int i = 1024, * p = &i, & r = i;
	int* p;
	int* p1, * p2;
	int* p1;
	int* p2;
	int ival = 1024;
	int* pi = &ival;
	int** ppi = &pi;
	std::cout << "The value of ival\n"
		<< "direct value: " << ival << '\n'
		<< "indirect value: " << *pi << '\n'
		<< "doubly indirect value: " << **ppi
		<< std::endl;
	int*** pppi = &ppi;
	*(*ppi) = 50;
	std::cout << ival << std::endl;
	*(*(*pppi)) = 48;
	std::cout << ival << std::endl;
	return 0;
}
有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中。
升序
#include <stdio.h>
int main()
{
	int arr[11] = { 1,3,5,7,9,10,25,26,30,35 };
	int i, j, number, temp1, temp2;
	for (i = 0; i < 10; i++)
	{
		printf("%4d", arr[i]);
	}
	printf("请输入你要添得数：>");
	scanf("%d", &number);//8
	if (number > arr[9])
	{
		arr[10] = number;
	}
	else
	{
		for (i = 0; i < 10; i++)
		{
			if (arr[i] > number && arr[i - 1] < number)
			{
				temp1 = arr[i];//arr[i]=9->temp1=9
				arr[i] = number;//arr[i]=8
				for (j = i + 1; j < 11; j++)
				{
					temp2 = arr[j];//arr[j]=10->temp2=10
					arr[j] = temp1;//arr[j]=9
					temp1 = temp2;//temp1=10
				}
				break;
			}
		}
	}
	for (i = 0; i < 11; i++)
		printf("%4d", arr[i]);
	printf("\n");
	return 0;
}
插入一组数
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
				*p = *(p+2);
				*(p+2) = temp;
			}//1<2=3
		}
		else if (temp1 == temp3)
		{
			if (temp2 < temp3)//2<1=3  1与2对调
			{
				int temp = 0;
				temp = *p;//5     255
				*p = *(p+1);//2
				*(p+1) = temp;//5
			}
			else//1=3<2   将2与3对调
			{
				int temp = 0;
				temp = *(p+1);
				*(p+1) = *(p+2);
				*(p+2) = temp;
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
	scanf("%d", &number);//8
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &letin[i]);
	}
	collect(letin);//将插入的数进行排序
	min = letin[0];
	max = letin[2];
	输入的最小值>原数列的最大值
	输入的最大值<原数列的最小值
	直接输出
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
		for (i = 0; i < 10; i++)
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
				break;
			}
			
			
			
		}
		
		;
		for (i = 0; i < 10; i++)
		{
			//无序
			
			int newletin[3], m, n;
			count = 0;
			
			for (j = 0; j < 3; j++)//遍历arr与letin的值
			{// 1,3,5,7,9,10,25,26,30,35          4 8 11
				letin[j];
				arr[i];
				if (arr[i] < letin[j])//寻找letin存在的位置
				{
					newletin[count] = i;
					count++;
					break;//找到一个结束循环
					//if (count == 3)
						//break;
				}
				if (count == 3)
				{
					int a, b, c;
					int newarr[13];
					a = newletin[0];//1    1,3,  4     5,7     8     ,9,10   11  ,25,26,30,35  
					b = newletin[1];//3    0 1   2     3 4     5      6   7   8    9 10 11 12
					c = newletin[2];//5
					for (m = 0; m <= a; m++)
					{
						newarr[m] = arr[m];
					}
					newarr[a + 1] = letin[0];
					for (m = a + 2; m <= b; m++)
					{//      3        3
						newarr[m] = arr[m];
					}
					newarr[b + 1] = letin[1];
					for (m = b + 2; m <= c; m++)
					{
						newarr[m] = arr[m];
					}
					newarr[c + 1] = letin[2];
					for (m = c + 2; m < 13; m++)
					{
						newarr[m] = arr[m];
					}
					for (n = 0; n < 13; n++)
						arr[n] = newarr[n];
					goto again;
				}

			}
			

			
			
		}
	}

	
again:
	for (i = 0; i < 13; i++)
		printf("%d ", arr[i]);
	return 0;

	if (number > arr[9])
	{
		arr[10] = number;
	}
	else
	{
		for (i = 0; i < 10; i++)
		{
			if (arr[i] > number && arr[i - 1] < number)
			{
				temp1 = arr[i];//arr[i]=9->temp1=9
				arr[i] = number;//arr[i]=8
				for (j = i + 1; j < 11; j++)
				{
					temp2 = arr[j];//arr[j]=10->temp2=10
					arr[j] = temp1;//arr[j]=9
					temp1 = temp2;//temp1=10
				}
				break;
			}
		}
	}
	for (i = 0; i < 11; i++)
		printf("%4d", arr[i]);
	printf("\n");
}
