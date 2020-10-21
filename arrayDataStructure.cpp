#include<iostream>
#include<cstring>
using namespace std;

class Exception{
    char *s;
    public:
    Exception(char msg[]){
        s=new char[strlen(msg)+1];
        strcpy(s,msg);
    }
    friend ostream& operator<<(ostream &ob, Exception E){
        ob<<E.s;
        return ob;
    }
};

template <class T>class Array{
    T *a;
    int size;
    int length;
    public:
    Array(int n);
    bool isEmpty();
    int getSize();
    void insert(T x,int);
    void del(int i);
    int indexOf(T x);
    float get(int);
    void display();
};
template <class T> Array<T>::Array(int n){
    a= new T[n];
        length =n;
        size=0;
}


template
<class T>
void Array<T>::insert(T ob,int index){
    if(size==length){
        char meassage[]="Array is full";
        throw Exception(meassage);
    }
    else if (index<0||index>size)
        cout<<"Invalid index"<<endl;
    else
        for(int i=size-1;i>index;i--)
            a[i+1]=a[i];
    a[index]=ob;
    size++;
}
template<class T>
bool Array<T>::isEmpty(){
    if(size==0)
        return (bool)true;
    else
        return (bool)false;
}
int main(){
    Array<int> x(10);
    x.insert(4,0);
    if(x.isEmpty())
        cout<<"Array is empty"<<endl;
    else
    {
        char acknowldgement[]="Array is not empty";
        throw Exception(acknowldgement);
    }
    
    return 0;
}