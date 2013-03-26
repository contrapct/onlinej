class Solution {
public:
   int sqrt(int x) {
       //with binary search
       if(x == 1 || x == 0 ) return x;
       int st = 0, dr = x/2;
       long long m,lastm ;
       
       while(st<=dr){
           m = st + ((dr - st)>>1);
           if(m*m >= x){
    		   lastm = m;
               dr = m-1;
           }else {lastm = m;st = m+1;}
           
       }
       if(lastm*lastm>x) return lastm-1;
       if((lastm+1)*(lastm+1) <= x) return lastm+1;
       return lastm;
    }
};