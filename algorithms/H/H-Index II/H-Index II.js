/**
 * The binary search solution.
 * 
 * Time Complexity:  O(log(n))
 * Space Complexity: O(1)
 * 
 * @param {number[]} citations
 * @return {number}
 */
var hIndex = function(citations) {
	const n = citations.length

	let l = 0
	let r = n - 1

	while (l <= r) {
		const m = Math.floor((l + r) / 2)

		if (citations[m] > n - m) {
			r = m - 1
			continue
		}

		if (citations[m] < n - m) {
			l = m + 1
			continue
		}

		return citations[m]
	}

	return n - l
}
