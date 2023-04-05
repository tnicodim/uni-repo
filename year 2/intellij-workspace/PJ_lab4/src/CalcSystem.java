import java.io.Serializable;

public class CalcSystem extends Item implements Serializable {

    private String monitorType;
    private float cpu_speed;
    private int c_hdd;
    private OperationSystem os;
    enum OperationSystem{
        WINDOWS,
        LINUX
    }

    @Override
    public String toString() {
        return "CalcSystem " + getName() +
                getNrInv() + " " +
                getPrice() + " " +
                getZone() + " " +
                getStatus() + " " +
                monitorType + " " +
                cpu_speed + " " +
                c_hdd + " " +
                os;
    }

    public CalcSystem(String name, int nrInv, float price, String zone, Status status, String monitorType, float cpu_speed, int c_hdd, OperationSystem os) {
        super(name, nrInv, price, zone, status);
        this.monitorType = monitorType;
        this.cpu_speed = cpu_speed;
        this.c_hdd = c_hdd;
        this.os = os;
    }

    public String getMonitorType() {
        return monitorType;
    }

    public void setMonitorType(String monitorType) {
        this.monitorType = monitorType;
    }

    public float getCpu_speed() {
        return cpu_speed;
    }

    public void setCpu_speed(float cpu_speed) {
        this.cpu_speed = cpu_speed;
    }

    public int getC_hdd() {
        return c_hdd;
    }

    public void setC_hdd(int c_hdd) {
        this.c_hdd = c_hdd;
    }

    public OperationSystem getOs() {
        return os;
    }

    public void setOs(OperationSystem os) {
        this.os = os;
    }
}
