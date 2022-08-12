// Given two integers a and b, return the sum of the two integers without using the operators + and -.

// Example 1:

// Input: a = 1, b = 2
// Output: 3
// Example 2:

// Input: a = 2, b = 3
// Output: 5

// Answer: 
const getSum = (a, b) => {
    const sum = a ^ b;
    const carry = (a & b) << 1;
    if (sum & carry) {
        return getSum(sum, carry);
    } else {
        return sum ^ carry;
    }
}
console.log(getSum(11, 9))
