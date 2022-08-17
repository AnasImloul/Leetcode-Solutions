class Solution {
    public String maximumTime(String time) {
        char[] times = time.toCharArray();
        //for times[0]
        //if both characters of hour is ?, then hour is 23 then times[0] should be '2'("??:3?)".
        //if 2nd character of hour is <= 3, then hour can be in 20s  then times[0] should be '2'.
        //if 2nd character of hour is >3, then hour can only be in 10s  then times[0] should be '1'.
        if(times[0]=='?')
            times[0]= (times[1]<='3' || times[1]=='?') ? '2' : '1';
        //if 1st character of hour is 0 or 1, then hour can be 09 or 19 then times[1] should be '9'.
        //if 1st character of hour is 2, then hour can be 23 then times[1] should be '3'.
        if(times[1]=='?')
            times[1]= times[0]=='2' ? '3' : '9';
        //if both characters of minute is ? then minute is 59, or only 4th character is ? then 5_ so times[3] is always '5'.
        if(times[3]=='?')
            times[3]='5';
        //if 2nd character of minute is ?, then times[4] is '9'.
        if(times[4]=='?')
            times[4]='9';
        return new String(times);
    }
}
