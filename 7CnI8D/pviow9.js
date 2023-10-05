javascript
class Qubit {
 constructor(state) {
    this.state = state;
 }

 measure() {
    let random = Math.random();
    let prob0 = Math.pow(Math.abs(this.state[0]), 2);
    let prob1 = Math.pow(Math.abs(this.state[1]), 2);

    if (random < prob0) {
      this.state = [1, 0];
      return 0;
    } else if (random < prob0 + prob1) {
      this.state = [0, 1];
      return 1;
    } else {
      return this.measure();
    }
 }
}

class QuantumEntanglement {
 constructor(qubit1, qubit2) {
    this.qubit1 = qubit1;
    this.qubit2 = qubit2;
 }

 measure() {
    let result1 = this.qubit1.measure();
    let result2 = this.qubit2.measure();

    if (result1 !== result2) {
      console.log('Quantum entanglement broken!');
    } else {
      console.log('Quantum entanglement maintained!');
    }

    return [result1, result2];
 }
}

function createEntangledPair() {
 let state = [1, 0];
 let qubit1 = new Qubit(state);
 let qubit2 = new Qubit(state);

 return new QuantumEntanglement(qubit1, qubit2);
}

let entangledPair = createEntangledPair();
entangledPair.measure();
