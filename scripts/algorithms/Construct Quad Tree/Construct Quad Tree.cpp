class Solution {
public:
    
    bool areValuesSame(vector<vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd){
        int val = grid[rowStart][colStart];
        for(int i=rowStart;i<=rowEnd;i++)
        {
            for(int j= colStart;j<=colEnd;j++)
            {
                if(grid[i][j]!= val)
                    return false;
            }
        }
        return true;
    }
    
    Node* helper(vector<vector<int>> &grid, int rowStart, int rowEnd, int colStart, int colEnd)
    {
	
	    // New Node with isLeaf set to true by default
        Node* newNode = new Node(grid[rowStart][colStart], true);
		
		// Base Case if either the grid has only one cell or all the cell values are same
        if( (rowStart == rowEnd && colStart == colEnd) || areValuesSame(grid, rowStart, rowEnd, colStart, colEnd) )
        {
            return newNode;
        }
        
		// Set isLeaf to false as base case failed
        newNode->isLeaf = false;
		
		/* Consider variables rowMid and colMid to set the middle index between 
		start and end of rows and columns of current grid portion*/
        int rowMid = rowStart+(rowEnd-rowStart)/2;
        int colMid = colStart+(colEnd-colStart)/2;
		
		// Recursively finding children of current node (newNode)
        newNode->topLeft = helper(grid, rowStart, rowMid , colStart, colMid);
        newNode->topRight = helper(grid, rowStart, rowMid, colMid+1, colEnd);
        newNode->bottomLeft = helper(grid, rowMid+1, rowEnd, colStart, colMid);
        newNode->bottomRight = helper(grid, rowMid+1, rowEnd, colMid+1, colEnd);
        
		return newNode;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return helper(grid,0,n-1,0,n-1);
    }
};

