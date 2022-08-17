class Solution {
     public static class Pair {
            int x;
            int y;
        
            Pair(int x, int y) {
              this.x = x;
              this.y = y;
            }
        
          }
    public int[][] outerTrees(int[][] trees) {
        List<Pair> points=new ArrayList<>();
        for(int[] point:trees){
           points.add(new Pair(point[0],point[1])); 
        }

        List<Pair> res=new ArrayList<>();
        if(points.size()==1){
            return trees;
        }
        int n=points.size();
        Collections.sort(points,(a,b)->a.y==b.y?a.x-b.x:a.y-b.y);
        HashSet<ArrayList<Integer>> dup=new HashSet<>();
        Stack<Pair> hull=new Stack<>();
        
        hull.push(points.get(0));
        hull.push(points.get(1));
        
        for(int i=2;i<n;i++){
            Pair top=hull.pop();
            while(!hull.isEmpty()&&ccw(hull.peek(),top,points.get(i))<0){
                top=hull.pop();
            }
            hull.push(top);
            hull.push(points.get(i));
        }
        for(int i=n-2;i>=0;i--){
            Pair top=hull.pop();
            while(!hull.isEmpty()&&ccw(hull.peek(),top,points.get(i))<0){
                top=hull.pop();
            }
            hull.push(top);
            hull.push(points.get(i));
        }

        for(Pair p:hull){
            ArrayList<Integer> tmp=new ArrayList<>();
            tmp.add(p.x);
            tmp.add(p.y);
            if(dup.contains(tmp))continue;
            dup.add(tmp);
            res.add(p);
        }

        int[][] ans=new int[res.size()][2];
        int i=0;
        for(Pair p:res){
            ans[i][0]=p.x;
            ans[i][1]=p.y;
            i++;
        }
        
        return ans;
        
    }

    public int ccw(Pair a,Pair b,Pair c){
        double cp=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
        if(cp<0)return -1;
        else if(cp>0)return 1;
        else return 0;
    }
}
