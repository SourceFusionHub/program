function largestElement(arr) {
    return arr.reduce((largest, current) =>
        (current > largest ? current : largest), arr[0]);
}
  
let num1 = [1, 5, 8, 10, 7, 2, 3];
console.log(largestElement(num1));
