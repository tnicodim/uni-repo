/* Să se insereze într-o anumită poziție a unui șir de caractere, un alt șir. Datele vor fi
preluate de la tastatură sau din fișier. Să se șteargă o porțiune a unui șir de caractere care
începe dintr-o anumită poziție și are un anumit număr de caractere. Se recomandă utilizarea
clasei StringBuilder */

package ex3lab;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(System.in);
        StringBuilder str = new StringBuilder("t/university-repo");
        System.out.println(str);
        System.out.println(str.insert(1,getSubstring()));
        System.out.println(str.delete(12,19));
    }

    public static String getSubstring() throws FileNotFoundException {
        String fileName = "src/ex3lab/substrings.txt";
        Scanner input = new Scanner(new File(fileName));
        return input.nextLine();
    }
}
