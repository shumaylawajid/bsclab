
package week.pkg4.pkg1;
import java.util.Scanner;

public class Week41 {

   
    public static void main(String[] args) {
     Scanner input = new Scanner(System.in);
     System.out.println("Enter the number : ");
     int n = input.nextInt();
     if(n%2 == 0)
     {
         System.out.println( n + " is even ");
     }
     else{
         System.out.println( n + " is odd ");
     }
     input.close();
    }
    
}
