class Solution {
    public int videoStitching(int[][] clips, int time) {
        Arrays.sort(clips , (x , y) -> x[0] == y[0] ? y[1] - x[1] : x[0] - y[0]);
        int n = clips.length;
        int interval[] = new int[2];
        int cuts = 0;
        while(true){
            cuts++;
            int can_reach = 0;
            for(int i = interval[0]; i <= interval[1]; i++){
                int j = 0;
                while(j < n){
                    if(clips[j][0] < i){
                        j++;
                    }
                    else if(clips[j][0] == i){
                        can_reach = Math.max(can_reach , clips[j][1]);
                        j++;
                    }
                    else{
                        break;
                    }
                }
                if(can_reach >= time) return cuts;
            }
            interval[0] = interval[1] + 1;
            interval[1] = can_reach;
            if(interval[0] > interval[1]) return -1;
        }
    }
}