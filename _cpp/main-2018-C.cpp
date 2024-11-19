#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <cassert>
#include <functional>
#include <fstream>

long walk(int index, int E, const std::vector<int>& A)
{
    long cur = 0;
    while(index<A.size() && E>2)
    {
        long dE = A[index]*(index+1);
        if (dE+2<=E)
        {
            auto w1 = A[index]+(E-dE-2>2?walk(index+1, E-dE-2, A):0);
            cur = std::max(cur, w1);
        }
        index++;
        E-=2;
    }
    return cur;
}

void read(int& E, std::vector<int>& A)
{
    int N; std::cin>>N>>E;
    std::vector<int> A(N);  
    for(auto& a: A)
        std::cin>>a;
}

int main()
{
    std::vector<int> A;
    int N,E; std::cin>>N>>E;
    std::vector<int> A(N);  
    for(auto& a: A)
        std::cin>>a;

    std::cout<<walk(0, E, A);

    return 0;
}
