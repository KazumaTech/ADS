//キューの実装
#include<iostream>
#include<vector>
using namespace std;
const int MAX=100000; //キュー配列の最大サイズ

int qu[MAX];
int tail=0,head=0;

void init(){
    head=tail=0;
}

bool isEmpty(){
    return (head==tail);
}

bool isFull(){
    return (head==(tail+1)%MAX);
}

void enqueue(int x){
    if(isFull()){
        cout<<"Error: Queue is full."<<endl;
        return;
    }
    qu[tail]=x;
    tail++;
    if(tail==MAX) tail=0;
}

int dequeue(){
    if(isEmpty()){
        cout<<"Error: Queue is empty."<<endl;
        return -1;
    }
    int res=qu[head];
    head++;
    if(head==MAX) head=0;
    return res;
}

int main()
{
    init();

    enqueue(3); //キューに3を挿入する{}->{3}
    enqueue(5); //キューに5を挿入する{3}->{3,5}
    enqueue(7); //キューに7を挿入する{3,5}->{3,5,7}

    cout<<dequeue()<<endl; //{3,5,7}->{5,7}で3を出力
    cout<<dequeue()<<endl; //{5,7}->{7}で5を出力

    enqueue(9); //キューに9を挿入する{7}->{7,9}
}
/*
3
5
*/