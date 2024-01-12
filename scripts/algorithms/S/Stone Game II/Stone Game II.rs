// Runtime: 0 ms (Top 100.0%) | Memory: 2.40 MB (Top 25.0%)

impl Solution {
    pub fn stone_game_ii(piles: Vec<i32>) -> i32 {
        let mut cache = vec![vec![None; piles.len()+1]; piles.len()+1];
        GameState::new(&mut cache, &piles).best_outcome().0
    }
}

struct GameState<'a> {
    cache: &'a mut Vec<Vec<Option<(i32, i32)>>>,
    piles: &'a [i32],
    m: usize,
}

impl<'a, 'b> GameState<'a> {
    fn new(cache: &'a mut Vec<Vec<Option<(i32, i32)>>>, piles: &'a [i32]) -> Self {
        Self {
            cache,
            piles,
            m: 1,
        }
    }

    fn next_state(&'b mut self, x: usize) -> GameState<'b> {
        GameState {
            cache: &mut self.cache,
            piles: &self.piles[x..],
            m: self.m.max(x),
        }
    }

    fn best_outcome(mut self) -> (i32, i32) {
        let n = self.piles.len();
        let maybe_cached_outcome = self
            .cache
            .get(n)
            .and_then(|row| row.get(self.m.min(n)))
            .and_then(|&outcome| outcome);

        if let Some(outcome) = maybe_cached_outcome {
            return outcome;
        }

        let max_x = n.min(2 * self.m);

        let mut taken = 0;
        let mut best_outcome = (0, 0);
        for x in (1..=max_x) {
            taken += self.piles[x-1];
            let future_outcome = self.next_state(x).best_outcome();
            if taken + future_outcome.1 > best_outcome.0 {
                best_outcome = (taken+future_outcome.1, future_outcome.0);
            }
        }
        self.cache[n][self.m.min(n)] = Some(best_outcome);
        best_outcome
    }
}
