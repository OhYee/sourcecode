import java.util.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

// 6093
public class Main {
    static final long MOD = 998244353;
    static final int maxd = 1600;
    static final int maxn = 3005;
    static long[] f;
    static  [] MAX;

    public static void main(String[] args) {
        //Scanner cin = new Scanner(new BufferedInputStream(System.in));
        Scanner cin = new Scanner(System.in);
        init();
        
        int T = cin.nextInt();
        for (int i = 0; i < T; i++) {
            BigInteger L = cin.nextBigInteger();
            BigInteger R = cin.nextBigInteger();

            //System.out.println(L);
            //System.out.println(R);
            Solve(L, R);
        }
        cin.close();
    }

    public static void init() {
        f = new long[maxn];
        for (int i = 2; i < maxn; ++i)
            f[i] = 0;
        f[0] = 1;
        f[1] = 1;

        MAX = new BigInteger[maxd];
        for (int i = 2; i < maxd; ++i)
            MAX[i] = getMax(i);
    }

    public static void Solve(BigInteger L, BigInteger R) {
        long ans = (MOD + calc(R) - calc(L.subtract(BigInteger.valueOf(1)))) % MOD;
        System.out.println(ans);
    }

    public static long calc(BigInteger num) {
        long ans = 0;

        /*
        for (int d = 2;; ++d) {
            BigInteger MaxInD = getMax(d);
            if (num.compareTo(MaxInD) > 0) {
                // num > MaxInD
                ans = (ans + getCount(d)) % MOD;
                System.out.printf("Radix %d all can choose, ans = %s now.\n", d, ans);
            } else {
                ans = (ans + getCountLessThan(num, d)) % MOD;
                System.out.printf("Radix %d not all can choose, ans = %s now.\n", d, ans);
                break;
            }
        }*/

        int d = getD(num, 2, maxd);
        for (int i = 2; i <= d; i++) {
            ans = (ans + getCount(d)) % MOD;
        }
        ans = (ans + getCountLessThan(num, d + 1)) % MOD;

        //System.out.printf("calc(%s) = %s\n", num, ans);
        return ans % MOD;
    }

    static int getD(BigInteger num, int l, int r) {
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            //System.out.printf("%d %d %d\n",l, r,mid);

            if (num.compareTo(MAX[mid]) >= 0) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        //System.out.printf("getD = %d\n", ans);
        return ans;
    }

    public static BigInteger getMax(int d) {
        /*
        BigInteger ans = BigInteger.valueOf(0);
        BigInteger D = BigInteger.valueOf(1);
        
        for (int i = 0; i < d; ++i) {
            // sum { d^i * i }
            ans = ans.add(D.multiply(BigInteger.valueOf(i)));
            D = D.multiply(BigInteger.valueOf(d));
        }*/

        //(n-n^n)/(n-1)^2+n^n
        BigInteger N = BigInteger.valueOf(d);
        MAX[d] = N.subtract(N.pow(d)).divide(N.subtract(BigInteger.valueOf(1)).pow(2)).add(N.pow(d));
        //System.out.printf("getMax(%d) = %s\n", d, ans);
        return MAX[d];

    }

    public static BigInteger getMin(int d) {
        BigInteger ans = BigInteger.valueOf(d);
        ans = ans.pow(d - 1);

        for (int i = 2; i < d; ++i) {
            ans = ans.add(BigInteger.valueOf(d).pow(i).multiply(BigInteger.valueOf(d - 1 - i)));
        }
        //System.out.printf("getMin(%d) = %s\n", d, ans);
        return ans;
    }

    public static long getCount(int d) {
        // (MOD + n! -(n-1)!) % MOD
        return (factorial(d) + MOD - factorial(d - 1)) % MOD;
    }

    public static long getCountLessThan(BigInteger num, int d) {
        if (num.compareTo(getMin(d)) < 0)
            return 0;

        List<Integer> list = changeRadix(num, d);
        boolean[] flag = new boolean[maxd];

        //初始化为false
        java.util.Arrays.fill(flag, false);

        int pos = -1;

        for (int i = list.size() - 1; i >= 0; --i) {
            Integer t = list.get(i);

            if (pos == -1) {
                if (flag[t] == true) {
                    pos = findMin(d, list.get(i), flag);
                    while (pos == -1) {
                        flag[i] = false;
                        ++i;
                        pos = findMin(d, list.get(i), flag);
                    }
                    list.set(i, pos);
                    flag[pos] = true;
                    pos = d - 1;
                } else {
                    flag[t] = true;
                }
            } else {
                while (flag[pos] == true) {
                    --pos;
                }
                list.set(i, pos);
                flag[pos] = true;
            }
        }

        //System.out.printf("%s no more than in radix %d is ", num, d);
        for (int i = list.size() - 1; i >= 0; --i) {
            //System.out.print(list.get(i));
        }
        //System.out.print("\n");

        return findKTPosition(list) % MOD;
    }

    public static int findMin(int d, int Max, boolean[] flag) {
        for (; Max >= 0; --Max)
            if (flag[Max] == false)
                break;
        return Max;
    }

    public static long factorial(int d) {
        if (f[d] == 0) {
            f[d] = (factorial(d - 1) * d) % MOD;
        }

        //System.out.printf("f[%d]=%d\n", d, f[d]);
        return f[d];
    }

    public static List changeRadix(BigInteger num, int d) {
        //System.out.printf("%s in radix %d is ", num, d);

        BigInteger D = BigInteger.valueOf(d);
        List list = new ArrayList<Integer>();

        while (!num.equals(BigInteger.valueOf(0))) {
            list.add(num.mod(D).intValue());
            num = num.divide(D);
        }

        // 倒序
        //Collections.reverse(list);

        for (int i = list.size() - 1; i >= 0; --i) {
            //System.out.print(list.get(i));
        }
        //System.out.print("\n");

        return list;
    }

    public static long findKTPosition(List<Integer> list) {
        boolean[] flag = new boolean[maxd];
        java.util.Arrays.fill(flag, false);
        long ans = 1;
        for (int i = list.size() - 1; i >= 0; --i) {
            int cnt = 0;
            for (int j = 0; j < list.get(i); ++j) {
                if (flag[j] == false)
                    ++cnt;
            }
            flag[list.get(i)] = true;
            //System.out.printf("KT: %d * f[%d]\n", cnt, i);
            ans = (ans + (factorial(i) * cnt) % MOD) % MOD;
        }
        //System.out.print(ans);
        ans = (MOD + ans - factorial(list.size() - 1)) % MOD;
        //System.out.printf(" %s\n", ans);
        return ans % MOD;
    }
}
