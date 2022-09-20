// Runtime: 74 ms (Top 75.46%) | Memory: 41.3 MB (Top 98.90%)
var middleNode = function(head) {
    var runner1 = head
    var runner2 = head?.next
    while(runner1 && runner2) {
        runner1 = runner1?.next
        runner2 = (runner2?.next)?.next
    }
    return runner1
};