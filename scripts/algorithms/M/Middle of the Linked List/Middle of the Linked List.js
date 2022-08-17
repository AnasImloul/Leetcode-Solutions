var middleNode = function(head) {
    var runner1 = head
    var runner2 = head?.next
    while(runner1 && runner2) {
        runner1 = runner1?.next
        runner2 = (runner2?.next)?.next
    }
    return runner1
};
