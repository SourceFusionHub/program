fn isqrt(n: usize) -> usize {
    n == 0 && return n;
    let mut s = (n as f64).sqrt() as usize;
    s = (s + n / s) >> 1;
    if s * s > n { s - 1 } else { s }
}

fn perfect_sqrt(n: usize) -> isize {
    match n & 0xf {
        0 | 1 | 4 | 9 => {
            let t = isqrt(n);
            if t*t == n { t as isize } else { -1 }
        },
        _ => -1,
    }
}

fn main() {
    for n in 0..200 {
        println!("{}: {}", n, perfect_sqrt(n));
    }
}
