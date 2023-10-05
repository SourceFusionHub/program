function getRandomInteger(min, max) {
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

const randomNum = getRandomInteger(1, 10);
console.log(randomNum); // This will output a random integer between 1 and 10 (inclusive)
