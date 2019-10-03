#include <iostream>
#include <vector>

using namespace std;

template<class T, std::size_t N = 100>
struct Test;

template<class T, std::size_t N>
struct Test<vector<T>, N>
{
    std::size_t n;
    vector<T> vec;
    Test():n(N){}
};

int main()
{
    Test<vector<double>, 33> t;

    cout << t.n << endl;
    return 0;
}