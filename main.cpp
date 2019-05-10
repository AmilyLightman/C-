#include <iostream>
#include <fstream>

using namespace std;

class trie {
private:
    int shortest;
    int capacity;

    class Node {
    public:
        Node *next[26];
        bool isWord;
        int val;

        Node() {
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
            isWord = false;
        }
    };

    Node *root;

    void deleteNode(Node *p) {
        for (int i = 0; i < 26; i++) {
            if (p->next[i] != nullptr) {
                deleteNode(p->next[i]);
            }
        }
        delete p;
    }

public:
    trie() : shortest(50), capacity(0) { root = new Node(); }

    ~trie() {
        for (int i = 0; i < 26; i++) {
            if (root->next[i] != nullptr) {
                deleteNode(root->next[i]);
            }
        }
    }

    Node *getRoot() {
        return root;
    }

    int findShort() {
        return shortest;
    }

    void insert(const string &word) {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (temp->next[index] == nullptr) {
                temp->next[index] = new Node();
            }
            temp = temp->next[index];
            temp->val++;
        }
        temp->isWord = true;
        capacity++;
        if (word.size() < shortest)
            shortest = word.size();
    }

    bool containsPrefix(string word) {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (temp->next[index] == nullptr) {
                return false;
            }
            temp = temp->next[index];
        }
        return true;
    }

    int preValue(string word) {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (temp->next[index] == nullptr) {
                return 0;
            }
            temp = temp->next[index];
        }
        return temp->val;
    }

    bool containsWord(string word) {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (temp->next[index] == nullptr) {
                return false;
            }
            temp = temp->next[index];
        }
        return temp->isWord;
    }

    int Value(string word) {
        int c1, c2;
        c1 = preValue(word);
        c2 = 0;

        Node *temp = root;
        for (int i = 0; i < 26; i++) {
            char ca = i + 'a';
            string temp = word + ca;
            c2 += preValue(temp);
        }
        return c1 - c2;
    }

    void print(Node *temp, char word[], int length) const {
        if (temp->isWord == true) {
            word[length] = '\0';
            cout << word << '\n';
        }
        //else
        for (int i = 0; i < 26; i++) {
            if (temp->next[i] != nullptr) {
                word[length] = (i + 'a');
                print(temp->next[i], word, length + 1);
            }
        }
    }

    void save(string *s, int cap, Node *temp, char word[], int length) const {
        if (temp->isWord == true) {
            s[cap] = word;
            //word[length] = '\0';
            cap++;
        }
        for (int i = 0; i < 26; i++) {
            if (temp->next[i] != nullptr) {
                word[length] = (i + 'a');
                print(temp->next[i], word, length + 1);
            }
        }
    }


    void buildPre(trie &pre, Node *copyRoot, Node *copy, Node *temp, int size, int level) {
        for (int j = 0; j < 26; ++j) {
            if (copy->isWord == true) {
                temp->isWord = true;
            }
            if (copy->next[j] != nullptr) {
                if (temp->next[j] == nullptr) {
                    temp->next[j] = new Node();
                }
                if (level < size) {
                    buildPre(pre, copyRoot, copy->next[j], temp->next[j], size, level + 1);
                } else {
                    temp->isWord = true;
                }
            }
        }
    }

    void buildTail(Node *copy, Node *temp, int size, int level, int *t, string str) {
        for (int j = 0; j < 26; ++j) {
            if (copy->isWord) {
                temp->isWord = true;
            }
            if (copy->next[j] != nullptr) {
                if (level < size) {
                    str += (j + 'a');
                    buildTail(copy->next[j], temp, size, level + 1, t,  str);
                }
                else {
                    if (temp->next[j] == nullptr) {
                        temp->next[j] = new Node();
                    }
                    buildTail(copy->next[j], temp->next[j], size, level + 1, t, str);
                }
            }
        }
    }
    void print2(ofstream& out,Node *temp, char word[], int length) const {
        if (temp->isWord) {
            word[length] = '\0';
            out << word << '\n';
        }
        for (int i = 0; i < 26; i++) {
            if (temp->next[i] != nullptr) {
                word[length] = char (i + 'a');
                print2(out,temp->next[i], word, length + 1);
            }
        }
    }




    /*void write(){
        ofstream out;
        out.open("/Users/caowanying/CLionProjects/practice12/dict.out");
        out.close;
    }*/
};

int main() {
    char word[256];
    ifstream in("/Users/caowanying/CLionProjects/practice12/dict.txt");
    trie orig;
    if (!in) {
        cout << "file open error" << '\n';
        return 1;
    }
    string s;
    while (!in.eof()) {
        in >> s;
        orig.insert(s);
    }
    /*
    trie orig;
    string keys[] = {"the", "there", "answer", "ab", "aaa", "abc",
                     "any", "by", "bye", "their"};
    for (int i = 0; i < (sizeof(keys) / sizeof(keys[0])); ++i) {
        orig.insert(keys[i]);
    }
    */

    //orig.print(orig.getRoot(), word, 0);
    int shortest = orig.findShort();
    cout << shortest << '\n';

    //  string s[10000];
    // orig.save(s, 0, orig.getRoot(), word, 0);
//    for(string st: s){ cout<<st; }
    trie pre;
    orig.buildPre(pre, orig.getRoot(), orig.getRoot(), pre.getRoot(), shortest, 0);
    //build.print(build.getRoot(), word, 0);
    //cout<< orig.containsWord("abc")<<'\n';
    trie tail;
    int t[100000];
    string str;
    tail.buildTail(orig.getRoot(), tail.getRoot(), shortest, 0, t,  str);
    ofstream out;
    out.open("/Users/caowanying/CLionProjects/practice12/dict.out");
    tail.print2(out,tail.getRoot(), word, 0);
    out.close();

}