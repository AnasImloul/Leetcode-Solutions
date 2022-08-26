// Runtime: 94 ms (Top 78.70%) | Memory: 44.9 MB (Top 73.58%)
var detectCycle = function(head) {
    let slowRunner = head
    let fastRunner = head

    while(fastRunner) {
        fastRunner = fastRunner.next?.next
        slowRunner = slowRunner.next

        if (fastRunner === slowRunner) {
            fastRunner = slowRunner
            slowRunner = head

            while (slowRunner !== fastRunner) {
                slowRunner = slowRunner.next
                fastRunner = fastRunner.next
            }

            return slowRunner
        }
    }

    return null
};