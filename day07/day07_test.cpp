//
// Created by unizh on 2024/1/2.
//
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    std::unordered_map<int, int> map;
    map[5]++;
    std::cout << "The value of key 5 is: " << map[5] << std::endl;

    map[4];
    std::cout << "The value of key 4 is: " << map[4] << std::endl;
    return 0;
}


