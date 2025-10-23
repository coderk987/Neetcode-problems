class Solution {
public:
    bool find(vector<vector<char>> &board, string &word, int i,int j,int n, int m, vector<vector<bool>> &done,string &cur,int iter){
        if(word==cur) return true;

        if(i<0 || j<0) return false;
        if(i>=n || j>=m) return false;
        if(cur.size()>=word.size()) return false;
        if(done[i][j]) return false;

        if(word[iter]!=board[i][j]) return false;

        done[i][j]=true;
        cur=cur+board[i][j];
        bool ans=find(board, word, i+1,j,n,m,done, cur, iter+1) || 
                find(board, word, i-1,j,n,m,done, cur, iter+1) || 
                find(board, word, i,j-1,n,m,done, cur, iter+1) || 
                find(board, word, i,j+1,n,m,done, cur, iter+1);
        done[i][j]=false;
        cur.pop_back();

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> done(n, vector<bool>(m,false));
        string cur="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(find(board,word,i,j,n,m,done,cur,0)) return true;
            }
        }
        return false;
    }
};