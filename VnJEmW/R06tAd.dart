class BankAccount {
  String accountNumber;
  String accountHolder;
  double balance;

  BankAccount(this.accountNumber, this.accountHolder, this.balance);

  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      print('$amount deposited. New balance: \$${balance.toStringAsFixed(2)}');
    } else {
      print('Invalid deposit amount. Amount must be greater than 0.');
    }
  }

  void withdraw(double amount) {
    if (amount > 0) {
      if (balance >= amount) {
        balance -= amount;
        print('$amount withdrawn. New balance: \$${balance.toStringAsFixed(2)}');
      } else {
        print('Insufficient balance. Cannot withdraw \$${amount.toStringAsFixed(2)}.');
      }
    } else {
      print('Invalid withdrawal amount. Amount must be greater than 0.');
    }
  }

  void printAccountDetails() {
    print('Account Number: $accountNumber');
    print('Account Holder: $accountHolder');
    print('Balance: \$${balance.toStringAsFixed(2)}');
  }
}

void main() {
  // Create a new bank account
  BankAccount myAccount = BankAccount('917832373630', 'Krrishn07', 20000.0);

  // Deposit and withdraw money
  myAccount.deposit(500.0);
  myAccount.withdraw(200.0);

  // Print account details
  myAccount.printAccountDetails();
}
