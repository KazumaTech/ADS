//配列から目的の値を探索する二分探索法
#include<iostream>
#include<vector>
using namespace std;

const int N=8;
const vector<int> a = {3,5,8,10,14,17,21,39};

//目的の値keyの添字を返す（存在する場合は-1）
int binary_search(int key)
{
    int left=0,right=(int)a.size()-1; //配列aの両端
    while(left<=right)
    {
        int mid = left + (right - left)/2;
        if(a[mid] == key) return mid;
        else if(a[mid] > key) right = mid - 1;
        else if(a[mid] < key) left = mid + 1;
    }
    return -1;
}

int main()
{
    cout<<binary_search(10)<<endl;
    cout<<binary_search(3)<<endl;
    cout<<binary_search(39)<<endl;

    cout<<binary_search(-100)<<endl;
    cout<<binary_search(9)<<endl;
    cout<<binary_search(100)<<endl;
}

/*
g++ code6_1.cpp -o code6_1 -std=c++14
./code6_1
3
0
7
-1
-1
-1
*/