/*
문제
모험가 x|최강영훈|x 은 온라인 RPG 게임 월드 아트 위그드라실(WAY)에서 활동중인 랭커이다.

x|최강영훈|x 은 매일 WAY의 퀘스트를 달성하는것에 재미를 느끼고 있다.

WAY에는 -10억부터 10억까지의 모든 정수 번호에 대해 퀘스트가 하나씩 부여되어 있다. 또한 특정 범위의 퀘스트를 모두 달성하면 업적을 받을 수 있다.

x|최강영훈|x 은 퀘스트를 달성하는 김에 업적도 얻고 싶었다. 하지만 WAY에는 항상 퀘스트를 순서대로 달성할 수 없는 경우가 존재해서 업적마다 몇 개의 퀘스트를 더 달성해야하는지 매번 계산해야 하는 불편함이 존재했다.

이를 안타깝게 여긴 모험가 사투-는 특정 범위의 퀘스트 중 모험가가 달성하지 못한 퀘스트의 개수를 출력하는 애드온을 개발하기로 했다.

물론 언제나 그렇듯, 구현은 당신이 해야 한다.

입력
첫째 줄에 지금까지 달성한 퀘스트의 개수 N이 주어진다. (1 ≤ N ≤ 1,000,000)

둘째 줄에 지금까지 달성한 퀘스트들의 번호 Q1 ... QN 까지의 N개의 수가 주어진다. (−1,000,000,000 ≤ Q[i] ≤ 1,000,000,000, Q[i] < Q[i+1])

셋째 줄에 애드온 요청의 개수 M이 주어진다. (1 ≤ M ≤ 1,000,000)

넷째 줄부터 M개의 줄에 걸쳐서 애드온에 요청할 명령이 주어진다.

1 X:  퀘스트 번호 X를 달성했다. 애드온에 이를 반영해야 한다. (−1,000,000,000 ≤ X ≤ 1,000,000,000)
2 L R: 퀘스트 번호 L 이상 R 이하인 퀘스트 중, 모험가가 달성하지 못한 퀘스트의 개수를 출력한다. (−1,000,000,000 ≤ L ≤ R ≤ 1,000,000,000)
출력
애드온 기능2에 해당하는 출력을 요청당 한 줄씩 출력한다.

풀이:
좌표압축 + 세그먼트 트리 + 오프라인 쿼리 문제입니다.
퀘스트의 번호가 -10억 ~ 10억이지만 퀘스트의 총 개수는 백만을 넘지 않으므로 모든 쿼리를 먼저 입력받아 사용될 퀘스트들만
따로 리스트에 담아 정렬해줍니다.(오름차순)
리스트의 인덱스를 퀘스트 번호로 사용하여 구간합 세그먼트 트리를 구성합니다.(퀘스트를 완료했으면 1, 아니라면 0입니다.)
2번 질문에 대한 답을 구할 때 lowerBound로 L 에 가장 가까운 인덱스, upperBound로 R에 가장 가까운 인덱스를 찾아 구간합을 구합니다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N, Q;
    public static int[] tree;
    public static ArrayList<Integer> quest = new ArrayList<>();
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        Queue<String> query = new LinkedList<>();
        query.offer(br.readLine());
        st = new StringTokenizer(query.peek());

        for (int i = 0; i < N ; i++) {
            int Qu = Integer.parseInt(st.nextToken());
            quest.add(Qu);
        }
        Q = Integer.parseInt(br.readLine());
        for (int i = 0; i < Q ; i++) {
            String que = br.readLine();
            query.offer(que);
            st = new StringTokenizer(que);
            int o = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            if(o == 1){
                    quest.add(x);
            }
        }
        Collections.sort(quest);

        double H = Math.ceil(Math.log(quest.size()) / Math.log(2));
        tree = new int[(int)Math.pow(2, H + 1)];

        st = new StringTokenizer(query.poll());
        for (int i = 0; i < N ; i++) {
            int Qu = Integer.parseInt(st.nextToken());
            update(1, 0, quest.size() - 1, getIdx(Qu));
        }
        while(!query.isEmpty()){
            st = new StringTokenizer(query.poll());
            int o = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());

            if(o == 1){
                update(1, 0, quest.size() - 1, getIdx(x));
            }
            else{
                int y = Integer.parseInt(st.nextToken());
                int res = y - x + 1;

                bw.write((res - getSum(1, 0, quest.size() - 1, getIdx(x), getIdx_u(y))) + "\n");
            }
        }
        bw.flush();
        bw.close();
    }
    public static int getIdx(int v){
        return lowerBound(0, quest.size(), v);
    }
    public static int getIdx_u(int v){
        return upperBound(0, quest.size(), v) - 1;
    }
    public static int upperBound(int s, int e, int v){
        while(s < e){
            int mid = (s + e) / 2;
            if(quest.get(mid) > v)
                e = mid;
            else
                s = mid + 1;
        }
        return s;
    }
    public static int lowerBound(int s, int e, int v){
        while(s < e){
            int mid = (s + e) / 2;
            if(quest.get(mid) >= v)
                e = mid;
            else
                s = mid + 1;
        }
        return s;
    }
    public static int update(int now, int left, int right, int idx){
        if(idx < left || idx > right)   return tree[now];
        if(left == right)
            return tree[now] = 1;

        return tree[now] = update(now * 2, left, (left + right) / 2, idx) +  update(now * 2 + 1, (left + right) / 2 + 1, right, idx);
    }
    public static int getSum(int now, int left, int right, int start, int end){
        if(left > end || right < start) return 0;
        if(left >= start && right <= end)   return tree[now];

        return getSum(now * 2, left, (left + right) / 2 , start, end) + getSum(now * 2 + 1, (left + right) / 2 + 1, right , start, end);
    }
}

