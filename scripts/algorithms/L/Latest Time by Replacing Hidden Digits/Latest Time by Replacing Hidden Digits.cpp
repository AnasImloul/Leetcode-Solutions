class Solution {
public:
    string maximumTime(string time) {
        //for time[0]
        //if both characters of hour is ?, then hour is 23 then time[0] should be '2'("??:3?)".
        //if 2nd character of hour is <= 3, then hour can be in 20s  then time[0] should be '2'.
        //if 2nd character of hour is >3, then hour can only be in 10s  then time[0] should be '1'.
        if(time[0]=='?')
            time[0]= (time[1]<='3' || time[1]=='?') ? '2' : '1';
        //if 1st character of hour is 0 or 1, then hour can be 09 or 19 then time[1] should be '9'.
        //if 1st character of hour is 2, then hour can be 23 then time[1] should be '3'.
        if(time[1]=='?')
            time[1]= time[0]=='2' ? '3' : '9';
        //if both characters of minute is ? then minute is 59, or only 4th character is ? then 5_ so time[3] is always '5'.
        if(time[3]=='?')
            time[3]='5';
        //if 2nd character of minute is ?, then time[4] is '9'.
        if(time[4]=='?')
            time[4]='9';
        return time;
    }
};
