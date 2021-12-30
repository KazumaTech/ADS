//グラフを入力として受け取る
#include<iostream>
#include<vector>
using namespace std;
using Graph = vector<vector<int>>;

int main()
{
    int N,M;
    cout<<"頂点数 辺数"<<endl;
    cin>>N>>M;

    //グラフ
    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);

        ///無向グラフの場合は以下を追加
        //G[b].push_back(a);
    }
}

/*
頂点数 辺数
8 12
4 1
4 2
4 6
1 3
1 6
2 5
2 7
6 7
3 0
3 7
7 0
0 5
*/