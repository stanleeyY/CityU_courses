int pow(int x,int n)
{
    if(!n) 
	   return 1;
    while((n&1)==0){
        n>>=1;
        x*=x;
    }
    int result=x;
    n>>=1;
    while(n){
        x*=x;
    	   if((n&1)!=0)
             result*=x;
        n>>=1;
    }
    return result;
}