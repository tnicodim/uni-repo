/*În fișierul de intrare carti.json se găsesc informații despre cărțile dintr-o colecție personală.
Pentru fiecare carte se reține id-ul cărții (a câta carte citită), titlul cărții, numele autorului şi
anul apariției.
Să se creeze tipul înregistrare (record) Carte având componentele titlul, autorul şi
anul apariție.
Să se creeze o colecție de obiecte de tip Map<Integer,Carte> în care se vor adăuga
cărțile citite din fișier. Id-ul cărților reprezintă cheia elementelor din colecția Map, iar
valoarea elementelor din colecție este reprezentată de obiecte de tip Carte. Se va utiliza
implementarea HashMap a interfeței Map şi inferența tipului pentru variabilele locale. Pentru
colecția Map creată să se implementeze următoarele cerințe:
1) Să se afișeze colecția (se vor afișa atât cheile cât şi valorile, utilizând inferenţa tipului
pentru variabilele locale).
2) Să se șteargă o carte din colecția Map
3) Să se adauge o carte la colecția Map (se va utiliza metoda putIfAbsent)
4) Sa se salveze în fișierul JSON modificările făcute asupra colecției
5) Să se creeze o colecție Set<Carte> care extrage din colecția Map cărțile autorului
Yual Noah Harari. Se va utiliza Stream API şi colectori. Se va afișa colecția creată cu
ajutorul metodei forEach.
6) Să se afișeze ordonat după titlul cărți elementele din colecția Set folosind Stream API,
expresii Lambda şi referințe la metode.
7) Să se afișeze datele celei mai vechi cărți din colecția Set folosind Stream API şi clasa
Optional. */


package org.example;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.File;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        Map<Integer, Book> map = citire();
        for (Integer integer : map.keySet()) {
            System.out.println(integer + ": " + map.get(integer));
        }
        map.remove(5);
        map.putIfAbsent(5, new Book("Baltagul", "Yuval Noah Harari", 1930));
        scriere(map);
        Set<Book> bookSet = map.values()
                .stream()
                .filter(book -> book.author().equals("Yuval Noah Harari")).collect(Collectors.toSet());
        System.out.println("\nYuval Noah Harari author set:");
        bookSet.stream().sorted(Comparator.comparing(Book::title)).forEach(System.out::println);
        System.out.println("\nOldest book in set: ");
        System.out.println(bookSet.stream().min(Comparator.comparing(Book::year)));
    }

    static Map<Integer, Book> citire() throws IOException {
        File file = new File("src/main/resources/carti.json");
        ObjectMapper mapper = new ObjectMapper();
        return mapper.readValue(file, new TypeReference<>() {
        });
    }

    static void scriere(Map<Integer, Book> map) throws IOException {
        File file = new File("src/main/resources/carti.json");
        ObjectMapper mapper = new ObjectMapper();
        mapper.writeValue(file, map);
    }
}