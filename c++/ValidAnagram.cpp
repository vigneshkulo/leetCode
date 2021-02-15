
bool isAnagram(char * s, char * t){
    int arr[26] = {0};
    
    if (strlen(s) != strlen(t)) {
        return false;
    }
    
    for (int i = 0; i < strlen(s); ++i) {
        arr[s[i] - 'a'] += 1;
        arr[t[i] - 'a'] -= 1;
    }
    
    for (int i = 0; i < 26; ++i) {
        if (arr[i] != 0) {
            return false;
        }
    }
    return true;
}
