#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

u32 sluts[5]={0};

struct node
{
  u32 name[20] ;
  u8 age;
  u32 gender[10];
  u32 id;
  struct node * next;
};
struct node * head=NULL;
struct node * tail=NULL;

struct node * find_id(u32 key);
void edit_patient(void);
int add_patient(void);
void reserve_slut(void);
u8 search_id(u32 id);
void cancel_reserve(void);
void view_record(void);
void view_reserve(void);

//#############################################################################
int main (void){
  u8 mode,i,admin_option,inf=0,user_option;
  u16 input_pass;
  
  while(inf==0){//inf loop

  printf("\n for Admin mode, enter 1\n for user mode, enter 2:\n");
  scanf("%d",&mode);

  if(mode==1){    // Admin mode 
    printf("\n enter your password :\n");
    
    for(i=0;i<3;i++){  //Admin password iteration
      scanf("%d",&input_pass);
      if(input_pass==1234){
	break;
      }//if input_pass
      printf("\n incorrect pass, try again:\n");
    }// password for loop

    if(i==3) {return 0;}//if all the three tries of password are wrong

    // now we are the Admin mode
    printf("\n\n enter an option number :\n 1- Add new patient record\n 2- Edit patient record\n 3- Reserve a slut with the doctor\n 4- Cancel reservation\n\n");
    scanf("%d",&admin_option);
    
    if(admin_option==1){//add new patient
      struct node *out;

      out=add_patient();

    }

    else if(admin_option==2){// edit patient
      edit_patient();

    }

    else if(admin_option==3){// reservation
      reserve_slut();

    }

    else if(admin_option==4){// cancel reservation
      cancel_reserve();

    }

    else{return 0;}//wrong input option
    
    
  }//if mode 1

  else if(mode==2){
    

    printf("\n\nChoose option number :\n\t1- View patient record\n\t2- View today's reservations\n\n");
    scanf("%d",&user_option);
    if(user_option==1){// view patient record
      view_record();


    }

    else if(user_option==2){// View reservations
      view_reserve();

    }


  }// if mode 2


  }// inf loop

}//main function

//###########################################find_id###############################################################
struct node * find_id(u32 key){

  struct node * ptr;
  ptr=head;
  while(ptr!=NULL)
    {
      if(ptr->id==key)
        {
	  return ptr;
        }
      ptr=ptr->next;
    }
  return NULL;
  
}

//##########################################ADD_PATIENT############################################################
int add_patient(void)
{
  struct node * ptr;
  struct node *id_check;
  u8 i=0,j;
  u32 temp;

  ptr=(struct node *)malloc(sizeof(struct node));
 
  //**********************************ID*******************
  printf("\n\n Enter patient ID: \n\n ");
  for(i=0;i<3;i++){
    scanf("%d",&temp);
    id_check=find_id(temp);
    if(id_check==NULL){
      ptr->id=temp;
      printf("\n\nDONE\n\n");
      break;
    }
    printf("\n\nID is exist!, choose another one:\n\n");
  }
  if(i==3){return 0;}//in case wrong id 3 times!
    //*****************************************************

    // Name
  printf("\nEnter the name :\n ");
  for(j=0;j<20;j++)
    {
      scanf("%c",&(ptr->name[j]));
    }

  // gender
  i=0;
  printf("\nEnter the gender :\n ");
      for(j=0;j<10;j++)
    {
      scanf("%c",&(ptr->gender[j]));
    }

  // age
  printf("\nEnter the age :\n ");
  scanf("%d",&(ptr->age));
  printf("\n\nDONE!\n\n");

  if(head == NULL)
    {
      head = ptr;
      tail = ptr;
      ptr->next=NULL;
    }
  else
    {
      tail->next=ptr;
      tail=ptr;
      tail->next=NULL;
    }
  return ptr;
}
//##############################################################################################


void edit_patient(void){
  u32 edited_id;
  struct node *id_check;
  u8 i,j=0,k;

  printf("\n\n enter ID to edit :\n");
  for(i=0;i<3;i++)  {
    scanf("%d",&edited_id);
    id_check=find_id(edited_id);

    if(id_check!=NULL){// edit the data inside this ID
  
      
      // Name
      printf("\n\nEnter the name :\n ");
      for(k=0;k<20;k++)
	{
	  scanf("%c",&(id_check->name[k]));
	}
      
      // gender
      k=0;
      printf("\nEnter the gender :\n ");
      for(k=0;k<10;k++)
	{
	  scanf("%c",&(id_check->gender[k]));
	}
      
      
      // age
      printf("\nEnter the age :\n ");
      scanf("%d",&(id_check->age));
      printf("\n\nDONE!\n\n");
      break;
    }// end of "if"
    else{
      printf("\n ID doesn't exist!, try again : \n");

    }//end of else

  }// end of for loop

}// function end

//################################################################add_reservation###############

void reserve_slut(void){
  u32 ID;  
  struct node *id_check1;
  u8 slut,i,k=0;
  
  
  
  printf("\n1- from 2:00 to 2:30");
  if(sluts[0]!=0){
    printf("\tNot available");
  }
  printf("\n2- from 2:30 to 3:00");
  if(sluts[1]!=0){
    printf("\tNot available");
  }
  printf("\n3- from 3:00 to 3:30");
  if(sluts[2]!=0){
    printf("\tNot available"); 
  }
  printf("\n4- from 4:00 to 4:30");
  if(sluts[3]!=0){
    printf("\tNot available"); 
  }
  printf("\n5- from 4:30 to 5:00");
  if(sluts[4]!=0){
    printf("\tNot available"); 
  }
 

  printf("\nEnter patient ID\n");
  
  for(i=0;i<3;i++)  {
    scanf("%d",&ID);
    id_check1=find_id(ID);

    if(id_check1!=NULL){// ID exist
      printf("\nEnter the slut number for reservation\n");
      scanf("%d",&slut);
      sluts[slut-1]=ID;
      printf("\nDONE\n");
      break;
    }// end of if 
    printf("\nID doesn't exist! try again.\n\n");

  }// end of for loop

}// end of function




//#########################################search_in_sluts#####

u8 search_id(u32 id){
  u8 i;
  for(i=0;i<5;i++){
    if(id==sluts[i]){
      return i;
    }// end of if

  }// end of for loop
  return NULL;

}// end of function



//#########################################cancel#################
void cancel_reserve(void){
  u32 ID;
  struct node *id_check2;
  u8 i,slut_index;

  printf("\nEnter patient ID\n");
  
  for(i=0;i<3;i++)  {
    scanf("%d",&ID);
    id_check2=find_id(ID);

    if(id_check2!=NULL){// ID exist
      slut_index=search_id(ID);
      if(slut_index!=NULL){// reservation is exist
	sluts[i]=0;
	printf("\nDONE\n");
	break;
      }//end of reservation if
      printf("\nNo reservation for this ID!\n");
    }// end of ID exist if 
    printf("\nID doesn't exist! try again.\n");

  }// end of for loop



}// end of function


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% USER_MODE %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


void view_record(void){
  u32 ID;
  u8 i,j;
  struct node*id_check3;

 printf("\n\n Enter the ID of the Patient \n: ");
  for(i=0;i<3;i++){
    scanf("%d",&ID);
    id_check3=find_id(ID);
    if(id_check3!=NULL){// id is exist
      printf("\n Name :\t");
      for(j=0;j<20;j++){// print name
	printf("%c",id_check3->name[j]);
      }// print name for loop 


      printf("\n Gender :\t");
      for(j=0;j<10;j++){// print gender
	printf("%c",id_check3->gender[j]);
      }// print gender for loop 

      printf("\n Age :\t%d",id_check3->age);

      printf("\n ID :\t%d",id_check3->id);


      break;
    }// id is exist
    printf("\nID does's exist! try again.:\n");
  }// end of for loop


}// end of function



void view_reserve(void){


 
  printf("\n1- from 2:00 to 2:30");
  if(sluts[0]==0){
    printf("\t available");
  }
  else{
    printf("\t ID:   %d",sluts[0]);
  }
 
  printf("\n2- from 2:30 to 3:00");
  if(sluts[1]==0){
    printf("\t available");
  }
  else{
    printf("\t ID:   %d",sluts[1]);
  }
  printf("\n3- from 3:00 to 3:30");
  if(sluts[2]==0){
    printf("\t available"); 
  }
  else{
    printf("\t ID:   %d",sluts[2]);
  }
  printf("\n4- from 4:00 to 4:30");
  if(sluts[3]==0){
    printf("\t available"); 
  }
  else{
    printf("\t ID:   %d",sluts[3]);
  }
  printf("\n5- from 4:30 to 5:00");
  if(sluts[4]==0){
    printf("\t available"); 
  }
  else{
    printf("\t ID:   %d",sluts[4]);
  }
 




}// end of function
