import java.util.Scanner;

public class If
{
    public static void main(String[]args)
    {
        int a;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the score of the test: ");
        a=scan.nextInt();
        if(a>=90)
        {
            System.out.println("A");
        }
        else if(a>=80)
        {
            System.out.println("B");
        }
        else if(a>=70)
        {
            System.out.println("C");
        }
        else if(a>=60)
        {
            System.out.println("D");
        }
        else
        {
            System.out.println("F");
        }
    }
}
