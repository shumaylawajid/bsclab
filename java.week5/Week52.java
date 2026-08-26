
package week.pkg5.pkg2;

import java.util.Scanner;
public class Week52 {

  
    public static void main(String[] args) {
       Scanner input = new Scanner(System.in);
       System.out.println(" Enter the number of elemnts :");
       int n = input.nextInt();
       int[] arr = new int[n];
       int sum = 0;
       System.out.println(" Enter " + n + "elements :");
       for(int i = 0; i<n ; i++)
       {
           arr[i] = input.nextInt();
           sum += arr[i];
       }
       System.out.println(" The sum of all array elements is :" + sum);
       input.close();
    }
    
}
