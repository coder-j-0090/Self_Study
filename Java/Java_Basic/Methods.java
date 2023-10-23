import java.util.Scanner;

public class Methods
{
    public static void main(String[]args)
    {
        hello();
        sum();
        average();
        bye();
    }
    public static void hello()
    {
        System.out.println("hello");
    }
    public static void sum()
    {
        int a,b,c;
        Scanner scan = new Scanner(System.in);
        System.out.print("a: ");
        a=scan.nextInt();
        System.out.print("b : ");
        b=scan.nextInt();
        System.out.print("sum : ");
        c=a+b;
        System.out.println(c);
    }
    public static void average()
    {
        int a,b;
        double c;
        Scanner scan = new Scanner(System.in);
        System.out.print("a: ");
        a=scan.nextInt();
        System.out.print("b: ");
        b=scan.nextInt();
        System.out.print("average : ");
        c=(a+b)/2.0;
        System.out.println(c);
    }
    public static void bye()
    {
        System.out.println("bye");
    }

}
