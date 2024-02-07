class Solution {
public:
    bool corr(vector<vector<char>> &board,int x,int y){
        return(x>=0 && y<board[0].size() && y>=0 && x<board.size());
    }
    void show(vector<vector<char>> &board,int x,int y){
        if(!corr(board,x,y))return;
        if(board[x][y]=='E'){
            int c=0;
            if(corr(board,x-1,y-1) && board[x-1][y-1]=='M')c++;
            if(corr(board,x-1,y) && board[x-1][y]=='M')c++;
            if(corr(board,x,y-1) && board[x][y-1]=='M')c++;
            if(corr(board,x-1,y+1) && board[x-1][y+1]=='M')c++;
            if(corr(board,x,y+1) && board[x][y+1]=='M')c++;
            if(corr(board,x+1,y+1) && board[x+1][y+1]=='M')c++;
            if(corr(board,x+1,y) && board[x+1][y]=='M')c++;
            if(corr(board,x+1,y-1) && board[x+1][y-1]=='M')c++;
        
            if(c>0){
                board[x][y]='0'+c;
            }
            else{
                board[x][y]='B';
                show(board,x-1,y-1) ;
                show(board,x-1,y) ;
                show(board,x,y-1) ;
                show(board,x-1,y+1) ;
                show(board,x,y+1) ;
                show(board,x+1,y+1) ;
                show(board,x+1,y) ;
                show(board,x+1,y-1) ;
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]]='X';
            return board;
        }
        show(board,click[0],click[1]);
        return board;
    }
};