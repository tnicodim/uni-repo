package SI_LAB6;

import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger one = new BigInteger("1");
        BigInteger n = new BigInteger("837210799");
        BigInteger e = new BigInteger("7");
        BigInteger d = new BigInteger("478341751");
        BigInteger k = (((d.multiply(e)).subtract(one)).divide(n)).add(one);
        System.out.println("k = " + k);
        BigInteger pPLUSq = (((n.add(one)).multiply(k)).add(one).subtract(e.multiply(d))).divide(k);
        System.out.println("p+q = " + pPLUSq);
        BigInteger delta = (pPLUSq.pow(2)).subtract(k.multiply(n));
        System.out.println("delta = " + delta);
        BigInteger x1 = (pPLUSq.add(SquareRoot(delta))).divide(new BigInteger("2"));
        BigInteger x2 = (pPLUSq.subtract(SquareRoot(delta))).divide(new BigInteger("2"));
        System.out.println("x1 = " + x1 + "\nx2 = " + x2);
    }
    //recursively searches for the sqr root of a in interval [left, right]
    private static BigInteger NaiveSquareRootSearch(BigInteger a, BigInteger left,
                                                    BigInteger right)
    {
        // fix root as the arithmetic mean of left and right
        BigInteger root = left.add(right).shiftRight(1);
        // if the root is not between [root, root+1],
        //is not an integer and root is our best integer approximation
        if(!((root.pow(2).compareTo(a) == -
                1)&&(root.add(BigInteger.ONE).pow(2).compareTo(a) == 1))){
            if (root.pow(2).compareTo(a) == -1) root = NaiveSquareRootSearch(a, root,
                    right);
            if (root.pow(2).compareTo(a) == 1) root = NaiveSquareRootSearch(a, left,
                    root);
        }
        return root;
    }

    public static BigInteger SquareRoot(BigInteger a)
    {
        return NaiveSquareRootSearch(a, BigInteger.ZERO, a);
    }
}