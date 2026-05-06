
import java.util.*;


public class C_Lucky_Numbers {
 
    public static void solve(){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();

         double a = n;
        double val = Math.pow(2.0, a);

        long ans = (long) val -1;
        System.out.println(ans * 2);

    }
    public static void main(String[] arg) {

    
           solve();
    
    }
};

