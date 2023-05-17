package ex2lab;

public class Vehicul {
    private int pret;
    private String marca;

    public Vehicul(int pret, String marca) {
        this.pret = pret;
        this.marca = marca;
    }

    @Override
    public String toString() {
        return "Vehicul{" +
                "pret=" + pret +
                ", marca='" + marca + '\'' +
                '}';
    }

    public int getPret() {
        return pret;
    }

    public void setPret(int pret) {
        this.pret = pret;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public Vehicul() {
    }
}
