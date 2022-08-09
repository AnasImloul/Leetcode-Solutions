class Solution {
    public List<String> cellsInRange(String s) {
        char sc = s.charAt(0), ec = s.charAt(3);
        char sr = s.charAt(1), er = s.charAt(4);
        List<String> res = new ArrayList<>();
        
        for (char i = sc; i <= ec; ++i){
            for (char j = sr; j <= er; ++j){
                res.add(new String(new char[]{i, j}));
            }
        }
        
        return res;
    }
}
