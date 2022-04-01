using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Casino
{
    internal class Stamp
    {
        private int StampID;
        private string StampName;
        private int PayOut;
        //public Image Ima ge1 { set; get;}
        public Stamp(int id) {
            StampID = id;
            if (id == 0) {
                //this.Image1=imageArray[id]
                StampName = "orange";
                PayOut = 1;
            }
            else if (id == 1) {
                //this.Image1=imageArray[id]
                StampName = "cherry";
                PayOut = 2;

            }
            else if (id == 2) {
                //this.Image1=imageArray[id]
                StampName = "watermelon";
                PayOut = 2;

            }
            else if (id == 3) {
                //this.Image1=imageArray[id]
                StampName = "horseshoe";
                PayOut = 3;


            }
            else if (id == 4) {
                //this.Image1=imageArray[id]
                StampName = "clover";
                PayOut = 4;


            }
            else if (id == 5) {
                //this.Image1=imageArray[id]
                StampName = "coins";
                PayOut = 5;


            }
            else if (id == 6) {
                //this.Image1=imageArray[id]
                StampName = "dollars";
                PayOut = 3;

            }
            else if (id == 7) {
                //this.Image1=imageArray[id]
                StampName = "7";
                PayOut = 7;


            }
            else if (id == 8) {
                //this.Image1=imageArray[id]
                StampName = "777";
                PayOut = 21;


            }
            else if (id == 9) {
                //this.Image1=imageArray[id]
                StampName = "diamond";
                PayOut = 100;


            }
            else {           
                //this.Image1=imageArray[id]
                StampName = "heart";
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
