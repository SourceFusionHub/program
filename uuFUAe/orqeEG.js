// Function to find the sum of even numbers from 1 to 20
function SumOfEvenNumbers(from, to){
    var sum = 0;
    for(var i=from; i<=to; i++){
        if (i%2 == 0){
            sum += i;
        }
    }
    return sum
}

console.log(`Sum of even numbers from 1 to 20 is ${SumOfEvenNumbers(1,20)}.`)