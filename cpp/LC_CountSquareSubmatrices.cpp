//(leetcode)
//1277. Count Square Submatrices with All Ones
/*

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

*/

#include<ios>
#include<vector>
#include<iostream>

using namespace std;

class Solution{
public:
    int countSquares(vector<vector<int>>& matrix){
        int result = 0;
        for(int i = 0; i < (int)matrix.size(); i++){
            for(int j = 0; j < (int)matrix[0].size(); j++){
                if(matrix[i][j] > 0 && i > 0 && j > 0){
                    matrix[i][j] = min(min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]+1);
                }
                result += matrix[i][j];
            }
        }
        return result;
    }

};
int main(){
    vector<vector<int>> input;
    input.push_back({0,1,1,1});
    input.push_back({1,1,1,1});
    input.push_back({0,1,1,1});

    Solution s;
    int out = s.countSquares(input);
    cout<< out;

}
