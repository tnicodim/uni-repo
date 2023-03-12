/*  Să se scrie un program care citește din fișierul produse.csv informații referitoare la
produsele dintr-un magazin. Pe fiecare linie se află: denumirea produsului, preţul (număr real)
cantitatea (număr întreg), data expirării (LocalDate). Cele patru elemente sunt separate prin
caracterul "," (zahar, 1.5, 50, 2024-02-25). Pentru fiecare rând citit se va crea un obiect de tip
Produs care se va adăuga unei colecții de obiecte de tip List. Se va defini o clasă Produs care
va conține: variabile membre private corespunzătoare celor trei elemente care descriu un produs,
cel puţin un constructor, gettere si settere în funcție de necesități şi redefinirea metodei toString()
din clasa Object, metodă care va fi utilizată pentru afișarea produselor.
Să se realizeze un program care va dispune de un meniu și va implementa următoarele
cerințe:
a) afișarea tuturor produselor din colecția List
b) afișarea produselor expirate
c) vânzarea unui produs, care se poate realiza doar dacă există suficientă cantitate pe stoc.
Daca produsul ajunge la cantitate zero, se elimina din listă. În clasa Produs se va declara
o variabilă statica încasări care se va actualiza la fiecare vânzare a unui produs, luând în
considerare prețul produsului vândut şi cantitatea vândută .
d) afișarea produselor cu prețul minim (pot fi mai multe cu același preț)
e) salvarea produselor care au o cantitate mai mică decât o valoare citită de la tastatură
într-un fișier de ieșire.
*/

package ex2lab;

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

import static ex2lab.Product.sales;
import static java.lang.System.exit;

public class Main {
    public static ArrayList<Product> productList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        readCSV();
        while (true) {
            System.out.println("1. Display all products");
            System.out.println("2. Display expired products");
            System.out.println("3. Sell products");
            System.out.println("4. Display cheapest products");
            System.out.println("5. Save products that need restocking in a file");
            System.out.println("6. Total amount sold");
            System.out.println("0. Exit");
            System.out.print("Choose an option: ");
            Scanner scanner = new Scanner(System.in);
            switch (scanner.nextInt()) {
                case 1 -> {
                    for (Product product : productList) {
                        System.out.println(product);
                    }
                }
                case 2 -> {
                    for (Product product : productList) {
                        if (product.isExpired())
                            System.out.println(product);
                    }
                }
                case 3 -> {
                    System.out.println("Which product would you like to sell?");
                    String productToSell = scanner.next();
                    System.out.println("Quantity: ");
                    int quantityToSell = scanner.nextInt();
                    int flag = 0, idx = -1, rmv = 0;
                    for (Product product : productList) {
                        idx++;
                        if (product.getName().equals(productToSell) && product.getStock() >= quantityToSell) {
                            product.sell(quantityToSell);
                            System.out.println("Successfully sold!");
                            flag++;
                            rmv = idx;

                        }
                    }
                    if (productList.get(rmv).getStock() == 0)
                        productList.remove(rmv);
                    if (flag != 1)
                        System.out.println("Error selling the product! Check the name or quantity to be sold!");
                }
                case 4 -> {
                    ArrayList<Product> cheapList = new ArrayList<>();
                    float min = productList.get(0).getPrice();
                    for (Product product : productList) {
                        if (product.getPrice() < min) {
                            min = product.getPrice();
                            cheapList.clear();
                            cheapList.add(product);
                        } else if (product.getPrice() == min)
                            cheapList.add(product);
                    }
                    for (Product product : cheapList) {
                        System.out.println(product);
                    }
                }
                case 5 -> {
                    System.out.print("Minimum stock: ");
                    int stockMin = scanner.nextInt();
                    System.out.println("Products that need restocking: ");
                    PrintWriter printWriter = new PrintWriter(new FileWriter("src/ex2lab/restock.txt"));
                    for (Product product : productList) {
                        if (product.getStock() <= stockMin) {
                            System.out.println(product);
                            printWriter.println(product.getName() + " " + product.getPrice() + "$ " + product.getStock());
                        }
                    }
                    printWriter.close();
                }
                case 6 -> System.out.println("Total amount sold: " + sales + "$");
                case 0 -> exit(0);
                default -> System.out.println("Error! Invalid choice");
            }
        }
    }

    public static void readCSV() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("src/ex2lab/products.csv"));
        scanner.useDelimiter(",|\\r\\n");
        while (scanner.hasNextLine()) {
            productList.add(new Product(scanner.next(), scanner.nextFloat(), scanner.nextInt(), scanner.next()));
        }
        scanner.close();
    }
}

