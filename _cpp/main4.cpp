#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

/*
6. Туризм
Лёгкая
Горная цепь состоит из отрезков, соединяющих точки на плоскости, каждая из которых находится правее предыдущей (координата x строго возрастает).
Трассой на горной цепи называется маршрут по отрезкам цепи из одной точки в другую. Трассы ориентированы — то есть маршрут может быть как слева направо, так и справа налево.
Подъёмом на трассе называется такой отрезок, на котором высота (координата y) возрастает, а высотой подъёма — разность высот между начальной и конечной точками отрезка.
Вам даны несколько трасс на одной горной цепи. Помогите для каждой трассы определить суммарную высоту подъёмов.

Формат ввода
В первой строке содержится число
N (1≤N≤30000) — количество точек в цепи, задающей горную цепь. Далее в N строках содержатся координаты точек — два целых числа xi и yi​(1≤xi,yi≤30000, xi≤xi+1​).
В следующей строке находится число MM — количество трасс (1≤M≤30000).Далее в M строках содержатся описания трасс. Каждое описание представляет собой два целых числа,
si и fi (1≤si,fi,≤N) — номера точек начала и конца трассы. Начало и конец трассы могут совпадать. Точки нумеруются с единицы.

Формат вывода
Для каждой трассы выведите одно число — суммарную высоту подъемов на данной трассе.

Пример 1
Ввод
7
2 1
4 5
7 4
8 2
9 6
11 3
15 3
1
2 6
Вывод
4
Пример 2
Ввод
6
1 1
3 2
5 6
7 2
10 4
11 1
3
5 6
1 4
4 2
Вывод
0
5
4
*/

int main()
{
    int N; std::cin>>N;
    std::vector<std::pair<long,long>> points(N);
    for(auto& pt: points)
        std::cin>>pt.first>>pt.second;
    int M; std::cin>>M;
    std::vector<std::pair<long,long>> pathes(M);
    for(auto& path: pathes)
    {
        std::cin>>path.first>>path.second;
        path.first -= 1;
        path.second -= 1;
    }
    for(auto& path: pathes)
    {
        double H = 0;
        if (path.first!=path.second)
        {
            int dP = path.first<path.second? 1:-1;
            for (int i=path.first+dP; i!=path.second; i+=dP)
            {
                if (points[i-dP].second<points[i].second)
                    H += points[i].second-prev.second;
                prev = points[i];
            }
        }
        std::cout<<H<<std::endl;
    }

    return 0;
}