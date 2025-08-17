#include <iostream>
using namespace std;
struct task {
string name;
int priority;
float time;
task* next;
};
class taskmanager {
task* head;
task* tail;
public:
taskmanager() {
head = NULL;
tail = NULL;
}
void addtask(string name, int priority, float time) {
task* newtask = new task;
newtask->name = name;
newtask->priority = priority;
newtask->time = time;
newtask->next = NULL;
if (head == NULL) {
head = newtask;
tail = newtask;
cout << "Task added successfully\n";
return;

}
else if (priority >= head->priority) {
newtask->next = head;
head = newtask;
}
else if (priority <= tail->priority) {
tail->next = newtask;
tail = newtask;
}
else {
task* ptr = head;
while (ptr->next != NULL && ptr->next->priority >= priority) {
ptr = ptr->next;
}
newtask->next = ptr->next;
ptr->next = newtask;
}
cout << "Task added successfully\n";
}
void deletetask(string name) {
if (head == NULL) {
cout << "No tasks to delete.\n";
return;
}
if (head->name == name) {
task* temp = head;
head = head->next;
delete temp;
if (head == NULL) tail = NULL;
cout << "Task \"" << name << "\" deleted successfully.\n";
return;
}
task* current = head;
task* prev = NULL;
while (current != NULL && current->name != name) {

prev = current;
current = current->next;
}
if (current == NULL) {
cout << "Task \"" << name << "\" not found.\n";
return;
}
prev->next = current->next;
if (current == tail) {
tail = prev;
}
delete current;
cout << "Task \"" << name << "\" deleted successfully.\n";
}
void totaltasksandtime() {
int count = 0;
float ttime = 0;
task* ptr = head;
while (ptr) {
count++;
ttime += ptr->time;
ptr = ptr->next;
}
cout << "Total tasks are " << count << endl;
cout << "Total time required is " << ttime << " hrs\n";
}
void prcounttask(int prio) {
int c = 0;
task* p = head;
while (p != NULL) {
if (p->priority == prio) {
c++;
}
p = p->next;

}
cout << "Number of tasks with priority " << prio << " is: " << c
<< endl;
}
void searchtask(string n) {
task* ptr = head;
while (ptr) {
if (ptr->name == n) {
cout << "Task found:\n";
cout << ptr->name << "\t" << ptr->priority << "\t" <<
ptr->time << " hrs\n";
return;
}
ptr = ptr->next;
}
cout << "Task not found\n";
}
void displaytask() {
if (head == NULL) {
cout << "No tasks to display\n";
return;
}
task* p = head;
cout << "Tasks List:\n";
cout << "Name\tPriority\tTime\n";
while (p != NULL) {
cout << p->name << "\t" << p->priority << "\t\t" << p->time <<
" hrs\n";
p = p->next;
}
}
void updatetask(string n){
task *ptr = head;
while(ptr){
if(ptr->name == n){
string nam;
int pr;

float t;
cout<<"Enter Updated Name:";
cin>>nam;
cout<<"Enter Updated Priority:";
cin>>pr;
cout<<"Enter Updated Time:";
cin>>t;
ptr->name = nam;
ptr->priority = pr;
ptr->time = t;
cout<<"Task Updated Successfully"<<endl;
return;
}
ptr = ptr->next;
}
}
void performTask() {
if (head == nullptr) {
cout << "No tasks to perform.\n";
return;
}
cout << "Performing task: " << head->name
<< " (Priority: " << head->priority
<< ", Time: " << head->time << " hrs)\n";
task* temp = head;
head = head->next;
delete temp;
}
};
int main() {
taskmanager tm;
tm.addtask("Study",3,7);
tm.addtask("Sleep",4,6);
tm.addtask("Play",1,3);
tm.addtask("Print",5,1);
tm.addtask("Bath",3,7);
tm.addtask("Talk",4,6);
tm.addtask("Pay",1,3);
tm.addtask("Press",5,1);

tm.addtask("Stand",3,7);
tm.addtask("Run",4,6);
tm.addtask("Walk",1,3);
tm.addtask("Type",5,1);
tm.addtask("Drive",3,7);
tm.addtask("Throw",4,6);
tm.addtask("Eat",1,3);
tm.addtask("Climb",5,1);
int choice;
do {
cout << "\n--- Task Manager Menu ---\n";
cout << "1. Add Task\n";
cout << "2. Delete Task\n";
cout << "3. Display All Tasks\n";
cout << "4. Count All Tasks\n";
cout << "5. Count Tasks by Priority\n";
cout << "6. Search Task by Name\n";
cout << "7. Update Task \n";
cout << "8. Perform Task (Highest Priority + Shortest Time)\n";
cout << "9. Exit\n";
cout << "Enter your choice: ";
cin >> choice;
cin.ignore(); // To ignore leftover newline after integer input
if (choice == 1) {
string name;
int priority;
float time;
cout << "Enter task name: ";
getline(cin, name);
cout << "Enter priority (1-5): ";
cin >> priority;
cout << "Enter time required (hours): ";
cin >> time;
cin.ignore();
tm.addtask(name, priority, time);
}
else if (choice == 2) {
string name;
cout<<"Enter task name to delete:";

cin>>name;
tm.deletetask(name);
}
else if (choice == 3) {
tm.displaytask();
}
else if (choice == 4) {
tm.totaltasksandtime();
}
else if (choice == 5) {
int prio;
cout << "Enter priority to count: ";
cin >> prio;
cin.ignore();
tm.prcounttask(prio);
}
else if (choice == 6) {
string name;
cout << "Enter task name to search: ";
cin>>name;
tm.searchtask(name);
}
else if (choice == 7) {
string name;
cout << "Enter task name to update: ";
cin>>name;
tm.updatetask(name);
}
else if (choice == 8) {
tm.performTask();
}
else if (choice == 9) {
cout << "Exiting program...\n";
}
else {
cout << "Invalid choice! Please try again.\n";
}
} while (choice != 9);
return 0;
}