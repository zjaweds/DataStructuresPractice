#include<iostream>

using namespace std;

template<class typeT> class Node{
    public:
    typeT linkedData;
    Node *nextNode;
};

template<class T> class LinkedList{
    Node<T> *first;
    public:
    LinkedList();
    void createLinkedList(int n);
    void displayLinkedList();
    LinkedList<T>* deleteNode(T x);
    int sizeOfLinkedList();
};
template<class T>int LinkedList<T>::sizeOfLinkedList(){
    int i=1;
    Node<T> *cur;
    cur=first;
    while(cur->nextNode!=NULL){
        i++;
        cur=cur->nextNode;
    }
    return i;
}
template<class T>LinkedList<T>* LinkedList<T>::deleteNode(T x){
    Node<T> *cur,*pre;
    cur=this->first;
    pre=first;
    // cout<<"\n"<<cur->linkedData<<" : "<<first->linkedData<<"\n"<<endl;
    for(int i=0;i<this->sizeOfLinkedList();i++){
        if(cur->linkedData==x){
                if(cur==first){
                    first=cur->nextNode;
                    break;
                }
                cur=cur->nextNode;
                pre->nextNode=cur;
                // cout<<"\n"<<i<<"\n"<<endl;
                break;    
            }
        pre=cur;
        cur=cur->nextNode;
    }
    return this;
}
template<class T>void LinkedList<T>::displayLinkedList(){
    Node<T> *cur;
    cur=first;
    while (cur!=NULL)
    {
        cout<<cur->linkedData<<endl;
        cur=cur->nextNode;
    }
}
template<class T>LinkedList<T>:: LinkedList(){
    first=NULL;
}
template<class T>void LinkedList<T>::createLinkedList(int n){
    Node<T> *current;
    for(int i=1;i<=n;i++){
        if(i==1){
            current=first=new Node<T>;
        }
        else
        {
            current->nextNode=new Node<T>;
            current=current->nextNode;
        }
        cout<<"Enter data: "<<endl;
        cin>>current->linkedData;
    }
    current->nextNode=NULL;
    // cout<<"\n"<<current<<endl;   
}

int main(){
    // Node<int> n;
    int n;
    cout<<"What: "<<endl;
    LinkedList<int> listOfInts;
    listOfInts.createLinkedList(2);
    listOfInts.displayLinkedList();
    cout<<"Size of the Linked List: "<<listOfInts.sizeOfLinkedList()<<endl;
    cout<<"Enter the number to be deleted: ";
    cin>>n;
    listOfInts.deleteNode(n);
    listOfInts.displayLinkedList();
    cout<<"Size of the Linked List after deletion: "<<listOfInts.sizeOfLinkedList()<<endl<<endl;    
    return 0;
}