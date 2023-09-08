// Runtime: 36 ms (Top 97.2%) | Memory: 44.02 MB (Top 69.2%)

class Tuple {

    int distance;

    int row;

    int col;

    

    Tuple(int distance, int row, int col) {

        this.distance = distance;

        this.row = row;

        this.col = col;

    }

}



class Solution {

    public int minimumEffortPath(int[][] heights) {

        // Create a min heap based on the distance

        PriorityQueue<Tuple> minHeap = new PriorityQueue<>((x, y) -> x.distance - y.distance);

        

        int rows = heights.length;

        int cols = heights[0].length;

        

        // Create a 2D array to store the minimum effort to reach each cell

        int effort[][] = new int[rows][cols];

        

        // Initialize all efforts to maximum initially

        for (int i = 0; i < rows; i++) {

            Arrays.fill(effort[i], Integer.MAX_VALUE);

        }

        

        effort[0][0] = 0; // Initial effort at the starting cell

        

        // Add the starting cell to the min heap

        minHeap.add(new Tuple(0, 0, 0));

        

        // Arrays to represent row and column changes for 4 directions

        int dr[] = {-1, 0, 1, 0}; // Up, Right, Down, Left

        int dc[] = {0, 1, 0, -1};

        

        while (!minHeap.isEmpty()) {

            Tuple current = minHeap.poll(); // Get the cell with the minimum effort

            int distance = current.distance;

            int row = current.row;

            int col = current.col;

            

            if (row == rows - 1 && col == cols - 1) {

                return distance; // If reached the destination, return the effort

            }

            

            // Explore each of the 4 possible directions

            for (int i = 0; i < 4; i++) {

                int newRow = row + dr[i]; // Calculate new row index

                int newCol = col + dc[i]; // Calculate new column index

                

                // Check if the new cell is within bounds

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {

                    

                    // Calculate the new effort based on the maximum of height difference and current effort

                    int newEffort = Math.max(Math.abs(heights[row][col] - heights[newRow][newCol]), distance);

                    

                    // If the new effort is less than the stored effort for the cell, update and add to heap

                    if (newEffort < effort[newRow][newCol]) {

                        effort[newRow][newCol] = newEffort;

                        minHeap.add(new Tuple(newEffort, newRow, newCol)); // Add to heap for further exploration

                    }

                }

            }

        }

        return 0; // This value should be replaced with the actual minimum effort

    }

}

