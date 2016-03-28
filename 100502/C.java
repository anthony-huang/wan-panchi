import java.util.*;
import java.io.*;
import java.math.BigInteger;

class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		BigInteger cat[] = new BigInteger[n + 1];
		cat[0] = BigInteger.ONE;
		BigInteger ans = BigInteger.ZERO;
		int x = 1, y = 2;
		for (int i = 1; i <= n; ++i) {
			cat[i] = cat[i - 1].multiply(BigInteger.valueOf(x * y)).divide(BigInteger.valueOf(i * i));
			x += 2; y += 2;
		}
		for (int i = 1; i <= n; ++i) {
			cat[i] = cat[i].divide(BigInteger.valueOf(i + 1));
		}
		for (int k = 0; k <= n; ++k) {
			ans = ans.add(cat[k].multiply(cat[n - k]));
		}
		System.out.println(ans);
	}
}