package ex2lab;

public class PerecheNumere {
    private int x;
    private int y;

    public PerecheNumere(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public PerecheNumere() {
        this.x = 0;
        this.y = 0;
    }

    @Override
    public String toString() {
        return "x=" + x +
                " y=" + y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
}
