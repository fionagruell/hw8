#include<iostream>
#include<cmath>
using namespace std;
void symp(double* p,double* q,double& H,double dt, const int dim);
int main(){
const double pi=M_PI;
const int dim =2;
const double dt=0.0005;
double p[dim];
double q[dim];
double tend=20*pi;
const int N=tend/dt;
const double e=0.6;
double t=0;

q[0]=1-e;
q[1]=0;
p[0]=0;
p[1]=sqrt((1+e)/(1-e));
double H=0.5*(p[0]*p[0]+p[1]*p[1])-1.0/sqrt(q[0]*q[0]+q[1]*q[1]); 

cout <<t<<"\t"<< q[0]<<"\t"<<q[1]<<"\t"<<p[0]<<"\t"<<p[1]<<"\t"<<H<<"\t"<< endl;
for(int i=1;i<N+1;i++){
  t+=dt;
symp(p,q,H,dt,dim);
cout <<t<<"\t"<< q[0]<<"\t"<<q[1]<<"\t"<<p[0]<<"\t"<<p[1]<<"\t"<<H<<"\t"<< endl;
}
return 0;
}
void symp(double* p,double* q,double& H,double dt, const int dim){
  double Q=q[0]*q[0]+q[1]*q[1];
  for(int i=0;i<dim;i++){
 p[i]-=dt*(q[i]/(pow(Q,1.5)));
 q[i]+=p[i]*dt;
  }
  H=0.5*(p[0]*p[0]+p[1]*p[1])-1.0/sqrt(q[0]*q[0]+q[1]*q[1]);
}