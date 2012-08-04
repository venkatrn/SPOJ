import java.util.Scanner;
import java.math.BigInteger;
 class fctrl2 {
  public static void main(String[] args) {
    //System.out.println("Hello, World");
    int N,i,t;
    Scanner in = new Scanner(System.in);
    t = in.nextInt();
    while(t--!=0)
    {
    BigInteger fact = BigInteger.valueOf(1);
    N = in.nextInt();
    for(i=2;i<=N;i++)
     fact = fact.multiply(BigInteger.valueOf(i));

    System.out.println(fact);
    }
    in.close();
  }
}
