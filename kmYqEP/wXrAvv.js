//Check if a string contains only uppercase letters

const string = "aysgWAASXAS";


function stringCheck(str) {
if( /A-Z/.test(str) ){
    console.log("yes, The String" ,str ," consists of only Upper case letters")
}else {
    console.log("No, The String " ,str ," doesn't consists of only Upper case letters")
}
}

stringCheck(string)
