// Runtime: 127 ms (Top 64.29%) | Memory: 49.7 MB (Top 100.00%)

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxSum = function(nums1, nums2) {
    let MODULO_AMOUNT = 10 ** 9 + 7;
    let result = 0;
    let ptr1 = 0;
    let ptr2 = 0;
    let n1 = nums1.length;
    let n2 = nums2.length;
    let section_sum1 = 0;
    let section_sum2 = 0;
    while(ptr1 < n1 || ptr2 < n2){
        if(ptr1 < n1 && ptr2 < n2 && nums1[ptr1] == nums2[ptr2]){
            result += Math.max(section_sum1, section_sum2) + nums1[ptr1];
            result %= MODULO_AMOUNT;
            section_sum1 = 0;
            section_sum2 = 0;
            ptr1 += 1;
            ptr2 += 1;
            continue;
        }

        if(ptr1 == n1 || (ptr2 != n2 && nums1[ptr1] > nums2[ptr2])){
            section_sum2 += nums2[ptr2];
            ptr2 += 1;
        }else{
            section_sum1 += nums1[ptr1];
            ptr1 += 1;
        }
    }
    result += Math.max(section_sum1, section_sum2);
    return result % MODULO_AMOUNT;
};