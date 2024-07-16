package ex2lab;

public class Tir extends Vehicul{
    private int greutateMax;

    public Tir(int pret, String marca, int greutateMax) {
        super(pret, marca);
        this.greutateMax = greutateMax;
    }

    @Override
    public String toString() {
        return "Tir{" +
                "greutateMax=" + greutateMax +
                "} " + super.toString();
    }

    public int getGreutateMax() {
        return greutateMax;
    }

    public void setGreutateMax(int greutateMax) {
        this.greutateMax = greutateMax;
    }

    public Tir() {
        this.greutateMax = 0;
    }
}
