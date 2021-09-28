#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct std
{
	int s_code;
	char s_name[50];
	char mob[10];
	char email[50];
	struct std *next;
}STUDENT;

void Disp(STUDENT *start);
STUDENT *Clean(STUDENT *start);
void Save(STUDENT *start);
int main(int argc, char *argv[])
{
	char str[6];
	char ch='n';
	STUDENT *head, *temp, *new_node;
	head=temp=new_node=NULL;
	do
	{
		new_node=(STUDENT *)malloc(sizeof(STUDENT));
		new_node->next=NULL;
		
		printf("\nType Student Record: \n");
		printf("*********************\n");
		
		printf("Student Code: ");
		gets(str);
		new_node->s_code=atoi(str);
		
		printf("Student Name: ");
		gets(new_node->s_name);
			
		printf("Mobile Number: ");
		gets(new_node->mob);
		
		printf("Email ID: ");
		gets(new_node->email);
		
		if(head==NULL)
		{
			head=new_node;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=new_node;
		}
		
		printf("\nDo you want more record? ");
		ch=getch();
	}while(ch=='y');
	
	Disp(head);
	printf("\nWant to save? ");
	ch=getch();
	if(ch=='y')
	{
		Save(head);
	}
	
	head=Clean(head);
	return 0;
}
void Disp(STUDENT *start)
{
	
	STUDENT *temp;
	printf("\n** DISPLAYING DATABASE **\n");
	if(start==NULL)
	{
		printf("No record to display!");
	}
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("%d %s \t%s \t%s\n",temp->s_code, temp->s_name, temp->mob, temp->email);
			temp=temp->next;
		}
	}
}
void Save(STUDENT *start)
{
	FILE *fp;
	STUDENT *temp=start;
	STUDENT buffer;
	if(start==NULL)
	{
	
		printf("No record to save");
	}
	else
	{
		fp=fopen("std_master.txt","w");
		while(temp!=NULL)
		{
			buffer.s_code=temp->s_code;
			strcpy(buffer.s_name,temp->s_name);
			strcpy(buffer.mob, temp->mob);
			strcpy(buffer.email,temp->email);
			
			fwrite(&buffer,1,sizeof(STUDENT),fp);
			temp=temp->next;
		}
		printf("All Records saved!");
	}
}
STUDENT *Clean(STUDENT *start)
{
	STUDENT *temp;
	if(start!=NULL)
	{
		if(start->next==NULL)
		{
			free(start);
			start=NULL;
		}
		temp=start;
		while(temp->next->next!=NULL)
		{
			free(temp->next);
			temp->next=NULL;
		}
		free(temp);
		start=NULL;
	}
	return start;
}
