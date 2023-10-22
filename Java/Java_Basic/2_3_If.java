import java.util.Scanner;

public class If
{
    public static void main(String[]args)
    {
        //Find if the student is passed or failed. Also, each score should be higher than 40 and the total score of the test must be over 180.
        //If the student got more than 100 at one test, then the student can get a special acceptance
        int a,b,c;
        Scanner scan = new Scanner(System.in);
        a=scan.nextInt();
        b=scan.nextInt();
        c=scan.nextInt();
        if(a==100||b==100||c==100)
        {
            System.out.println("Special Acceptance");
        }
        else if(a>40&&b>40&&c>40&&(a+b+c)>180)
        {
            System.out.println("Pass");
        }
        else
        {
            System.out.println("Fail");
        }

        /*
	    <= (Smaller than or equal to) 
	    ==(equal)
	    !=(not equal)
	    &&(and)
	    ||(or)
	    else (The last condition)
	*/

    }
}
