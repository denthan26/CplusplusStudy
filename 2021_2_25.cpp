#include <iostream>
#include <cstdlib>
int main()
{
	int i = 1024, j = 103;
	int* pi = &i;
	*pi = 102;
	std::cout << i;
	std::cout << '\n';
	int *pj = nullptr;
	pj = &j;
	*pj = 201;
	std::cout << j;
	//double obj = 3.14, * pd = &obj;
	//void* pv = &obj;
	//pv = pd;
	//int ival = 1024;
	//int* pi = 0;
	//int* pi2 = &ival;
	//if(pi)
	//	//
	//if(pi2)
	//	//

	//int i = 42;
	//int* pi = 0;
	//int* pi2 = &i;
	//int* pi3;

	//pi3 = pi2;
	//pi2 = 0;
	//int* p1 = nullptr;
	//int* p2 = 0;
	//int* p3 = NULL;
	/*int ival = 42;
	int* p = &ival;
	std::cout << *p;*/
	/*int* ip1, * ip2;
	double dp, * dp2;
	int ival = 42;
	int* p = &ival;*/
	//double dval;
	//double* pd = &dval;

	//int* pi = pd;
	//pi = &dval;
	return 0;
}
