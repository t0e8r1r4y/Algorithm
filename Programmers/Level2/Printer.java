package Programmers.Level2;

import java.util.*;

public class Printer {

    class Solution {
        public int solution(int[] priorities, int location) {
            int answer = 0;
            int ref = 0;
            LinkedList<Integer> list = new LinkedList<>();
            LinkedList<Integer> printList = new LinkedList<>();
            
            
            // 문제를 있는 그대로 구현한다.
            for(int i = 0; i < priorities.length; i++) { list.add(i); }
            
            while(!list.isEmpty())
            {
                ref = list.pop();
                printList.add(ref);
                
                for(int i = 0 ; i < list.size(); i++)
                {
                    if(priorities[list.get(i)] > priorities[ref])
                    {
                        list.add(ref);
                        printList.remove(printList.size()-1);
                        break;
                    }
                }
            }
            
            
            for(int i = 0; i < printList.size(); i++)
            {
                if(printList.get(i) == location)
                {
                    answer = i+1;
                    break;
                }
            }
         
            
            return answer;
        }
    }
    public static void main(String[] args) {
        
    }
}
