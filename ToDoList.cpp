#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct ToDoList{
	int id;
	string task;
};
int ID;
void banner();
void addtask();
void showtask();
int searchtask();
void deletetask();
void updatetask();

int main1(){
system("cls");
while(true)
{
  banner();
  cout<<"\n\t1.Add Task";
   cout<<"\n\t2.Show Task";
    cout<<"\n\t3.Search Task";
     cout<<"\n\t4.Delete Task";
      cout<<"\n\t5.Update Task";
      int choice;
      cout<<"\n\tEnter choice:";
      cin>>choice;
      switch(choice)
      {
      case 1:
      	addtask();
      	break;
      	case 2:
      	showtask();
      	break;
      	case 3:
      	searchtask();
      	break;
        case 4:
      	deletetask();
      	break;
        case 5:
      	updatetask();
      	break;
      }
}
return 0;
}

void banner(){
	cout<<"___________________________________"<<endl;
	cout<<"\t     WELCOME MY TODO LIST    "<<endl;
    cout<<"___________________________________"<<endl;
}
void addtask(){
	system("cls");
	banner();
	todolist todo;
	cout<<"Enter new task:"<<endl;
	cin.get();
	getline(cin,todo.task);
	char save;
	cout<<"save?(y/n):";
	cin>>save;
	if(save=='y')
	{
		ID++;
		ofstream fout;
		fout.open("todo.txt", ios::app);
		fout<<"\n"<<ID;
		fout<<"\n"<<todo.task;
		fout.close();

		char more;
		cout<<"Add more task?(y/n):";
		cin>>more;

		if(more=='y'){
			addtask();
		}
		else{
			system("cls");
			cout<<"Added Successfilly"<<endl;
			return;
		}
	}
	system("cls");
}

void showtask(){
	system("cls");
	banner();
	todolist todo;
	ifstream fin;
	fin.open("todo.txt");
	cout<<"Task:"<<endl;

   
   while(!fin.eof())
   {
   	fin>>todo.id;
   	fin.ignore();
   	getline(fin,todo.task);
   	if(todo.task!=""){
   		cout<<"\t"<<todo.id<<":"<<todo.task<<endl;
   	}
   	else{
   		cout<<"\tEmpty!"<<endl;
   	}
   }
   fin.close();
   char exit;
   cout<<"Exit?(y/n):";
   cin>>exit;
   if(exit!='y'){
   	showtask();
   }
   system("cls");
}
int searchtask(){
	system("cls");
	banner();
	int id;
	cout<<"Enter task id :";
	cin>>id;
	todolist todo;
	ifstream fin("todo.txt");
	while(!fin.eof())
	{
		fin>>todo.id;
		fin.ignore();
		getline(fin,todo.task);
		if(todo.id==id){
			system("cls");
			cout<<"\t"<<todo.id<<":"<<todo.task<<endl;
			return id;
		}
	}
	system("cls");
	cout<<"Not Found!"<<endl;
	return 0;
}
void deletetask(){
	system("cls");
	int id=searchtask();
	if(id!=0){
		char del;
		cout<<"\n\tDelete?(y/n):";
		cin>>del;
		if(del=='y'){
			todolist todo;
			ofstream tempfile;
			tempfile.open("temp.txt");
			ifstream fin;
			fin.open("todo.txt");
			int index=1;
			while(!fin.eof()){
				fin>>todo.id;
				fin.ignore();
				getline(fin,todo.task);
				if(todo.id!=id){
					tempfile<<"\n"<<index;
					tempfile<<"\n"<<todo.task;
                    index++;
                    ID--;
				}
			}
			fin.close();
			tempfile.close();
			remove("todo.txt");
			rename("temp.txt","todo.txt");
			system("cls");
			cout<<"\n\t Deleted Successfilly"<<endl;
		} 
		else{
			system("cls");
			cout<<"Not deleted "<<endl;
		}
	}
}
void updatetask(){
	system("cls");
	int id=searchtask();
	if(id!=0){
		char update;
		cout<<"\n\tupdate?(y/n):";
		cin>>delete;
		if(update=='y'){
			todolist todo;
			ofstream tempfile;
			tempfile.open("temp.txt");
			ifstream fin;
			fin.open("todo.txt");
			int index=1;
			while(!fin.eof()){
				fin>>todo.id;
				fin.ignore();
				getline(fin,todo.task);
				if(todo.id!=id){
					tempfile<<"\n"<<index;
					tempfile<<"\n"<<todo.task;
                    index++;
                    ID--;
				}
			}
			fin.close();
			tempfile.close();
			update("todo.txt");
			rename("temp.txt","todo.txt");
			system("cls");
			cout<<"\n\t update Successfilly"<<endl;
		} 
		else{
			system("cls");
			cout<<"Not updated "<<endl;
		}
	}
}