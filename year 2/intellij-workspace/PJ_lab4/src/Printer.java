import java.io.Serializable;

public class Printer extends Item implements Serializable {
    private int ppm;
    private String resolution;
    private int p_car;
    private PrintType printType;
    enum PrintType {
        COLOR,
        BLACK_AND_WHITE
    }

    @Override
    public String toString() {
        return "Printer " +
                getName() + " " +
                getNrInv() + " " +
                getPrice() + " " +
                getZone() + " " +
                getStatus() + " " +
                ppm + " " +
                resolution + " " +
                p_car + " " +
                printType;
    }

    public Printer(String name, int nrInv, float price, String zone, Status status, int ppm, String resolution, int p_car, PrintType printType) {
        super(name, nrInv, price, zone, status);
        this.ppm = ppm;
        this.resolution = resolution;
        this.p_car = p_car;
        this.printType = printType;
    }

    public Printer(String name, int nrInv, float price, String zone, Status status) {
        super(name, nrInv, price, zone, status);
    }

    public int getPpm() {
        return ppm;
    }

    public void setPpm(int ppm) {
        this.ppm = ppm;
    }

    public String getResolution() {
        return resolution;
    }

    public void setResolution(String resolution) {
        this.resolution = resolution;
    }

    public int getP_car() {
        return p_car;
    }

    public void setP_car(int p_car) {
        this.p_car = p_car;
    }

    public PrintType getPrintType() {
        return printType;
    }

    public void setPrintType(PrintType printType) {
        this.printType = printType;
    }
}
