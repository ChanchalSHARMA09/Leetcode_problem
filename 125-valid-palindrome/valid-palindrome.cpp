class Solution {
public:
    bool isPalindrome(string s) {
        int beg=0;
        int end=s.size()-1;
        while(beg<end){
            while(beg<end && !isalnum(s[beg])){
                beg++;
            }
            while(beg<end && !isalnum(s[end])){
                end--;
            }
            while(tolower(s[beg])!=tolower(s[end])){
                return false;
            }
            beg++;
            end--;

        }
        return true;
    }
};