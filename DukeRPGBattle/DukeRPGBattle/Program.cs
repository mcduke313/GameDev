using System;

namespace DukeRPGBattle
{
    class Program
    {
        static void Main(string[] args)
        {
            Player p = new Player();
            Enemy e = new Enemy();

            p.otherFighter = e;
            e.otherFighter = p;

            do
            {
                Console.WriteLine("=== Player Turn ===\nPlayer HP " + p.CHP + "\nEnemy HP " + e.CHP +"\n");
                p.TakeAction();

                if(e.alive)
                {
                    Console.WriteLine("=== Enemy Turn ===");
                    e.TakeAction();
                }
            } while (p.alive && e.alive);

            if(p.alive)
            {
                Console.WriteLine("You Won!");
            }
            else
            {
                Console.WriteLine("Game Over\nYou Died");
            }
        }
    }

    //shared abilies
    public class Fighter
    {
        public bool alive;
        public int MHP;
        public int CHP;
        public Fighter otherFighter;
        public Fighter()
        {
            alive = true;
            MHP = 20;
            CHP = MHP;
        }
        public virtual void TakeAction()
        {

        }
        public void takeDamage(int n)
        {
            CHP -= n;
            if (CHP < 1)
            {
                Die();
            }
        }
        public void Die()
        {
            alive = false;
        }
    }

    //player
    public class Player : Fighter
    {
        int potions;
        public Player()
        {
            alive = true;
            MHP = 20;
            CHP = MHP;
            potions = 3;
        }
        public override void TakeAction()
        {
            Console.WriteLine("What would you like to do?\n1 - Attack\n2 - Heal (" + potions + " potions remaining)\n");
            string userInput = Console.ReadLine();
            int num = int.Parse(userInput);

            if(num == 1)
            {
                Attack();
            }

            else if(num == 2)
            {
                Heal();
            }
            else
            {
                Console.WriteLine("Did not Attack or Heal! Turn Skipped!");
            }
        }
        public void Attack()
        {
            Console.WriteLine("Attacking Enemy for 5 points of Damage");
            otherFighter.takeDamage(5);
        }
        public void Heal()
        {
            if (potions > 0)
            {
                potions--;
                CHP += 10;
                if(CHP > MHP)
                {
                    int difference =10 -(CHP - MHP);
                    Console.WriteLine("Healed " + difference + " HP");
                }
            }
            else
                Console.WriteLine("You are out of potions");
        }
    }

    //enemy
    public class Enemy : Fighter
    {
        public override void TakeAction()
        {
            Attack();
        }

        public void Attack()
        {
            Console.WriteLine("Attacking Player for 5 points of Damage");
            otherFighter.takeDamage(5);
        }
    }
}
