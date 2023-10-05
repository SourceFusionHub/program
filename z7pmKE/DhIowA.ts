function sumNatural(): number {
    let sum = 0;
    for (let i = 1; i <= 50; i++) {
        sum += i;
    }
    return sum;
}
function main() {
    let result = sumNatural();
    console.log("The sum of natural numbers up to 50 is " + result);
}
main();
