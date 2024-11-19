#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

/*
https://coderun.yandex.ru/problem/nop-with-response-recovery/description

6. НОП с восстановлением ответа 
Даны две последовательности, требуется найти и вывести их наибольшую общую подпоследовательность.

Последовательность x называется подпоследовательностью последовательности y, если x получается из 
y удалением нескольких (возможно, нуля или всех) элементов. Наибольшая общая подпоследовательность - 
последовательность наибольшей длины, которая является подпоследовательностью обеих последовательностей.

Формат ввода
В первой строке входных данных содержится число N – длина первой последовательности (1 ≤ N ≤ 1000). Во второй строке заданы 
члены первой последовательности (через пробел) – целые числа, не превосходящие 10000 по модулю.
В третьей строке записано число M – длина второй последовательности (1 ≤ M ≤ 1000). В четвертой строке задаются члены второй 
последовательности (через пробел) – целые числа, не превосходящие 10000 по модулю.

Формат вывода
Требуется вывести наибольшую общую подпоследовательность данных последовательностей, через пробел. Если таких подпоследовательностей несколько, то можно вывести любую.

Примечание
В примере 2 существует сразу три наибольшие общие подпоследовательности.
1) 1
2) 2
3) 3
Любая из них будет правильным ответом.

Пример 1
Ввод
3
1 2 3
3
2 3 1
Вывод
2 3 
Пример 2
Ввод
3
1 2 3
3
3 2 1
Вывод
1 
*/

int main() 
{
    int N; std::cin>>N;
    std::vector<int> a(N);
    for(auto& num: a)
        std::cin>>num;
    int M; std::cin>>M;
    std::vector<int> b(M);
    for(auto& num: b)
        std::cin>>num;
        
    int dp[1000][1000] = {a[0]==b[0]? 1:0};
    for(int j=1; j<M; ++j)
        dp[0][j] = a[0]==b[j]? 1 : dp[0][j-1];

    for(int i=1; i<N; ++i)
    {
        dp[i][0] = a[i]==b[0]? 1 : dp[i-1][0];
        for(int j=1; j<M; ++j)
        {
            dp[i][j] = a[i]==b[j]? 1 + dp[i-1][j-1] : std::max(dp[i][j-1], dp[i-1][j]);
        }
    }

    auto len = dp[N-1][M-1];
    std::vector<int> result(len);
    
    for(int i=N-1,j=M-1,l=len-1; i>=0 && j>=0 && l>=0 && l>=0; )
    {
        if (a[i]==b[j])
        {
            result[l--] = a[i];
            --i; --j;
            continue;
        }
        if (j==0 || (i>0 && dp[i-1][j]>dp[i][j-1]))
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    for(int i=0; i<result.size(); ++i)
    {
        std::cout<<result[i]<<" ";
    }
    std::cout<<std::endl;

	return 0;
}