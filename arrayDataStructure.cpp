#include<iostream>

using namespace std;

class array{
    int index;
    int length;
    public:
    array(int l){
        length=l;
        index=0;
    }
    bool isEmpty();
    int size();
    void insert(float,int);
    void del(int i);
    int indexOf(float);
    float get(int);
    void display();
};

bool array::isEmpty(){
    if(index==0){
        return true;
    }
    else
    {
        return false;
    }
}

int main(){
    array x(10);
    if(x.isEmpty()){
        cout<<"Array is empty"<<endl;
    }
    return 0;
}