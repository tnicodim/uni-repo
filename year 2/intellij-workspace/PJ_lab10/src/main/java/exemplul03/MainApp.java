package exemplul03;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
class MainApp {
    public static void main(String []args){
        ApplicationContext context=new ClassPathXmlApplicationContext("beans03_1.xml");
        //ApplicationContext context=new ClassPathXmlApplicationContext("beans03_2.xml");
        //ApplicationContext context=new ClassPathXmlApplicationContext("beans03_3.xml");
        Persoana p=(Persoana)context.getBean("pers");
        System.out.print(p);
    }
}