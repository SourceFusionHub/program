def reveseNum(num):
    temp=num
    array=[]
    while temp :
        array.append(temp%10)
        temp=temp//10;
    
    length=len(array)
    ans,j=0,0
    while j<length:
        ans=ans*10+array[j];
        j=j+1
    return ans
    
print(reveseNum(48226))