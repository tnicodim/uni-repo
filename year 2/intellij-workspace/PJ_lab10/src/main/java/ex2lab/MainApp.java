package ex2lab;

import org.springframework.context.ApplicationContext;
import org.springframework.beans.factory.BeanFactory;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/*Se consideră clasa de bază Vehicul şi clasele derivate Autoturism, Motocicleta şi Tir.
Fiecare vehicul, indiferent de tip are o marca şi un preț. Pentru autoturisme se reține
volumul portbagajului și cât de mult cântărește. Pentru motociclete se reține viteza
maximă iar pentru tiruri se reține încărcătura maximă. Să se dezvolte un program care
implementează ierarhia de clase de mai sus. Fiecare clasă va avea variabile membre
private, constructor fără parametri, constructor cu parametri, gettere şi settere, metoda
toString(). În programul principal se vor crea două containere Spring. Primul container va
crea bean-uri în care se vor injecta valori cu ajutorul metadatelor de configurare preluate
din xml si al doilea container va crea bean-uri în care se vor injecta valori cu ajutorul
adnotațiilor. Bean-urile create se vor afișa în consolă. Clasa MainApp nu va avea nici o
dependență fată de clasele derivate, ci doar fată de clasa de bază.
În fișierul beans_lab1.xml se vor crea următoarele bean-uri:
a. un bean de tip Autoturism în care se vor injecta valori cu ajutorul setterelor.
b. Un bean de tip Autoturism în care se vor injecta valori cu ajutorul constructorului.
c. Un bean de tip Vehicul şi un bean de tip Motocicleta legate prin relație de moștenire în
care se vor injecta valori cu ajutorul constructorilor. Clasa Motocicleta va conține
metode care vor afișa mesaje corespunzătoare atunci când se creează, respectiv când se
distruge un bean motocicletă.*/
public class MainApp {
    public static void main(String[] args) {
        int []v=new int[5];

//        ApplicationContext context=new ClassPathXmlApplicationContext("beans_ex2.xml");
//        BeanFactory factory=new ClassPathXmlApplicationContext("beans_ex2.xml");
//        Vehicul t=(Tir)factory.getBean("tir");
//        Vehicul m=(Motocicleta)context.getBean("moto");
//        Vehicul a=(Autoturism)context.getBean("auto");
//        System.out.println(t);
//        System.out.println(m);
//        System.out.println(a);
    }
}
