/*
문제
히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.



히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

입력
입력은 테스트 케이스 여러 개로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000) 그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다. 이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다. 모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서, 히스토그램에서 가장 넓이가 큰 직사각형의 넓이를 출력한다.

풀이 : ㄹㅇ 어려움 아래 사이트 참고...
https://greeksharifa.github.io/ps/2018/07/07/PS-06549/
 */

import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));



        while(true){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            if(n == 0)
                break;

            Stack<Histo> stack = new Stack<>();
            long ans = 0;
            long height = 0;
            for (long i = 0; i < n ; i++) {
                height = Long.parseLong(st.nextToken());

                long minpos = i;
            while (!stack.isEmpty() && stack.peek().H > height) {
                    ans = Math.max(ans, (i - stack.peek().pos) * stack.peek().H);
                    minpos = stack.peek().pos;
                    stack.pop();
                    if(stack.isEmpty())
                        break;
                }
                stack.push(new Histo(height, minpos));
            }
            while(!stack.isEmpty()){
                ans = Math.max(ans, (n - stack.peek().pos) * stack.peek().H);
                stack.pop();
            }
            bw.write(ans + "\n");
            bw.flush();
        }
        bw.close();
    }
}

class Histo{
    long H;
    long pos;
    public Histo(long H, long pos){
        this.H = H;
        this.pos = pos;
    }
}