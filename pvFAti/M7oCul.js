//Javascript code for the above approach
class Solution {
	constructor(CVRMSE, configuration) {
		this.CVRMSE = CVRMSE;
		this.config = configuration;
	}
}

let T = 1;
const Tmin = 0.0001;
const alpha = 0.9;
const numIterations = 100;

function genRandSol() {
	// Instantiating for the sake of compilation
	const a = [1, 2, 3, 4, 5];
	return new Solution(-1.0, a);
}

function neighbor(currentSol) {
	return currentSol;
}

function cost(inputConfiguration) {
	return -1.0;
}

// Mapping from [0, M*N] --> [0,M]x[0,N]
function indexToPoints(index) {
	const points = [index % M, Math.floor(index / M)];
	return points;
}

const M = 5;
const N = 5;
const sourceArray = Array.from(Array(M), () => new Array(N).fill('X'));
let min = new Solution(Number.POSITIVE_INFINITY, null);
let currentSol = genRandSol();

while (T > Tmin) {
	for (let i = 0; i < numIterations; i++) {
		// Reassigns global minimum accordingly
		if (currentSol.CVRMSE < min.CVRMSE) {
			min = currentSol;
		}
		const newSol = neighbor(currentSol);
		const ap = Math.exp((currentSol.CVRMSE - newSol.CVRMSE) / T);
		if (ap > Math.random()) {
			currentSol = newSol;
		}
	}
	T *= alpha; // Decreases T, cooling phase
}

//Returns minimum value based on optimization
console.log(min.CVRMSE, "\n\n");

for (let i = 0; i < M; i++) {
	for (let j = 0; j < N; j++) {
		sourceArray[i][j] = "X";
	}
}

// Displays
for (const obj of min.config) {
	const coord = indexToPoints(obj);
	sourceArray[coord[0]][coord[1]] = "-";
}

// Displays optimal location
for (let i = 0; i < M; i++) {
	let row = "";
	for (let j = 0; j < N; j++) {
		row += sourceArray[i][j] + " ";
	}
	console.log(row);
}
