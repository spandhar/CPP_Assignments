//#include <bits/stdc++.h>
#include <unistd.h>
#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <algorithm>

int main()
{
    std::array<int, 3> first_ints {};
    std::generate(first_ints.begin(), first_ints.end(), []() { 
        return std::rand() * 1000;
    });
    
    //std::cout << "";
    std::for_each(first_ints.begin(), first_ints.end(), [](const auto& i)
    {
        std::cout << i << " ";
    });

    std::sort(first_ints.begin(), first_ints.end());

    std::cout << "mid = " << first_ints[1] << "\n";


}


