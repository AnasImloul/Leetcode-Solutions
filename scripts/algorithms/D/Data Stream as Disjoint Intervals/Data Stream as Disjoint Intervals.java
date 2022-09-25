// Runtime: 169 ms (Top 23.71%) | Memory: 73.9 MB (Top 52.59%)
class SummaryRanges {

    Map<Integer, int[]> st;
    Map<Integer, int[]> end;
    Set<Integer> pending;
    int[][] prev = new int[0][];
    Set<Integer> seen = new HashSet<>();
    int INVALID = -1;
    public SummaryRanges() {
        st = new HashMap<>();
        end= new HashMap<>();
        pending = new HashSet<>();
    }

    public void addNum(int val) { // [TC: O(1)]
        if (!seen.contains(val)){ // only add if not seen.
            pending.add(val); // pending processing list
        }
    }

    public int[][] getIntervals() { // [TC: O(pending list length (= k)) best case (all merges), O(n)+O(klogk) worst case (all inserts)]
        Set<int[]> addSet = new HashSet<>();
        for (int n : pending){
            if (st.containsKey(n+1)&&end.containsKey(n-1)){ // merge intervals on both ends, a new interval form -> add to addSet
                int[] s = st.get(n+1);
                int[] e = end.get(n-1);
                int[] m = new int[]{e[0], s[1]};
                st.remove(n+1);
                end.remove(n-1);
                st.put(m[0], m);
                end.put(m[1], m);
                s[0]=e[0]=INVALID;
                addSet.remove(s); // may be in addSet, remove them
                addSet.remove(e);
                addSet.add(m);
            }else if (st.containsKey(n+1)){ // merge with the next interval, no other action required.
                st.get(n+1)[0]--;
                st.put(n, st.get(n+1));
                st.remove(n+1);
            }else if (end.containsKey(n-1)){ // merge with the previous interval, no other action required.
                end.get(n-1)[1]++;
                end.put(n, end.get(n-1));
                end.remove(n-1);
            }else{ // new interval -> add to AddSet
                int[] m = new int[]{n, n};
                addSet.add(m);
                st.put(n, m);
                end.put(n, m);
            }
        }

        seen.addAll(pending);
        pending.clear(); // remember to clear the pending list.

        if (!addSet.isEmpty()){ // IF there is no new intervals to insert, we SKIP this.
            List<int[]> addList = new ArrayList<>(addSet);
            addList.sort(Comparator.comparingInt(o -> o[0]));
            int i = 0, j = 0; // two pointers because both prev & addList are sorted.
            List<int[]> ans = new ArrayList<>();
            while(i < prev.length || j < addList.size()){
                if (i < prev.length && prev[i][0]==INVALID){
                    i++;
                }else if (j == addList.size() || i < prev.length && prev[i][0]<addList.get(j)[0]){
                    ans.add(prev[i++]);
                }else if (i == prev.length || prev[i][0]>addList.get(j)[0]){
                    ans.add(addList.get(j++));
                }
            }
            prev = ans.toArray(new int[0][]);
        }

        return prev;
    }
}