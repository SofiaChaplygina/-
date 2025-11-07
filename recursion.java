public class Main {
    public static double power(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) return 1 / power(x, -n);
        
        double half = power(x * x, n / 2);
        return (n % 2 == 0) ? half : x * half;
    }
    
    public static void main(String[] args) {
        try {
            java.util.Scanner scanner = new java.util.Scanner(System.in);
            System.out.print("Введите основание: ");
            double base = scanner.nextDouble();
            System.out.print("Введите показатель степени: ");
            int exponent = scanner.nextInt();
            double result = power(base, exponent);
            System.out.println(base + " в степени " + exponent + " = " + result);
        } catch (java.util.InputMismatchException e) {
            System.out.println("Ошибка: введите корректные числовые значения");
        } catch (Exception e) {
            System.out.println("Произошла ошибка: " + e.getMessage());
        }
    }
}
//Введите основание: 7
//Введите показатель степени: 2
//7.0 в степени 2 = 49.0
