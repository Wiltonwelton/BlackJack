using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Casino
{
    internal class Slots
    {
        private Player User;
        private int ReelCount1;
        private int ReelCount2;
        private int ReelCount3;
        private int PlayerBet;
        private int TimeBetween =5;
        private int MinBet = 1;
        private Reels slotsReels = new Reels();
        public Slots(Player player) {
            User = player;
            Random r=new Random();
            ReelCount1 = r.Next(0, 21);
            ReelCount2 = r.Next(0, 21);
            ReelCount3 = r.Next(0, 21);
            while(StartGame());
        }
        private bool StartGame() {
            int betChoice;
            betChoice = 1;
            while (!GetBet() && betChoice == 1) {
                Console.WriteLine("Do you still want to to play?(1 for yes)");
                betChoice = int.Parse(Console.ReadLine());
            }
            if (PlayerBet == 0) {
                return false;
            }
            else {
                slotsReels.Display(ReelCount1, ReelCount2, ReelCount3);
                while (!Console.KeyAvailable) {
                    var startTime = DateTime.UtcNow;
                    while ((DateTime.UtcNow - startTime) < TimeSpan.FromSeconds(1)) {}
                    ReelCount1 = ((ReelCount1 + 3) % 22);
                    ReelCount2 = ((ReelCount2 + 3) % 22);
                    ReelCount3 = ((ReelCount3 + 3) % 22);
                    slotsReels.Display(ReelCount1, ReelCount2, ReelCount3);
                }
                string trash=Console.ReadLine();
                if(slotsReels.GetValues(ReelCount1, ReelCount2, ReelCount3)){
                    int PayOut = slotsReels.PayOut;
                    User.PayoutCash(PayOut*PlayerBet);
                    Console.WriteLine($"You Won!! {PayOut*PlayerBet}");

                }
                else {
                    Console.WriteLine("You Lost");
                }
                Console.WriteLine("Play again? (1 to continue)");
                int continueGame=int.Parse(Console.ReadLine());
                if (continueGame == 1) {
                    return true;
                }
                else {
                    return false;
                }
            }
            
        }
        private bool GetBet() {
            Console.WriteLine("How much are you wanting to bet?");
            PlayerBet= int.Parse(Console.ReadLine());
            if (PlayerBet < MinBet) {
                Console.WriteLine("You did not bet the minimum amount. Please rebet.");
                PlayerBet = 0;
                return false;
            }
            else if (PlayerBet > User.Cash) {
                Console.WriteLine("You do not have enough cash");
                PlayerBet = 0;
                return false;
            }
            else {
                User.BetCash(PlayerBet);
                return true;
            }
        }
    }
}
