// Runtime: 3 ms (Top 75.0%) | Memory: 2.25 MB (Top 75.0%)

pub fn normalize(
    mut vec: [Vec<u8>; 3],
    diff: u8,
) -> Option<[Vec<u8>; 3]> {
    if diff < 1 { return Some(vec); }

    if vec[1].is_empty() && vec[2].is_empty() {
        return None;
    }

    if vec[1].is_empty() {
        vec[2].pop();
        return normalize(vec, (diff + 1) % 3);
    }

    if vec[2].is_empty() {
        vec[1].pop();
        return normalize(vec, (diff + 2) % 3);
    }

    // both non-empty
    vec[diff as usize].pop();
    Some(vec)
}

impl Solution {
    fn preproc(mut vec: Vec<i32>) -> ([Vec<u8>; 3], u8) {
        vec.sort_unstable();
        vec.reverse();
        let diff = vec.iter().sum::<i32>() as u32;
        let diff = (diff % 3) as u8;

        let mut ret = [vec![], vec![], vec![]];

        for e in vec {
            ret[e as usize % 3].push(e as u8);
        }

        (ret, diff)
    }

    fn _impl(vec: Vec<i32>) -> Option<Vec<u8>> {
        let (vec, diff) = Self::preproc(vec);
        let [mut vec_0, mut vec_1, mut vec_2] = normalize(vec, diff)?;

        vec_0.append(&mut vec_1);
        vec_0.append(&mut vec_2);
        vec_0.sort_unstable();
        vec_0.reverse();

        if vec_0.is_empty() { return None; }
        if vec_0[0] < 1 { return Some(vec![0]); }

        Some(vec_0)
    }

    pub fn largest_multiple_of_three(vec: Vec<i32>) -> String {
        let ret = if let Some(inner) = Self::_impl(vec) {
            inner
        } else { return String::new(); };

        ret.into_iter()
            .map(|e| (e + '0' as u8) as char)
            .collect()
    }
}