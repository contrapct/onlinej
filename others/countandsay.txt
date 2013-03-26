class Solution {
public:
    string countAndSay(int n) {
        if(n==0) return "";
        --n;
        string ret="1";
        string aux="";
        while(n){
            aux="";
              int lgn=ret.length();
              int i=1;
              char c=ret[0];
              int nra =1;
              for( ;i<lgn;++i){
                  if(ret[i]==c){++nra;}
                    else{
                        aux+=(nra+'0');
                        aux+=c;                        
                        c=ret[i];
                        nra=1;
                    }
                }
                aux+=(nra+'0');
                aux+=c;
                        
                        
              ret = aux;
              --n;
        }
       
       return ret;
    }
};