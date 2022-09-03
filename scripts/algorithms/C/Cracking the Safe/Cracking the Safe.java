// Runtime: 91 ms (Top 5.23%) | Memory: 124.1 MB (Top 5.06%)

class Solution {
    String ans;
    public String crackSafe(int n, int k) {
        int minLen = (int)Math.pow(k, n) + (n -1);

        dfs("", n ,k, new HashSet<String>(),minLen);
        return ans;
    }

    private void dfs(String s, int n, int k, HashSet<String>visited,int minLen){
        if (s.length() == minLen){
            ans = s;
            return;
        }
        if (s.length() > minLen){return;}

        for (int i = 0; i < k; i++){
            s += String.valueOf(i);
            String lastN = s.substring(Math.max(0,s.length() - n), s.length());
            //If already in hashset, rollback and continue;
            if (visited.contains(lastN)){
                s = s.substring(0, s.length() - 1);
                continue;}
            if(lastN.length() == n){ // only put n length string in hashset
               visited.add(lastN);
            }

            dfs(s,n,k,visited,minLen);
            if (visited.size() == minLen - n + 1){return;} // if hashset contains all possible combinations just return
            visited.remove(lastN);
            s = s.substring(0, s.length() - 1);
        }

    }
}
