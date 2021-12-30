//部分和問題を再起関数を用いる全探索で解く
#include<iostream>
#include<vector>
using namespace std;

bool func(int i,int w,const vector<int> &a)
{
    //ベースケース
    if(i==0){
        if(w==0) return true;
        else return false;
    }

    //a[i-1]を選ばない場合
    if(func(i-1,w,a)) return true;

    //a[i-1]を選ぶ場合
    if(func(i-1,w-a[i-1],a)) return true;

    return false;
}

int main()
{
    int N,W; // N:配列のサイズ,W:対象の部分和の値
    cout<<"サイズ N:";cin>>N;
    cout<<"部分和 W:";cin>>W;
    cout<<"配列a   :";
    vector<int> a(N);
    for(int i=0;i<N;i++) cin>>a[i];

    //再帰的に解く
    if(func(N,W,a)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

/*
サイズ N:4
部分和 W:14
配列a   :3 2 6 5
Yes
*/