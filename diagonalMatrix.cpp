#include<iostream>
#include<cstring>
using namespace std;
class Exception{
   char *s;
   public:
   Exception(char msg[]){
      s = new char[strlen(msg)+1];
	  strcpy(s, msg);
   }
   friend ostream& operator<<(ostream &abc, Exception x){
      abc << x.s;
	  return abc;
   }
};

class DiagonalMatrix{
   float *a;
   int n;
   public:
   DiagonalMatrix(int n);
   void read();
   void print();
   DiagonalMatrix add(DiagonalMatrix B);
   DiagonalMatrix mul(DiagonalMatrix B);
   float det();
   DiagonalMatrix inverse();
};

DiagonalMatrix::DiagonalMatrix(int n){
	this->n = n;
	a = new float[n];
}
void DiagonalMatrix::read(){
	cout<<"Enter diagonal elements of diagonal matrix of order " << n <<endl;
	for(int i = 0; i<n; i++)
		cin>>a[i];
}
void DiagonalMatrix::print(){
	cout<<"Diagonal Matrix\n";
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			if(i == j)
				cout<<a[i]<<"\t";
			else
				cout<<"0" <<"\t";
		cout<<"\n";
	}
}

int main(){
	DiagonalMatrix A(3);
	A.read();
	cout<<"Matrix A";
	A.print();
	return 0;
}