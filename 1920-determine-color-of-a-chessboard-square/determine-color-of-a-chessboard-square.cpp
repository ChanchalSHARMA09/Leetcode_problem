class Solution {
public:
    bool squareIsWhite(string coordinates) {
       int row=coordinates[0]-'a'+1;
       int col=coordinates[1]-'0';
       if((row+col)%2==1){
        return true;
       }  else{
        return false;
       }
    }
};