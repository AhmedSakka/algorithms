    string reorganizeString(string s) {
        map<char, int> charMap;
        
        for(char& c : s){
            charMap[c]++;
        }
        
        map<char, int>::iterator it;
        int maxCharVal = 0;
        char maxChar;
        for(it = charMap.begin(); it != charMap.end(); it++){
            if(it->second > maxCharVal){
                maxCharVal = it->second;
                maxChar = it->first;
            }
        }
        
        if(maxCharVal > ((s.length()+ 1) /2)) return "";
        
        string result(s.length(),'x');
        int idx = 0;
        while(charMap[maxChar] > 0){
            result[idx] = maxChar;
            idx += 2;
            charMap[maxChar]--;
        }
        
        for(it = charMap.begin(); it != charMap.end(); it++){
            while(charMap[it->first] > 0){
                if(idx >= result.length()) idx = 1;
                result[idx] = it->first;
                charMap[it->first]--;
                idx += 2;
            }
        }
        return result;
    }