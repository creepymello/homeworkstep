

BankAccount account = new BankAccount(100,"unibamk");

double amount = 0; //по другому бы выводило ошибку инициализации в 7 строке 

account.PrintDelegateInfo(amount);

delegate void AccountOperation(double amount);


class BankAccount
{
    private double balance;
    private readonly string accountName;
    private AccountOperation delegateOperation;

    public BankAccount(double balance, string accountName)
    {
        this.balance = balance;
        this.accountName = accountName;
        delegateOperation = PrintDelegateInfo;

    }


    public void Deposit(double amount)
    {

        balance += amount;
        Console.WriteLine($"{amount}AZN has been deposited into your account");
        Console.WriteLine($"your current balance:{balance}AZN");
        delegateOperation(amount);
    }

    public void Withdraw(double amount)
    {
        double s;

        if (balance >= amount)
        {
            balance -= amount;
            Console.WriteLine($"your current balance:{balance}AZN");
            delegateOperation(amount);
        }
        else
        {
            s = amount - balance;
            throw new Exception($"Your balance is {balance}AZN, add another {s}AZN to withdraw money ");
        }

    }

    public void PrintDelegateInfo(double amount)
    {
        Console.WriteLine("amount: ");
        amount = double.Parse(Console.ReadLine());  
        Console.WriteLine("1 - deposit money into the account. " + '\n' 
            + "2 - withdraw money from account. ");
        string choise = Console.ReadLine();
        switch (choise)
        {
            case "1":
                Deposit(amount);
                break;
            case "2":
                Withdraw(amount);
                break;
            default:
                Console.WriteLine("input error. please enter 1 or 2.");
                break;
        }
        
    }

}
