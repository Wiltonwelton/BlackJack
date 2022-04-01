using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Casino
{
    internal class VideoPoker
    {
        private Deck DeckVP = new Deck(6);
        private Hand player = new Hand();
        private int SetPlayerBet = 0;
        //public int DeckNumber = 6;
        //private int MinBet = 10;
        private int MinCardCount = 6;
        private int continueGame = 1;
        public Player User{ get; set; }
    }
}
