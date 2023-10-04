function validIPAddress(address: string): boolean {
	// check for empty string and null
	if (address === "" || address === null) return false;

	// length Check i.e the maximum length for the address must be 15
	if (address.length > 15) return false;

	// split the address into tokens
	const splitTokens: string[] = address.split(".");

	// check for valid number of octets in the string.
	if (splitTokens.length !== 4) return false;

	for (const octet of splitTokens) {
		//check is string is numeric
		if (!/^\d+$/.test(octet)) {
			return false;
		}
		// convert from string to Number
		let currOctet: number = parseInt(octet, 10);

		// range check i.e from 0 to 255
		if (currOctet > 255 || currOctet < 0) {
			return false;
		}
		// zero check i.e the 0 can only lead in an octet if that oarticular octet has all zeros
		if (octet.length > 1 && octet.charAt(0) === "0") {
			return false;
		}
	}

	return true;
}
// Example Usage
const ipAddress: string = "127.0.0.1";
const result: boolean = validIPAddress("127.0.0.1");
console.log(result); // true
