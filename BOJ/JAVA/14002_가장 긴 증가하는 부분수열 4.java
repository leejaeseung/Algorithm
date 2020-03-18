/*
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다.

풀이:
parent[i] 는 value[i] 가 dp 에서 어느 인덱스에 위치하는지 기억하고 있는 배열이다.
따라서 parent 배열을 뒤에서부터 탐색하고, dp의 크기 -1 부터 시작하여 현재 탐색중인 dp 위치와 parent의 위치가 동일하면
스택에 넣어준다.
 */
import java.io.*;
import java.util.ArrayList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static int N;
    public static int[] value;
    public static ArrayList<Integer> dp = new ArrayList<>();
    public static tuple[] parent;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        value = new int[N];
        parent = new tuple[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N ; i++) {
            value[i] = Integer.parseInt(st.nextToken());
        }

        dp.add(value[0]);
        parent[0] = new tuple(0, value[0]);
        for (int i = 1; i < N ; i++) {
            if(value[i] <= dp.get(dp.size() - 1)){
                lowerBound(0, dp.size(), value[i], i);
            }
            else{
                parent[i] = new tuple(dp.size(), value[i]);
                dp.add(value[i]);
            }
        }

        bw.write(dp.size() + "\n");
        Stack<Integer> stack = new Stack<>();
        int temp = dp.size() - 1;
        for (int i = N - 1; i >= 0 ; i--) {
            if(parent[i] == null)   continue;
            if(temp == parent[i].first){
                stack.push(parent[i].second);
                temp--;
            }
        }
        while(!stack.isEmpty())
            bw.write(stack.pop() + " ");
        bw.flush();
        bw.close();
    }
    public static void lowerBound(int s, int e, int v, int idx){
        while(s < e){
            int mid = (s + e) / 2;
            if(dp.get(mid) >= v)
                e = mid;
            else
                s = mid + 1;
        }
        parent[idx] = new tuple(s, v);
        dp.set(s, v);
    }
}

class tuple{
    int first;
    int second;
    public tuple(int first, int second){
        this.first = first;
        this.second = second;
    }
}