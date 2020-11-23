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
			
			string s;
			int dots=0; 
            while(dots<1){
                new_file >>ch;
				s.push_back(ch);
				if(ch=='.'){
                    dots+=1;
                }
            }
			new_file.ignore(5);
			s.pop_back();
			s.pop_back();
			cout<<s<<endl;
        	break;
			cout<<endl<<endl;
		}
	}
	new_file.close();    
	return 0;
}

