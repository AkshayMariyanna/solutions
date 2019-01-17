//! https://codeforces.com/problemset/problem/630/I
//! To quickly hire highly skilled specialists one of the new IT City companies made an unprecedented move. Every employee was granted a car, and an employee can choose one of four different car makes.
//! The parking lot before the office consists of one line of (2n - 2) parking spaces. Unfortunately the total number of cars is greater than the parking lot capacity. Furthermore even amount of cars of each make is greater than the amount of parking spaces! That's why there are no free spaces on the parking lot ever.
//! Looking on the straight line of cars the company CEO thought that parking lot would be more beautiful if it contained exactly n successive cars of the same make. Help the CEO determine the number of ways to fill the parking lot this way.
use std::io;

fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).unwrap();
    let inp: u64 = inp.trim().parse().unwrap();

    let ans: u64 = (9*inp - 3) * binexp(4, inp - 3);
    println!("{}", ans);
}

fn binexp(mut x: u64, mut y: u64) -> u64 {
    let mut res = 1;
    while y != 0 {
        if y & 1 == 1 {
            res *= x;
        }
        x*=x;
        y>>=1;
    }
    res
}








