<script>
 
// Javascript program for finding if a number perfect Square or not
 
// Program to find if x is a
// perfect square.

function isPerfectSquare(x)
{  

    let left = 1, right = x;

   

    while (left <= right)
    {

        let mid = parseInt((left + right) / 2);

        

        // Check if mid is perfect square

        if (mid * mid == x) 

        {

            return true; 

        }

         

        // Mid is small -> go right to increase mid

        if (mid * mid < x)
        { 

            left = mid + 1; 

        }

        // Mid is large -> to left to decrease mid

        else

        {

            right = mid - 1; 

        }

    }

    return false;

} 

    let x = 2500;
 
// Function Call

if (x == 0 || isPerfectSquare(x))

    document.write("Yes");
else

    document.write("Yes");

     
// This code is contributed by SjxSubham
 
</script>