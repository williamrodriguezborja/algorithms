use std::cmp::max;

use std::io;

fn give_num(name: String) -> i32 {
    println!("Introduce {}", name);
    let mut num = String::new();
    io::stdin()
        .read_line(&mut num)
        .expect("number not valid");

    num = num.replace("\n", "");
    return num.parse().unwrap();
}

fn get_digits(mut num: i32) -> i32 {
    // corner case
    let mut result: i32 = 0;
    if num < 10 {
        return 1;
    }

    while num > 0 {
        num = num / 10;
        result = result + 1;
    }
    return result;
}

fn split_number(num: i32, middle: i32) -> (i32, i32) {
    let divisor: i32 = f32::powi(10 as f32, middle) as i32;
    if num >= divisor {
        (num / divisor, num % divisor)
    } else {
        (0, num)
    }
}

fn karatsuba(n1: i32, n2: i32) -> i32 {
    // corner case 0
    if n1 == 0 && n2 == 0 {
        return 0;
    }

    // first case
    if n1 < 10 || n2 < 10 {
        return n1 * n2;
    }

    let length_1 = get_digits(n1);
    let length_2 = get_digits(n2);
    let digits = max(length_1, length_2);
    let middle = digits / 2;

    let (a, b) = split_number(n1, middle);
    let (c, d) = split_number(n2, middle);


    let s1 = karatsuba(a, c);
    let s2 = karatsuba(b, d);
    let s3 = karatsuba(a, d) + karatsuba(b, c);
    return s1 * i32::pow(10, digits as u32)  + s3 * i32::pow(10, (digits / 2) as u32) + s2;
}

fn main() {
    let n1 = give_num("n1".to_string());
    let n2 = give_num("n2".to_string());
    println!("{}", karatsuba(n1, n2));
}
