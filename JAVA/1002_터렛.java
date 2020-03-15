/*
    풀이 :
    두 원의 접점을 찾는 문제.
    경우의 수는 (0,1,2,모든점) 네가지이므로 두 점 사이의 거리와 반지름의 길이의 경우를 모두 계산한다.
 */
import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N=Integer.parseInt(br.readLine());

        for (int i = 0; i <N ; i++) {
            String s=br.readLine();
            StringTokenizer st=new StringTokenizer(s);

            Point jo=new Point(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
            double ryu_jo=Integer.parseInt(st.nextToken());
            Point back=new Point(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
            double ryu_back=Integer.parseInt(st.nextToken());
            bw.write(where(jo,back,ryu_jo,ryu_back)+"\n");
        }
        bw.flush();
        bw.close();
    }
    public static int where(Point jo,Point back,double ryu_jo,double ryu_back){
        double joToback=pTop(jo,back);

        if(ryu_jo+ryu_back<joToback){
            return 0;
        }
        else if(ryu_jo+ryu_back==joToback){
            return 1;
        }
        else{
            if(Math.abs(ryu_jo-ryu_back)==joToback){
                if(joToback==0)
                    return -1;
                else
                    return 1;
            }
            else if(Math.abs(ryu_jo-ryu_back)>joToback){
                return 0;
            }
            else{
                return 2;
            }
        }
    }
    public static double pTop(Point p1,Point p2){
        return Math.sqrt(Math.pow(p1.x-p2.x,2)+Math.pow(p1.y-p2.y,2));
    }
}

class Point{

    public double x;
    public double y;
    public Point(double x,double y){
        this.x=x;
        this.y=y;
    }
}