# function to concatenate two lists
def concatenation(list1, list2):
    concatenated_list = list1 + list2
    print(concatenated_list)

# creating two empty lists
list1 = []
list2 = []

# number of elements as input in the first list
n1 = int(input("Enter number of elements in the 1st list: "))

print("Enter the elements of the 1st list : ")
# iterating till the range
for i in range(0, n1):
	ele = input()
	# adding the element one by one in the first list
	list1.append(ele) 
	
# number of elements as input in the second list
n2 = int(input("Enter number of elements in the 2nd list: "))

print("Enter the elements of the 2st list : ")
# iterating till the range
for i in range(0, n2):
	ele = input()
	# adding the element one by one in the second list
	list2.append(ele) 

# calling the concatenation function
concatenation(list1, list2)
