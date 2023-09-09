// Runtime: 93 ms (Top 100.0%) | Memory: 29.73 MB (Top 100.0%)

use std::collections::HashMap;

impl Solution {
    pub fn most_popular_creator(creators: Vec<String>, ids: Vec<String>, views: Vec<i32>) -> Vec<Vec<String>> {
        let mut popular: HashMap<String, (i32, u128, String)> = HashMap::new();
        let mut max_view = 0;

        creators.into_iter().zip(ids.into_iter().zip(views.into_iter()))
            .for_each(|(cr, (mut id, vw))| {
                popular.entry(cr).and_modify(|(prev_mv, v, i)| {
                    *v += vw as u128;
                    max_view = max_view.max(*v);

                    if *prev_mv == vw {
                        *i = (i.min(&mut id)).clone();
                    } else if *prev_mv < vw {
                        *i = id.clone();
                        *prev_mv = vw;
                    }
                }).or_insert_with(|| { max_view = max_view.max(vw as u128); (vw, vw as u128, id) });
            });

        popular.into_iter().fold(vec![], |mut res, (k, v)| {
            if v.1 == max_view {
                res.push(vec![k, v.2]);
            }
            res
        })
    }
}