#include <iostream>
using namespace std;

void testA(int* A)
{
	*A = 20;
}

int* testB(int* B)
{
	*B = 30;
	return B;
}

int main(int argc, char* argv[])
{
	int* a = NULL;
	*a = 10;
	cout << "1. *a:" << *a << "\ta:" << a << endl;

	testA(a);
	cout << "2. *a:" << *a << "\ta:" << a << endl;

	int * b = testB(a);
	cout << "3. *a:" << *a << "\ta:" << a << endl;
	cout << "4. *b:" << *b << "\tb:" << b << endl;

	return 0;
}