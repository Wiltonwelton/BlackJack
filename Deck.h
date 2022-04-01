using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Casino
{
    internal class Deck
    {
        public List <Card> Cards =new List <Card>();
        //public List <Card> ShuffledCards = new List <Card>();
        public int DeckCount;
        public Deck(int deckCount)
        {
            this.DeckCount = deckCount;
            //Console.WriteLine("Deck was initialized");
            for (int i = 0; i < deckCount; i++) {
                for (int j = 0; j < 52; j++) {
                    Card card = new Card(j);
                    Cards.Add(card);
                    //Console.WriteLine(Cards[j].CardName);
                }
            }
            //ShuffleDeck();
        }
        //public void ShuffleDeck() {
            //Console.WriteLine("Start of Shuffle");
            //for (int i = 0; i < 13; i++) {
            //    Console.WriteLine(Cards[i].CardName);
            //}
           // Random rand = new  Random();
           // for (int i = 0; i < Cards.Count; i++) {
                //Card temp = Cards[i];
              //  int swap = rand.Next(0, Cards.Count);
             //   Cards[i] = Cards[swap];
               // Cards[swap] = temp;
           // }
            //Console.WriteLine("After Shuffle");
            //for (int i = 0; i < 13; i++) {
            //    Console.WriteLine(Cards[i].CardName);
            //}
        //}
        public void DrawCard(Hand hand) {
            var rng = new Random();
            int pick;
            pick = rng.Next(Cards.Count);
            Card drawn = Cards[pick];
            Cards.Remove(drawn);
            hand.Cards.Add(drawn);
        }
        public void DisplayDeck() {
            for (int i = 0; i < Cards.Count; i++) {
                Console.WriteLine(Cards[i].CardName);
            }
        }

    }
}
