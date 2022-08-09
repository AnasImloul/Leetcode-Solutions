class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String> ans = new ArrayList<String>();
        permutation(s,"",ans);
        return ans;
    }
    
    private void permutation(String s, String asf, List<String> ans){
        if(s.length() == 0){
            if(!ans.contains(asf)){
                ans.add(asf);
            }
            return;
        }
        
        char ch = s.charAt(0);
        String ros = s.substring(1);
        permutation(ros, asf + Character.toUpperCase(ch), ans);
        permutation(ros, asf + Character.toLowerCase(ch), ans);
    }
}
