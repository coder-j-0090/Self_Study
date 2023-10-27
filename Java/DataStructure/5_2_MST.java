import java.util.Scanner;

public class MST
{
    public static void main(String[]args)
    {
        Graph g = new Graph();
        g.printy();
        //g.printScanVertex();
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter vertex: ");
        int n = scan.nextInt();
        g.printScanVertex(n);
    }

}
