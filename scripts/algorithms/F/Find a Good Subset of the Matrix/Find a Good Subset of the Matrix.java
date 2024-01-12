// Runtime: 3 ms (Top 97.14%) | Memory: 57.50 MB (Top 5.71%)

class Solution {
    public List<Integer> goodSubsetofBinaryMatrix(int[][] grid) {
        boolean[] bin = new boolean[32];
        ArrayList<Integer> ret = new ArrayList<>();
        ArrayList<int[]> list = new ArrayList<>();
        int num = 0;

        for (int i = 0; i < grid.length; i++) {
            num = 0;

            for (int j = 0; j < grid[0].length; j++) {
                num = (num << 1);
                if (grid[i][j] == 1) {
                    num = num | 1;
                }
            }
            //special case
            if (num == 0) {
                // If the binary representation of the row is 0,
                // the row satisfies the condition on its own
                ret.add(i); // Add the row index to the result list
                return ret; // Return the result immediately
            }
            //To counter repeating rows
            if (!bin[num]) {
                list.add(new int[]{num, i});
                bin[num] = true;
            }
        }

        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.size(); j++) {
                if (i != j && (list.get(i)[0] & list.get(j)[0]) == 0) {
                    // Check if the pair of rows is compatible:
                    // By checking If the bitwise AND of their binary representations is 0
                    // Add the row indices to the result list
                    ret.add(list.get(i)[1]); 
                    ret.add(list.get(j)[1]); 
                    return ret; // Return the result
                }
            }
        }

        return ret; // Return the empty result list if no compatible pair is found
    }
}

