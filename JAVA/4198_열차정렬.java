/*
문제
에린은 엔지니어이자, 기차를 운전하는 기관사입니다. 또한 그녀는 각 열차를 구성하는 차량을 배열하는 일도 합니다. 그녀는 차량들을 정렬할 때, 열차의 전면에 가장 무거운 차량을 놓고, 후미로 갈수록 중량이 감소하는 순서로 차량을 넣는 것을 좋아합니다.

불행하게도, 차량을 배열하는 일은 쉽지 않습니다. 기존에 구성된 열차에 다른 차량을 끼워넣는 일은 비실용적이어서 하지 않기에, 한 차량은 오로지 열차의 전면 혹은 후미에만 추가하는 것이 가능합니다.

차량들은 미리 준비된 순서에 따라 역에 도착합니다. 에린은 각 차량이 기차역에 도착할 때, 전면 혹은 후미에 차량을 추가하거나, 차량을 열차에 추가하는 것을 거부할 수 있습니다. 에린이 최종적으로 만든 열차는 가능한 길어야(많은 차량으로 구성되어야)하지만, 그 과정에서 열차는 에린이 배열하고자하는 정렬 순서에 맞아야 합니다.

각 차량이 역에 도착하는 순서대로 차량들의 중량이 주어질 때, 에린이 만들 수 있는 가장 긴 열차배열의 길이(=차량의 수)는 얼마입니까?

입력
첫째 줄에 차량의 수를 나타내는 N (0 <= N <= 2000)이 주어집니다. 이후 N개의 각 줄에는 음이 아닌 차량의 무게가 주어집니다. (단, 서로 다른 두 차량의 무게가 같은 일은 발생하지 않습니다.)

출력
에린이 만들 수 있는 가장 긴 열차의 길이를 출력하세요.

풀이:
감소 부분 수열(lds)와 증가 부분 수열(lis)를 합친 문제이다.
특정 인덱스를 기준으로 lis, lds 를 구해 lis + lds - 1 한 것 중 최대값이 답이 된다.(자기 자신은 중복되므로 -1)
기준으로 잡은 원소는 고정되므로 다음 것부터 수열을 구하는데, 기준 원소보다 크거나 작은(lds인지 lis인지에 따라) 값이 나오면
모순이므로 수열을 구할 때 걸러주어야 한다.
 */
import java.io.*;
import java.util.ArrayList;

public class Main {

    public static int N;
    public static int[] value;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        value = new int[N];

        for (int i = 0; i < N ; i++) {
            value[i] = Integer.parseInt(br.readLine());
        }

        int res = 0;
        for (int i = 0; i < N ; i++) {
            int lis = lis(i);
            int lds = lds(i);

            res = Math.max(res, lis + lds - 1);
        }

        System.out.println(res);
    }
    public static int lis(int start){
        ArrayList<Integer> dp = new ArrayList<>();
        dp.add(value[start]);

        int i;
        for (i = start + 1; i < N ; i++) {
            if(value[start] < value[i]){
              dp.add(value[i]);
              i++;
              break;
            }
        }
        for (; i < N ; i++) {
            if(value[start] >  value[i])  continue;
            //기준 원소보다 작은 값은 모순이므로 걸러준다.

            if (dp.get(dp.size() - 1) >= value[i])
                lowerBound(dp, 1, dp.size(), value[i]);
            else
                dp.add(value[i]);
        }
        return dp.size();
    }
    public static int lds(int start){
        ArrayList<Integer> dp = new ArrayList<>();
        dp.add(value[start]);

        int i;
        for (i = start + 1; i < N ; i++) {
            if(value[start] > value[i]){
                dp.add(value[i]);
                i++;
                break;
            }
        }
        for (; i < N ; i++) {
            if(value[start] <  value[i])  continue;
            //기준 원소보다 큰 값은 보순이므로 걸러준다.

            if (dp.get(dp.size() - 1) <= value[i])
                highBound(dp, 1, dp.size(), value[i]);
            else
                dp.add(value[i]);
        }
        return dp.size();
    }

    public static void lowerBound(ArrayList<Integer> list, int s, int e, int v){
        while(s < e){
            int mid = (s + e) / 2;
            if(list.get(mid) >= v)
                e = mid;
            else
                s = mid + 1;
        }
        list.set(s, v);
    }
    public static void highBound(ArrayList<Integer> list, int s, int e, int v){
        while(s < e){
            int mid = (s + e) / 2;
            if(list.get(mid) <= v)
                e = mid;
            else
                s = mid + 1;
        }
        list.set(s, v);
    }
}