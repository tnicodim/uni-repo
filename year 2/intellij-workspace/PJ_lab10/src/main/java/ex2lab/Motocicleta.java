package ex2lab;

public class Motocicleta extends Vehicul{
    private int vitezaMax;

    public Motocicleta(int pret, String marca, int vitezaMax) {
        super(pret, marca);
        this.vitezaMax = vitezaMax;
    }

    @Override
    public String toString() {
        return "Motocicleta{" +
                "vitezaMax=" + vitezaMax +
                "} " + super.toString();
    }

    public int getVitezaMax() {
        return vitezaMax;
    }

    public void setVitezaMax(int vitezaMax) {
        this.vitezaMax = vitezaMax;
    }

    public Motocicleta() {
        this.vitezaMax = 0;
    }
}
