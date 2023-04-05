package ex2lab;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.File;
import java.io.IOException;
import java.util.List;

/*
Să implementeze clasa PerecheNumere care are variabile membre private doi întregi.
Clasa PerecheNumere va avea un constructor cu parametri şi unul fără parametri, gettere şi
setttere pentru accesarea variabilelor membre şi va redefini metoda toString din clasa Object.
În program se va crea o colecție de obiecte de tip List în care se vor adăuga minim 3
perechi de numere.
În programul principal se vor dezvolta metodele:
static void scriere(List< PerecheNumere > lista);
static List<Persoana> citire();
Metoda scriere() va salva lista perechilor de numere într-un fișier JSON, iar metoda
citire() va încărca lista perechilor de numere din fișierul JSON în program.
În clasa PerecheNumere se vor dezvolta următoarele metode:
• o metodă care va returna o valoare booleana care indică dacă cele două numere care
formează perechea sunt numere consecutive în șirul lui Fibonaci
• o metodă care returnează cel mic multiplu comun al celor două numere
• o metodă care va returna boolean daca cele doua numere au suma cifrelor egală
• o metodă care va returna boolean dacă cele doua numere au același număr de cifre pare.
Să se documenteze clasele şi metodele şi să se genereze documentația proiectului.
Pentru fiecare din metodele de mai sus se vor scrie minim trei teste.
*/
public class Main {
    public static void main(String[] args) throws IOException {
        List<PerecheNumere> perecheNumereList = citire();
        for (PerecheNumere perecheNumere : perecheNumereList) {
            System.out.println(perecheNumere);
        }
       // perecheNumereList.add(new PerecheNumere(4,4));
        scriere(perecheNumereList);
    }
    static List<PerecheNumere> citire() throws IOException {
            File file=new File("src/main/resources/perechinumere.json");
            ObjectMapper mapper=new ObjectMapper();
            return mapper.readValue(file, new TypeReference<>() {});
    }
    static void scriere(List<PerecheNumere> lista) throws IOException {
            File file=new File("src/main/resources/perechinumere.json");
            ObjectMapper mapper=new ObjectMapper();
            mapper.writeValue(file,lista);
    }
}


