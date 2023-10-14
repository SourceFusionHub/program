def product_of_odd_numbers(list1):
  product = 1
  for num in list1:
    if num % 2 != 0:
      product *= num
  return product

list1 = [1, 2, 3, 4, 5]
product = product_of_odd_numbers(list1)
print(product)
