#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

inline string& strip(string& s, const char* t = " \t\n\r\f\v"){
    s.erase(0, s.find_first_not_of(t));
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}
//Node class
class Node{
    public:
        string parent;
        string child;
        vector<Node *> children;
        void addchild(Node * n) {
            this->children.push_back(n);
        }
};

Node * make_node(string key_word){
    size_t pos = 0;
    string k=strip(key_word), w="";
    if( (pos = key_word.find(" ")) != std::string::npos ){
        k = key_word.substr(0, pos);
        w = key_word.substr(pos+1, key_word.size());
    }
    Node* node = new Node;
    node->parent = k;
    node->child = w;
    return (node);

}

void _noun_phrases(unordered_map<Node *, string> &nps, Node *root, Node *parent_ref=nullptr) {   
    if (!root->children.size() && parent_ref && parent_ref->parent == "NP") { 
        nps[parent_ref] += " " + root->child; 
        return; 
    } 
    
    for (int i=0; i<root->children.size(); i++){
        _noun_phrases(nps, root->children[i], root);
    }
}

vector<string> noun_phrases(Node * root){
    unordered_map<Node *, string> nps;
    _noun_phrases(nps, root, nullptr);
    vector<string> ss;
    for(auto i : nps){
        ss.push_back(i.second);
    }
    return ss;
}

Node * make_tree(string s, int &start){
    if(start>s.length()) return NULL;
    string key_word="";
    while( start < s.length() && s[start] != '(' && s[start] != ')' ){
        key_word+=s[start++]; 
    }
    Node *root = make_node(key_word);
    if(start>=s.length()) return root;
    
    while(start < s.length() && s[start] == ' ') ++start;
    while(start < s.length() && s[start] == '('){
        ++start;
        Node * ch = make_tree(s, start);
        root->addchild(ch);
        while(start < s.length() && s[start] == ' ') ++start;
    }
    while(start < s.length() && s[start] == ' ') ++start;
    while(start < s.length() && s[start] == ')'){
        ++start;
        return root;
        while(start < s.length() && s[start] == ' ') ++start;
    }
    return root;
}



int main(){
    ifstream in("Imperial.txt");
    streambuf *cinbuf_backup = cin.rdbuf(); 
    cin.rdbuf(in.rdbuf()); 

    string line;
    string onetree = "";
    while(getline(cin, line)){
        if(line.size()) onetree += strip(line);
        else{
            int start = 0;
            onetree = onetree.substr(1, onetree.size() - 2);
            Node *r = make_tree(onetree, start);
            vector<string> npp = noun_phrases(r);
            cout<<"[ ";
            for(string i: npp){
                cout<<"'"<<i<<"', ";
            }
            cout<<"] \n\n";
            onetree = "";
        }
    }
    return 0;

}
