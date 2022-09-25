// Runtime: 786 ms (Top 7.64%) | Memory: 42.4 MB (Top 87.50%)
class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        List<Integer>list=new ArrayList<>();
        int ts=tomatoSlices;
        int cs=cheeseSlices;
        if (ts<cs*2 || ts>cs*4 || ts%2!=0 || (ts==0 && cs>0) || (cs==0 && ts>0))
        {
            return list;
        }
        int cnt=0;
        while(ts>0 && cs>0 && ts!=cs*2)
        {
            ts-=4;
            cnt++;
            cs--;
        }
        list.add(cnt);
        list.add(cs);
        return list;
    }
}