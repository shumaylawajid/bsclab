
package week.pkg5.pkg4;
import java.util.Scanner;

public class Week54 {

   
    public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
      System.out.println(" Enter the value of n :");
      double n = input.nextDouble();
      
      double sum = 0.0;
      for( int i = 1; i<=n; i++)
      {
          sum += 1.0/i;
          System.out.println(" sum =" + sum + "i =" + i);
      }
      System.out.println(" The sum of the series : " + sum);
      input.close();
    }
    
}
