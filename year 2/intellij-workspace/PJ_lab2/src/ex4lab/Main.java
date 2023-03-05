/*  Să se realizeze un program care citește numele si CNP-ul pe care îl au n persoane.
Valoarea lui n se citește de la tastatură. Programul va afișa informațiile introduse și în plus
pentru fiecare persoana va afișa vârsta. Cât timp un CNP-ul este introdus greșit programul va
cere reintroducerea acestuia. Pentru simplitate se consideră că CNP-ul este valid dacă
îndeplinește următoarele condiții:
• Are 13 caractere
• Toate caracterele sunt cifre
• Prima cifră are una din valorile 1, 2, 5, 6
• Cifra de control a CNP-ului are o valoare validă.
Detalii legate de semnificația cifrelor din codul numeric personal şi de modul de calcul al
cifrei de control se găsesc pe link-ul:
https://www.scientia.ro/stiinta-la-minut/128-cultura-economie/459-cnp-codulnumeric-personal.html
Se va crea clasa Persoana cu variabile membre private nume (String) şi cnp (String).
Clasa va avea constructor cu parametri, gettere si settere în funcție de necesități şi metoda
getVarsta() care va calcula şi va returna vârsta persoanei extrăgând data nașterii din CNP şi
citind din sistem data curentă. Se va utiliza clasa LocalDate. Se va crea un vector în care se
vor adăuga obiectele de tip Persoana. Fiecare element din vectorul va fi afișat pe un rând în
formatul nume, CNP, varsta. */

package ex4lab;

import java.util.Scanner;

import static ex4lab.Person.isValid;

public class Main {
    public static Person[] personList;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in).useDelimiter("\n");
        System.out.print("Number of entries: ");
        int arraySize = scanner.nextInt();
        personList = new Person[arraySize];
        for (int i = 0; i < arraySize; i++) {
            System.out.print("Name: ");
            String name = scanner.next();
            String cnp;
            boolean flag;
            do {
                System.out.print("CNP: ");
                cnp = scanner.next();
                flag = isValid(cnp);
            } while (!flag);
            personList[i] = new Person(name, cnp);
        }
        for (Person person : personList) {
            System.out.println(person.getName() + ", " + person.getCnp() + ", " + person.getAge() + "yrs");
        }
    }
}
