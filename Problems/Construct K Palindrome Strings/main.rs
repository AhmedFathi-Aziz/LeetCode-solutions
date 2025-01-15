use std::collections::HashMap;
impl Solution {
    pub fn can_construct(s: String, k: i32) -> bool {
        if s.len() < k as usize {
            return false;
        }
        let mut frequency = HashMap::new();
        for ch in s.chars() {
            let counter = frequency.entry(ch).or_insert(0);
            *counter += 1;
        }
        let mut odd_values = 0;
        for count in frequency.values() {
            if count % 2 != 0 {
                odd_values += 1;
            }
        }
        if odd_values > k {
            return false;
        }
        return true;
    }
}
