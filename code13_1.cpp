//グラフ探索の実装 (幅優先探索)
//todo: stack<int> 深さ優先探索
//todo: queue<int> 幅優先探索

#include<iostream>
#include<vector>
using namespace std;
using Graph = vector<vector<int>>;

void search(const Graph &G, int s)
{
    int N=(int)G.size(); //グラフの頂点数

    //データ構造
    vector<bool> seen(N,false); //全頂点を「未訪問」に初期化
    queue<int> todo; //空の状態(深さ優先の場合は stack<int> )

    //初期条件
    seen[s]=true; //s は探索済みとする
    todo.push(s); //todo は s のみを含む状態となる

    //todo が空になるまで探索を行う
    while(!todo.empty()){
        //todo から頂点を取り出す
        int v=todo.front();
        todo.pop();

        //v から辿れる頂点を全て調べる
        for(int x : G[v]){
            //既に発見済みの頂点は探索しない
            if(seen[x]) continue;

            //新たな頂点 x を探索済みとして todo に挿入
            seen[x]=true;
            todo.push(x);
        }
    }
}