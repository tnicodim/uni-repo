import java.io.Serializable;

public class CopyMachine extends Item implements Serializable {
    private int p_ton;

    private Format format;
    enum Format {
        A3,
        A4
    }

    @Override
    public String toString() {
        return "CopyMachine " +
                getName() + " " +
                getNrInv() + " " +
                getPrice() + " " +
                getZone() + " " +
                getStatus() + " " +
                p_ton + " " +
                format;
    }

    public CopyMachine(String name, int nrInv, float price, String zone, Status status, int p_ton, Format format) {
        super(name, nrInv, price, zone, status);
        this.p_ton = p_ton;
        this.format = format;
    }

    public int getP_ton() {
        return p_ton;
    }

    public void setP_ton(int p_ton) {
        this.p_ton = p_ton;
    }

    public Format getFormat() {
        return format;
    }

    public void setFormat(Format format) {
        this.format = format;
    }
}
