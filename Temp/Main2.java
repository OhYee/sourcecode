import java.io.*;
import java.util.*;
import java.math.*;

class Point {
    BigInteger x, y;

    public Point(BigInteger _x, BigInteger _y) {
        this.x = _x;
        this.y = _y;
    }
}

class Segment {
    Point a, b;

    public Segment(Point _a, Point _b) {
        this.a = _a;
        this.b = _b;
    }
}

public class Main {
    static Scanner cin;
    static BigInteger zero;
    static BigInteger one;

    public static Point Point_Mi(Point a, Point b) {
        return new Point(a.x.subtract(b.x), a.y.subtract(b.y));
    }

    public static Point Point_Ad(Point a, Point b) {
        return new Point(a.x.add(b.x), a.y.add(b.y));
    }

    static public Point read_point() {
        BigInteger x = cin.nextBigInteger();
        BigInteger y = cin.nextBigInteger();

        return new Point(x, y);
    }

    static BigInteger Dot(Point a, Point b) {
        return a.x.multiply(b.x).add(a.y.multiply(b.y));
    }

    static BigInteger Cross(Point a, Point b) {
        return a.x.multiply(b.y).subtract(a.y.multiply(b.x));
    }

    static int sgn(BigInteger d) {
        return d.signum();
    }

    static int Point_Segment(Point p, Segment L) {
        return sgn(Cross(Point_Mi(L.b, L.a), Point_Mi(p, L.a)));
    }

    static boolean Point_Polygon(Point p, Point polygon[], int numberOfSide) {
        Segment s = new Segment(polygon[numberOfSide - 1], polygon[0]);
        boolean ok = Point_Segment(p, s) >= 0;
        for (int i = 1; i < numberOfSide && ok; ++i) {
            Segment st = new Segment(polygon[i - 1], polygon[i]);
            if (!(Point_Segment(p, st) >= 0))
                ok = false;
        }
        return ok;
    }

    static Double getAngel(Point p) {
        BigDecimal d = new BigDecimal(Dot(new Point(zero, one), p));

        d.divide(Math.sqrt(new BigDecimal(Distance(p, new Point(zero, zero)))));
        return Math.acos(d.doubleValue());
    }

    static BigInteger Distance(Point a, Point b) {
        BigInteger x = a.x.subtract(b.x);
        BigInteger y = a.y.subtract(b.y);
        return add(x.multiply(x), y.multiply(y));
    }

    static BigInteger Point_Segment_Distance(Point p, Segment s) {
        BigInteger two = BigInteger.valueOf(2);
        return Distance(p, new Point(s.a.x.add(s.b.x).divide(two)), new Point(s.a.y.add(s.b.y).divide(two)));
    }

    static boolean calc(Segment s, Point a, Point p) {
        double angle1 = Math.abs(getAngel(Point_Mi(Point_Mi(s.a, p), Point_Mi(s.b, p))));
        double angle2 = Math.abs(getAngel(Point_Mi(Point_Mi(s.a, a), Point_Mi(s.b, a))));
        return sgn(angle1 + angle2 - Math.atan2(0, -1)) >= 0;
    }

    public static void main(String[] args) {
        cin = new Scanner(new BufferedInputStream(System.in));
        zero = BigInteger.valueOf(0);
        one = BigInteger.valueOf(1);

        int T = cin.nextInt();
        for (int kase = 0; kase < T; ++kase) {
            Point p[] = new Point[4];
            for (int i = 0; i < 4; ++i)
                p[i] = read_point();

            boolean Re = Point_Polygon(p[3], p, 3);
            if (!Re) {
                BigInteger dis[] = new BigInteger[3];

                BigInteger Min = zero;
                int pos = -1;

                for (int i = 0; i < 3; ++i) {
                    dis[i] = Point_Segment_Distance(p[3], new Segment(p[i], p[(i + 1) % 3]));

                    if (pos == -1 || Min.subtract(dis[i]).signum() > 0) {
                        Min = dis[i];
                        pos = i;
                    }
                }

                Re = calc(new Segment(p[pos], p[(pos + 1) % 3]), p[(pos - 1 + 3) % 3], p[3]);
            }
            if (Re == true) {
                System.out.println("Rejected");
            } else {
                System.out.println("Accepted");
            }

        }
        cin.close();
    }
}
