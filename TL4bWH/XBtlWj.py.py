def median(numbers):
    numbers.sort();

    if len(numbers)==0:
        return None

    elif len(numbers)%2==1:
        return numbers[len(numbers)//2]
    
    else:
        index_1 = len(numbers) // 2 - 1
        index_2 = len(numbers) // 2
        element_1 = numbers[index_1]
        element_2 = numbers[index_2]
        return (element_1 + element_2) / 2
    
  
numbers = [1,2,3,4,5,6,7,8]
median = median(numbers)
print("Median of list:", median)