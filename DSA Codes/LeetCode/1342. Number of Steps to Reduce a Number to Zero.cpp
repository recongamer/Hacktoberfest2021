//Dev Wadhwa

class Solution {
public:
    int numberOfSteps(int num) {
        int count=0;
        while(num!=0)
        {
            if(num%2==0)
            {
                num/=2;
                count++;
            }
            else
            {
                num--;
                count++;
            }
        }
        return count;
    }
};
