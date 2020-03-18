import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st=new StringTokenizer(br.readLine());
        int N=Integer.parseInt(st.nextToken());
        int M=Integer.parseInt(st.nextToken());

        int[][] student=new int[N+1][M+1];
        int[] size=new int[M+1];
        st=new StringTokenizer(br.readLine());
        for (int i = 1; i <=M ; i++) {
            size[i]=Integer.parseInt(st.nextToken());
        }
        int cl=0;
        for (int i = 1; i <=N ; i++) {
            st=new StringTokenizer(br.readLine());
            while (true) {
                cl = Integer.parseInt(st.nextToken());
                if(cl==-1)
                    break;
                if(size[cl]>=0)
                    student[i][cl]=1;
                size[cl]--;
                if(size[cl]<0){
                    for (int j = 1; j <=N ; j++) {
                        if(student[j][cl]==1)
                            student[j][cl]=0;
                    }
                }
            }
        }
        for (int i = 1; i <=N ; i++) {
            st=new StringTokenizer(br.readLine());
            while (true) {
                cl = Integer.parseInt(st.nextToken());
                if(cl==-1)
                    break;
                if(size[cl]>=0)
                student[i][cl]=2;
                size[cl]--;
                if(size[cl]<0){
                    for (int j = 1; j <=N ; j++) {
                        if(student[j][cl]==2)
                            student[j][cl]=0;
                    }
                }
            }
        }
        for (int i = 1; i <=N ; i++) {
            boolean fail_flag=false;
                for (int j = 1; j <=M; j++) {
                    if(student[i][j]==0)
                        continue;
                    fail_flag=true;
                    System.out.print(j + " ");
            }
            if(!fail_flag)
                System.out.print("망했어요");
            System.out.println();
        }
    }
}
