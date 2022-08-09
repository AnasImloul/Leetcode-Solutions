class Solution {

public int chalkReplacer(int[] chalk, int k) {
    long sum = 0;
    for (int c : chalk) {
        sum += c;
    }
    long left = k % sum; 
    for (int i = 0; i < chalk.length; i++){
        if(left >= chalk[i]){ 
            left -= chalk[i];
        } else {    
            return i;
        }
    }
    return -1;  //just for return statement, put whatever you want here
}
}