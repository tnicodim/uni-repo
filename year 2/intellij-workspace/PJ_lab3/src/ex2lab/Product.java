package ex2lab;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class Product {

    public static float sales;
    private final String name;
    private final float price;
    private int stock;
    private final LocalDate expirationDate;

    public Product(String name, float price, int quantity, String expirationDate) {
        this.name = name;
        this.price = price;
        this.stock = quantity;
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        this.expirationDate = LocalDate.parse(expirationDate,formatter);
    }

    @Override
    public String toString() {
        return name + " " + price + "$ " + stock + " " + expirationDate;
    }

    public void sell(int quantity){
        if (this.stock < quantity){
            System.out.println("Sell quantity exceeds current stock");
            return;
        }
        this.stock -= quantity;
        sales += this.price*quantity;
    }
    public boolean isExpired() {
        return LocalDate.now().isAfter(expirationDate);
    }

    public String getName() {
        return name;
    }

    public float getPrice() {
        return price;
    }

    public int getStock() {
        return stock;
    }

}
