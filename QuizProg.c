/*
This code allows the user to build their own quizzes and saves the quiz in a output file where the user can access the code they built and paste it into their own files

NOTES: The getchars() without an assignment are used to ctach \n characters after user
input. Sometimes the start of a function will have a getchar() so it catches a previous
\n from some other place that called said function

fgets and strcpy tend to be better that scanf which doesnt catch the \n

*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//global variables


//variables for quiz takers
int wrongAns=0;
int skipped=0;
int totalQues=0;

int playable=0; //if playable=1 then the questions for the quiz were set

//variables for the quiz
	char quizName[50];
	char quizQuestions[20][50];
	char questionAns[20][50];
	
	int totalQuestions=0;
	

//function definitions
void setQues();
//save the quiz questions and answers in file
void saveQuiz();
void playGame();

char tempString[200];

main(){

	char ans='z'; int redo=1;
	while(redo!=0){
	if(ans!='\n'){ //catched the \n character in ans after user input
	printf("\t\tQuiz Builder\n");
	printf("What would you like to do?(type either a,b,c,d)\n");
	
	printf(" A.Name quiz\n B.set Quiz Questions/Ans\n C.Play Quiz\n D.Upload a quiz E.Save and Exit\n");
	}
	ans=getchar();
	ans=toupper(ans);
	char temp;
	switch(ans){
		case 'A':
			getchar();
			printf("What would you like to name your quiz? (max 50 chars)\n");
			fgets( tempString, sizeof(tempString), stdin);
			strcpy(quizName,tempString);
			printf("Your Quiz is now named: %s\n\n",quizName);
			break;
		case 'B':
			getchar();
			printf("How many questions do you want your quiz to be?(20 max)\n");
			temp=getchar();
			totalQues=temp-'0'; //to avoid \n problem we covert temp to int
			if(totalQues>20){
				printf("please try again\n");
			}else{
			getchar(); //catches newline char
			setQues();
			playable=1;}
			break;
		case 'C': //player wants to play there quiz
			if(playable!=0){
				playGame();
			}else{
				printf("Sorry, you haven't set Quiz Questions/Ans yet\n");
			}
			break;
		case 'D'://player wants to save there quiz
			if(playable!=0){
				
				saveQuiz();
			}else{
				printf("Sorry, you haven't set Quiz Questions/Ans yet\n");
				
			}printf("See ya!\n"); redo=0;
			break;
		case '\n': break;
		default:
			printf("I cannot understand you, please try again\n");
			break;

	}

	}

		printf("Thank you for using Quiz Builder!!!\n");
return 0;
}

void uploadAQuiz(){
	
	
	
	
}




void setQues(){
	char question[100];
	char ans[50];
	int i;
	for(i=0; i<totalQues; i++){
		printf("Enter question number %d below (max 100 characters long):\n",i+1);
		fgets(question, sizeof(question), stdin);
		strcpy(quizQuestions[i],question);

		printf("Enter the corresponding answer to question %d below (max 50 characters long):\n",i+1);
		fgets(ans, sizeof(ans), stdin);
		strcpy(questionAns[i],ans);
	}
	printf("A total of %d questions were set.\n",totalQues);
}

//Lets the user play his/her quiz
void playGame(){
	int l; 
	getchar(); //catches \n from switch statement of 'C' in main
	char ansDisplay[4][50];
	int i; int rAns; int rQues;
	for(i=0; i<totalQues; i++){

		rAns=(rand()%4); //place the true answer in stop 0=a,1=b,2=c, ir 3=d
		rQues; //initlaizes index for the other answers (worng answers)

		char ansNow; //hold the users answer to the question
		//prints the question
		printf("%d. %s\n",i+1,quizQuestions[i]);

		//based on rAns, the solution is place in either a,b,c,d and other sol
		//utions are placed on the spots not taken by rAns
		if(rAns==0){
			printf("A. %s\n",questionAns[i]);
			//make sure rQues doesnt equal the index of the REAL ans i.e. i
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			
			printf("B. %s\n",questionAns[rQues]);
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			printf("C. %s\n",questionAns[rQues]);
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			printf("D. %s\n",questionAns[rQues]);
		}else if (rAns==1){
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			printf("A. %s\n",questionAns[rQues]);
			
			
			printf("B. %s\n",questionAns[i]);
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			printf("C. %s\n",questionAns[rQues]);
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			printf("D. %s\n",questionAns[rQues]);
		}else if(rAns==2){
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			printf("A. %s\n",questionAns[rQues]);
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			
			printf("B. %s\n",questionAns[rQues]);
			
			printf("C. %s\n",questionAns[i]);
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			printf("D. %s\n",questionAns[rQues]);
		}else{
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			printf("A. %s\n",questionAns[rQues]);
			
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			printf("B. %s\n",questionAns[rQues]);
			do{
			rQues=rand()%totalQues;

			}while(rQues==i);
			printf("C. %s\n",questionAns[rQues]);
			
			printf("D. %s\n",questionAns[i]);
		}
		printf("Choose the answer by typing a,b,c,or d\n");
		ansNow=getchar();
		getchar();
		ansNow=toupper(ansNow);
		//TELLS the user whether or not there ans was correct if not, wrongans++
	switch(ansNow){
		case 'A':
			if(rAns!=0){
				printf("WRONG\n");
				wrongAns++;
				}else{ printf("CORRECT\n");}
			break;
		case 'B':
			if(rAns!=1){
				printf("WRONG\n");
				wrongAns++;
				}else{ printf("CORRECT\n");}
			break;
		case 'C': 
			if(rAns!=2){
				printf("WRONG\n");
				wrongAns++;
				}else{ printf("CORRECT\n");}
			break;
		case 'D':
			if(rAns!=3){
				printf("WRONG\n");
				wrongAns++;
				}else{ printf("CORRECT\n");}
			break;
		default: 	
			if(ansNow!='A' ||ansNow!='B' ||ansNow!='C'||ansNow!='D'){
			printf("You skipped\n");
			skipped++;}
			break;
		
	}
		}
	//calculates and prints the users final score
	float score=totalQues-wrongAns;
	score=score/totalQues;
	score=score*100;
	printf("DONE!\n\n\n Your score is: %.2f\n", score);
	printf("You got:\n %d correct answers \n %d wrong answers\n %d were skipped\n",(totalQues-wrongAns),wrongAns, skipped);
	printf("Thank you for playing!!!\n\n");

}

//saves the questions and answers from the create quiz int an output file for the user
void saveQuiz(){
	FILE *f;
	//open file to write into output.txt
	f=fopen("output.txt", "w");
	//write title of quiz on the first line of the file, near center
	fprintf(f, "\t\t%s",quizName);
	fprintf(f,"\n\n\n");

	int i;
	//write questions with their corresponding answers in the file
	for(i=0; i<totalQues; i++){
	fprintf(f,"%d. %s \n Ans: %s\n\n" ,i+1,quizQuestions[i],questionAns[i]);
	}
	fclose(f);

}
