public int lengthOfLongestSubstring(String s) {
    if(s.isEmpty()) return 0;
    Integer maxLength = 1;
        
    for(Integer i = 0; i < s.length(); i++){
        Integer currentLength = 1;
        HashMap<Character, Boolean> charsMap = new HashMap<>();
        charsMap.put(s.charAt(i), true);
        for(Integer j = i + 1; j < s.length(); j++){
            if(charsMap.containsKey(s.charAt(j))){
                break;
            }
            currentLength++;
            charsMap.put(s.charAt(j), true);
            maxLength = Math.max(maxLength, currentLength);
        }
    }
    return maxLength;
}