//Created a TypeScript function to check if a string contains a valid date in a specified format
//Important: Please note that you'll have to install the moment library to run this code. You can use 'npm install moment' to do so
import moment from 'moment';

function isValidDate(dateString: string, format: string): boolean {
  const date = moment(dateString, format, true);
  return date.isValid();
}

const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

readline.question('Enter a date string: ', (dateString: string) => {
  readline.question('Enter the date format (e.g. YYYY-MM-DD): ', (format: string) => {
    const isValid = isValidDate(dateString, format);
    console.log(`Is ${dateString} a valid date in format ${format}? ${isValid}`);
    readline.close();
  });
});
