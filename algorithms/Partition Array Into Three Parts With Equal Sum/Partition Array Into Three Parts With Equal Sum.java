class Solution { 
     public boolean canThreePartsEqualSum(int[] arr) {
        int sum = 0;
        
        for (Integer no : arr) {
            sum += no;
        }
        if (sum % 3 != 0) {
            return false;
        }
        sum = sum / 3;
        int tempSum = 0;
        int count = 0;

        for (int i = 0; i < arr.length; i++) {
            tempSum += arr[i];
            if (tempSum == sum) {
                count++;
                tempSum = 0;
            }
        }

        return count >= 3;
    }
}
