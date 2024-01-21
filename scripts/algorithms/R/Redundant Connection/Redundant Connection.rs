// Runtime: 0 ms (Top 100.0%) | Memory: 2.20 MB (Top 35.29%)

impl Solution {
    pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut mapper = std::collections::HashMap::new();

        fn parent(node: i32, mapper: &mut std::collections::HashMap<i32, i32>) -> i32 {
            if !mapper.contains_key(&node) {
                mapper.insert(node, node);
            }

            let mut current_node = node;
            while current_node != *mapper.get(&current_node).unwrap() {
                current_node = *mapper.get(&current_node).unwrap();
            }

            return current_node;
        }

        for edge in edges {
            let u = edge[0];
            let v = edge[1];

            let pu = parent(u, &mut mapper);
            let pv = parent(v, &mut mapper);

            if pu == pv {
                return vec![u, v];
            } else {
                mapper.insert(pv, pu);
            }
        }

        return vec![];
    }   
        
}
