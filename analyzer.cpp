#include <iostream>
#include "StringData.h"
#include <string>

int linear_search(std::vector<std::string> arr, std::string element)
{
    int size = arr.size()-1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }

    return -1;
}

int binary_search(std::vector<std::string> bin_arr, std::string bin_element)
{
    int low = 0;
    int high = bin_arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low)/ 2;
        if (bin_arr[mid] == bin_element)
        {
            return mid;
        }
        else if (bin_arr[mid] < bin_element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    std::vector<std::string> stringcontainer = getStringData();
    
    std::chrono::time_point<std::chrono::system_clock> initial = std::chrono::system_clock::now();
    int linear_index = linear_search(stringcontainer, "not_here");
    std::chrono::time_point<std::chrono::system_clock> final = std::chrono::system_clock::now();
    std::cout<<"Time it took for a linear search of not_here: "<<final-initial<<" and its index is "<< linear_index<<std::endl;

    initial = std::chrono::system_clock::now();
    int binary_index = binary_search(stringcontainer, "not_here");
    final = std::chrono::system_clock::now();
    std::cout<<"Time it took for a binary search of not_here: "<<final-initial<<" and its index is "<< binary_index<<std::endl;

    initial = std::chrono::system_clock::now();
    linear_index = linear_search(stringcontainer, "mzzzz");
    final = std::chrono::system_clock::now();
    std::cout<<"Time it took for a linear search of mzzzz: "<<final-initial<<" and its index is "<< linear_index<<std::endl;

    initial = std::chrono::system_clock::now();
    binary_index = binary_search(stringcontainer, "mzzzz");
    final = std::chrono::system_clock::now();
    std::cout<<"Time it took for a binary search of mzzzz: "<<final-initial<<" and its index is "<< binary_index<<std::endl;

    initial = std::chrono::system_clock::now();
    linear_index = linear_search(stringcontainer, "aaaaa");
    final = std::chrono::system_clock::now();
    std::cout<<"Time it took for a linear search of aaaaa: "<<final-initial<<" and its index is "<< linear_index<<std::endl;

    initial = std::chrono::system_clock::now();
    binary_index = binary_search(stringcontainer, "aaaaa");
    final = std::chrono::system_clock::now();
    std::cout<<"Time it took for a binary search of aaaaa: "<<final-initial<<" and its index is "<< binary_index<<std::endl;

    
    return 0;
}
