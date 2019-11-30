# define MAX 5
#include<stdio.h>
#include<stdlib.h>

void adt(int);

void oprs();
void push(int *,int *);
void pop(int *,int *);
void isempty(int *);
void isfull(int *);
void valueattop(int *,int *);
void traverse(int *,int *);

void oprq();
void insert(int *,int *,int *);
void delete(int *,int *,int *);
void isemptyq(int *,int *);
void isfullq(int *);
void valueatf(int *,int *,int *);
void valueatr(int *,int *);
void traverseq(int *,int *,int *);

void oprcq();
void insertcq(int*,int*,int*);
void deletecq(int *,int *,int *);
void isemptycq(int *,int *,int *);
void isfullcq(int *,int *,int *);
void valueatfcq(int *,int *,int *);
void valueatrcq(int *,int *);
void traversecq(int *,int *,int *);

void oprdq();
void insertdq(int*,int*,int*);
void insertdqatf(int*,int*,int*);
void insertdqatr(int*,int*,int*);
void deletedq(int *,int *,int *);
void deletedqatf(int *,int *,int *);
void deletedqatr(int *,int *,int *);
void isemptydq(int *,int *,int *);
void isfulldq(int *,int *,int *);
void valueatfdq(int *,int *,int *);
void valueatrdq(int *,int *);
void traversedq(int *,int *,int *);

int main()
{
 int c=1;
 adt(c);
}
void adt(int c)
{
 while(c!=0)
 {
  printf("Types of ADT's: \n1. Stack\n2. Queue\n3. Circular Queue\n4. Deque\n0. Exit\nSelect ADT or 0 to Exit : ");
  scanf("%d",&c);
  switch(c)
  {
   case 1:
          oprs();
          break;
   case 2:
          oprq();
          break;
   case 3:
          oprcq();
          break;
   case 4:
          oprdq();
          break;
   case 0:
          printf("      ***EXIT***");
          exit(0);
  }
 }
}
// STACK
void oprs()
{
 int *a,top=-1,s=1;
 a=(int*)calloc(MAX,sizeof(int));
 while(s!=0)
 {
  printf("\n\nChoose the operation:\n1. Push\n2. Pop\n3. IsEmpty\n4. IsFull\n5. Value at Top\n6. Traverse\n7. Return to ADT Selection\n0. Exit\nEnter the Operation: ");
  scanf("%d",&s);
  switch(s)
  {
   case 1:
            push(a,&top);
            break;
   case 2:
            pop(a,&top);
            break;
   case 3:
            isempty(&top);
            break;
   case 4:
            isfull(&top);
            break;
   case 5:
            valueattop(a,&top);
            break;
   case 6:
            traverse(a,&top);
            break;
   case 7:
            adt(s);
   case 0:
            exit(0);
   default:
            printf("Invalid Choice");
  }
 }
}
void push(int a[],int *t)
{
 int e;
 if(*t<MAX-1)
 {
  printf("Enter the Element: ");
  scanf("%d",&e);
  *t=(*t)+1;
  a[*t]=e;
  traverse(a,t);
 }
 else
    printf("\nStack Overflow.\n");
}
void pop(int a[],int *t)
{
 if(*t<0)
    printf("\nNo Element in the Stack.\n");
 else
 {
  *t=(*t)-1;
  traverse(a,t);
 }
}
void isempty(int *t)
{
 if(*t<MAX-2)
  printf("\nStack is Empty.\n");
 else
    printf("\nStack is Not Empty.\n");
}
void isfull(int *t)
{
 if(*t>MAX-2)
    printf("\nStack is Full.\n");
 else
    printf("\nStack is Not Full.\n");
}
void valueattop(int a[],int *t)
{
 if(*t<0)
    printf("\nNo value at the Top.\n");
 else
    printf("\nValue at the Top is %d.\n",a[*t]);
}
void traverse(int a[],int *t)
{
 int i;
 for(i=0;i<=*t;i++)
    printf(" %d ",a[i]);
}
// QUEUE
void oprq()
{
 int *a,front=-1,rear=-1,s=1;
 a=(int*)calloc(MAX,sizeof(int));
 while(s!=0)
 {
  printf("\n\nChoose the operation:\n1. Insert\n2. Delete\n3. IsEmpty\n4. IsFull\n5. Value at Front\n6. Value at Rear\n7. Traverse\n8. Return to ADT Selection\n0. Exit\nEnter the Operation: ");
  scanf("%d",&s);
  switch(s)
  {
   case 1:
           insert(a,&front,&rear);
           break;
   case 2:
           delete(a,&front,&rear);
           break;
   case 3:
           isemptyq(&front,&rear);
           break;
   case 4:
           isfullq(&rear);
           break;
   case 5:
           valueatf(a,&front,&rear);
           break;
   case 6:
           valueatr(a,&rear);
           break;
   case 7:
           traverseq(a,&front,&rear);
           break;
   case 8:
           adt(s);
   case 0:
           exit(0);
   default:
           printf("Invalid Choice");
  }
 }
}
void insert(int a[],int *f,int *r)
{
 int e;
 if(*r==MAX-1)
    printf("\nQueue Overflow\n");
 else
 {
  if(*f==-1 && *r==-1)
    *f=0;
  printf("Enter the Element: ");
  scanf("%d",&e);
  (*r)++;
  a[*r]=e;
  traverseq(a,f,r);
 }
}
void delete(int a[],int*f,int*r)
{
 if(*f>*r)
    printf("\nNo Element in Queue.\n");
 else
 {
  (*r)--;
  traverseq(a,f,r);
 }
}
void isemptyq(int *f,int *r)
{
 if(*f<=0 && *r<=0)
    printf("\nQueue Empty.\n");
 else
    printf("\nQueue Not Empty.\n");
}
void isfullq(int *r)
{
 if(*r==MAX-1)
    printf("\nQueue Full.\n");
 else
    printf("\nQueue Not Full.\n");
}
void valueatf(int a[],int *f,int *r)
{
 if(*f<0 || *f>*r)
    printf("\nNo Value at Front.\n");
 else
    printf("\nValue at Front is %d.\n",a[*f]);
}
void valueatr(int a[],int *r)
{
 if(*r<0)
    printf("\nNo Value at Rear.\n");
 else
    printf("\nValue at Rear is %d.\n",a[*r]);
}
void traverseq(int a[],int *f,int *r)
{
 int i;
 if(*f<=0 && *r<=0)
    printf("\nNo Element in Queue.\n");
 else
    for(i=*f;i<=*r;i++)
        printf(" %d ",a[i]);
}
// CIRCULAR QUEUE
void oprcq()
{
 int *a,front=-1,rear=-1,s=1;
 a=(int*)calloc(MAX,sizeof(int));
 while(s!=0)
 {
  printf("\n\nChoose the operation:\n1. Insert\n2. Delete\n3. IsEmpty\n4. IsFull\n5. Value at Front\n6. Value at Rear\n7. Traverse\n8. Return to ADT Selection\n0. Exit\nEnter the Operation: ");
  scanf("%d",&s);
  switch(s)
  {
   case 1:
           insertcq(a,&front,&rear);
           break;
   case 2:
           deletecq(a,&front,&rear);
           break;
   case 3:
           isemptycq(a,&front,&rear);
           break;
   case 4:
           isfullcq(a,&front,&rear);
           break;
   case 5:
           valueatfcq(a,&front,&rear);
           break;
   case 6:
           valueatrcq(a,&rear);
           break;
   case 7:
           traversecq(a,&front,&rear);
           break;
   case 8:
           adt(s);
   case 0:
           exit(0);
   default:
           printf("Invalid Choice");
  }
 }
}
void insertcq(int a[],int *f,int *r)
{
 int e;
 if((*f==0 && *r==MAX-1) || ((*f)-(*r))==1)
    printf("\nCircular Queue Full.\n");
 else
 {
  if(*f==-1 && *r==-1)
  {
   *f=0;
   *r=0;
  }
  else if(*f!=0 && *r==MAX-1)
    *r=0;
  else
    (*r)++;
  printf("Enter the Element: ");
  scanf("%d",&e);
  a[*r]=e;
  traversecq(a,f,r);
 }
}
void deletecq(int a[],int *f,int *r)
{
 if((*f==-1 && *r==-1)||(a[*f]==0)||(a[*f]==-99))
    printf("\nNo Element in Circular Queue.\n");
 else
 {
  a[*f]=-99;
  (*f)++;
  if(*f>MAX-1)
  {
   *f=0;
   traversecq(a,f,r);
  }
  else
    traversecq(a,f,r);
 }
}
void isemptycq(int a[],int *f,int *r)
{
 int i,flag=0;
 for(i=0;i<MAX;i++)
 {
  if(a[i]==0 || a[i]==-99)
    flag=0;
  else
  {
   printf("\nCircular Queue is Not Empty.\n");
   flag=1;
   break;
  }
 }
 if(flag==0)
    printf("\nCircular Queue is Empty.\n");
}
void isfullcq(int a[],int *f,int *r)
{
 if((*f==0 && *r==MAX-1) || (*f==-99))
    printf("\nCircular Queue is Full.\n");
 else
    printf("\nCircular Queue is Not Full.\n");
}
void valueatfcq(int a[],int *f,int *r)
{
 if(*f<0 || (a[*f]==0) || (a[*f]==-99))
    printf("\nNo Value at Front.\n");
 else
    printf("\nValue at Front is %d.\n",a[*f]);
}
void valueatrcq(int a[],int *r)
{
 if(*r<0 || a[*r]==-99)
    printf("\nNo Value at Rear.\n");
 else
    printf("\nValue at Rear is %d.\n",a[*r]);
}
void traversecq(int a[],int *f,int *r)
{
 int i;
 for(i=0;i<MAX;i++)
 {
  if(a[i]==-99 || a[i]==0)
    printf(" - ");
  else
    printf(" %d ",a[i]);
 }
}
// DEQUE
void oprdq()
{
 int *a,front=-1,rear=-1,s=1;
 a=(int*)calloc(MAX,sizeof(int));
 while(s!=0)
 {
  printf("\n\nChoose the operation:\n1. Insert\n2. Delete\n3. IsEmpty\n4. IsFull\n5. Value at Front\n6. Value at Rear\n7. Traverse\n8. Return to ADT Selection\n0. Exit\nEnter the Operation: ");
  scanf("%d",&s);
  switch(s)
  {
   case 1:
           insertdq(a,&front,&rear);
           break;
   case 2:
           deletedq(a,&front,&rear);
           break;
   case 3:
           isemptydq(a,&front,&rear);
           break;
   case 4:
           isfulldq(a,&front,&rear);
           break;
   case 5:
           valueatfdq(a,&front,&rear);
           break;
   case 6:
           valueatrdq(a,&rear);
           break;
   case 7:
           traversedq(a,&front,&rear);
           break;
   case 8:
           adt(s);
   case 0:
           exit(0);
   default:
           printf("Invalid Choice");
  }
 }
}
void insertdq(int a[],int *f,int *r)
{
 int c;
 if(a[*f]==-99 || a[*f]==0)
 {
  *f=-1;
  *r=-1;
 }
 if((*f==0 && *r==MAX-1) || ((*f)-(*r))==1)
    printf("\nDeque Full.\n");
 else
 {
  printf("\nInsert at:\n1.Front\n2.Rear: ");
  scanf("%d",&c);
  switch(c)
  {
   case 1:
          insertdqatf(a,f,r);
          break;
   case 2:
          insertdqatr(a,f,r);
          break;
   case 0:
          exit(0);
   default:
   {
          printf("\nInvalid Choice");
          insertdq(a,f,r);
   }
  }
 }
}
void insertdqatf(int a[],int *f,int *r)
{
 int e;
 if(a[*f]==-99 || a[*f]==0)
 {
  *f=-1;
  *r=-1;
 }
 if(*f==-1 && *r==-1)
  {
   *f=0;
   *r=0;
  }
 else if(*f==0 && *r!=MAX-1)
    *f=MAX-1;
 else
    (*f)--;
 printf("Enter the Element: ");
 scanf("%d",&e);
 a[*f]=e;
 traversedq(a,f,r);
}

void insertdqatr(int a[],int *f,int *r)
{
 int e;
 if(a[*f]==-99 || a[*f]==0)
 {
  *f=-1;
  *r=-1;
 }
 if(*f==-1 && *r==-1)
  {
   *f=0;
   *r=0;
  }
 else if(*f!=0 && *r==MAX-1)
    *r=0;
 else
    (*r)++;
 printf("Enter the Element: ");
 scanf("%d",&e);
 a[*r]=e;
 traversedq(a,f,r);
}
void deletedq(int a[],int *f,int *r)
{
 int c;
 if((*f==-1 && *r==-1)||(a[*f]==0)||(a[*f]==-99))
    printf("\nNo Element in deque.\n");
 else
 {
  printf("Press 1 for Front or 2 for Rear: ");
  scanf("%d",&c);
  switch(c)
  {
    case 1:
           deletedqatf(a,f,r);
           break;
    case 2:
           deletedqatr(a,f,r);
           break;
    default:
    {
           printf("\nInvalid Choice");
           deletedq(a,f,r);
    }
  }
 }
}
void deletedqatf(int a[],int *f,int *r)
{
  a[*f]=-99;
  (*f)++;
  if(*f>MAX-1)
  {
    *f=0;
    traversedq(a,f,r);
  }
  else
    traversedq(a,f,r);
}
void deletedqatr(int a[],int *f,int *r)
{
  a[*r]=-99;
  (*r)--;
  if(*f>MAX-1)
  {
   *f=0;
   traversedq(a,f,r);
  }
  else
    traversedq(a,f,r);
}
void isemptydq(int a[],int *f,int *r)
{
 int i,flag=0;
 for(i=0;i<MAX;i++)
 {
  if(a[i]==0 || a[i]==-99)
    flag=0;
  else
  {
   printf("\nDeque is Not Empty.\n");
   flag=1;
   break;
  }
 }
 if(flag==0)
    printf("\nDeque is Empty.\n");
}
void isfulldq(int a[],int *f,int *r)
{
 if((*f==0 && *r==MAX-1) || (*f==-99))
    printf("\nDeque is Full.\n");
 else
    printf("\nDeque is Not Full.\n");
}
void valueatfdq(int a[],int *f,int *r)
{
 if(*f<0 || (a[*f]==0) || (a[*f]==-99))
    printf("\nNo Value at Front.\n");
 else
    printf("\nValue at Front is %d.\n",a[*f]);
}
void valueatrdq(int a[],int *r)
{
 if(*r<0 || a[*r]==-99)
    printf("\nNo Value at Rear.\n");
 else
    printf("\nValue at Rear is %d.\n",a[*r]);
}
void traversedq(int a[],int *f,int *r)
{
 int i;
 for(i=0;i<MAX;i++)
 {
  if(a[i]==-99 || a[i]==0)
    printf(" - ");
  else
    printf(" %d ",a[i]);
 }
}
