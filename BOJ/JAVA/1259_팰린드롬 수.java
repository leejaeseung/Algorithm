import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Stack<Character> stack;

        while(true) {
            String num = br.readLine();
            if(num.charAt(0) == '0')
                break;
            stack = new Stack<>();
            boolean flag = true;

            if(num.length() % 2 == 0) {     //짝수개
                for (int i = 0; i <= num.length() / 2 - 1; i++) {
                    stack.push(num.charAt(i));
                }
                for (int i = num.length() / 2; i < num.length(); i++) {
                    char next = stack.pop();
                    if(next != num.charAt(i)){
                        flag = false;
                        break;
                    }
                }
            }
            else {
                for (int i = 0; i < num.length() / 2; i++) {
                    stack.push(num.charAt(i));
                }
                for (int i = num.length() / 2 + 1; i < num.length(); i++) {
                    char next = stack.pop();
                    if(next != num.charAt(i)){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                bw.write("yes\n");
            else
                bw.write("no\n");
        }

        bw.flush();
        bw.close();
    }
}