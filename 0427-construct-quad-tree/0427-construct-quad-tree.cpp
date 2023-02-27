/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool check(vector<vector<int>>& grid, int x, int y, int l)
    {
        for (int i = x; i < x + l; i++) 
        {
            for (int j = y; j < y + l; j++)
            {
                if (grid[i][j] != grid[x][y])
                {
                    return false;
                }    
            }
        }

        return true;
    }

    Node* sol(vector<vector<int>>& grid, int x, int y, int l)
    {
        if(check(grid, x, y, l))
        {
            return new Node(grid[x][y], true);
        }
        else
        {
            Node* root =  new Node(false, false);
            root -> topLeft = sol(grid, x, y, l / 2);
            root -> topRight = sol(grid, x, y + l / 2, l /2 );
            root -> bottomLeft = sol(grid, x + l / 2, y , l / 2);
            root -> bottomRight = sol(grid, x + l / 2, y + l/2, l/2);
            return root;
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        return sol(grid, 0, 0, grid.size());
    }
};