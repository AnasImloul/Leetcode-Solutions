// Runtime: 1 ms (Top 73.34%) | Memory: 42 MB (Top 41.04%)
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list = new LinkedList();
        list.add(Arrays.asList(1));
        if(numRows == 1) return list;
        list.add(Arrays.asList(1,1));

        for(int i = 1; i < numRows - 1; i++) {
            List<Integer> temp = list.get(i);
            List<Integer> temp2 = new ArrayList();
            temp2.add(1);
            for(int j = 0; j < temp.size() - 1; j++) {
                temp2.add(temp.get(j) + temp.get(j+1));
            }
            temp2.add(1);
            list.add(temp2);
        }

        return list;
    }
}