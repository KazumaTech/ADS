//二分探索法を用いて、「ペア和を最適化する問題」に対する全探索解法を高速化する
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF=20000000;

int main()
{
    int N,K; cin>>N>>K;
    vector<int> a(N),b(N);
    cout<<"配列a : "; for(int i=0;i<N;i++) cin>>a[i];
    cout<<"配列b : "; for(int i=0;i<N;i++) cin>>b[i];

    //暫定最小値を格納
    int min_value=INF;

    sort(b.begin(),b.end());

    //bに無限大を表す変数(INF)を追加する。
    //これを行うことで、iter=b.end() となる可能性を回避する
    b.push_back(INF);

    //aを固定して解く
    for(int i=0;i<N;i++){
        //bの中でK-a[i]以上の範囲での最小値を示すイテレータ
        auto iter=lower_bound(b.begin(),b.end(),K-a[i]);

        //イテレータの示す値を取り出す
        int val=*iter;

        if(a[i]+val < min_value){
            min_value=a[i]+val;
        }
    }

    cout<<min_value<<endl;
}