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
        topLeft = topRight = bottomLeft = bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = topRight = bottomLeft = bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf,
         Node* _topLeft,
         Node* _topRight,
         Node* _bottomLeft,
         Node* _bottomRight) {
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
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {

        // Check whether all values in this n x n square are the same
        bool allSame = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[r][c] != grid[r + i][c + j]) {
                    allSame = false;
                    break;
                }
            }
            if (!allSame) break;
        }

        // If all values are identical, create a leaf node
        if (allSame) {
            return new Node(grid[r][c], true);
        }

        // Otherwise divide into four quadrants
        int half = n / 2;

        Node* topLeft = dfs(grid, half, r, c);
        Node* topRight = dfs(grid, half, r, c + half);
        Node* bottomLeft = dfs(grid, half, r + half, c);
        Node* bottomRight = dfs(grid, half, r + half, c + half);

        return new Node(
            true,           // value doesn't matter for non-leaf nodes
            false,
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }

    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }
};