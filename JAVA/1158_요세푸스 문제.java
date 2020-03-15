/*
문제
요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000)

출력
예제와 같이 요세푸스 순열을 출력한다.

풀이:
링크드리스트를 사용해 인덱스에 해당하는 원소를 제거해가며 풀이.
 */
import java.io.*;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        LinkedList<Integer> people = new LinkedList<>();

        for (int i = 1; i <= N ; i++) {
            people.add(i);
        }
        int turn = K - 1;

        bw.write("<");
        while(people.size() != 0){
            if(people.size() != 1)
                bw.write(people.get(turn % people.size()) + ", ");
            else
                bw.write(people.get(turn % people.size()) + ">");
            people.remove(turn = turn % people.size());

            turn = turn + K - 1;
        }
        bw.flush();
        bw.close();
    }
}