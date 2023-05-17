package ex2lab;

public class Autoturism extends Vehicul{
    private int volumPortbagaj;
    private int greutate;

    public Autoturism(int pret, String marca, int volumPortbagaj, int greutate) {
        super(pret, marca);
        this.volumPortbagaj = volumPortbagaj;
        this.greutate = greutate;
    }

    public Autoturism() {
        this.volumPortbagaj = 0;
        this.greutate = 0;
    }

    @Override
    public String toString() {
        return "Autoturism{" +
                "volumPortbagaj=" + volumPortbagaj +
                ", greutate=" + greutate +
                "} " + super.toString();
    }

    public int getVolumPortbagaj() {
        return volumPortbagaj;
    }

    public void setVolumPortbagaj(int volumPortbagaj) {
        this.volumPortbagaj = volumPortbagaj;
    }

    public int getGreutate() {
        return greutate;
    }

    public void setGreutate(int greutate) {
        this.greutate = greutate;
    }
}
