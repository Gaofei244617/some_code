#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <functional>

using namespace std;

double __sum(double a, double b, double c, double e)
{
    return a + b + c;
}

template<std::size_t... I>
inline double sum(double* array, std::index_sequence<I...>)
{
    return __sum(array[I]...);
}

vector<int> vec;
////////////////////////////////////////////////////////////////////
template<typename Sig>
struct get_ 
{ 
    static const size_t value = 13;
};

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
/////////////////////////////////////////////////////////////////////

class Test 
{
private:
    const int N;
    double* array;

public:
    template<typename... Args>
    Test(double (*func)(Args...)):N(sizeof...(Args))
    {
        array = new double[N]();
    } 

    // template<typename T> 
    // Test(T func):N(get_<decltype(func)>::value)
    // {
    //     array = new double[N]();
    // }

    int getN() const
    {
        return N;
    }  
};

int main()
{
    Test t(__sum);

    //cout << get_<decltype(__sum)*>::value << endl;
    cout << t.getN() << endl;
    
    function<int(int,int)> f = [](int a, int b){return a + b;};

    return 0;
}