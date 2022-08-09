

class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events,(a,b)->a[1]==b[1]?a[0]-b[0]:a[1]-b[1]);
        // here sorting the array on ths basis of last day because we want to finish the events which happens first,fist.
        
 TreeSet<Integer> set =new TreeSet<>();
        for(int i =1;i<=100000;i++){
            set.add(i);
        }
        //initliasing a tree set to check available days ;
        // a day can go maximum to 100000;
        int ans =0;
        for(int i =0;i<events.length;i++){
         Integer  temp = set.ceiling(events[i][0]);
            if(temp==null || temp >events[i][1])
                continue;
            else{
                set.remove(temp);
            ans +=1;
            }
        }
        return ans;        
    }
}
