class Solution {
    public boolean checkIfExist(int[] arr) {
        /*
            执行用时：3 ms, 在所有 Java 提交中击败了29.57%的用户
            内存消耗：41 MB, 在所有 Java 提交中击败了42.27%的用户
            2022年8月3日 14:36
        */
        int l, mid = 0, r;
        int val1, val2;
        Arrays.sort(arr); // 排序
        for(int i=0; i < arr.length - 1; i++){ // 只要搜寻 n - 1 个，因为最后一个数不会有倍数出现
            l = 0;
            r = arr.length - 1;
            while(l <= r){
                mid = (l + r) / 2; // 目前位置
                val1 = arr[mid]; // 目前位置的数值
                val2 = arr[i] * 2; // 要寻找的目标
                if(val1 == val2 && mid != i) // arr[mid] 必須和 arr[i] * 2 且不同位置
                    return true;
                else if(val2 < val1) // 目标在目前位置的左边，所以要往左边找
                    r = mid - 1;
                else // 目标在目前位置的右边，所以要往右边找
                    l = mid + 1;
            }
        }
        return false;
    }
}
