#include<bits/stdc++.h>
#include<fstream>
using namespace std;
void func(string s,set<string>& arr){
    string temp = "";
bool found = false;
    for(int i = 0;i<s.length();i++){
        if(s[i] == ' ' && found == false){
            arr.insert(temp);
            temp = "";
            found = true;
        }else if(s[i] != ' '){
            temp+=s[i];
            found = false;
        }
    }
    arr.insert(temp);


}
void func(string s,vector<string>& arr){
    string temp = "";
bool found = false;
    for(int i = 0;i<s.length();i++){
        if(s[i] == ' ' && found == false){
            arr.push_back(temp);
            temp = "";
            found = true;
        }else if(s[i] != ' '){
            temp+=s[i];
            found = false;
        }
    }
    arr.push_back(temp);


}

class stringset{
private:
    vector<string>Q = {"chocolate","is","great","we","love","it"};
    set<string> D;
    set<string> arr1;
    set<string>set_common;
    map<string,int>mp;
    vector<string> an;
     static int sum;
     static int size_d;
     static int size_arr1;
     string name;
public:
stringset(){

        cout<<"Please Enter file name"<<endl;

        cin>>name;
        fstream fio;
        fio.open(name,ios::out | ios::in);
        while (fio) {

        // Read a Line from standard input
        for(int i = 0;i<Q.size();i++){
            fio <<  Q[i] << endl;
        }
        break;

        // Write line in file

    }
        fio.seekg(0, ios::beg);

    while (fio) {
        string s;
        // Read a Line from File
        getline(fio, s);

        // Print line in Console
        D.insert(s);
    }
    fio.close();
    }
    stringset(string name){

        func(name,arr1);
    }

    void operator+(stringset s2){
                fstream fio;

        fio.open(name,ios::out | ios::in);
        while (fio) {

        // Read a Line from standard input
        for(int i = 0;i<Q.size();i++){
            fio <<  Q[i] << endl;
        }
        break;

        // Write line in file

    }
        fio.seekg(0, ios::beg);

    while (fio) {
        string s;
        // Read a Line from File
        getline(fio, s);

        // Print line in Console
        D.insert(s);
    }
    fio.close();

        for(string i:D){
            cout<<i<<" "<<endl;
        }
        for(string i: s2.arr1){
            cout<<i<<" "<<endl;
        }
    }
    void operator*(stringset s2){


        for(string s:D){
            mp[s]++;
            size_d++;
        }
        for(string s:s2.arr1){
            mp[s]++;
            size_arr1++;
        }
        for(auto it:mp){
            if(it.second >=2){
                sum++;
                an.push_back(it.first);
            }
        }
    }
    void addset(){
        cout<<"Please Enter the string"<<endl;
        string name;
        cin>>name;
        func(name,Q);
    }

    void removeset(){
        cout<<"Please Enter the string"<<endl;
        vector<string>::iterator it;
        string word;
        cin>>word;
        it = find (Q.begin(), Q.end(), word);
        if (it != Q.end())
        {
            int i = it - Q.begin();
            Q.erase(Q.begin()+i);
        }
        for(string i:Q){
            cout<<i<<" ";
        }
        cout<<endl;
        fstream fio;

        fio.open(name,ios::out);
        while (fio) {

        // Read a Line from standard input
        for(int i = 0;i<Q.size();i++){
            fio <<  Q[i] << endl;
        }
        break;

        // Write line in file

    }
        fio.seekg(0, ios::beg);

    while (fio) {
        string s;
        // Read a Line from File
        getline(fio, s);

        // Print line in Console
        D.insert(s);
    }
    fio.close();


    }

void memFunc(){

        if(sum >=1){
            cout<<ceil(sum/(sqrt(size_d)*sqrt(size_arr1)))<<endl;
            for(string i:an){
                cout<<i<<endl;
            }
        }else{
            cout<<(ceil(sum/(sqrt(D.size())*sqrt(arr1.size()))))<<endl;
        }

    }

};

int stringset::sum = 0;
int stringset::size_d = 0;
int stringset::size_arr1 = 0;
int main() {
    string str;
    cout<<"Welcome To the Application:"<<endl;
    cout<<"Enter a String"<<endl;
    getline(cin,str);
    cout<<endl;
            char a;
        cout<<"Choose one of the options:"<<endl;
        cout<<"1. Intersect between two string"<<endl;
        cout<<"2. Union of two strings"<<endl;
        cout<<"3. Add to set"<<endl;
        cout<<"4. Remove from set"<<endl;
        cin>>a;

    stringset s,t(str);
                if(a == '1'){
            s*t;
        s.memFunc();
        }else if(a == '2'){
            s+t;

        }else if(a == '3'){
            s.addset();
            s+t;
        }else if(a == '4'){
            s.removeset();
            s+t;
        }



  return 0;
}


