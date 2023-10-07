private const string Chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";

static void Main(string[] args)
{
    // Method to grab the passwordLength from user Input using passwordLength as out param.
    GetValidUserInput(out var passwordLength);

    // Method that generates password using Random Chars.
    GenerateRandomPassword(passwordLength);
}

static void GetValidUserInput(out int userInput)
{
    while (true)
    {
        Console.WriteLine("Please, Enter the length of the Password: ");

        if (int.TryParse(Console.ReadLine(), out userInput) && userInput > 0)
        {
            return;
        }
    }
}

static void GenerateRandomPassword(int passwordLength)
{
    var random = new Random();
    var password = new StringBuilder();

    for (var i = 0; i < passwordLength; i++)
    {
        var index = random.Next(Chars.Length);
        password.Append(Chars[index]);
    }

    Console.WriteLine(password.ToString());
}