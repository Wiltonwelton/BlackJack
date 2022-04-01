using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Casino
{
    internal class Stamp
    {
        private int StampID;
        private string StampName;
        private int PayOut;
        public Image Image1;
        public Stamp(int id) {
            StampID = id;
            if (id == 0) {
                Image1=Image.FromFile("bar.png");
                StampName = "Bar";
                PayOut = 1;
            }
            else if (id == 1) {
                Image1 = Image.FromFile("apple.png");
                StampName = "apple";
                PayOut = 2;

            }
            else if (id == 2) {
                Image1 = Image.FromFile("banana.png");
                StampName = "banana";
                PayOut = 2;

            }
            else if (id == 3) {
                Image1 = Image.FromFile("grape.png");
                StampName = "grape";
                PayOut = 3;


            }
            else if (id == 4) {
                Image1 = Image.FromFile("orange.png");
                StampName = "orange";
                PayOut = 4;


            }
            else if (id == 5) {
                Image1 = Image.FromFile("stawberry.png");
                StampName = "strawberry";
                PayOut = 5;


            }
            else if (id == 6) {
                Image1 = Image.FromFile("cherry.png");
                StampName = "cherry";
                PayOut = 3;
            }
            else if (id == 7) {
                Image1 = Image.FromFile("gem.png");
                StampName = "gem";
                PayOut = 7;
            }
            else {           
                Image1 = Image.FromFile("jackpot.png");
                StampName = "jackpot";
                PayOut = 10;


            }

        }
        public string Display() {
            return StampName;
        }
        public int GetID() {
            return StampID;
        }
        public int GetPayOut() {
            return PayOut;
        }
    }
}
