#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> strings;
    strings.push_back("Hello");
    strings.push_back("World");
    strings.push_back("I am");
    strings.push_back("Here");

    for (const string& s : strings){
        cout << s << endl;
    }   
}