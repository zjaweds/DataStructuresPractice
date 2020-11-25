#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Node{
    public:
        string parent;
        string child;
        vector<Node *> ChildNodes;
        void addchild(Node * n) {
            this->ChildNodes.push_back(n);
        }
};

inline string& breakLine(string& s, const char* t = " \t\n\r"){
    s.erase(0, s.find_first_not_of(t));
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

Node * createNode(string leafValue){
    size_t position = 0;
    string p=breakLine(leafValue), c="";
    if( (position = leafValue.find(" ")) != std::string::npos ){
        p = leafValue.substr(0, position);
        c = leafValue.substr(position+1, leafValue.size());
    }
    Node* node = new Node;
    node->parent = p;
    node->child = c;
    return (node);
}

void nounPhrase(unordered_map<Node *, string> &nps, Node *root, Node *pointingTo=nullptr) {   
    // int k=0;
    if (!root->ChildNodes.size() && pointingTo && pointingTo->parent == "NP") {
            nps[pointingTo] +=root->child+" ";
        return; 
    } 
    // nps[pointingTo] +=" ";
    for (int i=0; i<root->ChildNodes.size(); i++){
        // k++;
        nounPhrase(nps, root->ChildNodes[i], root);
    }
    // nps[pointingTo] +=" ";
}

vector<string> nounPhrases(Node * root){
    unordered_map<Node *, string> nps;
    nounPhrase(nps, root, nullptr);
    vector<string> leafString;
    for(auto i : nps){
        leafString.push_back(i.second);
    }
    return leafString;
}

Node * createTree(string s, int &initial){
    if(initial>s.length()) return NULL;
    string leafValue="";
    while( initial < s.length() && s[initial] != '(' && s[initial] != ')' ){
        leafValue+=s[initial++]; 
    }
    Node *root = createNode(leafValue);
    if(initial>=s.length()) return root;
    
    while(initial < s.length() && s[initial] == ' '){
        ++initial;
    }
    while(initial < s.length() && s[initial] == '('){
        ++initial;
        //Adding a child to root for every left parenthesis
        Node * ch = createTree(s, initial); 
        root->addchild(ch);
        while(initial < s.length() && s[initial] == ' ') 
            ++initial;
    }
    while(initial < s.length() && s[initial] == ' '){
        ++initial;
    }
    while(initial < s.length() && s[initial] == ')'){
        ++initial;
        return root;
        while(initial < s.length() && s[initial] == ' ')
            ++initial;
    }
    return root;
}



int main(){
    std::ifstream ipfile;
    ipfile.open("Imperial.txt",std::ifstream::in);
    streambuf *cinbuf_backup = cin.rdbuf(); 
    cin.rdbuf(ipfile.rdbuf()); 

    string treeData;
    string mainTree = "";
    while(getline(cin, treeData)){
        if(treeData.size()){
            mainTree += breakLine(treeData);
        }
        else{
            int initial = 0;
            mainTree = mainTree.substr(1, mainTree.size() - 2);
            Node *r = createTree(mainTree, initial);
            vector<string> npp = nounPhrases(r);
            cout<<"[ ";
            string nouns;
            for(string i: npp){
                
                // strcat(nouns,i);
                // nouns="\""+nouns;
                // nouns+="\""+i;
                cout<<"\""<<i<<"\", ";
                // nouns+="\",";
                // nouns+=",";
            }
            // nouns.pop_back();
            // for(int i=0;i<nouns.size();i++){
                // cout<<nouns;
            // }
            cout<<"] \n\n";
            mainTree = "";
        }
    }
    return 0;
}