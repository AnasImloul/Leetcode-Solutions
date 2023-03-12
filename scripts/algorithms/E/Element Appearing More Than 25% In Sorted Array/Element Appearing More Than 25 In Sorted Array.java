class Solution {
    public int findSpecialInteger(int[] arr) {
        HashMap<Integer,Integer>hm=new HashMap<>();
        int comp=arr.length/4;
        for (int i:arr)
        {
            if (!hm.containsKey(i)){hm.put(i,1);}
            else
            {
                int val=hm.get(i);
                val++;
                hm.put(i,val);
            }
            if (hm.get(i)>comp){return i;}
        }
        return 0;
    }
}