#include <iostream>
#include <cstdlib>
#include <utility>
#include <tuple>

using namespace std;

template<typename Fn>
class _mybind;

template<typename Rn, typename... Args>
class _mybind<Rn(*)(Args...)>
{
private:
	Rn(*fn)(Args...);
	tuple<Args...> tp;

	template<size_t... I>
	inline Rn callfunc(index_sequence<I...>)
	{
		return fn(std::get<I>(tp)...);
	}

public:
	_mybind(Rn(*f)(Args...), Args... args) :fn(f), tp(args...) {}

	Rn operator()()
	{
		return callfunc(make_index_sequence<sizeof...(Args)>());
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename Fn, typename... Args>
auto mybind(Fn f, Args... args) -> _mybind<decltype(f)>
{
	return _mybind<decltype(f)>(f, args...);
}
/////////////////// test ///////////////////////////////////////////////////////////////////////////////////////////

double sum(double x, double y, int z)
{
	return x + y + z;
}

int main()
{
	auto f = sum;
	auto my = mybind(sum, 2, 2, 3);

	cout << my() << endl;
	return 0;
}