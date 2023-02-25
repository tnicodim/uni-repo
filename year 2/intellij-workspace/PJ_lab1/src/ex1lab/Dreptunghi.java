package ex1lab;

public class Dreptunghi {

    private int latime;
    private int lungime;

    public Dreptunghi(int latime, int lungime) {
        this.latime = latime;
        this.lungime = lungime;
    }

    public int getSurface(){
        return latime * lungime;
    }

    public int getPerimeter(){
        return 2*(latime+lungime);
    }

    public void setLatime(int latime) {
        this.latime = latime;
    }

    public void setLungime(int lungime) {
        this.lungime = lungime;
    }
}
