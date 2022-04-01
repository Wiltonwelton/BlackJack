using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Casino
{
    internal class Card
    {
        public Image imgs;
        public int CardFace{ get; set; }
        public int CardSuit{ get; set; }
        public string CardName{ get; set; }
        public void GetCardName() {
            string first;
            string second;
            switch (this.CardSuit)
            {
                case 0: 
                    second = "Spades";
                    break;
                case 1:
                    second = "Clubs";
                    break;
                case 2:
                    second = "Hearts";
                    break;
                default:
                    second = "Diamonds";
                    break;
            }
            switch (this.CardFace)
            {
                case 0:
                    first = "Ace";
                    break;
                case 1:
                    first = "Two";
                    break;
                case 2:
                    first = "Three";
                    break;
                case 3:
                    first = "Four";
                    break;
                case 4:
                    first = "Five";
                    break;
                case 5:
                    first = "Six";
                    break;
                case 6:
                    first = "Seven";
                    break;        
                case 7:
                    first = "Eight";
                    break;
                case 8:
                    first = "Nine";
                    break;
                case 9:
                    first = "Ten";
                    break;
                case 10:
                    first = "Jack";
                    break;
                case 11:
                    first = "Queen";
                    break;
                default:
                    first = "King";
                    break;
            }
            this.CardName = first + " of " + second;
        }
        public Card(int cardNumber) {
            this.CardSuit= cardNumber/13;
            this.CardFace= cardNumber%13;
            GetImage();
            GetCardName();
        }
        private void GetImage() {
            string first;
            string second;
            string imageName;
            switch (this.CardSuit)
            {
            case 0:
                second = "spade";
                break;
            case 1:
                second = "club";
                break;
            case 2:
                second = "heart";
                break;
            default:
                second = "diamond";
                break;
            }
            switch (this.CardFace)
            {
            case 0:
                first = "ace";
                break;
            case 1:
                first = "2";
                break;
            case 2:
                first = "3";
                break;
            case 3:
                first = "4";
                break;
            case 4:
                first = "5";
                break;
            case 5:
                first = "6";
                break;
            case 6:
                first = "7";
                break;
            case 7:
                first = "8";
                break;
            case 8:
                first = "9";
                break;
            case 9:
                first = "10";
                break;
            case 10:
                first = "jack";
                break;
            case 11:
                first = "queen";
                break;
            default:
                first = "king";
                break;
            }
            imageName = first + "_" + second + ".png";
            imgs = Image.FromFile(imageName);
        }
    }
}
