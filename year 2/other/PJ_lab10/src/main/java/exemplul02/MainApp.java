package exemplul02;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
class Dreptunghi {
    private int lungime;
    private int latime;
    public Dreptunghi(int lungime, int latime) {
        this.lungime = lungime;
        this.latime = latime;
    }
    public void aria() {
        System.out.println("Aria dreptunghiului: "+(lungime
                *latime));
    }
}
class MainApp {
    public static void main(String []args){
        ApplicationContext context
                =new ClassPathXmlApplicationContext("beans02.xml");
        Dreptunghi
                d=(Dreptunghi)context.getBean("dreptunghi");
        d.aria();
    }
}