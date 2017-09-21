import java.io.*;
import java.util.*;
import java.math.*;

class Point {
    BigDecimal x, y;

    public Point() {
    }

    public Point(BigDecimal _x, BigDecimal _y) {
        this.x = _x;
        this.y = _y;
    }
}

class Segment {
    Point a, b;

    public Segment() {
    }

    public Segment(Point _a, Point _b) {
        this.a = _a;
        this.b = _b;
    }
}

public class Main {
    static Scanner cin;
    static BigDecimal two;
    static BigDecimal f1;

    static Point read_point() {
        BigDecimal x = cin.nextBigDecimal();
        BigDecimal y = cin.nextBigDecimal();
        return new Point(x, y);
    }

    static Point pa(Point a, Point b) {
        return new Point(a.x.add(b.x), a.y.add(b.y));
    }

    static Point ps(Point a, Point b) {
        return new Point(a.x.subtract(b.x), a.y.subtract(b.y));
    }

    static Point getPoint(Point a, Point b) {
        Point p = pa(a, b);
        p.x = p.x.divide(two);
        p.y = p.y.divide(two);
        return p;
    }

    static Point fa(Point p) {
        return new Point(p.y.multiply(f1), p.x);
    }

    static Segment getSegment(Segment s) {
        Point mp = getPoint(s.a, s.b);
        Point vec = fa(ps(s.b, s.a));
        return new Segment(mp, pa(mp, vec));
    }

    static Point Seg_Seg(Segment L1, Segment L2, BigDecimal[] f) {
        BigDecimal a = L1.b.x.subtract(L1.a.x);
        BigDecimal b = L2.b.x.subtract(L2.a.x);
        BigDecimal c = L1.b.y.subtract(L1.a.y);
        BigDecimal d = L2.b.y.subtract(L2.a.y);
        f[0] = a.multiply(d).subtract(b.multiply(c));
        BigDecimal g = L2.b.x.subtract(L1.a.x);
        BigDecimal h = L2.b.y.subtract(L1.a.y);
        BigDecimal t = d.multiply(g).subtract(b.multiply(h));
        Point p = new Point(L1.a.x.add(t.multiply(a)), L1.a.y.add(t.multiply(c)));
        return p;
    }

    static BigDecimal distance(Point a, Point b) {
        Point p = ps(a, b);
        return p.x.multiply(p.x).add(p.y.multiply(p.y));
    }

    static void sprint(Segment s) {
        pprint(s.a, false);
        pprint(s.b, false);
        System.out.print("\n");
    }

    static void pprint(Point p, boolean f) {
        System.out.print("(");
        System.out.print(p.x);
        System.out.print(" ");
        System.out.print(p.y);
        System.out.print(")");
        if (f == true)
            System.out.print("\n");
    }

    public static void main(String[] args) {
        cin = new Scanner(new BufferedInputStream(System.in));
        two = BigDecimal.valueOf(2);
        f1 = BigDecimal.valueOf(-1);

        Point p[] = new Point[4];

        int T = cin.nextInt();
        for (int kase = 0; kase < T; ++kase) {
            for (int i = 0; i < 4; ++i) {
                p[i] = read_point();
            }
            Segment a = getSegment(new Segment(p[0], p[1]));
            Segment b = getSegment(new Segment(p[1], p[2]));

            BigDecimal[] f = { two };
            Point o = Seg_Seg(a, b, f);

            p[0].x = p[0].x.multiply(f[0]);
            p[0].y = p[0].y.multiply(f[0]);
            p[3].x = p[3].x.multiply(f[0]);
            p[3].y = p[3].y.multiply(f[0]);

            BigDecimal r = distance(p[0], o);
            BigDecimal dis = distance(p[3], o);

            //sprint(a);
            //sprint(b);
            // System.out.println(r);
            // pprint(o, true);
            // System.out.println(dis);

            if (dis.subtract(r).signum() > 0) {
                System.out.println("Accepted");
            } else {
                System.out.println("Rejected");
            }
        }
        cin.close();
    }
}
