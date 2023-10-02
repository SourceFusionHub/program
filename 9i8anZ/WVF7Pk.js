// Function to calculate the overlap between two strings
function calculateOverlap(str1, str2) {
    for (let i = 0; i < str1.length; i++) {
        if (str2.startsWith(str1.slice(i))) {
            return str1.length - i;
        }
    }
    return 0;
}

// Function to find the shortest common superstring using the greedy algorithm
function findShortestSuperstring(strings) {
    while (strings.length > 1) {
        let maxOverlap = -1;
        let bestIndices = [-1, -1];

        for (let i = 0; i < strings.length; i++) {
            for (let j = 0; j < strings.length; j++) {
                if (i !== j) {
                    const overlap = calculateOverlap(strings[i], strings[j]);
                    if (overlap > maxOverlap) {
                        maxOverlap = overlap;
                        bestIndices = [i, j];
                    }
                }
            }
        }

        const [index1, index2] = bestIndices;
        const mergedString = strings[index1] + strings[index2].slice(maxOverlap);
        strings.splice(Math.max(index1, index2), 1);
        strings.splice(Math.min(index1, index2), 1);
        strings.push(mergedString);
    }

    return strings[0];
}

// Example usage
const inputStrings = ["abc", "bcde", "defg", "ghij"];
const shortestSuperstring = findShortestSuperstring(inputStrings);
console.log("Shortest Common Superstring:", shortestSuperstring);
