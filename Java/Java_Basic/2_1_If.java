import java.util.Scanner;

public class If
{
    public static void main(String[]args)
    {
        //Checking if the number is positive or negative
        System.out.println("Enter the number");
        int a;
        Scanner scan = new Scanner(System.in);
        a=scan.nextInt();

        if(a>0)
            System.out.println("positive");
        else if(a<0)
            System.out.println("negative");
        else
            System.out.println("Zero");
    }
}
