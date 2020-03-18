/*
문제
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 버스가 M개 있다. 각 버스는 A, B, C로 나타낼 수 있는데, A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간이다. 시간 C가 양수가 아닌 경우가 있다. C = 0인 경우는 순간 이동을 하는 경우, C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우이다.

1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 도시의 개수 N (1 ≤ N ≤ 500), 버스 노선의 개수 M (1 ≤ M ≤ 6,000)이 주어진다. 둘째 줄부터 M개의 줄에는 버스 노선의 정보 A, B, C (1 ≤ A, B ≤ N, -10,000 ≤ C ≤ 10,000)가 주어진다.

출력
만약 1번 도시에서 출발해 어떤 도시로 가는 과정에서 시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 -1을 출력한다. 그렇지 않다면 N-1개 줄에 걸쳐 각 줄에 1번 도시에서 출발해 2번 도시, 3번 도시, ..., N번 도시로 가는 가장 빠른 시간을 순서대로 출력한다. 만약 해당 도시로 가는 경로가 없다면 대신 -1을 출력한다.

풀이:
벨만 포드 기본 문제입니다.
 */
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static int N, M;
    public static ArrayList<ArrayList<tuple>> list;
    public static int[] dist;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        list = new ArrayList<>();
        dist = new int[N + 1];
        for (int i = 0; i <= N ; i++) {
            list.add(new ArrayList<>());
            dist[i] = 1000000000;
        }

        for (int i = 0; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            list.get(from).add(new tuple(to, d));
        }

        if(BellmanFord(1)){
            for (int i = 2; i <= N ; i++) {
                if(dist[i] != 1000000000)
                    bw.write(dist[i] + "\n");
                else
                    bw.write(-1 + "\n");
            }
        }
        else
            bw.write(Integer.toString(-1));
        bw.flush();
        bw.close();
    }
    public static boolean BellmanFord(int start){
        dist[start] = 0;
        boolean updated = false;

        for (int k = 1; k <= N ; k++) {
            updated = false;
            for (int i = 1; i <= N ; i++) {
                //i 가 도달할 수 없는 점이므로 간선을 무시한다.
                if(dist[i] == 1000000000)
                    continue;
                for (int j = 0; j < list.get(i).size(); j++) {
                    int next = list.get(i).get(j).first;
                    int distNext = list.get(i).get(j).second;
                    if (dist[next] > dist[i] + distNext) {
                        updated = true;
                        dist[next] = dist[i] + distNext;
                    }
                }
            }
            if(!updated)    break;
        }
        if(updated) return false;
            return true;
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