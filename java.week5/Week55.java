
package week.pkg5.pkg5;


public class Week55 {

    
    public static void main(String[] args) {
       int n = 5678;
       int r;
       int sum = 0;
       while(n>0)
       {
           r = n%10;
           n = n/10;
           System.out.println(" n =" + n + " r=" +r);
           sum = sum + r;
       }
       System.out.println(sum);
    }
    
}
