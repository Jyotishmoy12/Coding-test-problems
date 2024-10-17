To solve the problem of constructing a Quad Tree from a grid, the main idea is to recursively divide the grid into four sub-grids, check if all the elements within a sub-grid are uniform (all 1's or all 0's), and create leaf nodes if they are. If a sub-grid is not uniform, we recursively divide it further until we reach uniform sections.

Quad-Tree Node Structure
Each node of the Quad-Tree will contain:

val: Represents the value of the grid (True if the grid contains all 1's, False if it contains all 0's).
isLeaf: True if the node is a leaf (i.e., the grid is uniform and doesn't need to be divided further).
topLeft, topRight, bottomLeft, bottomRight: The four children of the node that represent the four quadrants of the grid.
Steps to solve the problem:
Base Case: If the grid section is uniform (all values are the same), create a leaf node with isLeaf=True and val set to the value of the grid.
Recursive Case: If the grid section is not uniform, divide the current grid into four quadrants, recursively construct Quad Trees for each sub-grid, and combine them as children of the current node.
Return the constructed Quad-Tree root.
Plan:
Create a helper function construct(grid, x, y, length) that constructs a Quad-Tree for a sub-grid starting at (x, y) with size length x length.
The base case of the recursion will handle grids of size 1 or grids where all the values are the same.
If the grid is not uniform, divide it into four sub-grids:
Top-left, Top-right, Bottom-left, Bottom-right.
Recursively construct the Quad-Tree for each sub-grid.
Code Implementation:
cpp
Copy code
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
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = nullptr;
        topRight = nullptr;
        bottomLeft = nullptr;
        bottomRight = nullptr;
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

class Solution {
public:
    // Helper function to check if all the elements in the grid are the same
    bool isUniform(vector<vector<int>>& grid, int x, int y, int length) {
        int value = grid[x][y];
        for (int i = x; i < x + length; i++) {
            for (int j = y; j < y + length; j++) {
                if (grid[i][j] != value) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // Helper function to construct the Quad-Tree
    Node* constructQuadTree(vector<vector<int>>& grid, int x, int y, int length) {
        // Base case: If the grid is uniform, create a leaf node
        if (isUniform(grid, x, y, length)) {
            return new Node(grid[x][y] == 1, true);
        }
        
        // Recursive case: Divide the grid into four sub-grids
        int halfLength = length / 2;
        Node* topLeft = constructQuadTree(grid, x, y, halfLength);
        Node* topRight = constructQuadTree(grid, x, y + halfLength, halfLength);
        Node* bottomLeft = constructQuadTree(grid, x + halfLength, y, halfLength);
        Node* bottomRight = constructQuadTree(grid, x + halfLength, y + halfLength, halfLength);
        
        // Create an internal node with four children
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    // Main function to construct the Quad-Tree
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructQuadTree(grid, 0, 0, n);
    }
};
Explanation:
Node Class:

This class defines a Node structure for the Quad-Tree with attributes like val, isLeaf, and the four child nodes.
isUniform():

This function checks if all the elements in the grid (within the range (x, y) to (x + length, y + length)) are the same.
If they are, we return true; otherwise, false.
constructQuadTree():

This recursive function builds the Quad-Tree.
If the grid is uniform, we create a leaf node.
If it's not uniform, we divide the grid into four sub-grids and recursively construct the Quad-Tree for each sub-grid.
We then create an internal node and set its four children to the Quad-Trees of the sub-grids.
construct():

This is the main function that starts the recursive construction process from the full grid.
Time Complexity:
The time complexity of this solution is 
𝑂
(
𝑛
2
)
O(n 
2
 ), where 
𝑛
n is the size of the grid (length of the side of the square grid).
In the worst case, the function will have to check every cell of the grid at least once.
Example Dry Run:
For the grid:

lua
Copy code
grid = [[0, 1], [1, 0]]
Initially, we check the full grid:

It's not uniform (contains both 0 and 1).
We split it into four sub-grids:
Top-left: [[0]]
Top-right: [[1]]
Bottom-left: [[1]]
Bottom-right: [[0]]
Each sub-grid contains a single value (0 or 1), so they are leaf nodes.

The root node will have isLeaf = False and its children will be the four leaf nodes constructed from the sub-grids.

Output:
css
Copy code
[[0,1],[1,0],[1,1],[1,1],[1,0]]
This output represents the Quad-Tree structure for the given grid.
