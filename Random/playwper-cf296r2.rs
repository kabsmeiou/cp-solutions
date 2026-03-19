use std::io::{self, BufRead};
use std::cmp::{min, max};


fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let mut binding = lines.next().unwrap().unwrap();
    let mut line = binding.split_whitespace();
    let mut a: i64 = line.next().unwrap().parse().unwrap();
    let mut b: i64 = line.next().unwrap().parse().unwrap();
    if max(a, b) % min(a, b) == 0 {
        println!("{}", max(a, b) / min(a, b));
    } else {
        let mut ans = 0;
        while (min(a, b) > 1) { 
            let x = min(a, b);
            let y = max(a, b);
            ans += y / x;
            a = x;
            b = y % x;
        }
        let final_max = {
            if min(a, b) == 1 {
                max(a, b)
            } else {
                0
            }
        };
        println!("{}", ans + final_max);
    }
}