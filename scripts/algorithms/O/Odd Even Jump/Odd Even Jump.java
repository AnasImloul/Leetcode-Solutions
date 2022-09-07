// Runtime: 152 ms (Top 15.26%) | Memory: 54.5 MB (Top 75.57%)
class Solution {
    public int oddEvenJumps(int[] arr) {

        int len = arr.length;
        int minjmp[] = new int[len];
        int maxjmp[] = new int[len];

        TreeMap<Integer, Integer> map = new TreeMap<>();
        int evjmp, oddjmp;
        for(int i = len-1; i>=0; i--)
        {
            Integer minpos = map.floorKey(arr[i]);
            evjmp = (minpos != null)?map.get(minpos):len; //default len, to show not possible

            if(evjmp != len && (evjmp == len-1 || maxjmp[evjmp] == len-1))
                evjmp = len-1; //check the last pos reachability

            Integer maxpos = map.ceilingKey(arr[i]);
            oddjmp = (maxpos != null) ? map.get(maxpos):len;

            if(oddjmp != len && (oddjmp == len-1 || minjmp[oddjmp] == len-1))
                oddjmp = len-1;//check the last pos reachability

            minjmp[i] = evjmp; //specify possible jump path, if not possible assign len
            maxjmp[i] = oddjmp;//specify possible jump path, if not possible assign len

            map.put(arr[i],i); //put the current index
        }

        int res = 0;

        for(int i = 0; i< len-1; i++) {

            if(maxjmp[i] == len-1)
                res++;
        }

        return res+1; //since last position will always be the answer
    }

}