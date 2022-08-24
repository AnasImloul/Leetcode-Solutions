// Runtime: 3 ms (Top 39.15%) | Memory: 41.9 MB (Top 60.38%)
class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        HashSet<Integer> set = new HashSet<>();
        for(int i = 1; i<bound; i*=x){
            for(int j = 1; i+j <= bound; j*=y){
                set.add(i+j);
                if(y==1) break;
            }
            if(x==1) break;
        }
        return new ArrayList<>(set);
    }
}