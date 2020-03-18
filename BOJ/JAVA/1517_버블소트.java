/*
문제
N개의 수로 이루어진 수열 A[1], A[2], …, A[N]이 있다. 이 수열에 대해서 버블 소트를 수행할 때, Swap이 총 몇 번 발생하는지 알아내는 프로그램을 작성하시오.

버블 소트는 서로 인접해 있는 두 수를 바꿔가며 정렬하는 방법이다. 예를 들어 수열이 3 2 1 이었다고 하자. 이 경우에는 인접해 있는 3, 2가 바뀌어야 하므로 2 3 1 이 된다. 다음으로는 3, 1이 바뀌어야 하므로 2 1 3 이 된다. 다음에는 2, 1이 바뀌어야 하므로 1 2 3 이 된다. 그러면 더 이상 바꿔야 할 경우가 없으므로 정렬이 완료된다.

입력
첫째 줄에 N(1≤N≤500,000)이 주어진다. 다음 줄에는 N개의 정수로 A[1], A[2], …, A[N]이 주어진다. 각각의 A[i]는 0≤|A[i]|≤1,000,000,000의 범위에 들어있다.

출력
첫째 줄에 Swap 횟수를 출력한다

풀이:
merge sort 를 이용해 swap 횟수를 구합니다.
버블 정렬에서 swap 의 조건은 왼쪽에 오른쪽 수보다 큰 값이 있을 때입니다.
따라서 오른쪽 배열이 왼쪽 값보다 더 작은 경우, 왼쪽의 큰 값들만큼 swap이 발생합니다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N;
    public static int[] list;
    public static int[] ret;
    public static long cnt = 0;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        ret = new int[N];
        list = new int[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N ; i++) {
            list[i] = Integer.parseInt(st.nextToken());
        }
        mergeSort(0, list.length - 1);
        System.out.println(cnt);
    }
    public static void mergeSort(int s, int e){
        if(s < e){
            int mid = (s + e) / 2;
            mergeSort(s, mid);
            mergeSort(mid + 1, e);
            merge(s, e, mid);
        }
    }
    public static void merge(int s, int e, int mid){
        int lIndex = s;
        int rIndex = mid + 1;
        int retIndex = s;

        while(lIndex != mid + 1 && rIndex != e + 1){
            int left_v = list[lIndex];
            int right_v = list[rIndex];

            if(left_v <= right_v){
                ret[retIndex++] = left_v;
                lIndex++;
            }
            else{
                cnt += mid - lIndex + 1;
                ret[retIndex++] = right_v;
                rIndex++;
            }
        }
        while(lIndex != mid + 1) {
            ret[retIndex++] = list[lIndex++];
        }
        while(rIndex != e + 1) {
            ret[retIndex++] = list[rIndex++];
        }

        for (int i = s; i <= e ; i++) {
            list[i] = ret[i];
        }
    }
}