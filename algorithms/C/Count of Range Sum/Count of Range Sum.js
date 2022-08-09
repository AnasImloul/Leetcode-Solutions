function SegmentTreeNode(tl, tr) {
    this.sum = 0;
    this.left = null;
    this.right = null;
    this.tl = tl; // tree left boundary
    this.tr = tr; // tree right boundary
}

const build = (a, tl, tr) => {
    if (tl > tr) return null;
    let stn = new SegmentTreeNode(a[tl], a[tr]);
    if (tl == tr) return stn;
    let mid = tl + tr >> 1;
    stn.left = build(a, tl, mid);
    stn.right = build(a, mid + 1, tr);
    return stn;
};

const update = (stn, newVal) => {
    if (stn == null) return;
    if (newVal >= stn.tl && newVal <= stn.tr) {
        stn.sum++;
        update(stn.left, newVal);
        update(stn.right, newVal);
    }
};

const sumUtil = (stn, l, r) => {
    if (stn == null) return 0;
    if (l <= stn.tl && r >= stn.tr) return stn.sum;
    if (r < stn.tl || l > stn.tr) return 0;
    return sumUtil(stn.left, l, r) + sumUtil(stn.right, l, r);
};

const countRangeSum = (a, lower, upper) => {
    let an = a.length;
    let pre = new Set();
    let sum = 0;
    for (const e of a) {
        sum += e;
        pre.add(sum);
    }
    let u = [...pre];
    let un = u.length;
    u.sort((x, y) => x - y);
    let root = build(u, 0, un - 1);
    let res = 0;
    for (let i = an - 1; ~i; i--) {
        update(root, sum);
        sum -= a[i];
        res += sumUtil(root, lower + sum, upper + sum);
    }
    return res;
};
