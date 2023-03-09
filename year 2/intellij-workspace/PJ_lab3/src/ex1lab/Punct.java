package ex1lab;

public class Punct {
    private final float x;
    private final float y;

    public Punct(float x, float y) {
        super();
        this.x = x;
        this.y = y;
    }

    @Override
    public String toString() {
        return "(" + x + ";" + y + ")";
    }
}
