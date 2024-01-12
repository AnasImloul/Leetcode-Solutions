// Runtime: 0 ms (Top 100.0%) | Memory: 2.40 MB (Top 13.11%)

impl Solution {
    pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
        let mut stack: Vec<i32> = Vec::new();
        for element in asteroids {
            let mut flag: i32 = 1;
            while !(stack.is_empty()) {
                let curr_asteroid: i32 = stack.pop().unwrap();
                if curr_asteroid * element < 0 && curr_asteroid.abs() > element.abs() && element < 0 {
                    flag = 0;
                    stack.push(curr_asteroid);
                    break;
                }
                else if curr_asteroid * element < 0 && curr_asteroid.abs() == element.abs() && element < 0 {
                    flag = 0;
                    break;
                }
                if curr_asteroid * element > 0 ||  (curr_asteroid * element < 0 && element > 0) {
                    stack.push(curr_asteroid);
                    break;
                }
            }
            if flag == 1 {
                stack.push(element);
            }
        }
        stack
    }
}
