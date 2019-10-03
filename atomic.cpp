#include <iostream>
#include <atomic>

using namespace std;

int main()
{
    atomic<int> my;
    my = 5;

    cout << my + 4 << endl;
    return 0;
}