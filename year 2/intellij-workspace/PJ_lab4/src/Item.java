import java.io.Serializable;

public class Item implements Serializable {
    private String name;
    private int nrInv;
    private float price;
    private String zone;
    private Status status;

    public enum Status {
        BOUGHT,
        ON_SALE,
        SOLD
    }

    public Item(String name, int nrInv, float price, String zone, Status status) {
        this.name = name;
        this.nrInv = nrInv;
        this.price = price;
        this.zone = zone;
        this.status = status;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNrInv() {
        return nrInv;
    }

    public void setNrInv(int nrInv) {
        this.nrInv = nrInv;
    }

    public float getPrice() {
        return price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public String getZone() {
        return zone;
    }

    public void setZone(String zone) {
        this.zone = zone;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }
}

