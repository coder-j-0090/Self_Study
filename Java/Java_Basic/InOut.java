import java.util.Scanner;

public class InOut
{
    public static void main(String[]args)
    {
        int a, b, c;
        Scanner scan = new Scanner(System.in);
        a = scan.nextInt();
        b = scan.nextInt();
        c = a+b;
        System.out.println("Sum of input Number is "+c);
    }
}
