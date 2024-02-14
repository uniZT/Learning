### 万能头文件
```c++
#include<bits/stdc++.h>
```
### vector的初始化
```c++
1.默认初始化，size为0
vector<int> vec; 

2.像数组一样初始化
vector<int> vec = {1,2,3,4,5,6,7};

3.拷贝初始化
vector<int> vec2(vec);  vector<int> vec2  = vec;
或者
vector<int> vec3(vec2.begin()+2, vec2.end()-1);

4.长度为7，默认为0
vector<int> vec4(7);

5.长度为7，全部元素为3
vector<int> vec5(7,3);
```