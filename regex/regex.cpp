/*
   @Author Wanying Cao
*/
#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(){
string a="[a-zA-Z0-9]+\\.[a-zA-Z0-9]";
//String b="[xy]="[0-9]*\\.[0-9]*"";
string searchwithin="";
smatch m;

string begin="<taspn";
string end="/>";

regex r(a);
bool doesItMatch= regex_match(searchwithin,r);
cout<<"match="<< doesItMatch<<'\n';

while(regex_search(searchwithin, m, r)){
    for (auto x:m) cout<< x<< ' ';
    cout<<"\n";
    searchwithin = m.suffix();
}

    regex r2(begin);
    bool doesItMatch2= regex_match(searchwithin,r2);
    cout<<"match="<< doesItMatch2<<'\n';

    while(regex_search(searchwithin, m, r2)){
        for (auto x:m) cout<< x<< ' ';
        cout<<"\n";
        searchwithin = m.suffix();
    }


}

abc
.   matchs any single letter except newline
[aeiou]   find any of the letters
a*   0 or more occurrences of a
a+   match 1 or more a   short ans of aa*
a{3}    aaa
a{2,5}     aa, aaa, aaaa, aaaaa
[a-z]    abcdefj...
[a-zA-Z]    any lowercase or uppercase letter
[A-z]   will not work because something between them
[^aeiou]     any character that is not aeiou
[^a-z]      any character that is not a to z
(dog|cat)     dog or cat
\d      shorthand for[0-9]
\w      shorthand for [a-zA-Z0-9]
a?   match 0 or 1 a
()   group and store what is inside
(?: )     group without storing



        phone
Regex [0-9]{3}[\)\.\-][0-9]{3}[\)\.\-][0-9]{4}
C++ [0-9]{3}[\\)\\.\\-][0-9]{3}[\\)\\.\\-][0-9]{4}

email
        Regex ([a-zA-Z0-9]+\.)?[a-zA-Z0-9]+\.[a-zA-Z0-9]+


