
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct point2d{
  int64 x,y;
} point;

typedef struct line2d{
  point s,t;
} line;

void swap(int64 *a,int64 *b){
  int64 tmp=*a;
  *a=*b;
  *b=tmp;
}

int func(const line *a,const point *b){
  int64 p=a->s.x;
  int64 q=a->s.y;
  int64 r=a->t.x;
  int64 s=a->t.y;
  int64 t=(s-q)*(b->x-p)-(r-p)*(b->y-q);
  return t==0?0:(t>0?1:-1);
}

int isIntersect(const line *a,const line *b){
  int p=func(a,&(b->s));
  int q=func(a,&(b->t));
  int r=func(b,&(a->s));
  int s=func(b,&(a->t));
  if(p==0 && q==0 && r==0 && s==0){
    if(a->s.x!=a->t.x){
      int64 p=a->s.x;
      int64 q=a->t.x;
      int64 r=b->s.x;
      int64 s=b->t.x;
      if(p>q) swap(&p,&q);
      if(r>s) swap(&r,&s);
      return !(p>s || r>q);
    } else {
      int64 p=a->s.y;
      int64 q=a->t.y;
      int64 r=b->s.y;
      int64 s=b->t.y;
      if(p>q) swap(&p,&q);
      if(r>s) swap(&r,&s);
      return !(p>s || r>q);
    }
  }
  return p*q<=0 && r*s<=0;
}

double calcPointDistance(const point *a,const point *b){
  int64 p=a->x;
  int64 q=a->y;
  int64 r=b->x;
  int64 s=b->y;
  return sqrt((p-r)*(p-r)+(q-s)*(q-s));
}

double calcArea(double a,double b,double c){
  double s=(a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

double calcLinePointDistance(const line *a,const point *b){
  double p=calcPointDistance(&(a->s),b);
  double min=p;
  double q=calcPointDistance(&(a->t),b);
  min=MIN(min,q);
  double l=calcPointDistance(&(a->s),&(a->t));
  if((p*p+l*l-q*q)>=0 && (q*q+l*l-p*p)>=0){
    min=MIN(min,2/l*calcArea(p,q,l));
  }
  return min;
}

double calcLineDistance(const line *a,const line *b){
  if(isIntersect(a,b)) return 0;

  double min=calcLinePointDistance(a,&(b->s));
  min=MIN(min,calcLinePointDistance(a,&(b->t)));
  min=MIN(min,calcLinePointDistance(b,&(a->s)));
  min=MIN(min,calcLinePointDistance(b,&(a->t)));
  return min; 
}

void run(void){
  for (int q = 0; q < 147; ++q){
    line a,b;
    //Placeholder for scanfLine(&a);
    a.s.x = 0; a.s.y = 0; a.t.x = 1; a.t.y = 1;
    //Placeholder for scanfLine(&b);
    b.s.x = 1; b.s.y = 0; b.t.x = 0; b.t.y = 1;
    double ans=calcLineDistance(&a,&b);
    printf("%.9lf\n",ans);
  }
  return;
}

int main(void){
  run();
  return 0;
}