//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.io.*;

// Position this line where user code will be pasted.

// Driver class with main function
class GFG {
    // Main function
    public static void main(String[] args)throws IOException {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());

        // Iterating over testcases
        while (t-- > 0) {
            int n = Integer.parseInt(in.readLine());
            int arr[] = new int[n];

            String s[]=in.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(s[i]);

            Solution obj = new Solution();
            System.out.println(obj.LargButMinFreq(arr, n));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

// Helper class to find largest number with minimum frequency
class Solution {
    // Function to find largest number with minimum frequency
    public static int LargButMinFreq(int arr[], int n) {
        // Your code here
        
        HashMap<Integer,Integer> mp = new HashMap<Integer , Integer>();
        for(int i = 0 ; i < n; i++){
           mp.put(arr[i], mp.getOrDefault(arr[i], 0) + 1);
        }
        
        int mn = 10000004;
        
        for(Integer it :  mp.keySet()){
            
            mn = Math.min(mp.get(it) , mn);
        }
        
        ArrayList<Integer>a = new ArrayList<> ();
        for(Integer it : mp.keySet()){
            if(mn ==mp.get(it)){
                a.add(it);
            }
        }
        int i=0;
        int mx =0;
        
        for( i = 0; i < a.size();i++){
            mx = Math.max(mx , a.get(i));
           // System.out.println(a.get(i));
        }
        
        return mx;
    }
}