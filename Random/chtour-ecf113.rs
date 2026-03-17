use std::io::{self, BufRead};

fn solve() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    
    let t: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
    
    for _ in 0..t {
        let _n: usize = lines.next().unwrap().unwrap().trim().parse().unwrap();
        let s = lines.next().unwrap().unwrap();
        let a: Vec<char> = s.chars().collect();
        let n = a.len();

        let mut twos = Vec::new();
        for i in 0..n {
            if a[i] == '2' { twos.push(i); }
        }

        let cnt = twos.len();
        if cnt == 1 || cnt == 2 {
            println!("NO");
            continue;
        }

        println!("YES");
        let mut grid = vec![vec!['='; n]; n];
        for i in 0..n { grid[i][i] = 'X'; }

        if cnt >= 3 {
            for i in 0..cnt {
                let u = twos[i];
                let v = twos[(i + 1) % cnt];
                grid[u][v] = '+';
                grid[v][u] = '-';
            }
        }

        for row in grid {
            let row_str: String = row.into_iter().collect();
            println!("{}", row_str);
        }
    }
}

fn main() {
    solve();
}