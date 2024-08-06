#include<stdio.h>
#define num 9
struct emp{
	int jobid;
	char name[90];
};
//int n;
//printf("Enter the number of employees: \n");
//scanf("%d",&n);
struct emp emp1[num];

	int f=-1;
	int r=-1;
	int isfull(){
	    if(r==num-1){
	  	return 1;
	    }
        else {
            return 0;
        }
	    
	}
	int ismt(){
	    if(f==r){
            return 1;
	    }
        else return 0;
    }
	void enq(){
		if(isfull()){
			printf("The queue is full.\n");
		}
		else{
			r++;
			printf("Enter the job id: \n");
			scanf("%d",&emp1[r].jobid);
			printf("Enter the name: \n");
			scanf("%s",emp1[r].name);
		}
	}
	void dq(){
		if(ismt()){
			printf("Queue is already empty.\n");
		}
		else{
			f++;
		}
	}
	
	void display(){
		for(int i=f+1;i<=r;i++){
			printf("Jobid: %d\n",emp1[i].jobid);
			printf("Name: %s\n",emp1[i].name);
		} 
	}

int main(){
	
	
	/*for(int i=0;i<num;i++){
		printf("Enter the Job Id of employee no. %d : \n",i+1);
		scanf("%d",&emp1[i].jobid);
		printf("Enter the name: \n");
		scanf("%s",emp1[i].name);
	}
	for(int i=0;i<num;i++){
		printf("The job id is: %d\n",emp1[i].jobid);
		printf("The name is: %s\n",emp1[i].name);
	}*/
	int ch;
    do{
	printf("Menu is: \n 1.Add element.\n 2.Delete element\n 3.check if queue is empty.\n4.Check if queue is full.\n");
	printf("Enter your choice: \n");
	scanf("%d",&ch);
	switch(ch){
	
		case 1:
			enq();
			display();
            break;
		
		case 2:
			dq();
			display();
            break;
		case 3:
			ismt();
			display();
            break;
		
		case 4:
			isfull();
			display();
            break;
		case 5:
			printf("Code exiting...\n");
			break;
    }
    }while(ch!=5);
	
	
	
	return 0;
}
