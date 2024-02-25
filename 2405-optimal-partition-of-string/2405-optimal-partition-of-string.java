class Solution {
    public int partitionString(String s) {
        int result = 1;
        Map<Character, Integer> map = new HashMap<>();
        for(int i = 0; i<s.length(); i++){
            if(map.containsKey(s.charAt(i))){
                result++;
                map.clear();
            }
               map.put(s.charAt(i),map.getOrDefault(s.charAt(i), 0) + 1);
        }
        return result;
    }
}