#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

template<class... Args>
double sum(double a, Args... args)
{
	return a + sum(args...);
}

template<>
double sum(double a)
{
	return a;
}
 
template<size_t... I>
double aid(double* arry, index_sequence<I...>)
{
	return sum(arry[I]...);
}

int main()
{
	double arry[] = { 1,5,7,3,8,3,0 };

	cout << aid(arry, make_index_sequence<5>()) << endl;

	system("pause");
	return 0;
}