/*
문제
N개의 숫자 구슬이 <그림 1>과 같이 막대에 꿰어져 일자로 놓여 있다. 이들 구슬은 막대에서 빼낼수 없고 따라서 바꿀 수 없다.



이 숫자 구슬을 M개의 그룹으로 나누었을 때 각각의 그룹의 합 중 최댓값이 최소가 되도록 하려 하다. 예를 들어 세 그룹으로 나눈다고 할 때 <그림 2>와 같이 그룹을 나누면 그룹의 합은 각각 11, 15, 18이 되어 그 중 최댓값은 18이 되고, <그림 3>과 같이 나누면 각 그룹의 합은 각각 17, 12, 15가 되어 그 중 최댓값은 17이 된다. 숫자 구슬의 배열이 위와 같을 때는 그룹의 합 중 최댓값이 17보다 작게 만들 수는 없다.



각 그룹의 합 중 최댓값이 최소가 되도록 M개의 그룹으로 나누었을 때, 그 최댓값과 각 그룹을 구성하는 구슬의 개수를 찾아 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 구슬의 개수 N과 그룹의 수 M이 주어진다. 둘째 줄에는 각 구슬이 적혀진 숫자가 왼쪽부터 차례로 주어진다. N은 300 이하의 자연수, M은 N이하의 자연수이며, 구슬에 적혀진 숫자는 100 이하의 자연수이다.

출력
각 그룹의 합 중 최댓값이 최소가 되도록 M개의 그룹으로 나누었을 때 그 최댓값을 첫째 줄에 출력하고, 둘째 줄에는 각 그룹을 구성하는 구슬의 개수를 왼쪽부터 순서대로 출력한다. 구슬의 개수를 출력할 때는 사이에 한 칸의 공백을 둔다. 만약 그룹의 합의 최댓값이 최소가 되도록 하는 경우가 둘 이상이라면 그 중 하나만을 출력한다.

풀이:
한양대 OPC 2번 "흩날리는 시험지 속에서 내 평점이 느껴진거야" 와 답을 구하는 방식은 같다(Parametric Search).
하지만 구슬의 그룹 개수를 출력할 때 구해야 하는 그룹의 개수보다 구해진 그룹의 개수가 적으므로
2개 보다 많은 구슬을 가진 그룹을 분할해 주어야 한다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static int[] ball;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int sum = 0;
        ball = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N ; i++) {
            ball[i] = Integer.parseInt(st.nextToken());
            sum += ball[i];
        }
        int left = 1;
        int right = sum;
        int res = 0;

        while(left <= right){
            int mid = (left + right) /2;

            if(com(mid)){
                right = mid - 1;
                res = mid;
            }
            else{
                left = mid + 1;
            }
        }
        bw.write(res + "\n");

        int[] resGroup = new int[N + 1];
        int cnt = 0, idx = 1;
        sum = 0;
        for (int i = 0; i < N ; i++) {
            sum += ball[i];
            cnt++;
            if(sum > res){
                sum = ball[i];
                resGroup[idx++] = cnt - 1;
                cnt = 1;
            }
        }
        resGroup[idx] = cnt;
        int dif = M - idx;
        for (int i = 1; i <= idx ; i++) {
            if(resGroup[i] == 1)    bw.write("1 ");
            else{
                while(resGroup[i] >= 2 && dif >= 1){
                    bw.write("1 ");
                    resGroup[i]--;
                    dif--;
                }
                bw.write(resGroup[i] + " ");
            }
        }
        bw.flush();
        bw.close();
    }
    public static boolean com(int mid){

        int sum = 0;
        int group = 1;

        for (int i = 0; i < N ; i++) {
            if(ball[i] > mid)
                return false;

            sum += ball[i];

            if(sum > mid){
                sum = ball[i];
                group++;
            }
        }
        if(group > M)
            return false;
        else
            return true;
    }
}