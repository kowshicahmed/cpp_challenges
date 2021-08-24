#include <iostream>
#include <vector>
#include <algorithm>



int main()
{
    std::vector<int> d;
    int no_of_data{};
    int querry{};
    int data_to_search{};
    int data{};
    std::cin >> no_of_data;

    for (int i{}; i < no_of_data; ++i)
    {
        std::cin >> data;
        d.push_back(data);
    }
    std::cin >> querry;
    int it{};
    for (int i{}; i < querry; ++i)
    {
        std::cin >> data_to_search;
        std::vector<int>::iterator low = std::lower_bound(d.begin(), d.end(), data_to_search);
       if (d[low - d.begin()] == data_to_search)
           std::cout << "Yes " << (low - d.begin()+1) << std::endl;
       else
           std::cout << "No " << (low - d.begin()+1) << std::endl;
    }

    return 0;
}