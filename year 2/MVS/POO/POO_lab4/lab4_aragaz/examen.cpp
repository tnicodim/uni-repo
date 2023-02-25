#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


template <class A>
A suma(A a, A b)
{
	return a + b;
}
template <class B:class A>
B produs(B a, B b)
{
	return a* b;
}
void main()
{
	cout << suma(2, 2) << ' ' << produs(2, 5);
}