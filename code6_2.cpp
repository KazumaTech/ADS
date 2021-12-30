//一般化した二分探索法の基本形
#include<iostream>
using namespace std;

//xが条件を満たすか
bool P(int x)
{

}

//P(x) = true となる最小の整数xを返す
int binary_search()
{
    int left,right; //P(left)=false , P(right)=true となるように
    while(1 < right - left )
    {
        int mid = left + (right - left)/2;
        if(P(mid)) right = mid;
        else left = mid;
    }
    return right;
}