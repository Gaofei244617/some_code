#include <iostream>
#include <cstdlib>
#include <typeinfo>

using namespace std;

template<typename Sig>
struct get_ { static const size_t value = 100; };

template<typename R, typename... Args>
struct get_<R(*)(Args...)> 
{
	static const size_t value = sizeof...(Args);
};

template<typename Sig>
size_t get(Sig e)
{
	return get_<Sig>::value;
}

int func(int a, int b, double c) ;

int main()
{
	//cout << typeid(int(*)(int, int, double)).name() << endl;
	cout << "fun的参数个数: " << get(func) << endl;
	cout << "fun的参数个数: " << get_<decltype(func)*>::value << endl;

	system("pause");
	return 0;
}