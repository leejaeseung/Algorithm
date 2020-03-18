/*
    풀이 : 영어의 모음은 a e u i o 5개다.
 */
import java.io.*;
import java.util.*;

public class Main {

    public static int L,C;
    public static char[] alpha;
    public static ArrayList<String> arr=new ArrayList<>();
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st=new StringTokenizer(br.readLine());
        L=Integer.parseInt(st.nextToken());
        C=Integer.parseInt(st.nextToken());

        st=new StringTokenizer(br.readLine());
        alpha=new char[C];
        for (int i = 0; i <C ; i++) {
            alpha[i]=st.nextToken().charAt(0);
        }
        Arrays.sort(alpha);
        BF(-1,0,new StringBuilder(),0,0);

        for (int i = 0; i <arr.size() ; i++) {
            System.out.println(arr.get(i));
        }
    }
    public static void BF(int now,int size,StringBuilder str,int m_count,int j_count){
        if(size==L){
            if(!arr.contains(str.toString())&&m_count>=1&&j_count>=2)
                arr.add(str.toString());
            size--;
            if(str.charAt(str.length()-1)=='a'||str.charAt(str.length()-1)=='e'||str.charAt(str.length()-1)=='i'||str.charAt(str.length()-1)=='u'||str.charAt(str.length()-1)=='o'){
                m_count--;
            }
            else
                j_count--;
            str.delete(str.length()-1,str.length());
        }
        for (int i = now+1; i <C ; i++) {
            if(alpha[i]=='a'||alpha[i]=='i'||alpha[i]=='e'||alpha[i]=='u'||alpha[i]=='o') {
                BF(i,size+1,new StringBuilder().append(str).append(alpha[i]),m_count+1,j_count);
                }
            else{
                BF(i,size+1,new StringBuilder().append(str).append(alpha[i]),m_count,j_count+1);
            }
        }
    }
}