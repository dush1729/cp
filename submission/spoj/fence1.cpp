#include<stdio.h>
#include<math.h>
main()
{
  int L;
  float a;
  scanf("%d",&L);
  while(L)
  {
      a=(L*L)/(2*M_PI);
      printf("%.2lf\n",a);
      scanf("%d",&L);
  }
}
