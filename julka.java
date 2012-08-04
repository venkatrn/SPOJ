import java.util.Scanner;
import java.math.BigInteger;
 class julka {
  public static void main(String[] args) {
    //System.out.println("Hello, World");
    int t;
    BigInteger n,k,x,N;
    Scanner in = new Scanner(System.in);
    //t = in.nextInt();
    t = 10;
    while(t--!=0)
    {
    N = in.nextBigInteger();
    x = in.nextBigInteger();
    n = N.subtract(x);
    n = n.divide(BigInteger.valueOf(2));
    k = N.subtract(n);
   // n  = fact.multiply(BigInteger.valueOf(i));

    System.out.println(k);
    System.out.println(n);
    }
    in.close();
  }
}
