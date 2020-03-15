/*
문제
One day, da Vinci found his workspace piled with completed paintings, making it difficult to move around. He then sent out his favorite student, Francesco Melzi, to sell one of these artworks. Da Vinci decided to determine the price in a quite simple way: he firstly assigned a price to each possible property (style, subject, season, weather, etc.), then named several properties of the painting to sell, and set the price of it to be the sum of prices of these properties. After that, da Vinci told Francesco Melzi the assignment of prices and the properties of that painting.

When Francesco set out to sell the artwork, he forgot some of its properties but memorized the price of each property very well. He wondered according to the information he remembered, what would the painting’s minimum and maximum possible price be?

입력
The first line contains a number 1 ≤ K ≤ 10, which is the number of input data sets in the file. This is followed by K data sets of the following form:

The first line of a data set contains two integers n, m with 1 ≤ m ≤ n ≤ 100: n is the number of all possible properties, and m is the number of properties of the artwork to sell. This is followed by n lines, each with a string si and an integer 0 ≤ ci ≤ 10000 separated by space, where si is the name of the i-th property and ci is the price assigned to it. si is a non-empty string consisting of at most 80 lowercase letters. All si’s are unique, but ci’s are not necessarily unique.

Next is a line containing m strings pj separated by space: the properties this artwork has. If pj is ?, then it is an unknown property, otherwise pj would be one of the properties si. No known property will appear twice.

출력
For each data set, first output “Data Set x:” on a line by itself, where x is its number.

Then, output the minimum and maximum possible price of the artwork on a single line.

Each data set should be followed by a blank line.

풀이:
주의할 점 : 질문을 먼저 받아놓고, 오프라인으로 풀이한다. ? 가 아닌 단어들을 먼저 처리해줘야 하기 때문.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int N,M;
    public static ArrayList<tuple> wordMin;
    public static ArrayList<tuple> wordMax;

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());

        for (int i = 0; i < K ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            wordMin = new ArrayList<>();
            wordMax = new ArrayList<>();

            for (int j = 0; j < N ; j++) {
                st = new StringTokenizer(br.readLine());
                String s = st.nextToken();
                int c = Integer.parseInt(st.nextToken());

                wordMin.add(new tuple(s, c));
                wordMax.add(new tuple(s, c));
            }
            wordMin.sort(new Comparator<tuple>() {
                @Override
                public int compare(tuple tuple, tuple t1) {
                    if(tuple.cost > t1.cost)
                        return 1;
                    else if(tuple.cost < t1.cost)
                        return -1;
                    else{
                        if(tuple.s.compareTo(t1.s) > 0)
                            return 1;
                        else
                            return -1;
                    }
                }
            });
            wordMax.sort(new Comparator<tuple>() {
                @Override
                public int compare(tuple tuple, tuple t1) {
                    if(tuple.cost < t1.cost)
                        return 1;
                    else if(tuple.cost > t1.cost)
                        return -1;
                    else{
                        if(tuple.s.compareTo(t1.s) > 0)
                            return 1;
                        else
                            return -1;
                    }
                }
            });
            st = new StringTokenizer(br.readLine());

            int min = 0;
            int max = 0;

            PriorityQueue<String> query = new PriorityQueue<>(new Comparator<String>() {
                @Override
                public int compare(String s, String t1) {
                    if(s.compareTo(t1) < 0)
                        return 1;
                    else
                        return -1;
                    }
            });
            for (int j = 0; j < M ; j++) {
                query.offer(st.nextToken());
            }
            while (!query.isEmpty()){
                String now = query.poll();

                if(now.charAt(0) == '?'){
                    int cost = 0;
                    for (int k = 0; k < wordMin.size() ; k++) {
                        if(wordMin.get(k).cost == -1)  continue;
                        cost = wordMin.get(k).cost;
                        wordMin.get(k).cost = -1;
                        break;
                    }
                    min += cost;
                    cost = 0;
                    for (int k = 0; k < wordMax.size() ; k++) {
                        if(wordMax.get(k).cost == -1)  continue;
                        cost = wordMax.get(k).cost;
                        wordMax.get(k).cost = -1;
                        break;
                    }
                    max += cost;
                }
                else{

                    for (int k = 0; k < wordMin.size() ; k++) {
                        if(wordMin.get(k).cost == -1)  continue;
                        if(wordMin.get(k).s.equals(now)){
                            min += wordMin.get(k).cost;
                            wordMin.get(k).cost = -1;
                            break;
                        }
                    }
                    for (int k = 0; k < wordMax.size() ; k++) {
                        if(wordMax.get(k).cost == -1)  continue;
                        if(wordMax.get(k).s.equals(now)){
                            max += wordMax.get(k).cost;
                            wordMax.get(k).cost = -1;
                            break;
                        }
                    }
                }
            }

            bw.write("Data Set " + (i + 1) + ":\n");
            bw.write(min + " " + max + "\n\n");
        }
        bw.flush();
        bw.close();
    }
}

class tuple{
    String s;
    int cost;
    public tuple(String s, int cost){
        this.s = s;
        this.cost = cost;
    }
}