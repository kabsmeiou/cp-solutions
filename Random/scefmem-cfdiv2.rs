use std::io::{self, BufRead};

fn solve(primes: &[bool; 101], lines: &mut std::io::Lines<std::io::StdinLock>) {
    let n: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    let s = lines.next().unwrap().unwrap();
    let a: Vec<char> = s.chars().collect();

    for &num in &a {
        let digit = num.to_digit(10).unwrap() as usize;
        if !primes[digit] {
            println!("1\n{}", num);
            return;
        }
    }
    // then check pairs of digits if we can form non-prime numbers
    for i in 0..a.len() {
        for j in i + 1..a.len() {
            let num1 = a[i].to_digit(10).unwrap() as usize;
            let num2 = a[j].to_digit(10).unwrap() as usize;
            let combined1 = num1 * 10 + num2;
            if !primes[combined1] {
                println!("2\n{}", combined1);
                return;
            }
        }
    }
    println!("{}\n{}", a.len(), s);
}

fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let t: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();

    // sieve of eratosthenes to find all primes up to 100
    let mut is_prime = [true; 101];
    is_prime[0] = false;
    is_prime[1] = false;
    for i in 2..=100 {
        if is_prime[i] {
            let mut j = i * i;
            while j <= 100 {
                is_prime[j] = false;
                j += i;
            }
        }
    }

    for _ in 0..t {
        solve(&is_prime, &mut lines);
    }
}