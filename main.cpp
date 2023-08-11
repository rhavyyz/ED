#include "vector.hpp"
#include "map.hpp"

#include <iostream>

using namespace std;

int main()
{

    vector<int> vec;


    vec.push_back(13);

    vec[0] = 2;

    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << '\n';
    }

    return 0;
}