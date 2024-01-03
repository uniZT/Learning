//
// Created by unizh on 2024/1/3.
//
#include<bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
    string sinput;
    string soutput;
    cin >> sinput;
    for(int i = 0; i < sinput.size(); i++){
        if(sinput[i] >= '0' && sinput[i] <= '9'){
            soutput.append("number");
        }
        else{
            soutput.push_back(sinput[i]);
        }
    }
    cout << soutput;
    return 0;
}