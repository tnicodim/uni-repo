/*Să se scrie un program care citește un set de numerele din fișierul de intrare in.txt, care
conține câte un număr pe un rând, având valorile din figura 18. Programul va determină suma
lor, media aritmetică, valoarea minimă, valoarea maximă, va afișa aceste valori pe ecran și le
va scrie în fișierul de ieșire out.txt. Media aritmetică va fi afișată ca un număr real.
*/

package ex2lab;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static ArrayList<Integer> arrInt = new ArrayList<>();
    public static int maxValue, minValue, sum;
    public static float medianValue;
    public static void main(String[] args) throws IOException {
        readNumbers();
        maxValue = arrInt.get(0);
        minValue = arrInt.get(0);
        sum = 0;
        for (Integer num : arrInt) {
            sum += num;
            if (num > maxValue){
                maxValue = num;
            }
            if (num < minValue){
                minValue = num;
            }
        }
        medianValue = (float)sum / arrInt.size();
        System.out.println("Min Value = " + minValue + "\nMax Value = " +
                maxValue + "\nSum = " + sum + "\nMedian Value = " + medianValue);
        writeToFile();
    }

    public static void writeToFile() throws IOException {
        String fileName = "src/ex2lab/out.txt";
        FileWriter fileWriter = new FileWriter(fileName);
        PrintWriter printWriter = new PrintWriter(fileWriter);
        printWriter.println(minValue);
        printWriter.println(maxValue);
        printWriter.println(sum);
        printWriter.println(medianValue);
        printWriter.close();
    }
    public static void readNumbers() throws FileNotFoundException {
        String fileName = "src/ex2lab/in.txt";
        Scanner input=new Scanner(new File(fileName));
        while(input.hasNextLine()){
            int x = input.nextInt();
            arrInt.add(x);
        }
    }
}
