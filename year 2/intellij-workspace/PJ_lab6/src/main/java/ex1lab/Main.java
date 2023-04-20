package ex1lab;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.fasterxml.jackson.datatype.jsr310.JavaTimeModule;

import java.io.File;
import java.io.IOException;
import java.time.LocalDate;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Angajati> angajatiList = citire();
        System.out.println("\nAfisare prin referinte la metode:");
        angajatiList.forEach(System.out::println);
        System.out.println("\nAfisarea angajaților care au salariul peste 2500 RON:");
        angajatiList
                .stream()
                .filter(a -> a.getSalariu() > 2500)
                .forEach(System.out::println);
        System.out.println("\nCrearea unei liste cu angajații din luna aprilie, a anului trecut, care au funcție de conducere: ");
        //!
        angajatiList
                .stream()
                .filter(angajati -> (angajati.getPost().contains("Director") || angajati.getPost().contains("Leader"))
                        && (angajati.getData_angajarii().getMonthValue() == 4 && angajati.getData_angajarii().minusYears(LocalDate.now().getYear()).getYear() == -1))
                .forEach(System.out::println);
        System.out.println("\nAfișarea angajaților care nu au funcție de conducere (postul lor nu conține cuvintele în ordine descrescătoare a salariilor");
        angajatiList
                .stream()
                .filter(angajati -> !(angajati.getPost().contains("Director") || angajati.getPost().contains("Leader")))
                .forEach(System.out::println);

    }

    public static void scriere(List<Angajati> lista) {
        try {
            ObjectMapper mapper = new ObjectMapper();
            mapper.registerModule(new JavaTimeModule());
            mapper.disable(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS);
            File file = new File("src/main/resources/angajati.json");
            mapper.writeValue(file, lista);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static List<Angajati> citire() {
        try {
            File file = new File("src/main/resources/angajati.json");
            ObjectMapper mapper = new ObjectMapper();
            mapper.registerModule(new JavaTimeModule());
            List<Angajati> angajati = mapper
                    .readValue(file, new TypeReference<>() {
                    });
            return angajati;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
}