//package uva_10183;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	static final int MAX = 501;
	static BigInteger fac[] = new BigInteger[MAX]; 
	
	static int searchA(BigInteger e){
		for(int i = fac.length - 1;i>=0;i--){
			if(fac[i].compareTo(e) == 0 )
				return i;
			if(fac[i].compareTo(e) == -1)
				return i+1;
		}
		return -1;	
	}
	static int SearchB(BigInteger e){
		for(int i=0;i<fac.length;i++){
			if(fac[i].compareTo(e) == 0)
				return i;
			if(fac[i].compareTo(e) == 1)
				return i-1;
		}
		return -1;
	}
	
	public static void main(String[] args) {
		fac[0] = BigInteger.ONE ;
		fac[1] = BigInteger.valueOf(2);
		for(int i=2;i<MAX;i++){
			fac[i] = fac[i-1].add(fac[i-2]);
		}
		Scanner in = new Scanner(System.in);
		while(true){
			String a,b;
			a = in.next();
			b = in.next();
			if(a.equals("0") && b.equals("0")) break;
			if(a.equals("0")) a = "1";
			int A = searchA(new BigInteger(a));
			int B = SearchB(new BigInteger(b));
			System.out.println(B-A+1);
		}
	}
}
