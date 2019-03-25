#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
/*
  Author: Wanying Cao
*/

class trie{
private:
    class Node{
    public:
        Node* next[26];
        bool isWord;
        Node(){
            for (int i = 0; i < 26; i++) {
                next[i]= nullptr;
            }
            isWord = false;
        }
    };
    Node* root;
    void deleteNode(Node* p){
        for (int i = 0; i < 26; i++) {
            if(p->next[i]!=nullptr){
                deleteNode(p->next[i]);
            }
        }
        delete p;
    }

public:
    trie(){root =new Node();}
    ~trie(){
        for (int i = 0; i < 26; i++) {
            if(root->next[i]!=nullptr){
                deleteNode(root->next[i]);
            }
        }
    }
    void insert(string word){
        Node* temp= root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i]-'a';
            if(temp->next[index] == nullptr){
                temp->next[index] = new Node();
            }
            temp= temp->next[index];
        }
        temp->isWord=true;
    }

    bool containsPrefix(string word){
        Node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            int index =word[i]-'a';
            if(temp->next[index]==nullptr){
                return false;
            }
            temp = temp->next[index];
        }
        return true;
    }
    bool containsWord(string word){
        Node* temp= root;
        for (int i = 0; i < word.size(); i++) {
            int index= word[i]-'a';
            if(temp->next[index]==nullptr){
                return false;
            }
            temp=temp->next[index];
        }
        return temp->isWord;
    }

    void print(bool b, string word)const{
        if(b){
            cout<< word << " is true"<<'\n';
        }
        else{
            cout<< word<< " is false"<<'\n';
        }
    }
};
int main(){
    string dictionary;
    trie t;
    ifstream dict("dict.txt");
    //ifstream dict("/Users/caowanying/CLionProjects/trie/dict.txt");
    if(!dict){
        cout << "dictionary file open error" << '\n';
        return 1;
    }
    while(!dict.eof()){
        dict >> dictionary;
        //cout<< dictionary;
        t.insert(dictionary);
    }
    dict.close();
    string word;
    ifstream test("hw5.txt");
    //ifstream test("/Users/caowanying/CLionProjects/trie/hw5.txt");
    if(!test){
        cout << "test file open error" << '\n';
        return 1;
    }
    while(!test.eof()){
        test >> word;
        t.print(t.containsWord(word),word);
    }
    test.close();
}