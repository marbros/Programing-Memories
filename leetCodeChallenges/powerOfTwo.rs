impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        let powerOfTwo: Vec<i32> = (0..31).map(|x| 2_i32.pow(x)).collect();
        powerOfTwo.binary_search(&n).is_ok()
    }
}