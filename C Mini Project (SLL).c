#include <stdio.h>
#include <stdlib.h>
struct node 
{
    char data;
    int count;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode() 
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    return x;
}
NODE insert_rear(NODE first, char item)
{
    NODE temp,prev,cur;
    temp = getnode();
    temp->data=item;
    temp->count=1;
    temp->link=NULL;
    if (first==NULL)
        return temp;
    cur=first;
    prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=temp;
    return first;
}
void encode_rle(NODE first,FILE *file) 
{
    NODE cur=first;
    while (cur!=NULL) 
    {
        char current=cur->data;
        int count=1;
        while (cur->link!= NULL&&cur->link->data==current) 
        {
            count++;
            cur=cur->link;
        }
        printf("%d%c",count,current);
        fprintf(file,"%d%c",count,current);
        cur=cur->link;
    }
}
void display_unencoded(NODE first) 
{
    NODE cur=first;
    printf("Unencoded content:\n");
    while(cur!=NULL) 
    {
        printf("%c",cur->data);
        cur=cur->link;
    }
    printf("\n");
}
int main() 
{
    FILE *fptr1,*fptr2;
    char f1[100],f2[100];
    NODE first=NULL;
    char ch;
    printf("Enter the input filename: ");
    scanf("%s",f1);
    fptr1=fopen(f1,"r");
    if (fptr1==NULL) 
    {
        printf("Error opening input file.\n");
        return 1;
    }
    while ((ch=fgetc(fptr1))!=EOF) 
    {
        first=insert_rear(first, ch);
    }
    fclose(fptr1);
    display_unencoded(first);
    printf("Enter the output filename: ");
    scanf("%s",f2);
    fptr2 =fopen(f2,"w");
    if(fptr2==NULL) 
    {
        printf("Error opening output file.\n");
        return 1;
    }
    encode_rle(first,fptr2);
    fclose(fptr2);
    printf("\nRun-length encoding completed. Encoded content written to %s.\n", f2);
    return 0;
}
