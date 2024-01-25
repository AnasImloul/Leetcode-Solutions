// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 42.86%)

impl Solution {
    pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
        let mut arr:[i32;1001]=[0;1001];
        let mut res:Vec<i32> = Vec::new();
        for i in arr1.iter() {
            let ui:usize = (*i) as usize;
            arr[ui]+=1;
        }
        for i in arr2.iter() {
            let ui = (*i) as usize;
            while arr[ui] > 0 {
                res.push(*i);
                arr[ui] -= 1;
            }
        }
        for i in 0 as usize..1001 {
            while arr[i] > 0 {
                res.push(i as i32);
                arr[i]-=1;
            }
        }
        res
    }
}
