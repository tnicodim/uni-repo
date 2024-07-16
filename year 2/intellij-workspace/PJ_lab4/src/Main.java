/* O firmă comercializează echipamente electronice. Fiecare echipament este înregistrat cu o
denumire, un număr de inventar nr_inv, are un preţ pret şi este plasat într-o anumită zonă din
magazie zona_mag. Orice echipament poate fi într-una din situaţiile:
• achiziţionat
• expus
• vândut

Firma comercializează următoarele tipuri de echipamente: imprimante, copiatoare şi
sisteme de calcul.
Imprimantele sunt caracterizate numărul de pagini scrise pe minut ppm, rezoluţie
(număr de puncte per inch dpi) şi număr de pagini/cartuş p_car şi modul de tipărire (color sau
alb negru).

Copiatoarele sunt caracterizate de numărul de pagini/toner p_ton şi formatul de
copiere (A3 sau A4).
Sistemele de calcul au un monitor de un anumit tip tip_mon, un procesor de o anumită
viteză vit_proc, o capacitate a HDD c_hdd şi li se poate instala unul din sistemele de operare
Windows sau Linux

Să se realizeze ierarhia de clase corespunzătoare modelului prezentat, utilizând tipul
enumerare pentru câmpurile potrivite; Să se documenteze clasele şi metodele şi să se genereze
documentația proiectului.

Să se creeze O SINGURĂ COLECȚIE DE OBIECTE DE TIP LIST în care să fie
preluate datele din fişierul de intrare electronice.txt. Se va dezvolta un meniu care va oferi
următoarele facilităţi:
• Afişarea tuturor echipamentelor
• Afişarea imprimantelor
• Afişarea copiatoarelor
• Afişarea sistemelor de calcul
• Modificarea stării în care se află un echipament
• Setarea unui anumit mod de scriere pentru o imprimantă
• Setarea unui format de copiere pentru copiatoare
• Instalarea unui anumit sistem de operare pe un sistem de calcul
• Afişarea echipamentelor vândute
• Să se realizeze două metode statice pentru serializarea / deserializarea colecției de
obiecte în fișierul echip.bin */

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.lang.System.exit;

public class Main {

    public static List<Item> itemList = new ArrayList<>();

    public static void main(String[] args) throws FileNotFoundException {
        readFile();
        scrie(itemList,"src/echip.bin");
        List<Item> binOutput;
        binOutput = (List<Item>) citeste("src/echip.bin");
        for (Item item : binOutput) {
            System.out.println(item.toString());
        }
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("""

                    1. Display all items
                    2. Display printers
                    3. Display copy machines
                    4. Display calculation systems
                    5. Modify the status of an item
                    6. Modify printing type for printer
                    7. Modify format for copy machine
                    8. Install OS on a calculation system
                    9. Show sold items
                    0. Exit
                    Option:\s""");
            int x = scanner.nextInt();
            switch (x) {
                case 1:
                    for (Item item : itemList) {
                        System.out.println(item.toString());
                    }
                    break;
                case 2:
                    for (Item item : itemList) {
                        if (item instanceof Printer) System.out.println(item);
                    }
                    break;
                case 3:
                    for (Item item : itemList) {
                        if (item instanceof CopyMachine) System.out.println(item);
                    }
                    break;
                case 4:
                    for (Item item : itemList) {
                        if (item instanceof CalcSystem) System.out.println(item);
                    }
                    break;
                case 5:
                    int index = 0;
                    for (Item item : itemList) {
                        System.out.println(index + ". " + item);
                        index++;
                    }
                    System.out.print("Choose an item: ");
                    x = scanner.nextInt();
                    System.out.print("Status(BOUGHT/ON_SALE/SOLD): ");
                    itemList.get(x).setStatus(Item.Status.valueOf(scanner.next().toUpperCase()));
                    break;
                case 6:
                    index = 0;
                    for (Item item : itemList) {
                        if (item instanceof Printer) {
                            System.out.println(index + ". " + item);
                        }
                        index++;
                    }
                    System.out.print("Choose a printer: ");
                    x = scanner.nextInt();
                    System.out.print("Print Type(COLOR/BLACK_AND_WHITE): ");
                    ((Printer) itemList.get(x)).setPrintType(Printer.PrintType.valueOf(scanner.next().toUpperCase()));
                    break;
                case 7:
                    index = 0;
                    for (Item item : itemList) {
                        if (item instanceof CopyMachine) {
                            System.out.println(index + ". " + item);
                        }
                        index++;
                    }
                    System.out.print("Choose a copy machine: ");
                    x = scanner.nextInt();
                    System.out.print("Format(A3/A4): ");
                    ((CopyMachine) itemList.get(x)).setFormat(CopyMachine.Format.valueOf(scanner.next().toUpperCase()));
                    break;
                case 8:
                    index = 0;
                    for (Item item : itemList) {
                        if (item instanceof CalcSystem) {
                            System.out.println(index + ". " + item);
                        }
                        index++;
                    }
                    System.out.print("Choose a calculation system: ");
                    x = scanner.nextInt();
                    System.out.print("Operation System(WINDOWS/LINUX): ");
                    ((CalcSystem) itemList.get(x)).setOs(CalcSystem.OperationSystem.valueOf(scanner.next().toUpperCase()));
                    break;
                case 9:
                    for (Item item : itemList) {
                        if (item.getStatus().toString().equals("SOLD")) System.out.println(item);
                    }
                    break;
                case 0:
                    exit(0);
                default:
                    System.out.println("Invalid option! Try again!");
                    break;
            }
        }
    }

    static void readFile() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("src/items.txt"));
        scanner.useDelimiter("[\\n\\r]");
        while (scanner.hasNextLine()) {
            String[] lineValues = scanner.nextLine().split(";");
            switch (lineValues[5]) {
                case "Printer":
                    itemList.add(new Printer(lineValues[0], Integer.parseInt(lineValues[1]), Float.parseFloat(lineValues[2]), lineValues[3], Item.Status.valueOf(lineValues[4].toUpperCase()), Integer.parseInt(lineValues[6]), lineValues[7], Integer.parseInt(lineValues[8]), Printer.PrintType.valueOf(lineValues[9])));
                    break;
                case "CopyMachine":
                    itemList.add(new CopyMachine(lineValues[0], Integer.parseInt(lineValues[1]), Float.parseFloat(lineValues[2]), lineValues[3], Item.Status.valueOf(lineValues[4].toUpperCase()), Integer.parseInt(lineValues[6]), CopyMachine.Format.valueOf(lineValues[7])));
                    break;
                case "CalcSystem":
                    itemList.add(new CalcSystem(lineValues[0], Integer.parseInt(lineValues[1]), Float.parseFloat(lineValues[2]), lineValues[3], Item.Status.valueOf(lineValues[4].toUpperCase()), lineValues[6], Float.parseFloat(lineValues[7]), Integer.parseInt(lineValues[8]), CalcSystem.OperationSystem.valueOf(lineValues[9].toUpperCase())));
                    break;
            }
        }
        scanner.close();
    }

    static void scrie(Object o, String fis) {
        try {
            FileOutputStream f = new FileOutputStream(fis);
            ObjectOutputStream oos = new ObjectOutputStream(f);
            oos.writeObject(o);
            oos.close();
            f.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static Object citeste(String fis) {
        try {
            FileInputStream f = new FileInputStream(fis);
            ObjectInputStream ois = new ObjectInputStream(f);
            Object o=ois.readObject();
            ois.close();
            f.close();
            return o;
        }
        catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        return null;
    }
}
