#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>

struct student {
		char *name;
		int middle;
		int final;
	};



int compare(const void *cp1, const void *cp2)
{
	return strcmp(((struct student *)cp1)->name, ((struct student *)cp2)->name);
}

void print_node(const void *studentptr, VISIT order, int level)
{
	if(order == preorder || order == leaf)
	{
		printf("이름 = %-10s, 중간 점수 = %d, 기말 점수 = %d\n",
			(*(struct student **)studentptr)->name,
			(*(struct student **)studentptr)->middle,
			(*(struct student **)studentptr)->final);
	}
}

int main()
{
	int snum;
	
	printf("Enter student num : ");
	scanf("%d", &snum);
	
	struct student *root = NULL;
	char *nameptr = (struct student *)malloc(10 * snum * sizeof(struct student));
	struct student *studentptr = (struct student *)malloc(snum * sizeof(struct student));
	struct student **ret;
	
	if(nameptr == NULL|| studentptr == NULL) {
		printf("memory setting failed\n");
		exit(1);
	}
	
	for(int i = 0 ; i<snum ; i++)
	{
		printf("Enter student[%d] Info (name middle final) : ", i);
		scanf("%s %d %d", nameptr, &studentptr->middle, &studentptr->final);
		
		studentptr->name = nameptr;
		
		/*트리에 넣기*/
		ret = (struct student **)tsearch((void *)studentptr, (void **)&root, compare); 
		printf("\"%s\" 님이 ", (*ret)->name);
		if(*ret == studentptr) printf("트리에 추가되었습니다.\n");
		else 
		{
			printf("트리에 이미 존재합니다.\n");
			i--;
			continue;
		}
		nameptr += strlen(nameptr)+1;
		studentptr++;
	}
	twalk((void *)root, print_node);
}
