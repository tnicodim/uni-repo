/*Să se creeze tabelele persoane şi excursii în baza de date lab8 din MySQL. Tabela
persoane va avea câmpurile id (întreg cheie primara si autoincrement), nume (varchar(45)) şi
varsta (întreg). Tabela excursii va avea câmpurile (id_persoana – cheie externă, unei
persoane îi corespund mai multe excursii, id_excursie – cheie primară şi autoincrement,
destinatia, anul).

Să se realizeze o aplicație Java, care se va conecta la baza de date MySQL cu ajutorul
tehnologiei JDBC (suportul teoretic este în curs) şi va realiza următoarele operații prin
intermediul unui meniu interactiv:

1. Adăugarea unei persoane în tabela persoane. Numele şi vârsta se vor prelua de la
tastatură.
2. Adăugarea unei excursii în tabela excursii. Înainte de a efectua adăugarea se va
verifica dacă persoana căreia îi aparține excursia a fost introdusă în tabela
persoane. Dacă nu a fost introdusă se va afișa un mesaj corespunzător. Datele
excursiei se vor prelua de la tastatură.
3. Afișarea tuturor persoanelor şi pentru fiecare persoană a excursiilor în care a fost
4. Afișarea excursiilor în care a fost o persoană al cărei nume se citește de la tastatură
5. Afișarea tuturor persoanelor care au vizitat o anumita destinație.
6. Afișarea persoanelor care au făcut excursii într-un an introdus
7. Ștergerea unei excursii
8. Ștergerea unei persoane (împreună cu excursiile în care a fost)
Situațiile de excepție care pot apărea datorită introducerii necorespunzătoare a datelor
de la tastatură atunci când se citește vârsta unei persoane, respectiv anul unei excursii vor fi
tratate. Mecanismul de tratare a excepțiilor va fi utilizat pentru a trata situațiile în care la
citirea acestor variabile se introduc de la tastatură alte caractere decât cifre sau valori prea
mici sau prea mari. De exemplu pentru vârsta nu se accepta valori negative sau mai mari decât
o limită superioară aleasă. Pentru câmpul anul efectuării unei excursii acesta nu poate fi mai
mic decât anul nașterii și nici mai mare decât anul curent. Se vor crea clasele pentru excepții
ExceptieVarsta şi ExceptieAnExcursie şi se vor arunca şi prinde excepții de aceste tipuri
însoțite de mesajele corespunzătoare. */


package ex1;

import java.sql.*;
import java.util.Random;
import java.util.Scanner;

import static java.lang.System.exit;

public class Main {
    public static void main(String[] args) throws SQLException {
        String url = "jdbc:mysql://localhost:3306/test";
        Connection connection= DriverManager.getConnection(url, "root", "whiteeagle441");
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("""
                                                            
                    1. Add new person
                    2. 
                    3. 
                    4. 
                    5. 
                    6. 
                    7. 
                    8. 
                    0. Exit
                    Option:\s""");
            int x = scanner.nextInt();
            switch (x) {
                case 1:
                    System.out.print("nume = ");
                    String nume = scanner.next();
                    System.out.print("varsta = ");
                    int varsta = scanner.nextInt();
                    adaugarePersoana(connection,nume,varsta);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 0:
                    connection.close();
                    exit(0);
                default:
                    System.out.println("Invalid option! Try again!");
                    break;
            }
        }
    }
    public static void adaugarePersoana(Connection connection, String nume, int varsta) {
        String sql="insert into persoane (nume,varsta) values (?,?)";
        try(PreparedStatement ps=connection.prepareStatement(sql)) {
            ps.setString(1, nume);
            ps.setInt(2, varsta);
            int nr_randuri=ps.executeUpdate();
            System.out.println("\nNumar randuri afectate de adaugare="+nr_randuri);
        } catch (SQLException e) {
            System.out.println(sql);
            e.printStackTrace();
        }
    }
}
