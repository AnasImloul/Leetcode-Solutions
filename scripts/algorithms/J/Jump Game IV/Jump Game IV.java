// Runtime: 147 ms (Top 48.60%) | Memory: 103.8 MB (Top 70.82%)
/*
Here we are using map and queue
map for storing the array elements and where are the other indices of the same element
and queue for BFS

Initially we start with 0 index
So we offer it to the queue
Now until the queue is empty we have to do few things for a given position
i> check the next index (i+1)
ii> check the previous index(i-1)
iii> check all the indices of the list whih are present in the map
once these three things have been done we will
remove the element that is arr[i]
because if we did not remove it we are going to do the same repeated task over and over again
and this will result in stack overflow
so it is important to remove the indices which have been visited once
every time we check the queue we incease the answer because viewing a queue means that
we are not at the last index

I hope the idea was clear :) you'll understand better when you see the code
*/
class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;

        if(n <= 1) return 0;
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for(int i = 0;i < arr.length ; i++) {
            if(!mp.containsKey(arr[i])) {
                mp.put(arr[i],new ArrayList<>());
            }
            List<Integer> ls = mp.get(arr[i]);
            ls.add(i);
        }
        //System.out.print(mp);
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        int ans = 0;
        while(!q.isEmpty()) {
            ans++;
            int size = q.size();
            for(int i = 0;i < size;i++)
            {
                int j = q.poll();
                //adding j+1
                if(j+1 < n && mp.containsKey(arr[j+1])) {
                    if(j+1 == n-1) return ans;
                    q.offer(j+1);
                }
                //adding j-1
                if(j-1 > 0 && mp.containsKey(arr[j-1])) {
                    q.offer(j-1);
                }

                //adding list indices
                if(mp.containsKey(arr[j])) {
                    for(int k : mp.get(arr[j])) {
                        //if(k == n-1) return ans;
                        if(k != j) {
                             if(k == n-1) return ans;
                            q.offer(k);
                        }
                    }
                    mp.remove(arr[j]);
                }
             }
        }
        return ans;
    }
}