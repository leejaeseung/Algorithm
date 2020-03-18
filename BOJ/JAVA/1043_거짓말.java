/*
    풀이 :
    1. 파티에서 진실을 말해야 하는지 검사한다.(파티에 진실을 아는 사람이 있으면 무조건 진실을 말해야 한다)
    2. 진실을 말한 파티의 모든 사람은 진실(true)가 된다.
    3. false로 되어있는 파티도 위 1,2번을 거친 뒤 다시 검사한다.
    4. 모두 검사를 마쳤을 때 false인 파티의 수를 출력한다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static People[] Man;
    public static int N;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String s=br.readLine();
        StringTokenizer st=new StringTokenizer(s);
        N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        Party[] pt=new Party[M];

        Man=new People[N+1];
        for (int i = 1; i <=N ; i++) {
            Man[i]=new People(i,false);
        }
        s=br.readLine();
        st=new StringTokenizer(s);
        int T=Integer.parseInt(st.nextToken());
        for (int i = 1; i <=T ; i++) {
            Man[Integer.parseInt(st.nextToken())].know=true;
        }
        for (int i = 0; i <M ; i++) {
            s=br.readLine();
            st=new StringTokenizer(s);
            int pt_num=Integer.parseInt(st.nextToken());
            pt[i]=new Party(pt_num,N);
            for (int j = 0; j <pt_num ; j++) {
                pt[i].Join(Man[Integer.parseInt(st.nextToken())]);
            }
        }
        for (int i = 0; i <M ; i++) {
            if(pt[i].truePT==false) {
                if (pt[i].istruePT(Man) == 1) {
                    i = -1;
                }
            }
        }
        int count=0;
        for (int i = 0; i <M ; i++) {
            if(pt[i].truePT==false)
                count++;
        }
        bw.write(Integer.toString(count));
        bw.flush();
        bw.close();
    }
}

class People{

    public int num;
    public boolean know;
    public People(int num,boolean know){
        this.num=num;
        this.know=know;
    }
}

class Party{

    public People[] join;
    public int size;
    public int N;
    public boolean truePT=false;
    public Party(int size,int N){
        this.size=size;
        join=new People[N+1];
        this.N=N;
    }
    public void Join(People pp){
        this.join[pp.num]=pp;
    }
    public int istruePT(People[] Man){
        for (int i = 1; i <=N ; i++) {
            if(join[i]!=null){
                join[i].know=Man[i].know;
                if(join[i].know==true) {
                    truePT = true;
                    for (int j = 1; j <=N ; j++) {
                        if(join[j]!=null){
                            join[j].know=true;
                            Man[j].know=join[j].know;
                        }
                    }
                    return 1;
                }
            }
        }
        return -1;
    }
}