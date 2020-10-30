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
    friend ostream& operator<<(ostream &abc,Exception x){
        abc<<x.s;
        return abc;
    }
};
template <class T> class Array{
    T *x;
    int size,length;
    public:
    Array(int n){
        x=new T[n];
        length=n;
        size=0;
    }
    bool isEmpty();
    int getSize();
    void insert(T t,int index);
    T del(int index);
    int indexOf(T t);
    T get(int index);
    void display();
};
template<class T>void Array<T>::display(){
    ostream& operator<<(ostream &cba,T t){
        cout<<t.size;
        cout<<t.length;
    }
}
template<class T>T Array<T>::get(int index){
    if(index>length||index<0)
        throw Exception("Invalid index");
    return x[index];
}
template<class T> int Array<T>::indexOf(T t){
    for(int i=0;i<=size;i++){
        if(t==x[i])
        return i;
    }
}
template<class T>T Array<T>::del(int index){
    if(index>length||index<0)
        throw Exception("Invalid index");
    T obj;
    obj=x[index];
    size--;
    return obj;
}
template<class T> bool Array<T>::isEmpty(){
    if(size==0)
        return true;
    else
        return false;
}
template<class T>int Array<T>::getSize(){
    return size;
}
template<class T>void Array<T>::insert(T t, int index){
    if(size==length)
        throw Exception("Array is full.");
    if(index>length||index<0)
       throw Exception("Invalid index.");
    for(int i=size-1;i>=index;i--)
        x[i+1]=x[i];
    x[index]=t;
    size++;
    cout<<size<<endl;
}
template<class T>void Array<T>::display(){
    cout<<x;        
}
class Person{
    char *name;
    int age;
    char *sex;
    public:
    Person(){
        age=0;
    }
    Person(char msg[],int a,char s[]){
        name=new char[strlen(msg)+1];
        strcpy(name,msg);
        age=a;
        strcpy(sex,s);
    }
};
int main(){
    Array <char*>student(5);
    student.insert("Student",0);
    student.insert("Name",1);
    student.del(1);
    student.insert("is",2);
    //student.insert("Dell",6);
    cout<<student.getSize()<<endl;
    cout<<"Index of student: "<<student.indexOf("Student")<<endl;
    Array<Person>p(3);
    cout<<p.getSize()<<endl;
    Person x("Student",34,"F"),r("Alpha",32,"NA");
    p.insert(x,1);
    //cout<<p.getSize();
    Person q("John",65,"M");
    p.insert(q,0);
    p.insert(r,2);
    cout<<p.getSize()<<endl;
    return 0;
}