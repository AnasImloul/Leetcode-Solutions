var SummaryRanges = function() {
    this.tree = null // { val, left?, right? }
};

/** 
 * @param {number} val
 * @return {void}
 */
SummaryRanges.prototype.addNum = function(val) {
    if (!this.tree) {
        this.tree = { val }
    } else {
        let node = this.tree
        let parent, side
        while (node) {
            if (node.val === val) { return }
            parent = node
            side = node.val > val ? 'left' : 'right'
            node = node[side]
        }
        parent[side] = { val }
    }
};

/**
 * @return {number[][]}
 */
SummaryRanges.prototype.getIntervals = function() {
    // travel from left to right
    // generate intervals
	// > (x === last[1] + 1) ? update last[1] : create a new one
    const travel = (node, check) => {
        if (!node) { return }
        travel(node.left, check)
        check(node.val)
        travel(node.right, check)
    }
    const result = []
    const check = val => {
        if (!result.length || val > result[result.length - 1][1] + 1) {
			result.push([val, val])
		} else {
			result[result.length - 1][1] = val
        }
    }
    travel(this.tree, check)
    return result
};

/** 
 * Your SummaryRanges object will be instantiated and called as such:
 * var obj = new SummaryRanges()
 * obj.addNum(val)
 * var param_2 = obj.getIntervals()
 */
