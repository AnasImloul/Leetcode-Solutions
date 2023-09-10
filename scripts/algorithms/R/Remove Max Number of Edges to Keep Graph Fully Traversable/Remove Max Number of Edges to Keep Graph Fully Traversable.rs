// Runtime: 47 ms (Top 100.0%) | Memory: 9.43 MB (Top 100.0%)

impl Solution {
    pub fn max_num_edges_to_remove(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut alice: Vec<_> = (0..=n as usize).collect();
        let mut bob: Vec<_> = (0..=n as usize).collect();

        fn uf_find(i: usize, uf: &mut [usize]) -> usize {
            if uf[i] != i {
                uf[i] = uf_find(uf[i], uf);
            }
            uf[i]
        }
        fn uf_union(i: usize, j: usize, uf: &mut [usize]) -> bool {
            let i = uf_find(i, uf);
            let j = uf_find(j, uf);
            if i == j {
                false
            } else {
                uf[i] = j;
                true                
            }
        }

        let mut ret = 0;
        let mut a_count = 1;
        let mut b_count = 1;
        for edge in &edges {
            if edge[0] == 3 {
                let a_change = uf_union(edge[1] as usize, edge[2] as usize, &mut alice);
                let b_change = uf_union(edge[1] as usize, edge[2] as usize, &mut bob);
                match (a_change, b_change) {
                    (true, true) => {
                        a_count += 1;
                        b_count += 1;
                    }
                    (true, false) => {
                        a_count += 1;
                    }
                    (false, true) => {
                        b_count += 1;
                    }
                    (false, false) => {
                        ret += 1;
                    }
                }
            }
        }
        for edge in edges {
            if edge[0] == 1 {
                if uf_union(edge[1] as usize, edge[2] as usize, &mut alice) {
                    a_count += 1;
                } else {
                    ret += 1;
                }
            } else if edge[0] == 2 {
                if uf_union(edge[1] as usize, edge[2] as usize, &mut bob) {
                    b_count += 1;
                } else {
                    ret += 1;
                }
            }
        }

        if a_count < n || b_count < n {
            -1
        } else {
            ret
        }
    }
}