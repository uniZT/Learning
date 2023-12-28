//
// Created by unizh on 2023/12/28.
//
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    //循环次数是n/2，如果n为奇数，最后在中心位置添加最后一个数即可
    int loop = n / 2;
    int startx = 0, starty = 0; //x是纵坐标，y是横坐标
    int mid = n / 2;            //最后的中间点的位置
    int count = 1;              //从1开始
    int offset = 1;             //偏移量，为了纠正最后在什么地方停下来
    int i, j;                    //i是行号，j是列号
    while (loop--) {
        i = startx;
        j = starty;
        //第i行，每一列遍历，第一个分号前的其实可以不要，因为在上面已经初始化了，但是这样看的更清楚
        //循环内的没什么好说的，就是简单的加1
        //关键是循环条件
        for (j = starty; j < n - offset; j++) {
            result[i][j] = count++;
        }
        //第一个分号的i赋值语句其实可以不要，上面已经赋值过了
        for (i = startx; i < n - offset; i++) {
            result[i][j] = count++;
        }
        for (; j > starty; j--) {
            result[i][j] = count++;
        }
        for (; i > startx; i--) {
            result[i][j] = count++;
        }
        starty++;
        startx++;
        offset++;
    }
    if (n % 2 == 1) {
        result[mid][mid] = count;
    }
    return result;
}