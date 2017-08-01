import java.util.*;
import java.io.*;
import java.math.*;

public class a {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Integer n;

        BigDecimal x, y, z;
        while (in.hasNext()) {
            n = in.nextInt();

            if (n == 0) {
                System.out.println(0);
                continue;
            }
            BigInteger dp_1 = BigInteger.valueOf(3);
            BigInteger dp_2 = BigInteger.valueOf(1);
            BigInteger dp = BigInteger.valueOf(3);

            for (int i = 1; i < n; i++) {
                dp = dp_1.multiply(BigInteger.valueOf(4)).subtract(dp_2);

                dp_2 = dp_1;
                dp_1 = dp;
            }
            System.out.println(dp);
        }
    }
}
