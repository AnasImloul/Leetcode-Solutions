class Solution {
    private List<Integer> res;
    public List<Integer> splitIntoFibonacci(String num) {
        dfs(0, num, -1, -1, new ArrayList<>());
        return res==null?new ArrayList<>():res;
    }
    private void dfs(int ptr, String s, int prev1, int prev2, List<Integer> list){
        if(ptr==s.length()) {
            if(list.size()>2){
                res = new ArrayList<>(list);
            }
            return;
        }
        else if(prev1==-1 || prev2==-1){
            if(s.charAt(ptr)=='0'){
                list.add(0);
                dfs(ptr+1, s, 0, prev1, list);
                if(res!=null) return;
                list.remove(0);
            }else{
                for(int i = ptr+1; i<=s.length();i++){
                    long n = Long.parseLong(s.substring(ptr, i));
                    if(n>=(long)Math.pow(2, 31)) break;
                    list.add((int)n);
                    dfs(i, s, (int)n, prev1, list);
                    if(res!=null) return;
                    list.remove(list.size()-1);
                }
            }
        }else{
            if(s.charAt(ptr)=='0'){
                if(prev1+prev2==0){
                    list.add(0);
                    dfs(ptr+1, s, 0, prev1, list);
                    if(res!=null) return;
                    list.remove(0);
                }
                return;
            }
            for(int i=ptr+1;i<=s.length();i++){
                long n = Long.parseLong(s.substring(ptr, i));
                if(n>=(long)Math.pow(2, 31)) break;
                if(n == prev1+prev2){
                    list.add((int)n);
                    dfs(i, s, (int)n, prev1, list);
                    if(res!=null) return;
                    list.remove(list.size()-1);
                }
            }
        }
    }
    
}
