public class ContactlessPaymentSystem {

    private double accountBalance;
    private List<Transaction> transactionHistory;

    public ContactlessPaymentSystem(double accountBalance) {
        this.accountBalance = accountBalance;
        this.transactionHistory = new ArrayList<>();
    }

    public void makePayment(double amount) {
        if (amount > accountBalance) {
            throw new InsufficientFundsException();
        }
        accountBalance -= amount;
        transactionHistory.add(new Transaction(amount));
    }

    public double getAccountBalance() {
        return accountBalance;
    }

    public List<Transaction> getTransactionHistory() {
        return transactionHistory;
    }

    public static class Transaction {

        private double amount;
        private Date timestamp;

        public Transaction(double amount) {
            this.amount = amount;
            this.timestamp = new Date();
        }

        public double getAmount() {
            return amount;
        }

        public Date getTimestamp() {
            return timestamp;
        }
    }
}
