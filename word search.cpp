class Solution {
public:
bool verifica(int x,int y,int n,int m){
    return (x>=0 && x<n && y>=0 && y<m);
}
bool drumuri(vector<vector<char>>&board,int x,int y,string word,int poz,int n,int m){
        if(poz == word.length())
            return true;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        char chestie;
        for(int i=0;i<4;++i){			
            int xx = dx[i]+x;
            int yy = dy[i]+y;
			if(verifica(xx,yy,n,m) == false) 
				continue;
            if(board[xx][yy]!='#' && board[xx][yy]==word[poz]){
                chestie = board[xx][yy];
                board[xx][yy]='#';
                bool ok = drumuri(board,xx,yy,word,poz+1,n,m);
                if(ok == true) 
                    return true;
                board[xx][yy]=chestie;
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
      //backtraking 
      int n=board.size();
      int m=board[0].size();
      char chestie;
      bool ok;
      for(int i=0;i<n;++i){
          for(int j=0;j<m;++j){
              if(board[i][j]==word[0]){
                  chestie = board[i][j];
                  board[i][j]='#';
                  ok = drumuri(board,i,j,word,1,n,m);
                  if(ok == true) 
                    return true;
                  board[i][j]=chestie;
              }
          }
      }
      return false;
        
    }
};