import java.io.*;
import java.util.*;
import java.math.*;

public class test {
    static Scanner cin;

    public static void main(String[] args) {
        cin = new Scanner(new BufferedInputStream(System.in));
        while(cin.hasNext()){
        BigInteger a = cin.nextBigInteger();
        System.out.println(a.signum());
        }
        cin.close();
    }
}