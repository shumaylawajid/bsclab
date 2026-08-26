
package week.pkg3.pkg4;
import java.util.Scanner;

public class Week34 {

  
    public static void main(String[] args) {
     Scanner input = new Scanner(System.in);
     System.out.println(" Enter first number :");
     double num1 = input.nextDouble();
     
     System.out.println(" Enter the second number :");
     double num2 = input.nextDouble();
     
     System.out.println(" Enter third number :");
     double num3 = input.nextDouble();
     double average = (num1+ num2+ num3)/3.0;
     System.out.println("The average is: " + average);
     
     input.close();
     
    }
    
}
