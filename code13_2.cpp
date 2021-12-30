//再帰関数を用いる深さ優先探索の実装の基本形
#include<iostream>
#include<vector>
using namespace std;
using Graph = vector<vector<int>>;

//深さ優先探索
vector<bool> seen;
void DFS(const Graph &G, int v)
{
    seen[v] = true; //v を訪問済みにする

    //v から行ける各頂点 next_v について
    for(auto next_v : G[v]){
        if(seen[next_v]) continue;
        DFS(G, next_v); //再帰的に探索
    }
}

int main()
{
    int N,M;
    cin >> N >> M;

    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    //探索
    seen.assign(N,false);
    for(int v=0;v<N;v++){
        if(seen[v]) continue;
        DFS(G, v);
    }
}