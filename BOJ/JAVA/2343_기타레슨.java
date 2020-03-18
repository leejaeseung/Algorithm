/*
문제
강토는 자신의 기타 레슨 동영상을 블루레이로 만들어 판매하려고 한다. 블루레이에는 총 N개의 레슨이 들어가는데, 블루레이를 녹화할 때, 레슨의 순서가 바뀌면 안 된다. 순서가 뒤바뀌는 경우에는 레슨의 흐름이 끊겨, 학생들이 대혼란에 빠질 수 있기 때문이다. 즉, i번 레슨과 j번 레슨을 같은 블루레이에 녹화하려면 i와 j 사이의 모든 레슨도 같은 블루레이에 녹화해야 한다.

강토는 이 블루레이가 얼마나 팔릴지 아직 알 수 없기 때문에, 블루레이의 개수를 가급적 줄이려고 한다. 오랜 고민 끝에 강토는 M개의 블루레이에 모든 기타 레슨 동영상을 녹화하기로 했다. 이때, 블루레이의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 단, M개의 블루레이는 모두 같은 크기이어야 한다.

강토의 각 레슨의 길이가 분 단위(자연수)로 주어진다. 이때, 가능한 블루레이의 크기 중 최소를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 레슨의 수 N (1 ≤ N ≤ 100,000)과 M (1 ≤ M ≤ N)이 주어진다. 다음 줄에는 강토의 기타 레슨의 길이가 레슨 순서대로 분 단위로(자연수)로 주어진다. 각 레슨의 길이는 10,000분을 넘지 않는다.

출력
첫째 줄에 가능한 블루레이 크기중 최소를 출력한다.

풀이:
이진 탐색을 응용한 parametric search이다.
배열 값을 보고 이진 탐색하는게 아닌, 구하고자 하는 값(최소 길이)를 보고 이진 탐색한다.
이 문제에선 총 레슨 길이를 절반으로 잘라가며 그 레슨길이를 만족시키기 위해 몇 그룹으로 나눌 수 있는지 센 후,
M 보다 나눠진 그룹 수가 많으면 false 이다.(비교값mid를 늘려가며 그룹을 줄인다.)
 */

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static int N,M;
    public static int[] lesson;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        lesson = new int[N];

        int sum = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N ; i++) {
            lesson[i] = Integer.parseInt(st.nextToken());
            sum += lesson[i];
        }
        int left = 1;
        int right = sum;
        int res = 0;
        while(left <= right){
            int mid = (left + right) / 2;

            if(com(mid)){
                res = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        System.out.println(res);
    }
    public static boolean com(int mid){

        int sum = 0;

        int group = 1;

        for (int i = 0; i < N ; i++) {
            if(lesson[i] > mid)
                return false;

            sum += lesson[i];
            if(sum > mid){
                group++;
                sum = lesson[i];
            }
        }
        if(group <= M)
            return true;
        else
            return false;
    }
}