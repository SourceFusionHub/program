def get_valid_number():
    while True:
        try:
            num = float(input("Enter a number: "))
            return num
        except ValueError:
            print("Invalid input. Please enter a valid number.")

def check_number_type(num):
    if num > 0:
        return "Positive"
    elif num < 0:
        return "Negative"
    else:
        return "Zero"

if __name__ == "__main__":
    num = get_valid_number()
    number_type = check_number_type(num)
    print(f"The number {num} is {number_type}.")
