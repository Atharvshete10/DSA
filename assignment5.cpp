#include<iostream>
#include<string>
using namespace std;

class texteditor{
    string text = "";
    public:
    void inserttext(string t){
        text += t;
    }

    void deletetext(int n){
        int i = text.size();
        if(n > i ){
            text = "";
        }else{
            text.erase(0 , n); //syntax erase(position , length)
        }
    }
    void display(){
        if(text.empty()){
            cout<<"Text is empty."<<endl;
            return;
        }else{
            cout<<text<<endl;;
        }
    }
    void searchtext(string word) {
        size_t pos = text.find(word); // find substring
        if (pos != string::npos) {
            cout << "Found \"" << word << "\" at position " << pos << endl;
        } else {
            cout << "Word \"" << word << "\" not found." << endl;
        }
    }
    
};

int main(){
    texteditor t1;
    string s;
    cout <<"Enter text:";
    getline(cin , s);
    t1.inserttext(s);
    t1.display();
    int n;
    cout<<"Enter size of text to delete"<<endl;
    cin>>n;
    t1.deletetext(n);
    t1.display();
    string str;
    cout<<"Enter word to search"<<endl;
    cin>>str;
    t1.searchtext(str);
    t1.display();
    return 0;
}