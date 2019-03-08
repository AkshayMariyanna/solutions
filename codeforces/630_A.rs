//! https://codeforces.com/contest/633/problem/A

use std::io;

#[derive(Clone, Copy)]
struct Solution(i32, i32);

fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).unwrap();
    let mut iter = inp.trim().split_whitespace();
    let a: i32 = iter.next().unwrap().parse().unwrap();
    let b: i32 = iter.next().unwrap().parse().unwrap();
    let c: i32 = iter.next().unwrap().parse().unwrap();

    println!("{}", match find_if_poss(a, b, c) {
        true => "Yes",
        false => "No"
    })
}

fn gcd(a: i32, b: i32) -> (Solution, i32) {
    if a == 0 {
        (Solution(0, 1), b)
    } else {
        let (Solution(x1, y1), g) = gcd(b % a, a);
        (Solution(y1 - (b / a) * x1, x1), g)
    }
}

fn find_one(a: i32, b: i32, c: i32) -> Option<(Solution, i32)> {
    let (Solution(x, y), g) = gcd(a.abs(), b.abs());
    if c % g != 0 {
        None
    } else {
        let mult = c / g;

        let x = get_sign(a) * mult * x;
        let y = get_sign(b) * mult * y;

        Some((Solution(x, y), g))
    }
}

fn get_sign(i: i32) -> i32 {
    if i < 0 { -1 } else { 1 }
}

fn shift_solution(sol: Solution, ag: i32, bg: i32, offset: i32) -> Solution {
    Solution(sol.0 + bg * offset, sol.1 - ag * offset)
}

fn find_if_poss(a: i32, b: i32, c: i32) -> bool {
    match find_one(a, b, c) {
        Some((mut sol, g)) => {
            let sign_a = get_sign(a);
            let sign_b = get_sign(b);

            let maxx = c/a;
            let maxy = c/b;

            let a = a / g;
            let b = b / g;

            let minx_offset = -sol.0/b;
            sol = shift_solution(sol, a, b, minx_offset);
            if sol.0 < 0 {
                sol = shift_solution(sol, a, b, sign_b);
            }
            if sol.0 > maxx {
                return false;
            }
            let lx1 = sol.0;

            let maxx_offset = (maxx - sol.0)/b;
            sol = shift_solution(sol, a, b, maxx_offset);
            if sol.0 > maxx {
                sol = shift_solution(sol, a, b, -sign_b);
            }
            let rx1 = sol.0;

            let miny_offset = sol.1/a;
            sol = shift_solution(sol, a, b, miny_offset);
            if sol.1 < 0 {
                sol = shift_solution(sol, a, b, -sign_a);
            }
            if sol.1 > maxy {
                return false;
            }
            let mut lx2 = sol.0;

            let maxy_offset = (sol.1 - maxy) / a;
            sol = shift_solution(sol, a, b, maxy_offset);
            if sol.1 > maxy {
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
                return false;
            }

            let count = (rx - lx)/b.abs() + 1;

            count > 0
        },
        None => false
    }
}
