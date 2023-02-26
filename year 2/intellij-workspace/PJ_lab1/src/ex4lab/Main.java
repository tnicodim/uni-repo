/* Să se determine cmmdc a două numere naturale, a căror valoare maximă este 30. Numerele
vor fi generate aleatoriu cu ajutorul unui obiect de tip Random și metodei nextInt(); */

package ex4lab;

import java.util.Random;

import static java.lang.Math.abs;

public class Main {
    public static void main(String[] args) {
        Random random = new Random();
        int x = random.nextInt(30);
        int y = random.nextInt(30);
        System.out.print("GCD of " + x + " and " + y + " is: ");
        while (x != 0) {
            int t = x;
            x = y % x;
            y = t;
        }
        System.out.print(abs(y));
    }
}
