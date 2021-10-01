import java.text.NumberFormat;
import java.util.Scanner;

public class factorial {
    public static void main(String[] args) {
        
        System.out.print("Nhap n: ");
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        double result = factor(n);
        scan.close();
        
        //NumberFormat formatDouble = new DecimalFormat("#0.0");

        if (result > 0)
            System.out.printf("Giai thua cua " + n + " la: " + result + "\n");

    }

    private static double factor(int n) {
        if (n > 0) {
            if (n == 1) return 1;
            else return (double) n*factor(n-1);
        }
        else {
            System.out.println("Invalid input!");
            return -1;
        }
    }
}