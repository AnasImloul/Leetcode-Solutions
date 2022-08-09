class Solution {
    public String longestDupSubstring(String s) {
        long[] e = new long[s.length()+1];
        long h = 1;
        int p = 991919;
        long M = 957689076713L;
        for (int i = 0; i < e.length; i++){
            e[i]=h;
            h=h*p%M;
        }
        int lo = 0, hi = s.length(), st = 0, end = 0;
        while(lo < hi){
            int mid = (lo+hi+1)>>1;
            Set<Long> seen = new HashSet<>();
            long hash = 0;
            boolean ok=false;
            for (int i = 0; i < s.length() && !ok; i++){
                hash = (hash*p+s.charAt(i))%M;
                if (i >= mid){
                    hash = (hash - e[mid]*(s.charAt(i-mid))%M+M)%M;
                }
                if (i >= mid-1 && !seen.add(hash)){
                    end = i;
                    st = i-mid+1;
                    ok=true;
                }
            }
            if (ok){
                lo=mid;
            }else{
                hi=mid-1;
            }
        }
        return lo == 0? "": s.substring(st, end+1);
    }
}
