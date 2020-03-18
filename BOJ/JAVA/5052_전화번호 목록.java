/*
문제
전화번호 목록이 주어진다. 이때, 이 목록이 일관성이 있는지 없는지를 구하는 프로그램을 작성하시오.

전화번호 목록이 일관성을 유지하려면, 한 번호가 다른 번호의 접두어인 경우가 없어야 한다.

예를 들어, 전화번호 목록이 아래와 같은 경우를 생각해보자

긴급전화: 911
상근: 97 625 999
선영: 91 12 54 26
이 경우에 선영이에게 전화를 걸 수 있는 방법이 없다. 전화기를 들고 선영이 번호의 처음 세 자리를 누르는 순간 바로 긴급전화가 걸리기 때문이다. 따라서, 이 목록은 일관성이 없는 목록이다.

입력
첫째 줄에 테스트 케이스의 개수 t가 주어진다. (1 ≤ t ≤ 50) 각 테스트 케이스의 첫째 줄에는 전화번호의 수 n이 주어진다. (1 ≤ n ≤ 10000) 다음 n개의 줄에는 목록에 포함되어 있는 전화번호가 하나씩 주어진다. 전화번호의 길이는 길어야 10자리이며, 목록에 있는 두 전화번호가 같은 경우는 없다.

출력
각 테스트 케이스에 대해서, 일관성 있는 목록인 경우에는 YES, 아닌 경우에는 NO를 출력한다.

풀이:
트라이 알고리즘 연습문제
각 문자열을 순서대로 트리형태로 집어넣고, 문자열의 끝마다 leaf노드를 표시한다.
문자열의 끝인데 다음 문자가 존재하거나 문자열이 아직 더 남았는데 leaf노드라면 일관성이 없다.
 */
import java.io.*;

public class Main {

    public static boolean flag;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T ; i++) {
            int N = Integer.parseInt(br.readLine());
            node root = new node("");
            flag = true;

            for (int j = 0; j < N ; j++) {
                String str = br.readLine();
                if(flag)
                    insert(root, str, 0);
            }
            if(flag)
                bw.write("YES\n");
            else
                bw.write("NO\n");
        }
        bw.flush();
        bw.close();
    }
    public static void insert(node nowNode, String str, int idx){
        if(idx >= str.length()) {
            for (int i = 0; i < 10 ; i++) {
                if(nowNode.next[i] != null) {
                    flag = false;
                    break;
                }
            }
            nowNode.isleaf = true;
            return;
        }
        int nowC = str.charAt(idx) - '0';
        if(nowNode.next[nowC] != null){        //이미 있으면
            if(nowNode.next[nowC].isleaf) {
                flag = false;
                return;
            }
            insert(nowNode.next[nowC], str, idx + 1);
        }
        else{
            nowNode.next[nowC] = new node(nowNode.name + str.charAt(idx));
            insert(nowNode.next[nowC], str, idx + 1);
        }
    }
}

class node{
    String name;
    boolean isleaf = false;
    node[] next = new node[10];
    public node(String name){
        this.name = name;
    }
}