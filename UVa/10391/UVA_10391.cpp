#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int main(){
    set <string> dictionary;
    set <string> :: iterator it;
    string input;
    int length;
    while ( cin >> input )
        dictionary.insert(input);

    for (it = dictionary.begin(); it != dictionary.end(); it++) {
        length = (*it).length();
        for (int i = 1; i < length; i++) {
            // cout<<(*it).substr(0,i)<<" "<<(*it).substr(i,length-1)<<endl;
            if ( dictionary.find((*it).substr(0,i)) != dictionary.end() &&
                 dictionary.find((*it).substr(i,length-1)) != dictionary.end()) {
                cout<<(*it)<<endl;
                break;
            }
        }
    }


}
