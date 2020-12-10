#include<iostream>
#define stackSize 100
using namespace std;
template<class typeT>class Node{
    public:
    typeT linkedData;
    Node *nextNode;
};
template<class typeT>class LinkedListforStack{
    Node<typeT>*tos;
    public:
    LinkedListforStack();
    void push(typeT x);
    typeT pop();
    typeT peek(int index);
    bool isEmpty();
    int sizeOfStack();
    bool isFull();
};
template<class typeT>typeT LinkedListforStack<typeT>::peek(int index){
    for(int i=1;i<index;i++){
        tos=tos->nextNode;
    }
    return tos->linkedData;
}
template<class typeT>LinkedListforStack<typeT>::LinkedListforStack(){
    tos=NULL;
}
template<class typeT>void LinkedListforStack<typeT>::push(typeT x){
    Node<typeT> *current;
    current=new Node<typeT>;
    current->linkedData=x;
    current->nextNode=tos;
    tos=current;
}
template<class typeT>typeT LinkedListforStack<typeT>::pop(){
    typeT x;
    Node<typeT> *current;
    current=tos;
    x=tos->linkedData;
    tos=tos->nextNode;
    free(current);
    return x;
}
int main(){
    LinkedListforStack<int> stackOfInts;
    LinkedListforStack<char> stackOfChars;
    stackOfInts.push(10);
    stackOfInts.push(20);
    stackOfInts.push(13);
    stackOfChars.push('A');
    stackOfChars.push('C');
    stackOfChars.push('B');
    cout<<"\n<-------------------Execution Successful------------------>\n"<<endl;
    // cout<<stackOfInts.pop()<<"\t"<<stackOfChars.pop()<<endl;
    // cout<<stackOfInts.pop()<<"\t"<<stackOfChars.pop()<<endl;
    cout<<stackOfInts.pop()<<"\t"<<stackOfChars.pop()<<"\t"<<stackOfChars.peek(0)<<endl;
    cout<<"\n<-------------------Execution Successful------------------>\n"<<endl;
    return 0;
}