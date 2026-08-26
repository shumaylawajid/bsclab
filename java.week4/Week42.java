
package week.pkg4.pkg2;
import java.util.Scanner;

public class Week42 {

  
    public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
      
      System.out.println(" Enter the first number :");
      double n1 = input.nextDouble();
      System.out.println(" Enter the second number :");
      double n2 = input.nextDouble();
      System.out.println("Enter the third number :");
      double n3 = input.nextDouble();
      
      double largest;
      if((n1>n2) && ( n1>n3))
      {
          largest = n1;
      } else if (( n2>n1 ) && ( n2>n3))
      {
          largest = n2;
      }
      else{
          largest = n3;
      }
      System.out.println("The largest number is :" + largest);
      input.close();
    }
    
}
