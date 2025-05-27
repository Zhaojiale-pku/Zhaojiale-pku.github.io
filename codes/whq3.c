#include<stdio.h>
#include<math.h>

#define EPS 1e-5
double c[4];

double f(double x){
    double v=0;
    for(int i=3;i>=0;i--){
        v+=c[i]*pow(x,i);
    }
    return v;
}

int main(){
    double x0,x1,x2,fx0,fx1,fx2;
    int n=0;
    scanf("%lf,%lf,%lf,%lf",&c[3],&c[2],&c[1],&c[0]);
    scanf("%lf,%lf",&x1,&x2);
    fx1=f(x1);
    fx2=f(x2);
    if(fx1*fx2>0){
        printf("(x1,x2)no-roots");
        return 0;
    }
    do{
        x0=(x1+x2)/2;
        fx0=f(x0);
        if(fx0*fx1<0){
            x2=x0;
            fx2=fx0;
        }else{
            x1=x0;
            fx1=fx0;
        }
        n++;
    }while(fabs(fx0)>EPS);
    printf("%.3lf\n",x0);
    printf("%d\n",n);
    return 0;
}