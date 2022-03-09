def wordPattern(pattern: str, s: str) -> bool:
    map_chars = {}
    map_words = {}
        
    words = s.split(' ')
        
    if len(words) != len(pattern):
        return False
        
    for char, word in zip(pattern, words):
        if char not in map_chars:
            if word not in map_words:
                map_chars[char] = word
                map_words[word] = char
            else:
                if map_words[word] != char:
                    return False
        else:
            if map_chars[char] != word:
                return False
    return True

test_pattern = "abba"
test_words   = "dog cat cat dog"

if wordPattern(test_pattern, test_words) == True:
    print(f"Pattern {test_pattern} matches with words {test_words}!")
else:
    print(f"Pattern {test_pattern} doesn't match with words {test_words}!")