// Runtime: 0 ms (Top 100.0%) | Memory: 2.30 MB (Top 100.0%)

use std::collections::VecDeque;

#[derive(Clone,Copy)]
struct State {
    speed: i32,
    pos: i32,
    moves: i32,
}
impl Solution {
    pub fn racecar(target: i32) -> i32 {
        let mut frontier = VecDeque::new();
        frontier.push_back(State{speed: 1, pos: 0, moves: 0});
        while let Some(State{speed, pos, moves}) = frontier.pop_front() {
            if pos == target {
                return moves;
            }
            // Always allow accelerating.
            frontier.push_back(State {
                speed: speed * 2, 
                pos: pos + speed, 
                moves: moves + 1,
            });
            if allow_reverse(target, pos, speed) {
                frontier.push_back(State {
                    speed: -1 * speed.signum(), 
                    pos: pos, 
                    moves: moves + 1,
                });
            }
        }
        -1
    }
}

pub fn allow_reverse(target: i32, position: i32, speed: i32) -> bool {
    // If speed + pos would overshoot target in one direction, allow reverse.
    let next_to_target = target - (speed + position);
    // If we're before the target and moving forwards, or after the target
    // and moving backwards, then we're moving in the correct direction and
    // shouldn't allow reverse--this corresponds to a positive sign of
    // the product.
    speed * next_to_target < 0
}
