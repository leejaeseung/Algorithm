/*
문제
때는 2119년, 정명이는 드디어 타임머신을 개발했다. 흙수저였던 지훈이는 타임머신을 이용해 100년 전으로 돌아가서 가상화페인 주홍코인을 통해 비루한 인생을 바꿔보기로 굳게 마음을 먹는다. 그에게는 할아버지 때부터 대대로 전해 내려오는 주홍코인의 가격 변동 차트가 있기 때문에 금수저 인생은 따 놓은 당상이다.
다만, 타임머신이 아직 완벽하지 않기에 제한 시간이 지나면 다시 현재 시점으로 돌아오게 된다. 또한 주홍코인은 거래소의 규제로 인해 거래를 하는데 다음과 같은 제약이 있다.

주홍코인의 구매는 매 분마다 1개만 가능하다.
주홍코인의 판매는 몇 개든 할 수 있다.
모든 거래에 대한 수수료는 발생하지 않는다.
물론 구매도 판매도 하지 않고 그냥 시간을 보낼 수도 있다. 정명이는 가격 변동 차트를 갖고 있기 때문에 앞으로 가격이 어떻게 변할지 모두 알고 있는 셈이다. 정명이가 과거로 돌아가서 주홍코인 거래를 통해 얻을 수 있는 최대의 수익이 얼마일지 구해보자.

입력
첫 번째 줄에 타임머신의 제한 시간 N분이 정수로 주어진다. (1 ≤ N ≤ 105)

두 번째 줄에 매 분마다의 주홍코인 가격이 공백으로 구분되어 N개 주어진다. 주홍코인의 가격은 1,000 이하의 자연수이다.

출력
첫 번째 줄에 정명이가 주홍코인 거래를 통해 얻을 수 있는 최대의 수익을 출력한다.

풀이:
우선순위 큐에 최대 가격과 그 시간을 집어넣는다.(가격이 같다면 빠른 시간 순서로 넣어야 한다.)
최대 가격을 발견하면 현재까지의 코인을 모두 팔고 다음 최대값으로 갱신한다.
최대값을 갱신할 때, 이미 지난 시간이라면 제외시켜야 한다.
 */
import java.io.*;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main15 {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] price = new int[N];

        PriorityQueue<tuple> pq = new PriorityQueue<>(new Comparator<tuple>() {
            @Override
            public int compare(tuple o1, tuple o2) {
                if(o1.price < o2.price)
                    return 1;
                else if( o1.price > o2.price)
                    return -1;
                else{
                    return o1.minute >= o2.minute ? 1 : -1;
                }
            }
        });

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N ; i++) {
            price[i] = Integer.parseInt(st.nextToken());
            pq.offer(new tuple(i, price[i]));
        }

        int now = 0;
        tuple nowMax = pq.poll();

        long sum = 0;
        int coin = 0;

        for (int i = 0; i < N ; i++) {
            now = price[i];
            coin++;
            sum -= now;

            if (now == nowMax.price) {
                sum += coin * now;
                coin = 0;
                while(!pq.isEmpty() && pq.peek().minute < i){
                    pq.poll();
                }
                if(!pq.isEmpty())
                    nowMax = pq.poll();
            }
        }
        for (int i = N - 1; i >= N - coin  ; i--) {
            sum += price[i];
        }
        System.out.println(sum);
    }
}

class tuple{
    int minute;
    int price;
    public tuple(int minute, int price){
        this.minute = minute;
        this.price = price;
    }
}