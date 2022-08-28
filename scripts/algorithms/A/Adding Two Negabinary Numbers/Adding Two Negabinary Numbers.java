// Runtime: 1 ms (Top 100.00%) | Memory: 42.4 MB (Top 98.61%)
class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {

        List<Integer> result = new ArrayList();
        int pointer_1 = arr1.length-1;
        int pointer_2 = arr2.length-1;

        int carry = 0;
        int current = 0;
        int sum = 0;

        while(pointer_1 >= 0 || pointer_2 >= 0){

            int a = (pointer_1 >=0)? arr1[pointer_1]: 0;
            int b = (pointer_2 >=0)? arr2[pointer_2]: 0;

            sum = a+b+carry;
            if(sum == 3){
                current = 1; carry = -1;
            }
            else if(sum == 2){
                current = 0; carry = -1;
            }
            else if(sum == 1){
                current = 1; carry = 0;
            }
            else if(sum == 0){
                current = 0; carry = 0;
            }
            else if(sum == -1)
            {
                current = 1; carry = 1;
            }

            result.add(current);
            pointer_1--;
            pointer_2--;
        }

        if(carry != 0)
            result.add(1);
        if(carry == -1)
            result.add(1);

        // Removing leading zeros
        int idx = result.size()-1;
        while(idx > 0 && result.get(idx) == 0)
            idx--;

        // reversing the list and adding the result to an array
        int len = idx+1;
        int[] negaBinary = new int[len];
        for(int i=0; i<len; i++){
            negaBinary[i] = result.get(idx);
            idx--;
        }

        return negaBinary;

    }
}