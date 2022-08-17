var swapNodes = function(head, k) {
    let A = head, B = head, K, temp
    for (let i = 1; i < k; i++) A = A.next
    K = A, A = A.next
    while (A) A = A.next, B = B.next
    temp = K.val, K.val = B.val, B.val = temp
    return head
};
