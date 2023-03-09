class Solution {
public:
    int minOperations(vector<int>& nums) {
        int k = nums.size() - 1;  // max size of sliding window is the target gap between min and max elements
        sort(nums.begin(), nums.end()); // sorting in O(nlogn) time so that we can remove duplicates and slide over the array
        int newLen = unique(nums.begin(), nums.end()) - nums.begin();  // remove adjacent duplicates with STL unique
        int l = 0, r = 0, fin = 1; //  initialize left and right pointers and the minimum elements in the window
        while (r < newLen) {  // iterate over the new unique array
            if (l == r)
                r++;  //  if the window is closed, open it ;)
            else if (nums[r] - nums[l] > k)
                l++;  //  if window becomes bigger than allowed size, shrink it
            else {
                fin = max(fin, r - l + 1);  //  if window is in allowed size, maximize the number of elements in the window
                r++;  // slide the right side 
            }
        }  //  at this point, we have maximized the number of elements at any time inside the window
        return k - fin + 1;   //  return the missing elements in that window
    }
};