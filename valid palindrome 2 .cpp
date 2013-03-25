class Solution {
public:
    bool isPalindrome(string s) {
        int st=0;
        int dr=s.length ()-1;
        
        while (st<dr) {
            while (st<dr && !isalnum (s[st]))
                ++st;
            while (st<dr && !isalnum (s[dr]))
                --dr;
                
            if (st<dr && toupper (s[st])!=toupper (s[dr]))
                return 0;
            ++st; --dr;
        }
    
        return 1;
    }
};