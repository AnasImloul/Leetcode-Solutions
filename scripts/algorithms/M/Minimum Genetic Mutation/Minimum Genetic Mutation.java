// Runtime: 1 ms (Top 90.87%) | Memory: 42.6 MB (Top 7.49%)
class Solution {
    public int minMutation(String start, String end, String[] bank) {
        Set<String> set = new HashSet<>();
        for(String tmp: bank){
            set.add(tmp);
        }
        if(!set.contains(end)) return -1;
        if(start.equals(end)) return 0;
        char[] var = {'A','C','G','T'};
        Queue<String> q = new LinkedList<>();
        q.add(start);
        int count = 0;
        while(!q.isEmpty()){
            int size = q.size();
            for(int i = 0; i < size; i ++){
                String str = q.poll();
                char[] tmp = str.toCharArray();
                if(str.equals(end)) return count;
                for(int j = 0; j < 8; j ++){
                    char ch = tmp[j];
                    for(int k = 0; k < 4; k ++){
                        tmp[j] = var[k];
                        String node = new String(tmp);
                        if(set.contains(node)){
                            q.add(node);
                            set.remove(node);
                        }
                    }
                    tmp[j] = ch;
                }
            }
            count++;
        }
        return -1;
    }
}