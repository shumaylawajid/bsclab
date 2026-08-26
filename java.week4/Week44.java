
package week.pkg4.pkg4;
import java.util.Scanner;

public class Week44 {

  
    public static void main(String[] args) {
     Scanner input = new Scanner(System.in);
     
     System.out.println(" Enter the value of N :");
     int n = input.nextInt();
     long sum = 0;
     for( int i = 1; i<= n ; i++)
     {
         sum += i;
     }
     System.out.println(" Sum of the series from 1 to" + n + " is:" + sum);
     input.close();
    }
    
}
