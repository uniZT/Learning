//
// Created by unizh on 2024/1/6.
//
#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '[' || s[i] == '('||s[i] == '{'){
            st.push(s[i]);
        }
        else if(st.empty()){
            return false;
        }
        else if(s[i] == ']'){
            if(st.top() != '['){
                return false;
            }
            st.pop();
        }
        else if(s[i] == ')'){
            if(st.top() != '('){
                return false;
            }
            st.pop();
        }
        else if(s[i] == '}'){
            if(st.top() != '{'){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s="(}";
    isValid(s);
    return 0;
}