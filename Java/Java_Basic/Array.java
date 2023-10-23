import java.util.Scanner;

public class Array
{
    public static void main(String[]args)
    {
        int [] arr = new int[10];
        int max,min;
        Scanner scan = new Scanner(System.in);
        for(int i=0;i<10;i++)
            arr[i]=scan.nextInt();

        max=arr[0];			//min=max=kor[0];
        min=arr[0];

        for(int i=1;i<=9;i++)		//위에줄에 0이 들어갔기때문에 1에서 부터 시작한다.
            if(arr[i]>max)
                max=arr[i];

        for(int i=1;i<=9;i++)
            if(arr[i]<min)
                min=arr[i];

        /*
		  for(int i=1;i<=9;i++)
		  {
		  	if(kor[i]>max)
				max=kor[i];
			if(kor[i]<min)
				min=kor[i];
		  }
		 */

        System.out.println(max);
        System.out.println(min);
    }
}
