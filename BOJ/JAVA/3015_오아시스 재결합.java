/*
문제
오아시스의 재결합 공연에 N명이 한 줄로 서서 기다리고 있다.

이 역사적인 순간을 맞이하기 위해 줄에서서 기다리고 있던 백준이는 갑자기 자기가 볼 수 있는 사람의 수가 궁금해 졌다.

두 사람 A와 B가 서로 볼 수 있으려면, 두 사람 사이에 A 또는 B보다 키가 큰 사람이 없어야 한다.

줄에 서있는 사람의 키가 주어졌을 때, 서로 볼 수 있는 쌍의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 줄에서 기다리고 있는 사람의 수 N이 주어진다. (1 ≤ N ≤ 500,000)

둘째 줄부터 N개의 줄에는 각 사람의 키가 나노미터 단위로 주어진다. 모든 사람의 키는 231 나노미터 보다 작다.

사람들이 서 있는 순서대로 입력이 주어진다.

출력
서로 볼 수 있는 쌍의 수를 출력한다.

풀이:
다음 사람(next)을 스택의 top과 비교해가며 카운트해주는데, 다음과 같은 방식으로 스택을 조정한다.
1. next < stack.top --> 카운트만 1 증가시킨다.(top과 next만 마주보는 경우밖에 없다.)
2. next >= stack.top --> 스택에서 next보다 작거나 같은 값은 모두 pop해주면서 카운트한다.(next보다 작은 값은 다른 사람과 마주 볼 기회가 더이상 없다.즉, 필요없는 값이므로 제거한다.)
2.1 next > stack.top 이 될때까지 스택을 pop해주는데, next == stack.top인 경우를 카운트 해준다.(키가 같은 사람은 스택에 남아있어야 한다.)
2.2 현재 스택은 stack.top보다 키가 작은 사람은 모두 없어진 상태인데, next와 키가 같은 사람들을 모두 스택에 push 해준다.(시간 초과 발생)

위 방식대로 하면 키가 같은 사람들이 많을 때 스택에 다시 push하는 부분에서 시간 초과가 난다.
따라서 스택에 값을 넣을 때 같은 키라면 사람의 수만 증가시켜준다.(Run-length coding 식으로)


 */
import java.io.*;
import java.util.Stack;

public class Main {

    public static void main(String[] argc) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Stack<tuple> stack = new Stack<>();

        int N = Integer.parseInt(br.readLine());
        stack.push(new tuple(Integer.parseInt(br.readLine()), 1));

        long cnt = 0;
        for (int i = 0; i < N - 1 ; i++) {
            int next = Integer.parseInt(br.readLine());
            tuple temp = null;

            if(stack.peek().tall <= next){
                while(!stack.isEmpty()){
                    if(stack.peek().tall < next){
                        cnt += stack.pop().same_cnt;
                    }
                    else if(stack.peek().tall == next){
                        temp = stack.pop();
                        cnt += temp.same_cnt;
                    }
                    else {
                        cnt++;
                        break;
                    }
                }
            }
            else{
                cnt++;
            }
            if(temp != null){
                temp.same_cnt++;
                stack.push(temp);
            }
            else
                stack.push(new tuple(next, 1));
        }

        bw.write(Long.toString(cnt));
        bw.flush();
        bw.close();
    }
}

class tuple{
    int tall;
    int same_cnt;
    public tuple(int tall, int same_cnt){
        this.tall = tall;
        this.same_cnt = same_cnt;
    }
}
