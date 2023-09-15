// Runtime: 8 ms (Top 25.0%) | Memory: 2.31 MB (Top 25.0%)

impl Solution {
    pub fn original_digits(s: String) -> String {

        if s.is_empty() {
            return String::new();
        }
        
        let ind_let = |x: u8| -> usize { (x - b'a') as usize };
        let str_to_arr = |s: &str| -> [usize; 26] {
            s.as_bytes().iter().fold([0; 26], |mut acc, x| {
                acc[ind_let(*x)] += 1;
                acc
            })
        };

        let num_str = [
            (str_to_arr("zero"), ind_let(b'z'), '0'),
            (str_to_arr("two"), ind_let(b'w'), '2'),
            (str_to_arr("four"), ind_let(b'u'), '4'),
            (str_to_arr("six"), ind_let(b'x'), '6'),
            (str_to_arr("eight"), ind_let(b'g'), '8'),
            (str_to_arr("three"), ind_let(b'r'), '3'),
            (str_to_arr("five"), ind_let(b'f'), '5'),
            (str_to_arr("seven"), ind_let(b's'), '7'),
            (str_to_arr("nine"), ind_let(b'i'), '9'),
            (str_to_arr("one"), ind_let(b'o'), '1'),
        ];

        let mut mas_w = str_to_arr(&s);
        let mut res = vec![];

        for &(mas, ind, c) in num_str.iter() {
            let k = mas_w[ind] / mas[ind];
            if k == 0 { continue; }
            
            res.append(&mut vec![c; k]);

            for i in 0..26 {
                if mas[i] > 0 {mas_w[i] -= k * mas[i]}
            }
        }

        res.sort_unstable();
        res.iter().collect::<String>()
    }
}