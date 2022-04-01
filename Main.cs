using System;
//All code runs here
//This is where you change code
namespace Casino
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("This is the start of the game");
            Console.WriteLine("What is your name?");
            string name;
            name=Console.ReadLine();
            Console.WriteLine("How much money are you willing to lose?");
            int monies=int.Parse(Console.ReadLine());
            Player playerUno= new Player(name, monies);
            Console.WriteLine("What Game would you like to pick?");
            Console.WriteLine("1 Baccarat      2  BlackJack      3   Slots      4   VideoPoker     5   Poker  6 To Exit");
            int choice=int.Parse(Console.ReadLine());
            while (choice != 6)
            {
                playerUno.Display();
                if (choice == 1)
                {
                    Console.WriteLine("Great Choice");
                    Baccarat game = new Baccarat(playerUno);
                }
                else if (choice == 2)
                {
                    Console.WriteLine("Great Choice");
                    Blackjack game = new Blackjack(playerUno);

                }
                else if (choice == 3)
                {
                    Console.WriteLine("Great Choice");
                    Slots game = new Slots(playerUno);

                }
                else if (choice == 4)
                {
                    Console.WriteLine("Not Available");

                }
                else if (choice == 5)
                {
                    Console.WriteLine("Not Available");
                }
                else
                {
                    Console.WriteLine("Invalid");
                }
                Console.WriteLine("What Game would you like to pick?");
                Console.WriteLine("1 Baccarat      2  BlackJack      3   Slots      4   VideoPoker     5   Poker  6 To Exit");
                choice = int.Parse(Console.ReadLine());
            }

        }
    }
}