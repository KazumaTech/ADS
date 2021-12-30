//Frog問題を動的計画法で解く
#include<iostream>
#include<vector>
using namespace std;
const long long INF=1LL<<60; //十分大きい値（2^60）

int main()
{
    int N; cin>>N;
    vector<long long> h(N);
    for(int i=0;i<N;i++) cin>>h[i];

    //配列dpを定義
    vector<long long> dp(N,INF);
    dp[0]=0;

    for(int i=1;i<N;i++){
        if(i==1) dp[i]=abs(h[i]-h[i-1]);
        else dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),
                       dp[i-2]+abs(h[i]-h[i-2]));
    }

    for(int i=0;i<N;i++) cout<<dp[i]<<" ";
    cout<<endl;

    cout<<dp[N-1]<<endl;
}

/*
7
2 9 4 5 1 6 10
0 7 2 3 5 4 8
8
*/