using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Casino
{
    internal class Reels
    {
        public int PayOut = 0;    
        public List <Stamp> Reel1 = new List <Stamp>();
        public List <Stamp> Reel2 = new List <Stamp>();
        public List <Stamp> Reel3 = new List <Stamp>();


        public Reels() {
            PayOut = 0;
            Console.WriteLine("What set of reels are you using? 0 = Normal 1 = Rigged");
            int choice = int.Parse(Console.ReadLine());
            if(choice==1){
                Console.WriteLine("What symbol are we implementing?");
                int img=int.Parse(Console.ReadLine());
                Reel1 = new List <Stamp>{ new Stamp(img),new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img),
                    new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img),
                    new Stamp(img),new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img) };
                Reel2 = new List <Stamp>{ new Stamp(img),new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img),
                    new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img),
                    new Stamp(img),new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img) };
                Reel3 = new List <Stamp>{ new Stamp(img),new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img),
                    new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img),
                    new Stamp(img),new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img), new Stamp(img) };
            }
            else {
                Reel1 = new List <Stamp>{ new Stamp(0),new Stamp(0), new Stamp(1), new Stamp(2), new Stamp(0), new Stamp(0), new Stamp(3), 
                    new Stamp(4), new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(8), new Stamp(8), new Stamp(8), new Stamp(8),
                    new Stamp(5), new Stamp(4), new Stamp(6), new Stamp(2), new Stamp(1) };
                Reel2 = new List <Stamp>{ new Stamp(0),new Stamp(0), new Stamp(0), new Stamp(0), new Stamp(0), new Stamp(0), new Stamp(0),
                    new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(8), new Stamp(8), new Stamp(8), new Stamp(8),
                    new Stamp(4), new Stamp(6), new Stamp(4), new Stamp(8), new Stamp(8) };
                Reel3 = new List <Stamp>{ new Stamp(0),new Stamp(0), new Stamp(0), new Stamp(0), new Stamp(0), new Stamp(0), new Stamp(0),
                    new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(3), new Stamp(8), new Stamp(8), new Stamp(8), new Stamp(8),
                    new Stamp(8), new Stamp(8), new Stamp(8), new Stamp(8), new Stamp(8) };
            }
        }
        public void Display(int r1, int r2, int r3) {
            Console.WriteLine($"{Reel1[r1].Display()}   {Reel2[r2].Display()}   {Reel3[r3].Display()}");
        }
        public bool GetValues(int r1, int r2, int r3) {
            if(Reel1[r1].GetID()!=Reel2[r2].GetID()){
                return false;
            }
            else if (Reel2[r2].GetID() != Reel3[r3].GetID()) {
                return false;
            }
            else
            {
                PayOut = Reel1[r1].GetPayOut();
                return true;
            }
        }
    }
}
