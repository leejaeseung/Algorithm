import java.io.*;
import java.util.Stack;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < str.length() ; i++) {
            char now = str.charAt(i);

            if(now <= '9' && now >= '0'){
                stack.push(now - '0');
            }
            else{
                int a = stack.pop();
                int b = stack.pop();
                if(now == '+'){
                    stack.push(a + b);
                }
                else if(now == '-'){
                    stack.push(b - a);
                }
                else if(now == '/'){
                    stack.push(b / a);
                }
                else{
                    stack.push(a * b);
                }
            }
        }
        System.out.println(stack.pop());
    }
}