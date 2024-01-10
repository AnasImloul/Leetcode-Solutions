// Runtime: 64 ms (Top 100.0%) | Memory: 42.70 MB (Top 85.71%)

/**
 * @param {number[]} nums
 * @param {number} n
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var rangeSum = function(nums, n, left, right) {
  var len = nums.length

  var prefix = [nums[0]]
  function buildPrefix() {
    for (var i = 1; i < len; i++) {
      prefix[i] = prefix[i - 1] + nums[i]
    }
  }

  buildPrefix()

  function countUnderSum(sum, cb) {
    var left = 0
    var count = 0
    var right = 0

    while (right < len) {
      let wholeSubSum = prefix[right] - (left === 0 ? 0 : prefix[left - 1])
      if (wholeSubSum <= sum) {
        count += right - left + 1
        cb && cb(left, right)
      } else {
        while (
          wholeSubSum > sum
        ) {
          if (left <= right) {
            wholeSubSum -= nums[left]
            left++
          } else {
            break
          }
        }
        count += right - left + 1
        cb && cb(left, right)
      }
      right++
    }

    return count
    
  }

  function calSubArraySumByRange(i, j) {
    var windowLen = j - i + 1
    var sum = 0
    while (windowLen > 0) {
      sum += nums[j] * windowLen
      windowLen--
      j--
    }
    return sum
  }

  function calSum(count) {
    var lowSum = findTheLowestSumThatSatisfyTheSpecficCount(count)
    var sum = 0 
    countUnderSum(lowSum, (i, j) => {
      sum += calSubArraySumByRange(i, j)
    })

    //This line is used to deal with some same value cases
    //Such as if the low value is 9, and we have 9 subarrays of which low value 
    //is 9. But the count is 8, so we must remove one of it.
    return sum - (countUnderSum(lowSum) - count) * lowSum
  }

  function findTheLowestSumThatSatisfyTheSpecficCount(count) {
    var l = 0
    var r = prefix[len - 1]
    while (l < r) {
      var mid = Math.floor((l + r) / 2)
      if (countUnderSum(mid) < count) {
        l = mid + 1
      } else {
        r = mid
      }
    }

    return l
  }

  return (calSum(right) - calSum(left - 1)) % (Math.pow(10, 9) + 7)

};

