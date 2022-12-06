
package Programmers.Level2;

import java.util.*;
/**
 * ColoringBook
 */
public class ColoringBook {

    class Solution {
        
        private boolean[][] v;
        
        class Node
        {
            private int x;
            private int y;
            
            public Node(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
        }
        
        private int findSameArea(int[][] arr, int color, Node n )
        {
            LinkedList<Node> list = new LinkedList<>();
            int area = 0;
            
            list.add(n);
            v[n.x][n.y] = true;
            
            while(!list.isEmpty())
            {
                Node t = list.pop();
                area++;
                
                // System.out.println(t.x + "." + t.y + ":" + area);
                
                // 상
                if(t.x - 1 >= 0)
                {
                    if( arr[t.x-1][t.y] == color && v[t.x-1][t.y] == false )
                    {
                       list.add(new Node(t.x-1, t.y));
                        v[t.x-1][t.y] = true;
                    }
                }
                
                // 하
                if(t.x + 1 < arr.length)
                {
                    if( arr[t.x+1][t.y] == color && v[t.x+1][t.y] == false )
                    {
                       list.add(new Node(t.x+1, t.y));
                        v[t.x+1][t.y] = true;
                    }
                }
                
                // 좌
                if(t.y-1 >=0 )
                {
                    if( arr[t.x][t.y-1] == color && v[t.x][t.y-1] == false)
                    {
                        list.add(new Node(t.x, t.y-1));
                        v[t.x][t.y-1] = true;
                    }
                }
                
                // 우
                if(t.y+1 < arr[0].length )
                {
                    if( arr[t.x][t.y+1] == color && v[t.x][t.y+1] == false)
                    {
                        list.add(new Node(t.x, t.y+1));
                        v[t.x][t.y+1] = true;
                    }
                }
            }
            
            return area;
            
        }
        
        public int[] solution(int m, int n, int[][] picture) {
            int numberOfArea = 0;
            int maxSizeOfOneArea = 0;
            
            int area = 0;
            List<Integer> list = new LinkedList<>();
            v = new boolean[picture.length][picture[0].length];
            
            for(int i = 0 ; i < picture.length; i++)
            {
                for(int j = 0 ; j < picture[0].length; j++)
                {
                    if(picture[i][j] == 0) v[i][j] = true;
                    else
                    {
                        if(v[i][j] == false)
                        {
                            area = findSameArea(picture, picture[i][j], new Node(i,j));
                            list.add(area);
                        }
                        
                    }
                    
                    area = 0;
                }
            }
            
            numberOfArea = list.size();
            maxSizeOfOneArea = Collections.max(list);
            
    
            int[] answer = new int[2];
            answer[0] = numberOfArea;
            answer[1] = maxSizeOfOneArea;
            return answer;
        }
    }

    public static void main(String[] args) {
        
    }
}