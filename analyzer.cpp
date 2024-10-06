#include <iostream>
#include <string>
#include "StringData.h"

int linear_search(std::vector<std::string> container, std::string str) {
    for (int i = 0; i < container.size(); i++) {
        std::string value = container[i];
        if(value==str) {
            return i;
        }

    }
 return -1;
}

int binary_search(std::vector<std::string> container, std::string str) {
    int low = 0;
    int high = container.size() - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (container[mid] == str) {
            return mid;
        }
        else if (container[mid] < str) {
            low = mid + 1;
        } else {
            high = mid - 1;}
        }
    return -1;
}

int main(){
    std::vector<std::string> data = getStringData();
    std::string words[3] = {"not_here", "mzzzz", "aaaaa"};


    for(std::string test : words) {
        std::cout<<"Linear Search for "<<test<<std::endl;
        std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();
        int result = linear_search(data, test);
        std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
        std::cout<<"Index/Result: "<<result<<" Time taken: "<<end_time-start_time<<" seconds"<<std::endl<<std::endl;
    }
    for(std::string test : words) {
        std::cout<<"Binary Search for "<<test<<std::endl;
        std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();
        int result = binary_search(data, test);
        std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
        std::cout<<"Index/Result: "<<result<<" Time taken: "<<end_time-start_time<<" seconds"<<std::endl<<std::endl;
        }
    }
