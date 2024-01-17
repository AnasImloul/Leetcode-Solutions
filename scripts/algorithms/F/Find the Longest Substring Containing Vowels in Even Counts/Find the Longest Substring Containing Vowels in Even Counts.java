// Runtime: 12 ms (Top 87.39%) | Memory: 45.40 MB (Top 86.55%)

class Solution {

    // taken help as for my code TLE T.C = (n^2);

/*    static boolean check(String s){
        int n = s.length();

        int arr[] = new int[26];

        for(int i=0; i<n; i++){
            int a = s.charAt(i)-97;
            arr[a]++;
        }

        if(arr[0]%2!=0 || arr[4]%2!=0 || arr[8]%2!=0 || arr[14]%2!=0 ||arr[20]%2!=0) return false;
        else return true; 
    }

    static int helper(String str){
        int ans = 0;
        int n = str.length();
        StringBuilder s = new StringBuilder(str);

        for(int k=1; k<=n; k++){
            for(int i=0; i<=n-k; i++){
                String x = s.substring(i,i+k);
                if(check(x)){
                    ans = Math.max(ans,k);
                    break;
                }
            }
        }
        return ans;
    }

    */
    public int findTheLongestSubstring(String s) {

        int[] map = new int[32];
        Arrays.fill(map, -2);
        map[0] = -1;
        int n = s.length(), mask = 0, len = 0;
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') mask ^= 1 << (4 -
                    (ch == 'a' ? 0 : ch == 'e' ? 1 : ch == 'i' ? 2 : ch == 'o' ? 3 : 4));
            if (map[mask] == -2) map[mask] = i;
            else len = Math.max(len, i - map[mask]);
        }
        return len;
    }
}


