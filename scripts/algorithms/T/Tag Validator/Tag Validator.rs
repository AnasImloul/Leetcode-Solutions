// Runtime: 1 ms (Top 50.0%) | Memory: 2.20 MB (Top 25.0%)

impl Solution {
    pub fn is_valid(code: String) -> bool {
        Self::_is_valid(code.as_bytes()).unwrap_or(false)
    }

    fn _is_valid(code: &[u8]) -> Option<bool> {
        let mut s = String::new();
        let mut i = 0;
        while i < code.len() {
            if code[i] == b'<' && code.get(i + 1)? == &b'!' {
                let mut t = String::new();
                for (j, &item) in code.iter().enumerate().skip(i + 2) {
                    if j - i == 9 {
                        break;
                    }
                    t.push(item as char);
                }
                if t == "[CDATA[" || t == "[cdata[" {
                    i += 7;
                    while i < code.len() {
                        if code[i - 2] == b']' && code[i - 1] == b']' && code[i] == b'>' {
                            break;
                        }
                        i += 1;
                    }
                    s.push('#');
                } else {
                    return Some(false);
                }
            } else {
                s.push(code[i] as char);
            }
            i += 1;
        }

        let s = s.as_bytes();

        if s.is_empty() || s[0] != b'<' {
            return Some(false);
        }

        let mut st = Vec::new();
        let mut k = 0;
        let mut n = 0;
        i = 0;
        while i < s.len() {
            if s[i] == b'<' {
                let mut t = String::new();
                n = 0;
                if i == s.len() {
                    return Some(false);
                }

                if s.get(i + 1)? == &b'/' {
                    i += 2;
                    while i < s.len() {
                        let &s_i_byte = s.get(i)?;
                        if s_i_byte == b'>' {
                            break;
                        }
                        if !(b'A'..=b'Z').contains(&s_i_byte) {
                            return Some(false);
                        }
                        t.push(s_i_byte as char);
                        if t.len() == 10 {
                            return Some(false);
                        }
                        i += 1;
                    }

                    if st.is_empty() || st.pop().unwrap() != t {
                        return Some(false);
                    }
                } else {
                    i += 1;
                    while i < s.len() {
                        let &s_i_byte = s.get(i)?;
                        if s_i_byte == b'>' {
                            break;
                        }
                        if !(b'A'..=b'Z').contains(&s_i_byte) {
                            return Some(false);
                        }
                        t.push(s_i_byte as char);
                        if t.len() == 10 {
                            return Some(false);
                        }
                        i += 1;
                    }

                    if t.is_empty()
                        || (st.is_empty() && {
                            k += 1;
                            k == 2
                        })
                    {
                        return Some(false);
                    }
                    st.push(t);
                }
            } else {
                n = 1;
            }
            i += 1;
        }
        Some(st.is_empty() && n == 0)
    }
}
