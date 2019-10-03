#include <iostream>

using namespace std;

template<size_t... I>
struct index_seq{};

template<size_t N, size_t... I>
struct make_index_seq:public make_index_seq<N-1, N-1, I...>{};

template<size_t... I>
struct make_index_seq<0, I...>:public index_seq<I...>{}; 

//////////////////////////////////////////////////////////////////////
double sum(double x, double y, double z)
{
    return x + y + z;
}

template<size_t... I>
double call(double* arry, index_seq<I...>)
{
    return sum(arry[I]...);
}
////////////////////////////////////////////////////////////////////

int main()
{
    double arry[] = {1,2,3,4,5,6,7};
    cout << call(arry, make_index_seq<3>()) << endl;
    return 0;
}