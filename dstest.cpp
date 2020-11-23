#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;
int main()
{
	fstream new_file; 
	new_file.open("Imperial.txt",ios::in);   
	if(!new_file) 
		cout<<"No such file"; 
	else 
	{
		char ch;
        
		while (!new_file.eof()) 
		{   
			int dots=0; 
            while(dots<2){
                new_file >>ch;
				if(ch=='.'){
                    dots+=1;
                } 
                cout << ch;
            }
            // break;

            cout<<endl;
		}
	}
	new_file.close();    
	return 0;
}

