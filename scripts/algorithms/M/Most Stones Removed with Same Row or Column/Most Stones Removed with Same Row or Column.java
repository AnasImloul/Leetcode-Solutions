// Runtime: 70 ms (Top 33.32%) | Memory: 48.7 MB (Top 77.91%)
class Solution {
    public int removeStones(int[][] stones) {
        int ret=0;
        DisjointSet ds=new DisjointSet(stones.length);

        for(int i=0;i<stones.length;i++) {
            for(int j=i+1;j<stones.length;j++) {
                int s1[]=stones[i];
                int s2[]=stones[j];

                if(s1[0]==s2[0] || s1[1]==s2[1]) {
                    ds.union(i, j);
                }
            }
        }
        // System.out.println(Arrays.toString(ds.sets));
        for(int i=0;i<ds.sets.length;i++) {
            if(ds.sets[i]<0)
                ret+=Math.abs(ds.sets[i])-1;
        }

        return ret;
    }

    class DisjointSet {
        public int sets[];

        public DisjointSet(int size) {
            sets=new int[size];
            Arrays.fill(sets, -1);
        }

        //
        // weighted union
        //union->return size in negative
        public int union(int idx1, int idx2) {
            int p1=find(idx1);
            int p2=find(idx2);

            if(p1==p2) { //same parent so directly returning size
                return sets[p1];
            }else {
                int w1=Math.abs(sets[p1]);
                int w2=Math.abs(sets[p2]);

                if(w1>w2) {
                    sets[p2]=p1;

                    //collapsing FIND
                    sets[idx1]=p1;
                    sets[idx2]=p1;

                    return sets[p1]=-(w1+w2);
                }else {
                    sets[p1]=p2;

                    //collapsing FIND
                    sets[idx1]=p2;
                    sets[idx2]=p2;

                    return sets[p2]=-(w1+w2);
                }
            }
        }

        // collapsing FIND
        //find parent
        public int find(int idx) {
            int p=idx;
            while(sets[p]>=0) {
                p=sets[p];
            }
            return p;
        }
    }
}