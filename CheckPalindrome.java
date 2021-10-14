package daa.assignment;

public class CheckPalindrome {
    
    public static void main(String[] args) {
        int n = 717;
        int res = palindrome(n, 0);
        
        if (res == n) {
            System.out.println("Yes");
        }else {
            System.out.println("No");
        }
    }
    
    public static int palindrome(int n, int temp) {
        if (n == 0) {
            return temp;
        }

        temp = (temp * 10) + (n % 10);

        return palindrome(n / 10, temp);
    }
    
}
