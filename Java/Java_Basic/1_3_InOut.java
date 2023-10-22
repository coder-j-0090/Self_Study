import java.util.Scanner;

public class InOut
{
    public static void main(String[]args)
    {
        int a,b,c;
        Scanner scan = new Scanner(System.in);
        System.out.print("a : ");
        a=scan.nextInt();
        System.out.print("b : ");
        b=scan.nextInt();
        System.out.print("c : ");
        c=a+b;
        System.out.println(c);
    }
}
