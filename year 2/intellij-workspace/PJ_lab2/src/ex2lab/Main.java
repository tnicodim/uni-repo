/* Fișierul cantec_in.txt conține versurile unui cântec la alegere. Să se scrie un
program care creează fișierul cantec_out.txt, care conține versurile cântecului original dar în
plus în dreptul fiecărui rând sunt afișate numărul de cuvinte de pe rând şi numărul de vocale
de pe fiecare rând. În dreptul rândurilor care se încheie cu o grupare de litere aleasă se va
pune o steluță (*). Rândurile pentru care un număr generat aleator este mai mic decât 0.1 vor
fi scrise cu majuscule (se vor genera aleator numere între 0 şi 1).
Se va defini o clasă Vers, care are o variabilă membră privată un șir de caractere
reprezentând versul și se va dezvolta câte un operator pentru fiecare cerință de mai sus (o
metodă care returnează numărul de cuvinte, o metodă care returnează numărul de vocale, etc).
Se va crea un vector de obiecte de tip Vers care va conține informația preluată din fișierul de
intrare. */

package ex2lab;

import java.io.*;
import java.util.Scanner;

public class Main {

    private static final Vers[] arrayLyrics = new Vers[62];

    public static void main(String[] args) throws IOException {
        loadLyrics();
        writeToFile();
    }

    public static void loadLyrics() throws FileNotFoundException {
        String fileName = "src/ex2lab/cantec_in.txt";
        Scanner input = new Scanner(new File(fileName));
        int k = 0;
        while (input.hasNextLine()) {
            arrayLyrics[k++] = new Vers(input.nextLine());
        }
    }

    public static void writeToFile() throws IOException {
        String fileName = "src/ex2lab/cantec_out.txt";
        FileWriter fileWriter = new FileWriter(fileName);
        PrintWriter printWriter = new PrintWriter(fileWriter);
        for (Vers lyric : arrayLyrics){
            printWriter.println(lyric.randomAllCaps() + lyric.getAsterisk("lights") + lyric.getWords() + " " + lyric.getVowels());
        }
        printWriter.close();
    }
}

