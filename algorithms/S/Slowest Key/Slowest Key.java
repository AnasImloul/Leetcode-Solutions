class Solution {
    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int max = releaseTimes[0];
        char ch = keysPressed.charAt(0);
        for(int i=1;i<releaseTimes.length;i++){
            int diff = releaseTimes[i]-releaseTimes[i-1];
            if( diff >= max){
                if(diff>max)
                    ch = keysPressed.charAt(i);
                else if(diff== max)
                    ch = (char)Math.max((int) ch, (int) keysPressed.charAt(i));
                max = diff;
            }   
        }
        return ch;      
    }    
}
