#include <iostream>
#include <typeinfo>
#include <type_traits>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int a = 3;
int& b = a;
int&& b2 = 4;
int* c = nullptr;
int arr[5] = {4};
const int e = 6;
volatile int g = 5;

const double&& func();
const double bar();

int main()
{
    auto f = add;
    cout << is_same<decltype(func()), const double&&>::value << endl;
    decltype(func()) my = 8.3;
    cout << is_same<decltype(my), const double&&>::value << endl;
    return 0;
}