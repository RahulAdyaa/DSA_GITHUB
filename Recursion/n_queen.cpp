#include<iostream>
using namespace std;

bool issafe(int row , int col , int n , vector<string>&board){
    int duprow=row;// to start from same row for each check
    int dupcol=col;// to start from same col for each check

    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
    }

    row=duprow; 
    col=dupcol;
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
    }
    row=duprow;
    col=dupcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        col--;
        row++;
    }
    return true;
}

void permute(int col , int n, vector<string>&board , vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++){
        if(issafe(row,col,n,board)){
                board[row][col]='Q';
                permute(col+1,n,board,ans);
                board[row][col]='.';
        }
    }
}

int main(){
    vector<vector<string>>ans;

    int n;
    cout<<"enter value of n"<<endl;
    cin>>n;
    vector<string>board(n);
    string s(n ,'.');

    for(int i=0;i<n;i++){
        board[i]=s;
    }

    permute(0 , n , board , ans);

    for(auto sol:ans){
        cout<<"{";
        for(auto val:sol){
            cout<<val<<" ";
        }
        cout<<"}\n";
    }

}