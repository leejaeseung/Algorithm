/*
    문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
    풀이 :
    난 머저리~
 */
import java.io.*;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s=br.readLine();

        int[] alpha=new int[26];
        for (int i = 0; i <s.length() ; i++) {
            if(s.charAt(i)>=65&&s.charAt(i)<=90){                       //대문자면
                alpha[s.charAt(i)-65]++;
            }
            else{
                alpha[s.charAt(i)-97]++;
            }
        }
        int max=0;
        int out=0;
        boolean max_flag=false;
        for (int i = 0; i <26 ; i++) {
            if(max<alpha[i]) {
                max = alpha[i];
                out=i;
                max_flag=true;
                continue;
            }
            if(max==alpha[i]&&max_flag==true){
                max_flag=false;
            }
        }
        if(max_flag==true)
            System.out.println((char)(out+65));
        else{
            System.out.println("?");
        }
    }
}