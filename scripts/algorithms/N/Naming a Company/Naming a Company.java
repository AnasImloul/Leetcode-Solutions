class Solution {
    public long distinctNames(String[] ideas) {
        // HashSet + String Manipulation; TC: O(26*26*n); SC: O(26*n) 
        HashSet<String> [] arr = new HashSet[26];
        for(int i=0; i<26; i++) {
            arr[i] = new HashSet<>();
        }
        for(String s: ideas) {
            arr[s.charAt(0)-'a'].add(s.substring(1));
        }
        long ans=0, cnt;
        for(int i=0; i<26; i++) {
            for(int j=i+1; j<26; j++) {
                cnt=0;
                for(String str: arr[j]) {
                    if(arr[i].contains(str)) cnt++;
                }
                ans+=2*(arr[i].size()-cnt)*(arr[j].size()-cnt);
            }
        }
        return ans;
    }
}
