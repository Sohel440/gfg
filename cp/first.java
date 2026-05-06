import java.util.*;
public class first {

  static  public void main(String []arg){

//         int t;
         Scanner sc = new Scanner(System.in);
//         t = sc.nextInt();
// // int sc
//         while(t>0){
            int n ;
            n = sc.nextInt();

            // ArrayList<Integer>  arr = new ArrayList<>();
            // for(int i =0  ; i < n; i++){
            //     int x = sc.nextInt();
            //     arr.add(x);
            // }

            // for(int i : arr){
            //     System.err.println(i);
            // }

            // HashMap<String, Integer> mp = new HashMap<>();


            // mp.put("sohel", 34);
            // mp.put("saheb", 35);
            // mp.put("mal", 33);
            // mp.put("rohit", 45);
            // mp.put("virat", 18);

            // if(mp.containsKey("sohel")){
            //     System.out.println("Present");
            // }
            
            // System.err.println(mp.get("sohel"));
            int []a = {1 ,2,3,2,3,4};
            HashMap<Integer,Integer> freq = new HashMap<>();

            for (int num : a) {
                freq.put(num, freq.getOrDefault(num, 0) + 1);
            }
            Arrays.sort(a);
            //
           for(int val : a){
               System.out.print(val +" ");
           } 
           System.out.println("\n");
            for(Map.Entry<Integer,Integer> it: freq.entrySet()){
                System.out.print(it.getKey());
                System.out.print("->");
                System.out.print(it.getValue());
                System.out.print("\n");
            }

            HashSet<Integer> st = new HashSet<>();
            for(int i : a){
                st.add(i);
            }
            if(st.contains(2)){
                System.out.println("I am here !!");
            }

            
           
        //     t-=1;
        // }

   }
}