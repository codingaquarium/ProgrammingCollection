//package UVa_485;

import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		BigInteger next[] = new BigInteger[100000];
		BigInteger curr[] = new BigInteger[100000];
		BigInteger end = BigInteger.TEN;
		for(int i=2;i<=60;i++)
				end = end.multiply(BigInteger.TEN);
		curr[0] = curr[1] = BigInteger.ONE;
		System.out.println("1\n1 1");
		int line = 1;
		Boolean stop = true;
		for(;stop;){
			next[0] = BigInteger.ONE;
			for(int i=1;i<=line;i++){
				next[i]  = curr[i].add(curr[i-1]);
				if(next[i].compareTo(end) >= 0) stop = false;
			}
			next[++line] = BigInteger.ONE;
			for(int i=0;i<line;i++){
				System.out.print(next[i] + " ");
				curr[i] = next[i];
			}
			curr[line] = BigInteger.ONE;
			System.out.println(1);
		}		
	}
}
