class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat)
    {
        // code here
        int size = mat.size() * mat[0].size();
        int rows = mat.size();
        int cols = mat[0].size();

        // right, down, left, up
        vector<int> rowDir = {0, 1, 0, -1};
        vector<int> colDir = {1, 0, -1, 0};

        int dir = 0;

        int curRow = 0;
        int curCol = 0;

        vector<vector<bool>> vis(mat.size(), vector<bool>(mat[0].size(), false));

        vector<int> ans;

        for (int i = 0; i < size; i++)
        {
            vis[curRow][curCol] = true;

            ans.push_back(mat[curRow][curCol]);

            int nextRow = curRow + rowDir[dir];
            int nextCol = curCol + colDir[dir];

            if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && vis[nextRow][nextCol] == false)
            {
                curRow = nextRow;
                curCol = nextCol;
            }
            else
            {
                dir = (dir + 1) % 4;
                curRow += rowDir[dir];
                curCol += colDir[dir];
            }
        }
        return ans;
    }
};

/*
Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix.
This is because each element of the matrix is visited exactly once.

Space Complexity: O(m * n), due to the 'vis' matrix used to track visited elements. The output vector 'ans' also takes O(m * n) space.
*/
