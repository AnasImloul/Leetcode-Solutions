// Runtime: 31 ms (Top 67.39%) | Memory: 49 MB (Top 10.87%)
class Solution {
    public boolean isSolvable(String[] words, String result) {
        boolean[] l = new boolean[26]; // init for all info here in this huge block
        int[] a = new int[26];
        int[] b = new int[26];
        int[] r = new int[result.length()];
        Arrays.fill(a, -1);
        Arrays.fill(b, -1);
        for (int i = 0; i < result.length(); i++){
            r[i]=result.charAt(i)-'A';
        }
        int max = 0;
        for (String s : words){
            max = Math.max(s.length(), max);
        }
        List[] d = new ArrayList[max];
        Arrays.setAll(d, o -> new ArrayList<>());
        for (String s : words){
            for (int i = s.length()-1, j=max-1; i >= 0; i--, j--){
                d[j].add(s.charAt(i)-'A');
            }
            if (s.length()>1){
                l[s.charAt(0)-'A']=true;
            }
        }
        return max==result.length()||max==result.length()-1?
               solve(max-1, 0, l, d, r, a, b):false;
    }

    private boolean solve(int idx, int carry, boolean[] l, List<Integer>[] d, int[] r, int[] a, int[] b){
        if (idx == -1){ // this function indicates that we are done with a list, moving onto the next list
            return r.length>d.length? carry > 0 &&
                   ok(carry, r[0], a, b) : carry == 0;
        }
        return solveD(0, idx, carry, l, d, r, a, b);
    }

    private boolean solveD(int cur, int idx, int carry, boolean[] l, List<Integer>[] d, int[] r, int[] a, int[] b){
        if (cur == d[idx].size()){ // this function solves for what is within a list.
            int sum = carry;
            for (int wh : d[idx]){
                sum += a[wh];
            }
            int aa = r[idx+(r.length>d.length?1:0)], bb = sum%10, o = a[aa];
            if ((bb>0||!l[aa]) && ok(bb, aa, a, b)){
                if (a[aa]==-1){
                    a[aa]=bb;
                    b[bb]=aa;
                }
                if (solve(idx-1, sum/10, l, d, r, a, b)){
                    return true;
                }
                if (o == -1){
                    a[aa]=b[bb]=-1;
                }
            }
            return false;
        }
        int w = d[idx].get(cur);
        if (a[w] >= 0){
            return solveD(cur+1, idx, carry, l, d, r, a, b);
        }
        for (int i = l[w]?1:0; i < 10; i++){
            if (b[i] == -1){
                a[w]=i;
                b[i]=w;
                if (solveD(cur+1, idx, carry, l, d, r, a, b)){
                    return true;
                }
                a[w]=b[i]=-1;
            }
        }
        return false;
    }

    private boolean ok(int d, int c, int[] a, int[] b){ // check if there is a conflict.
        return a[c] == -1 && b[d] == -1
            || a[c] == d && b[d] == c;
    }
}