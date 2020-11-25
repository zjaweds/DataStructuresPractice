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

inline string& lineBreak(string& s, const char* t = " \t\n\r"){
    s.erase(0, s.find_first_not_of(t));
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

Node * buildNode(string leafData){
    size_t locate = 0;
    string par=lineBreak(leafData), chi="";
    if( (locate = leafData.find(" ")) != std::string::npos ){
        par = leafData.substr(0, locate);
        chi = leafData.substr(locate+1, leafData.size());
    }
    Node* node = new Node;
    node->parent = par;
    node->child = chi;
    return (node);
}

void nPhrase(unordered_map<Node *, string> &nps, Node *root, Node *pointsTo=nullptr) {   
    int k=0;
    if (!root->ChildNodes.size() && pointsTo && pointsTo->parent == "NP" ) {
            nps[pointsTo] +=" "+root->child;
        return; 
    } 
    for (int i=0; i<root->ChildNodes.size(); i++){
        if(i>=0)
            k++;
        nPhrase(nps, root->ChildNodes[i], root);
    }
}

vector<string> nPhrases(Node * root){
    unordered_map<Node *, string> nps;
    nPhrase(nps, root, nullptr);
    vector<string> leafWord;
    for(auto i : nps){
        leafWord.push_back(i.second);
    }
    // leafWord.push_back(" ");
    return leafWord;
}

Node * buildTree(string s, int &first){
    if(first>s.length()) return NULL;
    string leafData="";
    while( first < s.length() && s[first] != '(' && s[first] != ')' ){
        leafData+=s[first++]; 
    }
    Node *root = buildNode(leafData);
    if(first>=s.length()) return root;
    
    while(first < s.length() && s[first] == ' '){
        ++first;
    }
    while(first < s.length() && s[first] == '('){
        ++first;
        //Adding a child to root for every left parenthesis
        Node * ch = buildTree(s, first); 
        root->addchild(ch);
        while(first < s.length() && s[first] == ' ') 
            ++first;
    }
    while(first < s.length() && s[first] == ' '){
        ++first;
    }
    while(first < s.length() && s[first] == ')'){
        ++first;
        return root;
        while(first < s.length() && s[first] == ' ')
            ++first;
    }
    return root;
}
int main(){
    std::ifstream ipfile;
    ipfile.open("Imperial.txt",std::ifstream::in);
    streambuf *cinbuf_backup = cin.rdbuf(); 
    cin.rdbuf(ipfile.rdbuf()); 
    string treeData;
    string baseTree = "";
    while(getline(cin, treeData)){
        if(treeData.size()){
            baseTree += lineBreak(treeData);
        }
        else{
            int first = 0;
            baseTree = baseTree.substr(1, baseTree.size() - 2);
            Node *r = buildTree(baseTree, first);
            vector<string> nph = nPhrases(r);
            cout<<"[";
            string nouns;
            for(string noun: nph){
                cout<<"\""<<noun<<"\", ";
            }
            cout<<"] \n\n";
            baseTree = "";
        }
    }
    return 0;
}