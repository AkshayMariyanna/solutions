//! https://codeforces.com/problemsets/acmsguru/problem/99999/106

use std::io;

fn main() {
    let mut inp = String::new();

    io::stdin().read_line(&mut inp).unwrap();
    let mut iter = inp.trim().split_whitespace();
    let a: i32 = iter.next().unwrap().parse().unwrap();
    let b: i32 = iter.next().unwrap().parse().unwrap();
    let c: i32 = iter.next().unwrap().parse().unwrap();

    let mut inp = String::new();
    io::stdin().read_line(&mut inp).unwrap();
    let mut iter = inp.trim().split_whitespace();
    let x1: i32 = iter.next().unwrap().parse().unwrap();
    let x2: i32 = iter.next().unwrap().parse().unwrap();

    let mut inp = String::new();
    io::stdin().read_line(&mut inp).unwrap();
    let mut iter = inp.trim().split_whitespace();
    let y1: i32 = iter.next().unwrap().parse().unwrap();
    let y2: i32 = iter.next().unwrap().parse().unwrap();

    println!("{}", find_all(a, b, c, x1, x2, y1, y2));
}

fn gcd_ex(a: i32, b: i32) -> (i32, i32, i32) {
    if a == 0 {
        return (0, 1, b);
    } else {
        let (x1, y1, g) = gcd_ex(b % a, a);
        return (y1 - (b / a) * x1, x1, g);
    }
}

fn find_some(a: i32, b: i32, c: i32) -> Option<(i32, i32, i32)> {
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

fn shift_solution(sol: (i32, i32), ag: i32, bg: i32, offset: i32) -> (i32, i32) {
    (sol.0 +  bg * offset, sol.1 - ag * offset)
}

fn find_all(a: i32, b: i32, c: i32, x1: i32, x2: i32, y1: i32, y2: i32) -> i32 {
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
            
            sol = shift_solution(sol, a, b, (y1 - sol.1) / a);
            if sol.1 < y1 {
                sol = shift_solution(sol, a, b, -sign_a)
            }
            if sol.1 > y2 {
                return 0;
            }
            let mut lx2 = sol.0;

            sol = shift_solution(sol, a, b, (y2 - sol.1) / a);
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