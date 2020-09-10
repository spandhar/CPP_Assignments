//#include <bits/stdc++.h>
#include <unistd.h>
#include <iostream>
#include <array>
#include <vector>

int main()
{
    int k = 9 ;
    std::array<int, 10> ints = {1, 2, 3, 4, 5, 6, 0, 7, 8};

    int pid = fork();
    if(pid < 0)
        exit(0);

     if(pid ==0)
    {
        //child
        std::cout << "number to be searched is : " << k << "\n";
    }
    
    if(pid > 0)
    {
        //parent
        std::any_of(ints.begin(), ints.end(), [k](const auto& itr){
            return (itr == k);
        }) ? std::cout << "found\n" : std::cout << "Not found\n";
    }
   
}


