import java.util.Scanner;


public class Main {
	
	private static Scanner scan = new Scanner(System.in);

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int x,y;
		System.out.print("x = ");
		x = scan.nextInt();
		System.out.print("y = ");
		y = scan.nextInt();
	//	System.out.println("Hello World!");
		System.out.println(x + " + " + y + " = " + (x+y));
	}

}
