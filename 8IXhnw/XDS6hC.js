function calculateSphereVolume(r) {
    if (r < 0) {
      return "Radius cannot be negative";
    }
    const volume = (4/3) * Math.PI * Math.pow(r, 3);
    return volume;
  }
  
  // Input radius from user
  const radius = parseFloat(prompt("Enter the radius of the sphere:"));
  
  // Calculate volume and display the result
  const volume = calculateSphereVolume(r);
  
  if (isNaN(r)) {
    console.log("Invalid input. Please enter a valid number for the radius.");
  } else if (typeof volume === "string") {
    console.log(volume);
  } else {
    console.log(`The volume of the sphere with radius ${r} units is ${volume} cubic units.`);
  }
  
