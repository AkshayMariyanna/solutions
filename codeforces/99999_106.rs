//! https://codeforces.com/problemsets/acmsguru/problem/99999/106

use std::io;

fn main() {
    let mut inp = String::new();

    io::stdin().read_line(&mut inp).unwrap();
    let mut iter = inp.trim().split_whitespace();
    let a: i64 = iter.next().unwrap().parse().unwrap();
    let b: i64 = iter.next().unwrap().parse().unwrap();
    let c: i64 = iter.next().unwrap().parse().unwrap();
    let c = -c;

    let mut inp = String::new();
    io::stdin().read_line(&mut inp).unwrap();
    let mut iter = inp.trim().split_whitespace();
    let x1: i64 = iter.next().unwrap().parse().unwrap();
    let x2: i64 = iter.next().unwrap().parse().unwrap();

    let mut inp = String::new();
    io::stdin().read_line(&mut inp).unwrap();
    let mut iter = inp.trim().split_whitespace();
    let y1: i64 = iter.next().unwrap().parse().unwrap();
    let y2: i64 = iter.next().unwrap().parse().unwrap();

    println!("{}", find_all(a, b, c, x1, x2, y1, y2));
}

fn gcd_ex(a: i64, b: i64) -> (i64, i64, i64) {
    if a == 0 {
        return (0, 1, b);
    } else {
        let (x1, y1, g) = gcd_ex(b % a, a);
        return (y1 - (b / a) * x1, x1, g);
    }
}

fn find_some(a: i64, b: i64, c: i64) -> Option<(i64, i64, i64)> {
    let (mut x, mut y, g) = gcd_ex(a.abs(), b.abs());
    if c % g != 0 {
        return None
    }

    let mult = c / g;

    if a < 0 {
        x = x * -mult;
    } else {
        x = x * mult;
    }

    if b < 0 {
        y = y * -mult;
    } else {
        y = y * mult;
    }

    Some((x, y, g))
}

fn shift_solution(sol: (i64, i64), ag: i64, bg: i64, offset: i64) -> (i64, i64) {
    (sol.0 +  bg * offset, sol.1 - ag * offset)
}

fn find_all(a: i64, b: i64, c: i64, x1: i64, x2: i64, y1: i64, y2: i64) -> i64 {
    if a == 0 && b == 0 && c ==0 {
        return (y2 - y1 + 1) * (x2 - x1 + 1)
    } else if a == 0 && b == 0 {
        return 0;
    } else if a == 0 && (c / b) >= y1 && (c / b) <= y2 {
        return x2 - x1 + 1
    } else if b == 0 && (c / a) >= x1 && (c / a) <= x2 {
        return y2 - y1 + 1
    } else if a == 0 || b == 0 {
        return 0
    }
    match find_some(a, b, c) {
        Some((_x, _y, g)) => {
            let a = a / g;
            let b = b / g;

            let sign_a = if a > 0 { 1 } else { -1 };
            let sign_b = if b > 0 { 1 } else { -1 };

            let mut sol = (_x, _y);

            sol = shift_solution(sol, a, b, (x1 - sol.0) / b);
            if sol.0 < x1 {
                sol = shift_solution(sol, a, b, sign_b);
            }
            if sol.0 > x2 {
                return 0;
            }
            let lx1 = sol.0;

            sol = shift_solution(sol, a, b, (x2 - sol.0) / b);
            if sol.0 > x2 {
                sol = shift_solution(sol, a, b, -sign_b);
            }
            let rx1 = sol.0;
            
            sol = shift_solution(sol, a, b, -(y1 - sol.1) / a);
            if sol.1 < y1 {
                sol = shift_solution(sol, a, b, -sign_a)
            }
            if sol.1 > y2 {
                return 0;
            }
            let mut lx2 = sol.0;

            sol = shift_solution(sol, a, b, -(y2 - sol.1) / a);
            if sol.1 > y2 {
                sol = shift_solution(sol, a, b, sign_a);
            }
            let mut rx2 = sol.0;

            if lx2 > rx2 {
                let temp = lx2;
                lx2 = rx2;
                rx2 = temp;
            }

            let lx = if lx1 > lx2 { lx1 } else { lx2 };
            let rx = if rx1 < rx2 { rx1 } else { rx2 };

            if lx > rx {
                return 0
            } else {
                return (rx - lx) / b.abs() + 1
            }
        },
        None => 0
    }
}