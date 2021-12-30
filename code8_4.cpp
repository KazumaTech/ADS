//連結リストを挿入操作を用いて構築する
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//連結リストの各ノードを表す構造体
struct Node {
    Node* next; //次がどのノードを指すか
    string name; //ノードに付随する値

    Node(string name_="") : next(NULL),name(name_){ }
};

//番兵を表すノードをグローバル領域に置いておく
Node* nil;

//初期化
void init()
{
    nil = new Node();
    nil->next = nil; //初期状態ではnilがnilを指すようにする
}

//連結リストを出力する
void printList()
{
    Node* cur = nil->next; //先頭から出発
    for(; cur !=nil; cur = cur->next){
        cout<< cur->name << " -> ";
    }
    cout<<endl;
}

//ノードpの直後にノードvを挿入する
//ノードpのデフォルト引数をnilとしておく
//そのためinsert(v)を呼び出す操作は、リストの先頭への挿入を表す
void insert(Node* v, Node* p=nil)
{
    v->next=p->next;
    p->next=v;
}

int main()
{
    //初期化
    init();

    //作りたいノードの名前一覧
    //最後尾のノードから順に挿入することに注意
    vector<string> names={"Yamamoto",
                          "Watanabe",
                          "Ito",
                          "Takahashi",
                          "Suzuki",
                          "Sato"};

    //各ノードを作成して、連結リストの先頭に挿入していく
    for(int i=0;i<(int)names.size();i++){
        //ノードを作成する
        Node* node = new Node(names[i]);

        //作成したノードを連結リストの先頭に挿入する
        insert(node);

        //各ステップの連結リストの様子を出力する
        cout<<"step "<<i<<": ";
        printList();
    }
}

/*
step 0: Yamamoto ->
step 1: Watanabe -> Yamamoto ->
step 2: Ito -> Watanabe -> Yamamoto ->
step 3: Takahashi -> Ito -> Watanabe -> Yamamoto ->
step 4: Suzuki -> Takahashi -> Ito -> Watanabe -> Yamamoto ->
step 5: Sato -> Suzuki -> Takahashi -> Ito -> Watanabe -> Yamamoto ->
*/