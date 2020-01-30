#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> Ints;

int square(int x)
{
    return x * x;
}

template <typename F, typename T>
vector<T> transform_vec(F f, const vector<T> &xs)
{
    vector<T> ys;
    ys.reserve(xs.size());
    transform(begin(xs), end(xs), back_inserter(ys), f);
    return ys;
}
Ints sqr_transform_vec(Ints xs)
{
    return transform_vec(square, xs);
}

template <typename T>
void cout_vec(const vector<T> &xs)
{
    copy(xs.begin(), xs.end(), std::ostream_iterator<T>(std::cout, " \n"));
}
int main()
{
    Ints xs{0, 1, 2, 3, 4};
    Ints ys;
    std::vector<char> path;
    for (int ch = 'a'; ch <= 'z'; ++ch)
        path.push_back(ch);

    ys.reserve(xs.size());
    ys = sqr_transform_vec(xs);
    cout_vec(ys);
    cout_vec(path);
}