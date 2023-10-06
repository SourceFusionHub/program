function printShortestSuperSeq(X,Y)
{
        let m = X.length;
        let n = Y.length;
        let dp = new Array(m + 1);
        for(let i=0;i<(m+1);i++)
        {
            dp[i]=new Array(n+1);
            for(let j=0;j<(n+1);j++)
                dp[i][j]=0;
        }
   
        // Fill table in bottom up manner 
        for (let i = 0; i <= m; i++) 
        {
            for (let j = 0; j <= n; j++) 
            {
                   
                // Below steps follow recurrence relation 
                if (i == 0) 
                {
                    dp[i][j] = j;
                } 
                else if (j == 0) 
                {
                    dp[i][j] = i;
                } 
                else if (X[i-1] == Y[j-1]) 
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 
                    1 + Math.min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        let str = "";
        let i = m, j = n;
        while (i > 0 && j > 0)
           
        {
            if (X[i-1] == Y[j-1]) 
               
            {
                // Put current character in result 
                str += (X[i-1]);
   
                // reduce values of i, j and index 
                i--;
                j--;
            } 
               
            // If current character in X and Y are different 
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                   
                // Put current character of Y in result 
                str += (Y[j-1]);
   
                // reduce values of j and index 
                j--;
            } 
            else
            {
                   
                // Put current character of X in result 
                str += (X[i-1]);
   
                // reduce values of i and index 
                i--;
            }
        }
   
        // If Y reaches its end, put remaining characters 
        // of X in the result string 
        while (i > 0) 
        {
            str += (X[i-1]);
            i--;
        }
        while (j > 0)
        {
            str += (Y[j-1]);
            j--;
        }
   
        // reverse the string and return it 
        str = reverse(str);
        return str;
}
 
function reverse(input)
{
    let temparray = input.split("");
        let left, right = 0;
        right = temparray.length - 1;
   
        for (left = 0; left < right; left++, right--)
        {
            // Swap values of left and right 
            let temp = temparray[left];
            temparray[left] = temparray[right];
            temparray[right] = temp;
        }
        return (temparray).join("");
}

let X = "AGGTAB";
let Y = "GXTXAYB";
document.write(printShortestSuperSeq(X, Y));
