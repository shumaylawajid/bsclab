
package week.pkg4.pkg5;
import java.util.Scanner;
public class Week45 {


    public static void main(String[] args) {
     Scanner input = new Scanner(System.in);
     System.out.println(" Enter the number :");
     int n = input.nextInt();
     while ( n>=10)
     {
         System.out.println("Cureent value: " + n);
         n = n/2;
     }
     input.close();
    }
    
}
