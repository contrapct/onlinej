#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int PRIME=666013;
const int MAXVER=20;
const int BASE=13;

list <pair <string,string> > Hash[MAXVER][PRIME];
vector <pair <string,string> > Ver;
int B[PRIME];
int lastVersion=0;

int hash_function (string key) {
    //abc -> a*B^2+b*B^1+c*B^0
    int hash_value=0;
    for (int i=0; i<(int)key.size (); ++i)
        hash_value=(hash_value+key[i]*B[key.size ()-i-1])%PRIME;

    return hash_value;//my hash_value
}

bool find (pair <string,string> keyValue) {
    int index=hash_function (keyValue.first);

    for (list <pair <string,string> > :: iterator it=Hash[lastVersion][index].begin (); it!=Hash[lastVersion][index].end (); ++it)
        if (*it==keyValue)
            return 1;
    return 0;
}

string find (string key) {
    int index=hash_function (key);

    for (list <pair <string,string> > :: iterator it=Hash[lastVersion][index].begin (); it!=Hash[lastVersion][index].end (); ++it)
        if (it->first==key)
            return it->second;

    return "";
}

bool find (pair <string,string> keyValue,int nr_ver) {
    int index=hash_function (keyValue.first);

    for (list <pair <string,string> > :: iterator it=Hash[nr_ver][index].begin (); it!=Hash[nr_ver][index].end (); ++it)
        if (*it==keyValue)
            return 1;

    return 0;
}

void insert (pair <string,string> keyValue) {
    if (find (keyValue)==1)
        return ;

    Hash[lastVersion][hash_function (keyValue.first)].push_back (keyValue);
}

void remove (pair <string,string> keyValue) {
    if (find (keyValue)==0)
        return ;

    int index=hash_function (keyValue.first);
    for (list <pair <string,string> > :: iterator it=Hash[lastVersion][index].begin (); it!=Hash[lastVersion][index].end (); ++it)
        if (*it==keyValue) {
            Hash[lastVersion][index].erase (it);
            return ;
        }
}

void copy (int ver1,int ver2) {
    for (int i=0; i<PRIME; ++i)
        Hash[ver2][i]=Hash[ver1][i];
}

void precompute () {
    B[0]=1;
    for (int i=1; i<PRIME; ++i)
        B[i]=(B[i-1]*BASE)%PRIME;
}

int main () {
    string type;

    precompute ();
    while (true) {
        string key,value;
        int nr_ver;

        cin>>type;

        if (type=="exit")
            return 0;

        if (type=="put") {
            copy (lastVersion,lastVersion+1);
            ++lastVersion;

            cin>>key>>value;
            insert (make_pair (key,value));
        }

        if (type=="get") {
            cin>>key>>value;
            if (find (make_pair (key,value)))
                cout<<"Found\n";
            else
                cout<<"NOT Found\n";
        }

        if (type=="getver") {
            cin>>key>>value>>nr_ver;

            int ver=find (make_pair (key,value),nr_ver);
            if (ver>0)
                cout<<"Found "<<ver<<"\n";
            else
                cout<<"NOT Found\n";
        }

        if (type=="getval") {
            cin>>key;
            value=find (key);

            if (value!="")
                cout<<value<<"\n";
            else
                cout<<"NOT Found\n";
        }

        if (type=="del") {
            copy (lastVersion,lastVersion+1);
            ++lastVersion;

            cin>>key>>value;
            remove (make_pair (key,value));
        }
    }

    return 0;
}

//put foo bar
//get foo bar
//=> Found
//del foo bar
//get foo bar
//=> NOT Found
//getver foo bar 1
//=> Found 1
//getver foo bar 2
//=> NOT Found
//
