#include<iostream>
#define stackSize 100 //Not used in this program
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
    typeT peek(int index);  //Returns indexth element from the tos
    bool isEmpty();
    int sizeOfStack();
    bool isFull();
};
template<class typeT>int LinkedListforStack<typeT>::sizeOfStack(){
    int sizeStack=0;
    while(tos){
        sizeStack++;
        tos=tos->nextNode;
    }
    return sizeStack;
}
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
    stackOfChars.push('D');
    cout<<"\n<-------------------Execution Successful------------------>\n"<<endl;
    // cout<<stackOfInts.pop()<<"\t"<<stackOfChars.pop()<<endl;
    // cout<<stackOfInts.pop()<<"\t"<<stackOfChars.pop()<<endl;
    cout<<"Popped integer: "<<stackOfInts.pop()<<endl;
    cout<<"Pooped character: "<<stackOfChars.pop()<<endl;
    cout<<"Peeked integer: "<<stackOfInts.peek(0)<<endl;
    cout<<"Peeked character: "<<stackOfChars.peek(0)<<endl;
    cout<<"Size of stacks: \nStack of Integers: "<<stackOfInts.sizeOfStack()<<"\nStack of Characters: "<<stackOfChars.sizeOfStack()<<endl;
    cout<<"\n<-------------------Execution Successful------------------>\n"<<endl;
    return 0;
}