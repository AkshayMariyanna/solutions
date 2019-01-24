//! https://codeforces.com/gym/100963/problem/J
//! 
//! This fails with larger numbers, due to overflow
//! Check 100963_J.cpp

fn read_input() -> (i64, i64, i64, i64) {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).expect("read error");
    let mut iter = buf.trim().split_whitespace();
    (
        iter.next().unwrap().parse().expect("parse error"),
        iter.next().unwrap().parse().expect("parse error"),
        iter.next().unwrap().parse().expect("parse error"),
        iter.next().unwrap().parse().expect("parse error"),
    )
}

fn main() {
    loop {
        let (a, b, c, d) = read_input();
        if a == 0 {
            break;
        }
        let diff = (c + d - b).abs();
        let (x, _, g) = gcd_ext(b, d);
        if diff % g != 0 {
            println!("Impossible");
            continue;
        }
        let diff = diff / g;
        let x = x * diff;
        let lcm = (a/g) * b;
        println!("{}", ((a + b * x) + lcm) % lcm);
    }
}

fn gcd_ext(a: i64, b: i64) -> (i64, i64, i64) {
    if a == 0 {
        (0, 1, b)
    } else {
        let (x, y, g) = gcd_ext(b % a, a);
        (y - (b/a)*x, x, g)
    }
}