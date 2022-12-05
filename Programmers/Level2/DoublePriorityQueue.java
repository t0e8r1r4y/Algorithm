package Programmers.Level2;
import java.util.*;


/**
 * 
 */
public class DoublePriorityQueue {


class Solution {
    
    private final static String D_MAX = "D 1";
    private final static String D_MIN = "D -1";
    
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        // 문제에서 주어준 힌트
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        PriorityQueue<Integer> maxPq = new PriorityQueue<>(Collections.reverseOrder());
        
        for(String s : operations) {
            
            if(s.equals(D_MAX)){
                if(pq.isEmpty()) continue;
                int max = maxPq.poll();
                pq.remove(max);
            } else if(s.equals(D_MIN)){
                if(pq.isEmpty()) continue;
                int min = pq.poll();
                maxPq.remove(min);
            } else {
                pq.offer(Integer.parseInt(s.split(" ")[1]));
                maxPq.offer(Integer.parseInt(s.split(" ")[1]));
            }
            // System.out.println(pq);
        }
        
        if(pq.size() > 0) {
            answer[0] = maxPq.peek();
            answer[1] = pq.peek();
        }
        
        return answer;
    }
}
    public static void main(String[] args) {
        
    }
}
