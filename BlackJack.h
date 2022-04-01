using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Casino
{
    internal class Blackjack
    {
        private Deck DeckBlack = new Deck(6);
        private Hand dealer = new Hand();
        private Hand player = new Hand();
        private int SetPlayerBet = 0;
        private int Winner = 0;
        //public int DeckNumber = 6;
        private int MinBet = 10;
        private int MinCardCount = 6;
        private int continueGame = 1;
        public Player User{ get; set; }
            public Blackjack(Player player) {
            User = player;
            StartGame();
        }
        public void StartGame() {
            while (continueGame == 1) {
                if (DeckBlack.Cards.Count < MinCardCount) {
                    DeckBlack = new Deck(6);
                    Console.WriteLine("New Deck Shuffled");
                }
                SetPlayerBet = 0;
                GetBets();
                if (SetPlayerBet == 0) {
                    Console.WriteLine("You have decided not to play");
                    break;
                }
                DeckBlack.DrawCard(player);
                DeckBlack.DrawCard(dealer);
                DeckBlack.DrawCard(player);
                DeckBlack.DrawCard(dealer);
                Console.WriteLine($"You have a {player.Cards[0].CardName} and a {player.Cards[1].CardName}");
                Console.WriteLine($"The dealer has {dealer.Cards[1].CardName} showing.");
                DetermineWinner();
                if (Winner == 0) {
                    Console.WriteLine($"Tie! You won {SetPlayerBet}");
                    User.PayoutCash(SetPlayerBet);
                }
                else if (Winner == 1) {
                    Console.WriteLine($"Dealer won! You lost.");
                }
                else {
                    Console.WriteLine($"Player won! You won {SetPlayerBet*2}");
                    User.PayoutCash(SetPlayerBet*2);
                }
                dealer.discardHand();
                player.discardHand();
                Console.WriteLine($"Your new bank is {User.Cash}");
                Console.WriteLine("Would you like to continue? (Type '1' to continue)");
                continueGame = int.Parse(Console.ReadLine());
            }
        }

        public int GetScore(Hand scoree) {
            int score = 0;
            int aceCount = 0;
            for (int i = 0; i < scoree.Cards.Count; i++) {
               // Console.WriteLine(scoree.Cards[i].CardName);
                if (scoree.Cards[i].CardFace == 0) {
                    aceCount++;
                }
                else if(scoree.Cards[i].CardFace<10){
                    score += scoree.Cards[i].CardFace + 1;
                }
                else {
                    score += 10;
                }

            }
            for (int i = 0; i < aceCount; i++) {
                if (22>(score+11+(aceCount-1))) {
                    score += 11;
                }
                else {
                    score++;
                }
            }
            //Console.WriteLine(score);
            return score;
        }
        public void GetBets() {
            Console.WriteLine("How much are you betting?");
            SetPlayerBet=int.Parse(Console.ReadLine());
            int setbet = 1;
            int Rebet = 1;
            while ((setbet == 1) && ((SetPlayerBet < MinBet) || (SetPlayerBet > User.Cash)))
            {
                if (SetPlayerBet < MinBet) {
                    Console.Write("Your bet does not meet the minimum. Would you like to rebet? (0 = No, 1 = Yes) ");
                    Rebet = int.Parse(Console.ReadLine());
                }
                if (User.Cash < SetPlayerBet) {
                    Console.Write("You have insuffiecient funds. Would you like to rebet? (0 = No, 1 = Yes) ");
                    Rebet = int.Parse(Console.ReadLine());
                }
                if (Rebet == 0) {
                    Console.WriteLine("You have opted not to bet on this option");
                    SetPlayerBet = 0;
                }
                else
                {
                    Console.WriteLine("How much would you like to bet?");
                    SetPlayerBet = int.Parse(Console.ReadLine());
                }
            }
            User.BetCash(SetPlayerBet);
        }
        public void DetermineWinner() {
            int playerScore=0;
            int dealerScore = 0;
            int DealCount = 2;
            int DealCountD = 2;
            playerScore = GetScore(player);
            dealerScore = GetScore(dealer);
            if (playerScore == 21) {
                if (dealerScore == 21) {
                    Console.WriteLine("Both have Blackjack. Tie!");
                    Winner = 0;
                }
                else {
                    Console.WriteLine("Blackjack! You won!");
                    Winner = 2;
                }
            }
            else {
                Console.WriteLine("Do you want to hit? (0 = no, 1 = yes) ");
                int hit = int.Parse(Console.ReadLine());
                while (hit == 1) {
                    DeckBlack.DrawCard(player);
                    Console.WriteLine($"You were dealt a {player.Cards[DealCount].CardName}");
                    DealCount++;
                    playerScore = GetScore(player);
                    if (playerScore < 21) {
                        Console.WriteLine("Do you want to hit? (0 = no, 1 = yes) ");
                        hit = int.Parse(Console.ReadLine());
                    }
                    else if (playerScore == 21)
                    {
                        Console.WriteLine("You hit 21!");
                        Winner = 2;
                        hit = 0;
                    }
                    else {
                        Console.WriteLine("You bust.");
                        Winner = 1;
                        hit = 0;
                    }
                }
                Console.WriteLine($"Dealer shows a {dealer.Cards[0].CardName}");
                    if (dealerScore > 16 || playerScore>21) {
                        Console.WriteLine("Dealer sits");
                        hit = 0;
                    }
                    else {
                        hit = 1;
                        while (hit == 1) {
                            DeckBlack.DrawCard(dealer);
                            Console.WriteLine($"Dealer was dealt a {dealer.Cards[DealCountD].CardName}");
                            DealCountD++;
                            dealerScore = GetScore(dealer);
                            if (dealerScore > 17) {
                                hit = 0;
                                if (dealerScore > 21) {
                                    Console.WriteLine("Dealer bust");
                                    Winner = 2;
                                }
                                
                            }
                        }
                    }
                Console.WriteLine($"You had a total of {playerScore}");
                Console.WriteLine($"Dealer had a total of {dealerScore}");
                if (dealerScore < 22 && playerScore < 22) {
                    if (dealerScore == playerScore) {
                        Winner = 0;
                    }
                    else if (dealerScore > playerScore) {
                        Winner = 1;
                    }
                    else {
                        Winner = 2;
                    }
                }
            }

        }
    }
}
