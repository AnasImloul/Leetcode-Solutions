// Runtime: 4 ms (Top 66.6%) | Memory: 2.94 MB (Top 66.6%)

type Num = u64;

use std::collections::BinaryHeap;

impl Solution {
    fn preproc(vec: Vec<i32>) -> Vec<Num> {
        vec.into_iter()
            .map(|e| e as Num)
            .collect::<Vec<_>>()
    }

    pub fn is_possible(vec: Vec<i32>) -> bool {
        let vec = Self::preproc(vec);
        
        let mut heap_sum = vec.iter().sum::<Num>();
        let mut heap = BinaryHeap::from(vec);
        while let Some(e) = heap.pop() {
            heap_sum -= e;
            if e <= heap_sum || heap_sum < 1 {
                heap.push(e);
                break;
            }

            let mut e_next = e % heap_sum;
            if e_next < 1 {
                e_next += heap_sum;
            }
            
            heap_sum += e_next;
            heap.push(e_next);
        }

        heap.into_iter()
            .filter(|&e| e != 1)
            .count() < 1
    }
}