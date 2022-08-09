class Solution {
    public int maxDiff(int num) {
        int[] arr = new int[String.valueOf(num).length()];
        for (int i = arr.length - 1; i >= 0; i--){
            arr[i] = num % 10;
            num /= 10;
        }
        return max(arr.clone()) - min(arr);
    }

    private int max(int[] arr){ // find max
        for (int i = 0, t = -1; i < arr.length; i++){
            if (t == -1 && arr[i] != 9){
                t = arr[i];
            }
            if (t == arr[i]){
                arr[i] = 9;
            }
        }
        return parse(arr);
    }

    private int min(int[] arr){ // find min
        int re = arr[0] == 1? 0 : 1;
        int t = arr[0] == 1? -1 : arr[0];
        for (int i = 0; i < arr.length; i++){
            if (t == -1 && arr[i] != 0 && arr[i] != arr[0]){
                t = arr[i];
            }
            if (t == arr[i]){
                arr[i] = re;
            }
        }
        return parse(arr);
    }

    private int parse(int[] arr){
        int ans = 0;
        for (int i = 0; i < arr.length; i++){
            ans = 10 * ans + arr[i];
        }
        return ans;
    }
}
