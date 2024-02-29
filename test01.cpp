//
// Created by unizh on 2023/12/26.
//
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Number{
    int x;
    int y;
};

bool cmp(Number a, Number b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

Number arr[1001];

int main() {
    char source = 'a';
    source += 1;
    cout << source;
    return 0;
}