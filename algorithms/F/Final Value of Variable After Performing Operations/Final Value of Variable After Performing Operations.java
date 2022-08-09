class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int val = 0;
        for(int i = 0; i<operations.length; i++){
            if(operations[i].charAt(1)=='+') val++;
            else val--;
        }
        return val;
    }
}
