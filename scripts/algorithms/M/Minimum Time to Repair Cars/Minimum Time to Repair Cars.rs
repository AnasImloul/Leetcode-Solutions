// Runtime: 816 ms (Top 100.0%) | Memory: 11.80 MB (Top 100.0%)

type Target = i64;
type UseValue = i64;
fn lower_bound(arr: &Vec<Target>, x: &UseValue) -> usize {
    let mut low = 0;
    let mut high = arr.len();
    while low != high {
        let mid = (low + high) / 2;
        match arr[mid].cmp(x) {
            std::cmp::Ordering::Less => {
                low = mid + 1;
            }
            std::cmp::Ordering::Equal | std::cmp::Ordering::Greater => {
                high = mid;
            }
        }
    }
    low
}
impl Solution {
  pub fn repair_cars(ranks: Vec<i32>, cars: i32) -> i64 {
    let n = ranks.len();
    let cars = cars as i64;

    if n == 1 {
      return ranks[0] as i64 * cars * cars
    }

    let ranks = ranks.into_iter().map(|v| v as i64).collect::<Vec<i64>>();
    let mut memo = vec![0;10usize.pow(6)];
    for i in 1..10i64.pow(6) {
      memo[i as usize] = i * i;
    }

    let mut left = 0;
    let mut right = 10i64.pow(10);
    while left < right {
      let mid = (left+right)/ 2;
      let mut temp = 0;

      for i in 0..n {
        let num_square = mid / ranks[i];
        let ti = lower_bound(&memo, &num_square);
        if memo[ti] == num_square {
          temp += ti as i64;
        } else {
          temp += ti as i64 - 1;
        }
      } 

      if temp < cars {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    right
  }
}
