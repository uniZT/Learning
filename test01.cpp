//
// Created by unizh on 2023/12/26.
//
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {

    int h;
    cin >> h;
    int total = h + (h - 1) * 2;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < total; j++){
            if(j < total - (h + 2 * i)){
                cout << " ";
            }
            else{
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}