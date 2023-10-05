function isValidIPv4(ip) {
  const ipv4Regex = /^(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)$/;
  return ipv4Regex.test(ip);
}

function isValidIPv6(ip) {
  const ipv6Regex = /^(?:[0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$|^(?!(?:.*[0-9a-fA-F]{1,4}:){8,})((([0-9a-fA-F]{1,4}:){0,6}[0-9a-fA-F]{1,4})?::(([0-9a-fA-F]{1,4}:){0,6}[0-9a-fA-F]{1,4}))$/;
  return ipv6Regex.test(ip);
}

function validateIPAddress(ip) {
  if (isValidIPv4(ip)) {
    return "IPv4";
  } else if (isValidIPv6(ip)) {
    return "IPv6";
  } else {
    return "Invalid";
  }
}

// Example usage:
const ipAddress = "192.168.1.1";
const result = validateIPAddress(ipAddress);
console.log(`The IP address ${ipAddress} is ${result}.`);
