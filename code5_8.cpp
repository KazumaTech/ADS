//編集距離を動的計画法を用いて求める
#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<class T> void chmin(T& a,T b)
{
    if(a>b) a=b;
}

const int INF=1<<29; //十分大きな値(2^29)

int main()
{
    string S,T;
    cin>>S>>T;

    //DP テーブル定義
    vector<vector<int> > dp(S.size()+1,vector<int>(T.size()+1,INF));

    //DP 初期条件
    dp[0][0]=0;

    //DP ループ
    for(int i=0;i<=S.size();i++){
        for(int j=0;j<=T.size();j++){
            //変更操作
            if(i>0 && j>0){
                if(S[i-1]==T[j-1]) chmin(dp[i][j],dp[i-1][j-1]);
                else               chmin(dp[i][j],dp[i-1][j-1]+1);
            }
            //削除操作
            if(i>0) chmin(dp[i][j],dp[i-1][j]+1);

            //挿入操作
            if(j>0) chmin(dp[i][j],dp[i][j-1]+1);
        }
    }

    cout<<dp[S.size()][T.size()]<<endl;
}

/*
logistic
algorithm
6
*/