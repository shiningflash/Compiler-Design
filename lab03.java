import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
	public static void main (String[] args) throws java.lang.Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String reg[] = new String[n];
		for (int i = 0; i < n; i++) reg[i] = sc.next();
		int m = sc.nextInt();
		for (int i = 0; i < m; i++) {
			boolean flag = false;
			String s = sc.next();
			for (int j = 0; j < n; j++) {
				String ptr = reg[j];
				Pattern ptrr = Pattern.compile(ptr);
				Matcher mtr = ptrr.matcher(s);
				if (mtr.find()) {
					System.out.println("YES, " + (j+1));
					flag = true;
					break;
				}
			}
			if (!flag) System.out.println("NO");
		}
	}
}
