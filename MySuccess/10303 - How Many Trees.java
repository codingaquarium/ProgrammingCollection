//package uva_10303;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int input;
		BigInteger fact[] = new BigInteger[2001];
		BigInteger ans[] = new BigInteger[1001];
		fact[0] = fact[1] = BigInteger.ONE;
		for(int i=2;i<2001;i++){
			fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
		}
		for(int i=1;i<=1000;i++){
			ans[i] = fact[2*i].divide(fact[i+1].multiply(fact[i]));
		}
		while(in.hasNext()){
			input = in.nextInt();
			if(input==0) break;
			System.out.println(ans[input].toString());
		}
	}
}
