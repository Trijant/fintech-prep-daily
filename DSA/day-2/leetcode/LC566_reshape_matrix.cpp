#include <iostream>
#include <vector>
using namespace std;

// Time-complexity: O(row*col)
// Space-complexity: O(row*col)

vector<vector<int>> reshape(vector<vector<int>>& mat,int r , int c){
    int rows=mat.size();
        int cols=mat[0].size();
        if(rows*cols!=r*c){
            return mat;
        }
        vector<vector<int>> reshaped_mat(r,vector<int>(c,0));
        int a=0,b=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(b==c){
                    a++;
                    b=0;
                }
                reshaped_mat[a][b++]=mat[i][j];
            }
        }
        return reshaped_mat;
}

int main(){
    int row, col,reshape_row,reshape_col;
    cout << "Enter no. of rows: ";
    cin >> row;
    cout << "Enter no. of cols: ";
    cin >> col;
    vector<vector<int>> mat(row, vector<int>(col));
    cout << "Enter elements: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }
    cout << "Enter no. of reshape row: ";
    cin >> reshape_row;
    cout << "Enter no. of reshape col: ";
    cin >> reshape_col;
    vector<vector<int>>reshaped_mat=reshape(mat, reshape_row, reshape_col);
    for (int i = 0; i < reshape_row; i++)
    {
        for (int j = 0; j < reshape_col; j++)
        {
            cout<<reshaped_mat[i][j]<<" ";
        }
        cout << endl;
    }
}