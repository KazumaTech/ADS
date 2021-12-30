//重み付きグラフの実装
#include<iostream>
#include<vector>
using namespace std;

struct Edge {
    int to; //隣接頂点番号
    long long w; //重み
    Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main()
{
    int N,M; cin>>N>>M;

    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b,w));
    }
}