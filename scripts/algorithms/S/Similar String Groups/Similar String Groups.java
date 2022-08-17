class Solution {
    public int numSimilarGroups(String[] strs) {
        boolean[] visited = new boolean[strs.length]; // record the word that we checked
        int res = 0;
        for (int i = 0; i < strs.length; i++) {
            if (!visited[i]) {
                res++;
                dfs(strs, visited, i);
            }
        }
        return res;
    }
    
    void dfs(String[] strs, boolean[] visited, int index) { // explore all similar words we can explore
        visited[index] = true;
        String curr = strs[index];
        for (int i = 0; i < strs.length; i++) {
            if (!visited[i] && isSimilar(curr, strs[i])) {
                dfs(strs, visited, i);
            } 
        }
    }
    
    boolean isSimilar(String a, String b) {
        int diff = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diff++;
                if (diff > 2) return false;
            }
        }
        return true;
    }
}
