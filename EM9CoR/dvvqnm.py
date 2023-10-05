is_leap_year = lambda year: (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)
# takes the input from user
year = int(input("Enter a year: "))
if is_leap_year(year): print(year, " is a leap year") 
else: print(year, "is not a leap year.")