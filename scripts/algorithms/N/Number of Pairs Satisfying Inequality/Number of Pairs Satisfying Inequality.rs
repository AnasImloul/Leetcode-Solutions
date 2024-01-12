// Runtime: 32 ms (Top 100.0%) | Memory: 4.30 MB (Top 66.67%)

#[derive(Clone)]
pub struct SegmentTree<T, F> {
    n: usize,

    inner: Vec<T>,
    op: F,
}

impl<T: Default + Clone, F: Fn(T, T) -> T> SegmentTree<T, F> {
    pub fn new(vec: Vec<T>, op: F) -> Self {
        let n = vec.len();
        let mut inner = vec![T::default(); n];
        inner.extend(vec.into_iter());

        for i in (1..n).rev() {
            inner[i] = op(inner[i * 2].clone(), inner[i * 2 + 1].clone());
        }

        Self { n, inner, op }
    }
}

impl<T: Default + Clone, F: Fn(T, T) -> T> SegmentTree<T, F> {
    pub fn query(&self, p0: usize, p1: usize) -> T {
        if p0 >= p1 { return T::default(); }
        if p1 > self.n { panic!("out of bound: {}", p1); }

        let l = p0 + self.n;
        let r = p1 + self.n - 1;

        self.query_inner(l, r)
    }

    fn query_inner(&self, l: usize, r: usize) -> T {
        let mut ret = T::default();
        if l > r { return ret; }

        if l % 2 > 0 { ret = (self.op)(ret, self.inner[l].clone()); }

        if r % 2 < 1 { ret = (self.op)(ret, self.inner[r].clone()); }

        let (l_next, r_next) = ((l + 1) / 2, (r - 1) / 2);
        ret = (self.op)(ret, self.query_inner(l_next, r_next));

        ret
    }

    pub fn update(&mut self, index: usize, val_next: T) {
        if index >= self.n { panic!("out of bound"); }

        let i = index + self.n;
        self.inner[i] = val_next;

        self.update_inner(i / 2);
    }

    fn update_inner(&mut self, i: usize) {
        if i < 1 { return; }

        let (child_0, child_1) = (i * 2, i * 2 + 1);
        self.inner[i] = (self.op)(self.inner[child_0].clone(), self.inner[child_1].clone());

        self.update_inner(i / 2);
    }
}

impl Solution {
    pub fn number_of_pairs(
        vec_0: Vec<i32>,
        vec_1: Vec<i32>,
        diff: i32
    ) -> i64 {
        let vec = vec_0.into_iter()
            .zip(vec_1.into_iter())
            .map(|(e0, e1)| e0 + 20_000 - e1)
            .map(|e| e as u32)
            .collect::<Vec<_>>();
        // println!("vec: {:?}", vec);

        let mut ret = usize::MIN;

        let mut tree = SegmentTree::new(
            vec![usize::MIN; 50_007],
            |op0, op1| op0 + op1
        );
        for e in vec {
            let mut threshold = e as i32;
            threshold += diff + 1;
            let threshold = threshold.max(0) as usize;
            
            let _ret = tree.query(usize::MIN, threshold);
            
            let count = tree.query(e as usize, e as usize + 1);
            tree.update(e as usize, count + 1);

            ret += _ret;
        }

        ret as i64
    }
}
