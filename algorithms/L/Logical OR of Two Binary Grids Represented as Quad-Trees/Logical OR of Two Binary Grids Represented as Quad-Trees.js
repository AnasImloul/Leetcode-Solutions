var intersect = function(quadTree1, quadTree2) {
    if (!quadTree1.isLeaf && !quadTree2.isLeaf) {
        const tl = intersect(quadTree1.topLeft, quadTree2.topLeft)
        const tr = intersect(quadTree1.topRight, quadTree2.topRight)
        const bl = intersect(quadTree1.bottomLeft, quadTree2.bottomLeft)
        const br = intersect(quadTree1.bottomRight, quadTree2.bottomRight)
        if (
            tl.isLeaf && tr.isLeaf && bl.isLeaf && br.isLeaf &&
            tl.val === tr.val && tr.val === bl.val && bl.val === br.val
        ) {
            return tl
        } else {
            return new Node(true, false, tl, tr, bl, br)   
        }
    } else if (
        (quadTree2.isLeaf && quadTree2.val) ||
        (quadTree1.isLeaf && !quadTree1.val)
    ) {
        return quadTree2
    } else if (
        (quadTree1.isLeaf && quadTree1.val) ||
        (quadTree2.isLeaf && !quadTree2.val)
    ) {
        return quadTree1
    }
    throw new Error('it\'s not possible')
};
