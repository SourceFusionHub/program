import 'dart:io';

class BankAccount {
  String accountNumber;
  String accountHolder;
  double balance;

  BankAccount(this.accountNumber, this.accountHolder, this.balance);

  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      print("Deposited $amount. New balance: \$$balance");
    } else {
      print("Invalid amount for deposit.");
    }
  }

  void withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
      balance -= amount;
      print("Withdrawn $amount. New balance: \$$balance");
    } else {
      print("Insufficient funds or invalid amount for withdrawal.");
    }
  }

  void transfer(BankAccount recipient, double amount) {
    if (amount > 0 && amount <= balance) {
      balance -= amount;
      recipient.deposit(amount);
      print("Transferred $amount to ${recipient.accountHolder}");
    } else {
      print("Insufficient funds or invalid amount for transfer.");
    }
  }

  void displayBalance() {
    print("Account Holder: $accountHolder");
    print("Account Number: $accountNumber");
    print("Balance: \$$balance");
  }
}

void main() {
  var account1 = BankAccount("123456789", "Alice", 1000.0);
  var account2 = BankAccount("987654321", "Bob", 500.0);

  while (true) {
    print("\nBanking System Menu:");
    print("1. Deposit");
    print("2. Withdraw");
    print("3. Transfer");
    print("4. Check Balance");
    print("5. Exit");

    stdout.write("Enter your choice: ");
    var choice = int.parse(stdin.readLineSync());

    switch (choice) {
      case 1:
        stdout.write("Enter the deposit amount: ");
        var amount = double.parse(stdin.readLineSync());
        account1.deposit(amount);
        break;
      case 2:
        stdout.write("Enter the withdrawal amount: ");
        var amount = double.parse(stdin.readLineSync());
        account1.withdraw(amount);
        break;
      case 3:
        stdout.write("Enter the recipient's account number: ");
        var recipientAccountNumber = stdin.readLineSync();
        var recipient =
            recipientAccountNumber == account2.accountNumber ? account2 : null;
        if (recipient == null) {
          print("Recipient account not found.");
        } else {
          stdout.write("Enter the transfer amount: ");
          var amount = double.parse(stdin.readLineSync());
          account1.transfer(recipient, amount);
        }
        break;
      case 4:
        account1.displayBalance();
        break;
      case 5:
        print("Exiting the program.");
        exit(0);
        break;
      default:
        print("Invalid choice. Please select a valid option.");
    }
  }
}

