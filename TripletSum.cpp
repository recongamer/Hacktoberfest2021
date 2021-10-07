int tripletSum(int *input, int size, int x)
{
    int count=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            for(int k=j+1;k<size;k++){
                if(input[i]+input[j]+input[k]==x){
                    count++;
                }
            }
        }
    }
    return count;
}
