// Runtime: 18 ms (Top 71.11%) | Memory: 51.5 MB (Top 97.04%)
class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        int[][] mat = new int[2][colsum.length];

        Stack<Integer> prev_upper = new Stack<>();
        Stack<Integer> prev_lower = new Stack<>();

        int uppersum = 0;
        int lowersum = 0;

        for(int i=0; i<colsum.length; i++){
            if(colsum[i] == 0)
                continue;

            if(colsum[i] == 2){
                if(uppersum == upper){
                    if(prev_upper.isEmpty())
                        return new ArrayList<>();
                    else{
                        mat[0][prev_upper.peek()] = 0;
                        mat[1][prev_upper.pop()] = 1;
                        mat[0][i] = 1;
                        lowersum++;
                    }
                }
                else{
                    mat[0][i] = 1;
                    uppersum++;
                }

                if(lowersum == lower){
                    if(prev_lower.isEmpty())
                        return new ArrayList<>();
                    else{
                        mat[1][prev_lower.peek()] = 0;
                        mat[0][prev_lower.pop()] = 1;
                        mat[1][i] = 1;
                        uppersum++;
                    }
                }
                else{
                    mat[1][i] = 1;
                    lowersum++;
                }
            }
            else if(uppersum < upper){
                prev_upper.push(i);
                mat[0][i] = 1;
                uppersum++;
            }

            else if(lowersum < lower){
                prev_lower.push(i);
                mat[1][i] = 1;
                lowersum++;
            }
            else
                return new ArrayList<>();
        }

        if(uppersum != upper || lowersum != lower)
            return new ArrayList<>();

        List<List<Integer>> ans = new ArrayList<>();

        ans.add(new ArrayList<>());
        ans.add(new ArrayList<>());

        for(int i=0; i<mat.length; i++){
            for(int j=0; j<mat[0].length; j++){
                ans.get(i).add(mat[i][j]);
            }
        }

        return ans;
    }
}