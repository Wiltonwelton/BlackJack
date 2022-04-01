using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Casino
{
    internal class Hand
    {
        public List <Card> Cards = new List <Card>();
        public void showHand() {
            Console.WriteLine("This hand has: ");
            for (int i = 0; i < Cards.Count; i++) {
                Console.WriteLine(Cards[i].CardName);
            }
        }
        public void discardCard(int disc) {
            Card discard = Cards[disc];
            Cards.Remove(discard);
        }
        public void discardHand() {
            while (Cards.Count > 0) {
                discardCard(0);
            }
        }

    }
}
