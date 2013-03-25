#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void RemoveD(string &s1,string &s2){
    unordered_map<string,vector<int> > Hash_set;
    vector <int> mark;

    stringstream s1stream (s1);
    stringstream s2stream (s2);

    int cnt=0;
    string in,in1,in2,in3;

    while (s1stream>>in) {
        if (cnt==0) {
            in1=in; ++cnt;
        }
        else if (cnt==1) {
            in2=in; ++cnt;
        }
        else if (cnt==2) {
            in3=in; ++cnt;
        }
        else {
            ++cnt;
            in1=in2;
            in2=in3;
            in3=in;
        }

        if (cnt>=3)
            Hash_set[in1+in2+in3].push_back(cnt-1);
    }

    vector<int> viz1;
    viz1.resize(cnt);
    vector<int> viz2;
    cnt=0;
    while (s2stream>>in) {
        viz2.push_back(0);
        if (cnt==0) {
            in1=in; ++cnt;
        }
        else if (cnt==1) {
            in2=in; ++cnt;
        }
        else if (cnt==2) {
            in3=in;
            ++cnt;
        }
        else {
            cnt++;
            in1=in2;
            in2=in3;
            in3=in;
            }

        if(cnt>=2){
            vector<int> aux = Hash_set[in1+in2+in3];
            for(int i=0;i<aux.size();++i){
                viz1[aux[i]]=viz1[aux[i]-1]=viz1[aux[i]-2] = 1;
                viz2[cnt-1]=viz2[cnt-2]=viz2[cnt-3]=1;
            }
        }
    }
    //string ss1,ss2;
    stringstream s1stream1 (s1);
    stringstream s2stream2 (s2);
    s1=s2="";
    cnt = 0;
    while (s1stream1>>in) {
        if(viz1[cnt]==0)
            s1+=in+" ";
        ++cnt;
    }
    cnt = 0;
    while (s2stream2>>in) {
        if(viz2[cnt]==0)
            s2+=in+" ";
        ++cnt;
    }
}

int main(){
    string s1 = "Ana are mere multe si pere putine";
    string s2 = "Maria are mere multe si marunte";
    RemoveD(s1,s2);

    cout<<s1<<s2;
    return 0;
}
