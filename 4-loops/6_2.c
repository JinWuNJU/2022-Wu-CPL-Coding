#include<stdio.h>
#include<math.h>
#define exp 1e-5
double caozuo(double q){
    double z=1.0*2/q;
    return z;
}
int main(){
    double fenzi=sqrt(2);
    double ji=2.0;
    double f;
    for(int i=1;;i++){
        ji*=caozuo(fenzi);
        f=caozuo(fenzi)-1;
        if(fabs(f)<exp){
            break;
        }
       fenzi=sqrt(fenzi+2);
        

    }printf("%lf",ji);

    return 0;
}