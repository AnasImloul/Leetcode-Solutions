class Solution {
    public int minSwapsCouples(int[] row) { // Union -Find pairs for 2
        Map<Integer,Integer> parents=new HashMap<>();
        int count=0;
        for(int i=0;i<row.length;i+=2){
            int parent=Math.min(row[i],row[i+1]);
            int child=Math.max(row[i],row[i+1]);
            parents.put(parent,child);
        }
        for(int i=0;i<row.length;i+=2){
            if((parents.containsKey(i) && parents.get(i)==(i+1)) 
               || (parents.containsKey(i-1) && parents.get(i-1)==i))
                continue;
            count+=1;
            int curChild=parents.get(i);
            int correctChildsChild = parents.get(i+1);
            parents.remove(i+1); // remove mapping of 1 in eg) //0,2 ; 1,3
            parents.put(Math.min(curChild,correctChildsChild),Math.max(curChild,correctChildsChild));
            // add mapping 2->7 , also place smaller number as parent for eg)//0,4 ; 1,3
            parents.put(i,i+1);
        }
        return count;
    }
}
