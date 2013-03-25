class Solution {
public:
  bool isPalindrome(string s) {
       int start=0,end = s.length()-1;
       int ch_start=0,ch_end=0;
       while(start<=end){
    	   if(start == end) return true;
		   ch_start=0,ch_end=0;
            while(start <= end && !('a'<=s[start] && s[start]<='z') )
                if(!('A'<=s[start] && s[start]<='Z'))
					if(!('0'<=s[start] && s[start]<='9'))
						++start;
					else break;
				else break;
            while(start <=end && !('a'<=s[end] && s[end]<='z') )
                if(!('A'<=s[end] && s[end]<='Z'))
                	if(!('0'<=s[end] && s[end]<='9'))
						--end;
					else break;				
                else break;
            if(start>end) return true;
           if( 'a'<=s[start] && s[start]<='z'){
                ch_start = (s[start]-'a');
                ++start;
            }  
            else      
                if( 'A'<=s[start] && s[start]<='Z'){
                    ch_start = (s[start]-'A');
                    ++start;
                }
				else if('0'<=s[start] && s[start]<='9'){
					ch_start = s[start]-'0'+100;
					++start;
				}
                
            if('a'<=s[end] && s[end]<='z'){
                ch_end = (s[end]-'a');
                --end;
            }  
            else      
                if('A'<=s[end] && s[end]<='Z'){
                    ch_end = (s[end]-'A');
                    --end;
                }
				else if('0'<=s[end] && s[end]<='9'){
					ch_end = s[end]-'0'+100;
					--end;
				}
            if(ch_end!=ch_start) return false;
       }
        return true;
    }

};