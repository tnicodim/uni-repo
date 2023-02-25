/*  Se cere să se scrie un program Java care să calculeze şi să afişeze perimetru şi aria unui
dreptunghi. Valorile pentru lungime şi lățime se citesc de la tastatura. Sa se adauge un break
point pe prima linie care citește valoarea unei laturi si din acel punct să se ruleze programul
linie cu linie urmărind valorile variabilelor în memorie. */

package ex1lab;

import java.util.Scanner;

public class MainApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("latime = ");
        int lat = scanner.nextInt();
        System.out.print("lungime = ");
        int l = scanner.nextInt();
        Dreptunghi d = new Dreptunghi(lat,l);
        System.out.println("Surface area: " + d.getSurface() + "\nPerimeter: " + d.getPerimeter());
    }
}

