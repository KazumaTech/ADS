//スタックの実装
#include<iostream>
#include<vector>
using namespace std;
const int MAX=100000; //スタック配列の最大サイズ

int st[MAX]; //スタック配列
int top=0; //スタックの先頭を表す添字（※要素数も同時に表している）

//スタックを初期化
void init(){
    top=0;
}

//スタックが空か判定
bool isEmpty(){
    return (top == 0);
}

//スタックが満杯か判定
bool isFull(){
    return (top == MAX);
}

//push
void push(int x){
    if(isFull()){
        cout<<"Error: Stack is full."<<endl;
        return;
    }
    st[top]=x;
    top++;
}

//pop
int pop(){
    if(isEmpty()){
        cout<<"Error: Stack is empty."<<endl;
        return -1;
    }
    top--;
    return st[top];
}

int main()
{
    //スタックを初期化
    init();

    push(3); //{}->{3}
    push(5); //{3}->{3,5}
    push(7); //{3,5}->{3,5,7}

    cout<<pop()<<endl; //{3,5,7}->{3,5} で7を出力
    cout<<pop()<<endl; //{3,5}->{3} で5を出力

    push(9); //{3}->{3,9}
}

/*
7
5
*/