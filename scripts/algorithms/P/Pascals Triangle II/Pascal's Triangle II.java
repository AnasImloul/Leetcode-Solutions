// Runtime: 1 ms (Top 92.46%) | Memory: 41.7 MB (Top 63.33%)
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> out = new ArrayList<>();
        for(int i = 0; i<=rowIndex; i++){
            List<Integer>in = new ArrayList<>(i+1);
            for(int j = 0 ; j<= i; j++){
                if(j == 0 || j == i){
                    in.add(1);
                }
                else{
                    in.add(out.get(i-1).get(j-1) + out.get(i-1).get(j));
                }

            }
            out.add(in);
        }
        return out.get(rowIndex);
    }
}