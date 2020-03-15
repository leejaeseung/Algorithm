import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

    public static int C, M, S;
    public static HashMap<String, ArrayList<String>> hm;
    public static HashMap<String, Integer> classes;
    public static void main(String[] argc) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());

        for (int i = 0; i < K ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            C = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            S = Integer.parseInt(st.nextToken());

            hm = new HashMap<>();
            classes = new HashMap<>();

            for (int j = 0; j < C ; j++) {
                st = new StringTokenizer(br.readLine());
                String cls = st.nextToken();
                int unit = Integer.parseInt(st.nextToken());

                classes.put(cls, unit);
            }
            ArrayList<String> g = new ArrayList<>();
            for (int j = 0; j < M ; j++) {
                st = new StringTokenizer(br.readLine());
                String Major = st.nextToken();

                hm.put(Major, new ArrayList<>());
                g.add(Major);

                int it = Integer.parseInt(st.nextToken());
                for (int k = 0; k < it ; k++) {
                    String cl = br.readLine();
                    hm.get(Major).add(cl);
                }
            }
            bw.write("Data Set " + (i + 1) + ":\n");
            for (int j = 0; j < S ; j++) {
                int stuNum = Integer.parseInt(br.readLine());
                bw.write("Student " + (j + 1) + "\n");

                double sum = 0;
                int u = 0;
                ArrayList<String> grad = new ArrayList<>();
                HashMap<String, Double> sc = new HashMap<>();
                for (int k = 0; k < stuNum ; k++) {
                    st = new StringTokenizer(br.readLine());
                    String clas = st.nextToken();
                    double score = Double.parseDouble(st.nextToken());

                    sc.put(clas, score);

                    sum += (double)classes.get(clas) * score;
                    u += classes.get(clas);

                    grad.add(clas);
                }
                bw.write("GPA: " + String.format("%.2f",(sum / (double)u)) + "\n");
                for (int k = 0; k < g.size() ; k++) {
                    String nowG = g.get(k);

                    boolean flag = true;
                    for (int l = 0; l < hm.get(nowG).size() ; l++) {
                        if(!grad.contains(hm.get(nowG).get(l))) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        double s = 0;
                        int un = 0;
                        for (int l = 0; l < hm.get(nowG).size() ; l++) {
                            s += (double)classes.get(hm.get(nowG).get(l)) * sc.get(hm.get(nowG).get(l));
                            un += classes.get(hm.get(nowG).get(l));
                        }
                        bw.write( nowG + ": " + String.format("%.2f",(s / (double)un)) + "\n");
                    }
                }
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}