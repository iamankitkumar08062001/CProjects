#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/*----------------------ARRANGEMENT MODEL-----------------------------
                     --NULL--
			|
			|
                 -----home--------
                 /     \         \
		/       \         \
	    folder1--->folder2-->folder3-->NULL
	         /      \
		/         \
       sub-folder1-->sub-folder2-->NULL
            |              |
       	    |              |
           NULL          NULL
*/
//this is a attempt to make linux file system tree(loose re-creation) using
//left-child, right-sibling representation of a tree

struct node{
	struct node *parent;
	struct node *left_child;
	struct node *right_sibling;
	char dir_name[100];
};

typedef struct node node;

#define NEW_CONTINUE(str)({\
	free(command);\
	continue;\
})

//linux commands name will be same in this program
//for example
//ls will be used to list all child directries
//cd will be used to navigate to a given folder
//ls -R will be used to list all files below the parent node, etc

//supported commands
//1. cd folder_name
//2. ls
//   Options:-
//   i. -R
//3. pwd
//4. mkdir folder_name

//to be implemented
//1.rm
//2.rmdir
//3.rm -R

//functions
void current_dir(node *);                   //main_function
void init(node *,char *,node *);           //to initialise a node
void print_children(node *,int);          //ls -R and ls
void add_folder(node *,char *);          //mkdir
void navigate_to(node *,char *);        // cd

int main()
{
	printf("\n\nTHIS PROGRAM IS AN ATTEMPT TO CREATE LINUX FILE TREE SYSTEM...\n\n");
	node home;
	init(&home,"home",NULL);
	current_dir(&home);
	//commands
	printf("\n\nTHANK YOU FOR USING MY PROGRAM...\n\n");
	return 0;
}

void current_dir(node *dir)
{
	char *command;
	while(strcmp(command,"exit")!=0 && strcmp(command,"logout")!=0)
	{
		command=(char *)malloc(sizeof(char)*10);
		printf("\nENTER COMMAND : ");
		scanf(" %[^\n]s",command);
		if(strcmp(command,"pwd")==0)
		{
			printf("\n%s",dir->dir_name);
			NEW_CONTINUE(command);
		}
		if(strcmp(command,"ls")==0)
		{
			print_children(dir,0);
			NEW_CONTINUE(command);
		}
		if(strcmp(command,"ls -R")==0)
		{
			print_children(dir->left_child,1);
			NEW_CONTINUE(command);
		}
		if(strstr(command,"mkdir")!=NULL)
		{
			if(*(command+5)=='\0')
			{
				printf("\nENTER A VALID FOLDER NAME!!!");
				continue;
			}
			add_folder(dir,command+6);
			NEW_CONTINUE(command);
		}
		if(strstr(command,"cd")!=NULL)
		{
			if(*(command+3)=='\0')
			{
				printf("\nENTER A VALID FOLDER NAME!!!");
				continue;
			}
			navigate_to(dir,command+4);
			NEW_CONTINUE(command);
		}
	}
	return;
}

void init(node *dir,char *folder_name,node *parent_dir)
{
	dir->parent=parent_dir;
	dir->left_child=NULL;
	dir->right_sibling=NULL;
	stpcpy(dir->dir_name,folder_name);
	return;
}

void print_children(node *dir,int choice)
{
	//choice=0 for ls
	//choice=1 for ls -R
	if(choice==0)
	{
		node *temp=dir->left_child;
		while(temp!=NULL)
		{
			printf("%s ",temp->dir_name);
			temp=temp->right_sibling;
			printf("\n");
		}
	}
	else
	{
		if(dir==NULL)
		{
			return;
		}
		if(dir->left_child==NULL)
		{
			print_children(dir->right_sibling,1);
		}
		else
		{
			printf("\n");
			print_children(dir->left_child,1);
		}
		printf(dir->dir_name);
	}
	return;
}

void add_folder(node *dir,char *folder_name)
{
	node *new=(node *)malloc(sizeof(node));
	init(new,folder_name,dir);
	if(dir->left_child==NULL)
	{
		return;
	}
	else
	{
		node *temp=dir->left_child->left_child;
		while(temp->right_sibling!=NULL)
		{
			temp=temp->right_sibling;
		}
		init(new,folder_name,dir);
		temp->right_sibling=new;
	}
	return;
}

void navigate_to(node *dir,char *folder_name)
{
	if(strcmp(folder_name,".")==0)
	{
		return;
	}
	if(strcmp(folder_name,"..")==0)
	{
		if(dir->parent)
		{
			return;
		}
		else
		{
			current_dir(dir->parent);
			return;
		}
	}
	node *temp=dir->left_child;
	while(temp!=NULL)
	{
		if(strcmp(temp->dir_name,folder_name)==0)
		{
			current_dir(temp);
			return;
		}
		temp=temp->right_sibling;
	}
	printf("\n\nINVALID FOLDER NAME!!!\n\n");
	return;
}

//debugging line
//	printf("****************CHECK********************");
