package ex4lab;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Person {
    private String name;
    private String cnp;

    public Person(String name, String cnp) {
        this.name = name;
        this.cnp = cnp;
    }

    public static boolean isValid(String cnp) {
        if (!cnp.matches("[0-9]+")) {
            System.out.println("Wrong format!");
            return false;
        }
        if (cnp.length() != 13) {
            System.out.println("Wrong length!");
            return false;
        }
        if (cnp.charAt(0) != '1' && cnp.charAt(0) != '2' && cnp.charAt(0) != '5' && cnp.charAt(0) != '6') {
            System.out.println("Invalid first number!");
            return false;
        }
        if (!hasValidControl(cnp)) {
            System.out.println("Control number is wrong, try again!");
            return false;
        }
        return true;
    }

    public static boolean hasValidControl(String cnp) {
        int[] control = new int[]{2, 7, 9, 1, 4, 6, 3, 5, 8, 2, 7, 9};
        int sum = 0;
        int modulus;
        for (int i = 0; i < 12; i++) {
            sum += Integer.parseInt(String.valueOf(cnp.charAt(i))) * control[i];
        }
        modulus = sum % 11;
        if (modulus == 10)
            modulus = 1;
        return modulus == Integer.parseInt(String.valueOf(cnp.charAt(12)));
    }

    public int getAge() {
        int year, month, day;
        if (cnp.charAt(0) == '1' || cnp.charAt(0) == '2') {
            year = Integer.parseInt(("19" + cnp.substring(1, 3)));
        } else
            year = Integer.parseInt(("20" + cnp.substring(1, 3)));
        month = Integer.parseInt(cnp.substring(3, 5));
        day = Integer.parseInt(cnp.substring(5, 7));
        LocalDate birthDate = LocalDate.of(year, month, day);
        LocalDate currentDate = LocalDate.now();
        return (int) ChronoUnit.YEARS.between(birthDate, currentDate);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCnp() {
        return cnp;
    }

    public void setCnp(String cnp) {
        this.cnp = cnp;
    }
}
