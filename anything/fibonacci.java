import java.util.Scanner;

public class fibonacci {
    public static void main(String[] args) {
        int n;
        double result;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Type a number: ");
        n = scanner.nextInt();
        
        fibonacci fibona = new fibonacci();
        result = fibona.fibo(n);
        System.out.print("Fibonacci " + n + ": " + result + "\n");

        scanner.close();

    }
    public double fibo(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        return (fibo(n - 1) + fibo(n - 2));
    }
}