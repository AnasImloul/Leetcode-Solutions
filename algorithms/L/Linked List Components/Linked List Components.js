var numComponents = function(head, nums) {
    let broken = true, count = 0;

    while (head) {
        if (nums.includes(head.val) && broken) {
            count++;
            broken = false;
        }
        else if (!nums.includes(head.val)) {
            broken = true;
        }

        // reset head as next
        head = head.next
    }

    // result
    return count;
};
