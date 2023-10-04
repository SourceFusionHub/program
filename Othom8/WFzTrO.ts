
function Median(A: number[], B: number[]): number {
    let n = A.length;
    let m = B.length;
    if (n > m)
        return Median(B, A);
    let start = 0;
    let end = n;
    let realmidinmergedarray = Math.floor((n + m + 1) / 2);

    while (start <= end) {
        let mid = Math.floor((start + end) / 2);
        let leftAsize = mid;
        let leftBsize = realmidinmergedarray - mid;
        let leftA = (leftAsize > 0) ? A[leftAsize - 1] : Number.MIN_VALUE;
        let leftB = (leftBsize > 0) ? B[leftBsize - 1] : Number.MIN_VALUE;
        let rightA = (leftAsize < n) ? A[leftAsize] : Number.MAX_VALUE; 
        let rightB = (leftBsize < m) ? B[leftBsize] : Number.MAX_VALUE; 

        if (leftA <= rightB && leftB <= rightA) {
            if ((m + n) % 2 === 0)
                return (Math.max(leftA, leftB) + Math.min(rightA, rightB)) / 2.0;
            return Math.max(leftA, leftB);
        } else if (leftA > rightB) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0.0;
}

let arr1: number[] = [1,3,5,7,9];
let arr2: number[] = [2,4,6,8,10];
console.log("Median of the two sorted arrays are: " + Median(arr1, arr2));
