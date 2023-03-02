/* Fișierul judete_in.txt, conține lista neordonată a județelor din țară. Să se încarce
datele din fișier într-un tablou de String-uri și să se ordoneze acest tablou cu ajutorul metodei
sort() din clasa Arrays. Să se returneze pe ce poziție se află în vectorul ordonat un județ
introdus de la tastatură. Se va utiliza metoda de căutare binară din clasa Arrays. */

package ex1lab;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    private static final String[] judeteArray = new String[11];

    public static void main(String[] args) throws FileNotFoundException {
        loadJudete();
        System.out.println("Unordered: " + Arrays.toString(judeteArray));
        Arrays.sort(judeteArray);
        System.out.println("Ordered: " + Arrays.toString(judeteArray));
        Scanner scanner = new Scanner(System.in);
        System.out.print("Search: ");
        String searchedString = scanner.next();
        int search = searchJudet(searchedString);
        if (search == -1)
            System.out.println("Judet not found!");
        else
            System.out.println(searchedString + " is at position " + (search + 1));
    }

    public static int searchJudet(String judetSearched) {
        int l = 0, r = judeteArray.length - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int srch = judetSearched.compareTo(judeteArray[m]);
            if (srch == 0)
                return m;
            if (srch > 0)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

    public static void loadJudete() throws FileNotFoundException {
        String fileName = "src/ex1lab/judete_in.txt";
        Scanner input = new Scanner(new File(fileName));
        int k = 0;
        while (input.hasNextLine()) {
            judeteArray[k++] = input.next();
        }
    }
}
