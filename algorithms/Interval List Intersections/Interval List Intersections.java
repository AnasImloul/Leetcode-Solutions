class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        int i = 0;
        int j = 0;
        
        List<int[]> ans = new ArrayList<>();
        
        while(i<firstList.length && j<secondList.length){
            int a[] = firstList[i];
            int b[] = secondList[j];
            
            if(b[0]<=a[1] && b[0]>=a[0])
                ans.add(new int[]{b[0], Math.min(a[1], b[1])});
            else if(a[0]<=b[1] && a[0]>=b[0])
                ans.add(new int[]{a[0], Math.min(a[1], b[1])});
            
            if(a[1]<=b[1])
                i++;
            else
                j++;
        }
        
        int res[][] = new int[ans.size()][2];
        
        for(i=0;i<ans.size();i++){
            res[i] = ans.get(i);
        }
        return res;
    }
}
