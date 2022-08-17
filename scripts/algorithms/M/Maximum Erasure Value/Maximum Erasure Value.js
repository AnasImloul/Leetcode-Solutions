var maximumUniqueSubarray = function(nums) {
    let nmap = new Int8Array(10001), total = 0, best = 0
    for (let left = 0, right = 0; right < nums.length; right++) {
        nmap[nums[right]]++, total += nums[right]
        while (nmap[nums[right]] > 1)
            nmap[nums[left]]--, total -= nums[left++]
        best = Math.max(best, total)
    }
    return best
};
