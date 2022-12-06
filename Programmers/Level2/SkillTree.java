package Programmers.Level2;

import java.util.*;

public class SkillTree {
    
    class Solution {
        public int solution(String skill, String[] skill_trees) {
            int answer = 0;
            Set<String> s = new HashSet<>();
            StringBuilder sb = new StringBuilder();
            
            // 배울 수 있는 스킬셋을 만든다.
            for(int i = 1; i <= skill.length(); i++ ) {
                for(int j = 0; j < i; j++) {
                    sb.append(skill.charAt(j));
                }
                s.add(sb.toString());
                sb.setLength(0);
            }
            
            // 스킬트리에서 skill 과불필요한 문자 싹 제거
            for(int i = 0; i < skill_trees.length; i++){
                for(int j = 0; j < skill_trees[i].length(); j++) {
                    if(skill.indexOf(skill_trees[i].charAt(j)) != -1) {
                        sb.append(skill_trees[i].charAt(j));
                    }
                }
    
                if(s.contains(sb.toString()) || sb.toString().equals("")) {
                    answer++;
                }
                
                sb.setLength(0);            
            }
            
            return answer;
        }
    }

    public static void main(String[] args) {
        
    }
}
