class Solution {
    int[] parent;
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        parent = new int[26];
        for(int i=0;i<26;i++)
            parent[i]=i;
        for(int i=0;i<s1.length();i++){
            int u = find(s1.charAt(i)-'a');
            int v = find(s2.charAt(i)-'a');
            if(u<v)
              parent[v]=u;
            else if(u>v)
              parent[u]=v;
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<baseStr.length();i++)
            sb.append((char)(find(baseStr.charAt(i)-'a')+'a'));
        return sb.toString();
    }

    private int find(int u){
        return parent[u]==u? u:find(parent[u]);
    }
}