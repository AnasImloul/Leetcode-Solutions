// Runtime: 16 ms (Top 100.0%) | Memory: 3.10 MB (Top 100.0%)

use std::collections::{HashMap, VecDeque};

impl Solution {
    pub fn watched_videos_by_friends(
        watched_videos: Vec<Vec<String>>,
        friends: Vec<Vec<i32>>,
        id: i32,
        level: i32,
    ) -> Vec<String> {
        let mut queue = VecDeque::from([id as usize]);
        let mut visited = vec![false; friends.len()];
        visited[id as usize] = true;
        for _ in 0..level {
            let len = queue.len();
            for _ in 0..len {
                if let Some(node) = queue.pop_front() {
                    for nei in friends[node as usize].iter().map(|&nei| nei as usize) {
                        if !visited[nei] {
                            queue.push_back(nei);
                            visited[nei] = true;
                        }
                    }
                }
            }
        }

        let mut watched_videos = queue
            .into_iter()
            .fold(HashMap::new(), |mut freq, user| {
                watched_videos[user].iter().fold(freq, |mut freq, v| {
                    *freq.entry(v).or_insert(0) += 1;
                    freq
                })
            })
            .into_iter()
            .collect::<Vec<_>>();
        watched_videos.sort_unstable_by(
            |(v_a, f_a), (v_b, f_b)| if f_a == f_b { v_a.cmp(&v_b) } else { f_a.cmp(&f_b) },
        );
        watched_videos.into_iter().map(|(v, _)| v.to_string()).collect()
    }
}
