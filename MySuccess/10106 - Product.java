
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			BigInteger p = sc.nextBigInteger();
			BigInteger q = sc.nextBigInteger();
			System.out.println(p.multiply(q));
		}
	}
}