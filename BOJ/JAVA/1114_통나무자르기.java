/*
문제
벌목꾼 백은진은 나무를 종이 공장에 옮겨야 한다. 하지만, 통나무의 길이가 너무 길어서 트럭에 들어가지 않으므로, 여러개의 조각으로 나눠야 한다.

통나무의 길이는 L cm이다. 그리고 통나무의 특정한 위치에서만 자를 수 있다. 통나무를 자를 수 있는 위치가 주어지고, 이때 이 위치는 통나무의 가장 왼쪽에서부터 떨어진 거리이다. 백은진은 많아야 C번 통나무를 자를 수 있다.

이때, 통나무의 가장 긴 조각을 작게 만드는 프로그램을 작성하시오.


입력
첫째 줄에 L, K와 C가 주어진다. L은1,000,000,000보다 작거나 같은 자연수이고, K는 통나무를 자를 수 있는 위치의 개수이다. K와 C는 10,000보다 작거나 같은 자연수이다. 둘째 줄에 통나무를 자를 수 있는 위치가 주어진다.

출력
첫째 줄에 두 개의 수를 출력한다. 첫 번째 수는 가장 긴 조각의 길이이고, 두 번째 수는 그 때 처음 자르는 위치를 출력한다. 만약 가능한 것이 여러 가지라면, 처음 자르는 위치가 작은 것을 출력한다.

풀이:
파라매트릭 서치 문제입니다.
이분 탐색으로 가장 긴 나무 조각의 길이를 줄여가며 찾습니다.
오른쪽 끝부터 나무를 잘라가면 마지막에 자른 곳이 가장 짧은 처음 자른 곳입니다.
만약 횟수가 남았다면 list[1](왼쪽에서 가장 가까운 곳)이 답이 됩니다.
 */
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static int L, K, C;
    public static int[] list;
    public static int res_pos = 0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        L = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        list = new int[K + 2];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= K ; i++) {
            list[i] = Integer.parseInt(st.nextToken());
        }
        list[0] = 0;
        list[list.length - 1] = L;
        Arrays.sort(list);

        int s = 0;
        int e = L;
        int res = 0;

            while (s < e) {
                int mid = (s + e) / 2;

                if(search(mid)){
                    e = mid;
                    res = mid;
                }
                else{
                    s = mid + 1;
                }
            }
            System.out.println(res + " " + res_pos);
    }
    public static boolean search(int leng){

        int i;
        int cnt = 0;
        int diff = 0;
        int cut = 0;

        for (i = K + 1; i >= 1  ; i--) {
            diff += list[i] - list[i - 1];
            if(diff > leng){
                //차이값이 나무조각의 길이보다 커지면 자른다.
                cut = list[i];
                cnt++;
                diff = list[i] - list[i - 1];
                if(diff > leng){
                    //자른 조각이 나무조각의 길이보다 길면 false
                    return false;
                }
            }
        }
        if(cnt <= C) {
            if(cnt < C){
                res_pos = list[1];
            }
            else
                res_pos = cut;
            return true;
        }
        return false;
    }
}