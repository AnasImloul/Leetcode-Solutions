class Solution {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> res = new ArrayList<>();
        int i = 0;
        while(i<s.length()-1){
            int j = i+1;
            while(j<s.length()){
                List<Integer> temp = new ArrayList<>();
                if(s.charAt(i) == s.charAt(j)){
                    j++;
                    
                }
                else{
                    if(j - i >= 3 ){
                        temp.add(i);
                        temp.add(j-1);
                        res.add(temp);
                    }
                    i = j;
                    j = i+1;
                }
                if(j == s.length() && j - i >= 3){
                    temp.add(i);
                    temp.add(j-1);
                    res.add(temp);
                }
            }
            i = j+1;
        }
        return res;
    }
}