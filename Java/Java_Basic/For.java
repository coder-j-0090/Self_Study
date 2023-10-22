import java.util.Scanner;

public class For
{
    public static void main(String[]args)
    {
        //Right Triangle
        int i, j;

        for (j = 1; j <= 10; j++)
        {
            for (i = 1; i <= j; i++)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();

        //Inverted Triangle
        i = 0;
        j = 0;

        for (j = 1; j <= 10; j++)
        {
            for (i = j; i <= 10; i++)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();

        //Triangle(two * increase per each line)
        i = 0;
        j = 0;

        for (j = 1; j <= 10; j++)
        {
            for (i = 1; i <= j * 2 - 1; i++)
            {
                System.out.printf("*");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();

        //Inverted Triangle(two * decrease per each line)
        for (j = 1; j <= 10; j++)
        {
            for (i = j * 2 - 1; i < 20; i++)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();

        //Basic Pyramid
        i=0;
        j=0;

        for(i=1;i<=10;i++)
        {
            for(j=i;j<=10;j++)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j++)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();

        //Diamond
        i=0;
        j=0;

        for(i=1;i<=10;i=i+1)
        {
            for(j=i;j<=10;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        for(i=2;i<=10;i=i+1)
        {
            for(j=1;j<=i;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();

        //Double Diamond
        i=0;
        j=0;

        for(i=1;i<=10;i=i+1)
        {
            for(j=i;j<=10;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }

        for(i=2;i<=10;i=i+1)
        {
            for(j=1;j<=i;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            for(j=2;j<=i*2;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }

        System.out.println();
        System.out.println();

        //Two Diamonds(Overlap)
        i=0;
        j=0;
        for(i=1;i<=10;i=i+1)
        {
            for(j=i;j<=10;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            for(j=i*2;j<=18;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }

        for(i=2;i<=10;i=i+1)
        {
            for(j=1;j<=i;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=18;j=j+1)
            {
                System.out.print("*");
            }
            for(j=2;j<=i*2;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=18;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }

        System.out.println();
        System.out.println();

        //Overlap 2
        i=0;
        j=0;
        for(i=1;i<=10;i=i+1)
        {
            for(j=i;j<=10;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            for(j=i*2;j<19;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }

        for(i=2;i<=10;i=i+1)
        {
            for(j=1;j<=i;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            for(j=2;j<=i*2-1;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }

        System.out.println();
        System.out.println();

        //Overlap3
        i=0;
        j=0;
        for(i=1;i<=10;i=i+1)
        {
            for(j=i;j<=10;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            for(j=i*2;j<19;j=j+1)
            {
                System.out.print(" ");
            }
            if(i<=9)
            {
                for(j=1;j<=i*2-1;j=j+1)
                {
                    System.out.print("*");
                }
            }
            else
            {
                for(j=1;j<=i*2-2;j=j+1)
                {
                    System.out.print("*");
                }
            }
            System.out.println();
        }

        for(i=2;i<=10;i=i+1)
        {
            for(j=1;j<=i;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            for(j=2;j<=i*2-2;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();

        //Two diamonds in vertical way
        i=0;
        j=0;

        for(i=1;i<=10;i=i+1)
        {
            for(j=i;j<=10;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        for(i=2;i<=10;i=i+1)
        {
            for(j=1;j<=i;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        for(i=1;i<=10;i=i+1)
        {
            for(j=i;j<=10;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        for(i=2;i<=10;i=i+1)
        {
            for(j=1;j<=i;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();

        //Two diamonds in vertical way(2)
        i=0;
        j=0;
        for(i=1;i<=10;i=i+1)
        {
            for(j=i;j<=10;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        for(i=2;i<=10;i=i+1)
        {
            for(j=1;j<=i;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        for(i=1;i<=10;i=i+1)
        {
            for(j=i;j<=10;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=1;j<=i*2-1;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }
        for(i=2;i<=10;i=i+1)
        {
            for(j=1;j<=i;j=j+1)
            {
                System.out.print(" ");
            }
            for(j=i*2;j<=20;j=j+1)
            {
                System.out.print("*");
            }
            System.out.println();
        }

    }
}
