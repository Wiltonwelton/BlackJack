using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Casino
{
    internal class Baccarat
    {   
        private Deck DeckBac = new Deck(6);
        private Hand dealer = new Hand();
        private Hand player = new Hand();
        private int SetDealerBet = 0;
        private int SetPlayerBet = 0;
        private int SetTieBet = 0;
        private int Winner = 0;
        //public int DeckNumber = 6;
        private int cashToAdd{ get; set; }
        private int MinBet = 10;
        private int MinCardCount = 6;
        private int continueGame = 1;
        public Player User{ get; set; }
        public Baccarat(Player player) {
            User=player;
            StartGame();
        }
        public void StartGame() {
            while (continueGame==1){
                if(DeckBac.Cards.Count < MinCardCount){
                    DeckBac = new Deck(6);
                    Console.WriteLine("New Deck Shuffled");
                }
                SetDealerBet = 0;
                SetPlayerBet = 0;
                SetTieBet = 0;
                GetBets();
                DeckBac.DrawCard(player);
                DeckBac.DrawCard(dealer);
                DeckBac.DrawCard(player);
                DeckBac.DrawCard(dealer);
                DetermineWinner();
                if (Winner == 0) { 
                    Console.WriteLine($"Tie! You won {SetTieBet*8}");
                    User.PayoutCash(SetTieBet * 8); }
                else if (Winner == 1) {
                    Console.WriteLine($"Dealer won! You won {SetDealerBet}");
                    User.PayoutCash(2*SetDealerBet); }
                else { 
                    Console.WriteLine($"Player won! You won {SetPlayerBet}");
                    User.PayoutCash(2*SetPlayerBet); }
                Console.WriteLine("Would you like to continue? (Type '1' to continue)");
                continueGame= int.Parse(Console.ReadLine());
            }
        }









        private void GetBets() {
            Console.WriteLine($"Player Bank: {User.Cash}");
            // get player's bet
            int Rebet = 1;
            int setBet;
            Console.WriteLine("Where would you like to bet?");
            Console.Write("Dealer hand wins? Pays 1:1 (1 = yes): ");
            setBet = int.Parse(Console.ReadLine());
            if (setBet == 1)
            {
                Console.WriteLine("How much would you like to bet?");
                SetDealerBet=int.Parse(Console.ReadLine());
                while (((SetDealerBet < MinBet)||(User.Cash<SetDealerBet))&&(Rebet==1)){
                    if(SetDealerBet < MinBet) {
                        Console.Write("Your bet does not meet the minimum. Would you like to rebet? (0 = No, 1 = Yes) ");
                        Rebet=int.Parse(Console.ReadLine());
                    }
                    if (User.Cash < SetDealerBet) {
                        Console.Write("You have insuffiecient funds. Would you like to rebet? (0 = No, 1 = Yes) ");
                        Rebet = int.Parse(Console.ReadLine());
                    }
                    if (Rebet == 0) {
                        Console.WriteLine("You have opted not to bet on this option");
                        SetDealerBet = 0;
                    }
                    else
                    {
                        Console.WriteLine("How much would you like to bet?");
                        SetDealerBet = int.Parse(Console.ReadLine());
                    }
                }
                User.BetCash(SetDealerBet);
            }
            Console.Write("Player hand wins? Pays 1:1 (1 = yes): ");
            Rebet = 1;
            setBet = int.Parse(Console.ReadLine());
            if (setBet == 1)
            {
                Console.WriteLine("How much would you like to bet?");
                SetPlayerBet = int.Parse(Console.ReadLine());
                while (((SetPlayerBet < MinBet) || (User.Cash < SetPlayerBet)) && (Rebet == 1)) {
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
            Console.Write("Tie game? Pays 8:1 (1 = yes): ");
            Rebet = 1;
            setBet = int.Parse(Console.ReadLine());
            if (setBet == 1)
            {
                Console.WriteLine("How much would you like to bet?");
                SetTieBet = int.Parse(Console.ReadLine());
                while (((SetTieBet < MinBet) || (User.Cash < SetTieBet)) && (Rebet == 1)) {
                    if (SetTieBet < MinBet) {
                        Console.Write("Your bet does not meet the minimum. Would you like to rebet? (0 = No, 1 = Yes) ");
                        Rebet = int.Parse(Console.ReadLine());
                    }
                    if (User.Cash < SetTieBet) {
                        Console.Write("You have insuffiecient funds. Would you like to rebet? (0 = No, 1 = Yes) ");
                        Rebet = int.Parse(Console.ReadLine());
                    }
                    if (Rebet == 0) {
                        Console.WriteLine("You have opted not to bet on this option");
                        SetTieBet = 0;
                    }
                    else
                    {
                        Console.WriteLine("How much would you like to bet?");
                        SetTieBet = int.Parse(Console.ReadLine());
                    }
                }
                User.BetCash(SetTieBet);
            }
            Console.WriteLine();
        }







        public int GetScore(Hand scoree) {
            int score=0;
            for (int i = 0; i < scoree.Cards.Count; i++) {
                Console.WriteLine(scoree.Cards[i].CardName);
                if (scoree.Cards[i].CardFace < 9) {
                    score+=scoree.Cards[i].CardFace+1;
                }
            }
            score = score % 10;
            Console.WriteLine(score);
            return score;
        }
        private void DetermineWinner() {
            int playerTotal;
            int dealerTotal;
            bool tieGame = false;
            bool playerWin = false;
            bool dealerWin = false;
            playerTotal = GetScore(player);
            dealerTotal = GetScore(dealer);

            // no more cards drawn if player or dealer have 8 or 9 points
            if (playerTotal == 8 || playerTotal == 9 || dealerTotal == 8 || dealerTotal == 9)
            {
                // tie hand dealt
                if (playerTotal == dealerTotal)
                    tieGame = true;
                // player has 9 and dealer has 8 - player wins
                else if (playerTotal > dealerTotal)
                    playerWin = true;
                // player has 8 and dealer has 9 - dealer wins
                else
                    dealerWin = true;


            }
            // any other outcome than the player/dealer having natural 8 or 9
            else
            {
                // player is dealt a total 0 - 5
                if (playerTotal < 6)
                {
                    DeckBac.DrawCard(player);  // player is dealt a third card
                    int thirdCard = player.Cards[2].CardFace;

                    // dealer is dealt a third card based on the player's third card 
                    //If the banker total is 2 or less, then the banker draws a card, regardless of what the player's third card is
                    if (dealerTotal <= 2)
                    {
                        DeckBac.DrawCard(dealer);
                    }
                    //If the banker total is 3, then the banker draws a third card unless the player's third card was an 8.
                    else if (dealerTotal == 3 && thirdCard != 7)
                    {
                        DeckBac.DrawCard(dealer);
                    }
                    //If the banker total is 4, then the banker draws a third card if the player's third card was 2, 3, 4, 5, 6, 7.
                    else if (dealerTotal == 4 && thirdCard > 0 && thirdCard < 7)
                    {
                        DeckBac.DrawCard(dealer);
                    }
                    //If the banker total is 5, then the banker draws a third card if the player's third card was 4, 5, 6, or 7.
                    else if (dealerTotal == 5 && thirdCard > 2 && thirdCard < 7)
                    {
                        DeckBac.DrawCard(dealer);
                    }
                    //If the banker total is 6, then the banker draws a third card if the player's third card was a 6 or 7.
                    else if (dealerTotal == 6 && (thirdCard == 5 || thirdCard == 6))
                    {
                        DeckBac.DrawCard(dealer);
                    }

                    //If the banker total is 7, then the banker stands
                    //If the banker total is one of the above and the player's third card does not meet the criteria for dealer to draw another card
                    Console.WriteLine();

                    // show new totals
                    playerTotal = GetScore(player);
                    dealerTotal = GetScore(dealer);

                    // tie hand dealt
                    if (playerTotal == dealerTotal)
                        tieGame = true;
                    // player has a better hand - player wins
                    else if (playerTotal > dealerTotal)
                        playerWin = true;
                    // dealer has a better hand - dealer wins
                    else
                        dealerWin = true;
                }
                // player is dealt a total of 6 or 7 and dealer has a total of 0-5
                else if (dealerTotal < 6)
                {
                    // dealer gets another card
                    DeckBac.DrawCard(dealer);
                    Console.WriteLine();

                    // show new totals
                    playerTotal = GetScore(player);
                    dealerTotal = GetScore(dealer);

                    // tie hand dealt
                    if (playerTotal == dealerTotal)
                        tieGame = true;
                    // player has a better hand - player wins
                    else if (playerTotal > dealerTotal)
                        playerWin = true;
                    // dealer has a better hand - dealer wins
                    else
                        dealerWin = true;
                }
                // dealer and player both have a total of 6 or 7
                else
                {
                    Console.WriteLine();
                    playerTotal = GetScore(player);
                    dealerTotal = GetScore(dealer);
                    // tie hand dealt
                    if (playerTotal == dealerTotal)
                        tieGame = true;
                    // player has 7 and dealer has 6 - player wins
                    else if (playerTotal > dealerTotal)
                        playerWin = true;
                    // player has 6 and dealer has 7 - dealer wins
                    else
                        dealerWin = true;
                }
            }
            if (tieGame) { 
                Winner = 0; }
            else if (dealerWin){ 
                Winner = 1; }
            else if(playerWin) { 
                Winner = 2; }
        }
    }

}