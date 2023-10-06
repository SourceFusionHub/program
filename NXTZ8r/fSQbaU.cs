using System;

class Program
{
    static void Main()
    {
        while (true)
        {
            Console.WriteLine("Rock, Paper, Scissors - Enter your choice: ");
            Console.WriteLine("1. Rock");
            Console.WriteLine("2. Paper");
            Console.WriteLine("3. Scissors");
            Console.WriteLine("4. Quit");

            int userChoice = GetUserChoice();
            if (userChoice == 4)
            {
                Console.WriteLine("Thanks for playing!");
                break;
            }

            int computerChoice = GetComputerChoice();
            Console.WriteLine($"Computer chose: {GetChoiceName(computerChoice)}");

            int result = DetermineWinner(userChoice, computerChoice);
            if (result == 0)
            {
                Console.WriteLine("It's a tie!");
            }
            else if (result == 1)
            {
                Console.WriteLine("You win!");
            }
            else
            {
                Console.WriteLine("Computer wins!");
            }
        }
    }

    static int GetUserChoice()
    {
        while (true)
        {
            if (int.TryParse(Console.ReadLine(), out int choice) && choice >= 1 && choice <= 3)
            {
                return choice;
            }
            Console.WriteLine("Invalid choice. Please choose 1, 2, or 3.");
        }
    }

    static int GetComputerChoice()
    {
        Random random = new Random();
        return random.Next(1, 4);
    }

    static string GetChoiceName(int choice)
    {
        switch (choice)
        {
            case 1:
                return "Rock";
            case 2:
                return "Paper";
            case 3:
                return "Scissors";
            default:
                return "Invalid";
        }
    }

    static int DetermineWinner(int userChoice, int computerChoice)
    {
        if (userChoice == computerChoice)
        {
            return 0; // Tie
        }
        else if ((userChoice == 1 && computerChoice == 3) ||
                 (userChoice == 2 && computerChoice == 1) ||
                 (userChoice == 3 && computerChoice == 2))
        {
            return 1; // User wins
        }
        else
        {
            return -1; // Computer wins
        }
    }
}
