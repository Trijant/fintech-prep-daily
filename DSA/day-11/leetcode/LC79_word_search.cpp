#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TOPIC: Backtracking + bitMask + freq array
// time-complexity: O(r*c*4^n) ; where n=length of word,r=row,c=col
// space-complexity: O(r*c)

class Solution
{
private:
    struct Index
    {
        int row;
        int col;
    };
    bool helper(vector<vector<char>> &board, string word, vector<int> &path, int row, int col, int word_index)
    {
        // base case
        if (word_index == word.size())
        {
            return true;
        }
        else if (row >= board.size() || row < 0 || col >= board[0].size() || col < 0)
        {
            return false;
        }
        else if (path[row] & (1 << col))
        {
            return false;
        }

        bool exist = false;
        // checking if we can make choice
        if (board[row][col] == word[word_index])
        {
            int colBitMask = 1 << col;
            path[row] |= colBitMask; // make choice
            // exploring recursions
            exist = helper(board, word, path, row + 1, col, word_index + 1) || helper(board, word, path, row - 1, col, word_index + 1) || helper(board, word, path, row, col + 1, word_index + 1) || helper(board, word, path, row, col - 1, word_index + 1);
            path[row] ^= colBitMask; // undo choice
        }
        return exist;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.size() == 0)
        {
            return false;
        }
        else if (word.size() == 0)
        {
            return false;
        }
        vector<int> freq(128, 0);
        vector<vector<Index>> startIdx(128, vector<Index>(0));

        // getting record of frequency and startIdx
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[row].size(); col++)
            {
                char ch = board[row][col];
                Index idx = {row, col};
                startIdx[ch].push_back(idx);
                freq[ch]++;
            }
        }

        // reversing word if last char has less frequency to reduce recursions
        if (freq[word[0]] > freq[word.back()])
        {
            reverse(word.begin(), word.end());
        }

        // pruning based on frequency
        for (char ch : word)
        {
            freq[ch]--;
            if (freq[ch] < 0)
            {
                return false;
            }
        }
        vector<int> path(board.size(), 0);

        for (Index idx : startIdx[word[0]])
        {
            if (helper(board, word, path, idx.row, idx.col, 0))
            {
                return true;
            }
        }
        return false;
    }
};

int main(){
    int row, col;
    string word;
    cout << "Enter no. of row: ";
    cin >> row;
    cout << "Enter no. of cols: ";
    cin >> col;
    vector<vector<char>> board(row, vector<char>(col));
    cout << "Enter elements of board: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> board[i][j];
        }
    }
    cout << "Enter word: ";
    cin >> word;
    Solution s;
    if (s.exist(board,word))
    {
        cout << "Word exist" << endl;
    }
    else{
        cout << "Word not exist" << endl;
    }
}