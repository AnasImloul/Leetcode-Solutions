// Runtime: 74 ms (Top 83.33%) | Memory: 10.20 MB (Top 11.11%)

func getMaxLen(nums []int) int {
    n := len(nums)
    pos := make([]int, n)
    neg := make([]int, n)
    if nums[0] > 0 {
        pos[0] = 1
    } else if nums[0] < 0 {
        neg[0] = 1
    }
    ans := pos[0]
    for i := 1; i < n; i++ {
        if nums[i] > 0 {
            pos[i] = 1 + pos[i - 1]
            if neg[i - 1] > 0 {
                neg[i] = 1 + neg[i - 1]
            } else {
                neg[i] = 0
            }
        } else if nums[i] < 0 {
            if neg[i - 1] > 0 {
                pos[i] = 1 + neg[i - 1]
            } else {
                pos[i] = 0
            }
            neg[i] = 1 + pos[i - 1]
        }
        ans = Max(ans, pos[i])
    }
    return ans
}

func Max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
