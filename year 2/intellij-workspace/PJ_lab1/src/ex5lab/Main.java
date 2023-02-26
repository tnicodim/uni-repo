/* Să se scrie un program care generează aleatoriu un număr întreg cuprins între 0 și 20.
Programul va determina dacă numărul aparține șirului lui Fibonacci. */

package ex5lab;

import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random random = new Random();
        int x = random.nextInt(20);
        if (isFibonacci(x))
            System.out.println(x + " is part of the fibonacci sequence");
        else
            System.out.println(x + " is not part of the fibonacci sequence");
    }

    public static boolean isFibonacci(int x) {
        int[] fibonacci = new int[]{0, 1, 1, 2, 3, 5, 8, 13};
        for (int fib : fibonacci)
            if (x == fib)
                return true;
        return false;
    }
}
