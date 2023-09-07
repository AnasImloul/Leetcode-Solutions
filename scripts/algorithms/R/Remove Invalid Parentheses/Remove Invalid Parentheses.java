// Runtime: 42 ms (Top 72.6%) | Memory: 44.48 MB (Top 39.7%)

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> ans=new ArrayList<>();
        HashSet<String> set=new HashSet<String>();
        
        int minBracket=removeBracket(s);
        getAns(s, minBracket,set,ans);
        
        return ans;
    }
    
    public void getAns(String s, int minBracket, HashSet<String> set, List<String> ans){
        if(set.contains(s)) return;
        
        set.add(s);
        
        if(minBracket==0){
            int remove=removeBracket(s);   
            if(remove==0) ans.add(s);
            return;
        }
        
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!='(' && s.charAt(i)!=')') continue;
            String L=s.substring(0,i);
            String R=s.substring(i+1);
            
            if(!set.contains(L+R)) getAns(L+R,minBracket-1,set,ans);
        }
    }
    
    public int removeBracket(String s){
        Stack<Character> stack=new Stack<>();
        
        for(int i=0;i<s.length();i++){
            char x=s.charAt(i);
            
            if(x=='(') stack.push(x);
            else if(x==')'){
                if(!stack.isEmpty() && stack.peek()=='(') stack.pop();
                else stack.push(x);
            } 
        }
        return stack.size();
    }
}