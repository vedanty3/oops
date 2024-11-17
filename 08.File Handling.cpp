#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    ofstream fout;
    fout.open("random.txt");
    fout<<"hello, people of the internet !";
    fout.close();

    ifstream fin;
    fin.open("random.txt");
    char c = fin.get();

    while(!fin.eof()) {
        cout<<c;
        c = fin.get();
    }

    fin.close();

    vector<int>arr = {100, 200, 300, 400, 500};
    fout.open("zero.txt");

    for(int i=0; i<arr.size(); ++i) {
        fout<<arr[i];
        fout<<" ";
    }

    cout<<endl;

    fout.close();

    fin.open("zero.txt");
    char num;
    num = fin.get();

    while(!fin.eof()) {
        num = fin.get();
    }

    cout<<endl;

    fin.close();

    fout.open("people.txt");
    fout<<"Vedant Yetekar\n";
    fout<<"Parth Yetekar\n";
    fout<<"John Doe\n";
    fin.close();

    fin.open("names.txt");
    string line;

    while(getline(fin, line)) {
        cout<<line<<endl;
    }

    fin.close();

    return 0;
}