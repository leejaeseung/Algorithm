/*
문제
KOI 준비를 위해 회의를 개최하려 한다. 주최측에서는 회의에 참석하는 사람의 수와 참석자들 사이의 관계를 따져 하나 이상의 위원회를 구성하려고 한다. 위원회를 구성하는 방식은 다음과 같다.

서로 알고 있는 사람은 반드시 같은 위원회에 속해야 한다.
효율적인 회의 진행을 위해 위원회의 수는 최대가 되어야 한다.
이런 방식으로 위원회를 구성한 후에 각 위원회의 대표를 한 명씩 뽑아야 한다. 각 위원회의 대표만이 회의 시간 중 발언권을 가지며, 따라서 회의 참석자들이 자신의 의견을 말하기 위해서는 자신이 속한 위원회의 대표에게 자신의 의견을 전달해야 한다. 그런데 각 참석자는 자신이 알고 있는 사람에게만 의견을 전달할 수 있어 대표에게 의견을 전달하기 위해서는 때로 여러 사람을 거쳐야 한다. 대표에게 의견을 전달하는 경로가 여러 개 있을 경우에는 가장 적은 사람을 거치는 경로로 의견을 전달하며 이때 거치는 사람의 수를 참석자의 의사전달시간이라고 한다.

위원회에서 모든 참석자들의 의사전달시간 중 최댓값이 최소가 되도록 대표를 정하는 프로그램을 작성하시오.

예를 들어 1번, 2번, 3번 세 사람으로 구성되어 있는 위원회에서 1번과 2번, 2번과 3번이 서로 알고 있다고 하자. 1번이 대표가 되면 3번이 대표인 1번에게 의견을 전달하기 위해서 2번을 거쳐야만 한다. 반대로 3번이 대표가 되어도 1번이 대표인 3번에게 의견을 전달하려면 2번을 거쳐야만 한다. 하지만 2번이 대표가 되면 1번과 3번 둘 다 아무도 거치지 않고 대표에게 직접 의견을 전달 할 수 있다. 따라서 이와 같은 경우 2번이 대표가 되어야 한다.

입력
첫째 중에 회의에 참석하는 사람의 수 N이 주어진다. 참석자들은 1부터 N까지의 자연수로 표현되며 회의에 참석하는 인원은 100 이하이다. 둘째 줄에는 서로 알고 있는 관계의 수 M이 주어진다. 이어 M개의 각 줄에는 서로 아는 사이인 참석자를 나타내는 두개의 자연수가 주어진다.

출력
첫째 줄에는 구성되는 위원회의 수 K를 출력한다. 다음 K줄에는 각 위원회의 대표 번호를 작은 수부터 차례로 한 줄에 하나씩 출력한다. 한 위원회의 대표가 될 수 있는 사람이 둘 이상일 경우 그중 한 명만 출력하면 된다.

풀이:
플로이드 와샬 문제였지만 BFS 로 풀이함.
모든 사람에 대해 BFS를 해가며 cnt가 가장 적은 사람을 대표로 뽑고, 이미 BFS한 사람은 조를 다시 배정하지 않음.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N, group_num = 0;
    public static ArrayList<node> people;
    public static int group[];
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());
        people = new ArrayList<>();
        group = new int[N + 1];
        int[] min = new int[N + 1];
        int[] res = new int[N + 1];

        for (int i = 0; i <= N ; i++) {
            people.add(new node(i));
            min[i] = Integer.MAX_VALUE;
            res[i] = Integer.MAX_VALUE;
        }

        for (int i = 0; i < M ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            people.get(from).next.add(people.get(to));
            people.get(to).next.add(people.get(from));
        }
        for (int i = 1; i <= N ; i++) {
            int min_cnt = BFS(i);
            if(min[group[i]] > min_cnt){
                min[group[i]] = min_cnt;
                res[group[i]] = i;
            }
        }
        Arrays.sort(res);

        bw.write(group_num + "\n");
        for (int i = 0; i < group_num ; i++) {
            bw.write(res[i] + "\n");
        }
        bw.flush();
        bw.close();
    }
    public static int BFS(int start){
        Queue<node> q = new LinkedList<>();
        boolean[] visit = new boolean[N + 1];
        q.offer(people.get(start));
        visit[start] = true;
        int cnt = -1;

        if(group[people.get(start).num] == 0)
            group_num++;

        while (!q.isEmpty()){
            int size = q.size();
            cnt++;

            for (int i = 0; i < size ; i++) {
                node now = q.poll();

                if(group[now.num] == 0)
                    group[now.num] = group_num;

                for (int j = 0; j < now.next.size(); j++) {
                    node next = now.next.get(j);

                    if (!visit[next.num]) {
                        visit[next.num] = true;
                        q.offer(next);
                    }
                }
            }
        }
        return cnt;
    }
}

class node{
    int num;
    ArrayList<node> next;
    public node(int num){
        this.num = num;
        next = new ArrayList<>();
    }
}