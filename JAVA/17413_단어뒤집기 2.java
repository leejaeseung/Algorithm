/*
    문제
문자열 S가 주어졌을 때, 이 문자열에서 단어만 뒤집으려고 한다.

먼저, 문자열 S는 아래와과 같은 규칙을 지킨다.

알파벳 소문자('a'-'z'), 숫자('0'-'9'), 공백(' '), 특수 문자('<', '>')로만 이루어져 있다.
문자열의 시작과 끝은 공백이 아니다.
'<'와 '>'가 문자열에 있는 경우 번갈아가면서 등장하며, '<'이 먼저 등장한다. 또, 두 문자의 개수는 같다.
태그는 '<'로 시작해서 '>'로 끝나는 길이가 3 이상인 부분 문자열이고, '<'와 '>' 사이에는 알파벳 소문자와 공백만 있다. 단어는 알파벳 소문자와 숫자로 이루어진 부분 문자열이고, 연속하는 두 단어는 공백 하나로 구분한다. 태그는 단어가 아니며, 태그와 단어 사이에는 공백이 없다.

입력
첫째 줄에 문자열 S가 주어진다. S의 길이는 100,000 이하이다.

출력
첫째 줄에 문자열 S의 단어를 뒤집어서 출력한다.
    풀이 :
    tag는 queue에, 단어는 stack에 저장하여 word마다 tag인지 단어인지 확인하여 따로 따로 출력한다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s=br.readLine();
        Queue<Character>[] q=new LinkedList[50000];
        Stack<Character>[] stack=new Stack[50000];
        boolean wordORtag[]=new boolean[50000];
        int wordindex=0;
        boolean tag_flag=false;

        for (int i = 0; i<s.length(); i++) {
            if(s.charAt(i)=='<')
                tag_flag=true;
            if(s.charAt(i)=='>') {
                tag_flag = false;
                wordORtag[wordindex]=false;
                q[wordindex].offer(s.charAt(i));
                wordindex++;
                continue;
            }
            if(tag_flag==true){
                if(q[wordindex]==null)
                    q[wordindex]=new LinkedList<>();
                q[wordindex].offer(s.charAt(i));
            }
            else{
                if(stack[wordindex]==null)
                    stack[wordindex]=new Stack<>();
                if(s.charAt(i)==32||i+1==s.length()||(i+1!=s.length()&&s.charAt(i+1)=='<')) {
                    wordORtag[wordindex] = true;
                    stack[wordindex].push(s.charAt(i));
                    wordindex++;
                }
                else {
                    stack[wordindex].push(s.charAt(i));
                }
            }
        }
        boolean emptyflag=false;
        for (int i = 0; i <wordindex ; i++) {
            if(wordORtag[i]==true){
                while(!stack[i].isEmpty()){
                    if(stack[i].peek()==32){
                        emptyflag=true;
                        stack[i].pop();
                    }
                    else
                    bw.write(stack[i].pop());
                }
                if(emptyflag==true&&i+1!=wordindex) {
                    bw.write(" ");
                    emptyflag=false;
                }
            }
            else{
                while(!q[i].isEmpty()){
                    bw.write(q[i].poll());
                }
            }
        }
        bw.flush();
        bw.close();

    }
}