import java.math.BigInteger;
import java.util.Scanner;
class LTIME20C {
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		while(test-- > 0) { 
			BigInteger x = sc.nextBigInteger();
			BigInteger res = BigInteger.ONE;
			
			String rem = sc.nextLine();
			rem = rem.replace('*', ' ');
			Scanner uc = new Scanner(rem);			
			while(uc.hasNext()){
				BigInteger a,b,tmp;				
				a = uc.nextBigInteger();
				b = uc.nextBigInteger();
				res = res.multiply(a.modPow(b, x));
				res = res.mod(x);
			}
			System.out.println(res);
			//BigInteger x = sc.nextBigInteger(), m = sc.nextBigInteger(), n = sc.nextBigInteger();
			//System.out.println(geometricSum(x, m, n));
		}
	}	
}
