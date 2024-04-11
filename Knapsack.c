include<stdio.h>
int main()
{
     float w[50],p[50],r[50],tv,temp,c,a;
     int n,i,j;
     printf("Enter the number of items :");
     scanf("%d",&n);   
    for (i = 0; i < n; i++)
    {
        printf("Enter w and p for item[%d] :\n",i);
        scanf("%f %f", &w[i], &p[i]);
    } 
    printf("Enter the c of knapsack :\n");
    scanf("%f",&c);
     
     for(i=0;i<n;i++)
         r[i]=p[i]/w[i];
         
    for (i = 0; i < n; i++) 
      for (j = i + 1; j < n; j++) 
         if (r[i] < r[j]) 
        {
            temp = r[j];
            r[j] = r[i];
            r[i] = temp;
 
            temp = w[j];
            w[j] = w[i];
            w[i] = temp;
 
            temp = p[j];
            p[j] = p[i];
            p[i] = temp;
         }

     for (i = 0; i < n; i++) 
     {
      if (w[i] > c)
          break;
       else 
      {
          tv = tv + p[i];
          c = c - w[i];
       }
     } 
       if (i < n)
       tv = tv + (r[i]*c);
     printf("\nThe maximum value is :%f\n",tv);     
     return 0;
}
