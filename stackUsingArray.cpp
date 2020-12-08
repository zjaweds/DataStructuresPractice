#include<iostream>
#define arraySize 100
using namespace std;

template<class stackType>class Stack{
    stackType T[arraySize];
    int tos;
    public:
    Stack();
    void push(stackType data);
    stackType pop();
    stackType peep(int index);
    int sizeOfStack();
};
template<class stackType>stackType Stack<stackType>::peep(int index){
    stackType y;
    y=T[index];
    return y;
}
template<class stackType>stackType Stack<stackType>::pop(){
    stackType x;
    x=T[tos];
    tos--;
    return x;
}
template<class stackType>int Stack<stackType>::sizeOfStack(){
    return tos+1;
}
template<class stackType> Stack<stackType>::Stack(){
    tos=-1;
}
template<class stackType>void Stack<stackType>::push(stackType data){
    tos++;
    T[tos]=data;
}
int main(){
    cout<<"______________Execution Successful____________"<<endl;
    Stack<int> exampleStack;
    exampleStack.push(10);
    exampleStack.push(30);
    exampleStack.push(3);
    exampleStack.push(13);
    cout<<exampleStack.sizeOfStack()<<endl;
    cout<<exampleStack.pop()<<endl;
    cout<<exampleStack.pop()<<endl;
    cout<<exampleStack.peep(2)<<endl;
    return 0;
}