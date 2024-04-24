#include<iostream>
#include<iomanip>
using namespace std;

struct node{
    string name;
    int reg;
    string branch;
    int year;
    node* next;
};

node* head = NULL;

void add()
{
    node* temp = new node();
    node *t = head;
    cout<<"Enter name: ";
    cin>>temp->name;
    cout<<"Enter register number: ";
    cin>>temp-> reg;
    cout<<"Enter branch: ";
    cin>>temp->branch;
    cout<<"Enter year: ";
    cin>>temp->year;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        while(t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
}

void modify(int x)
{
    node* t = head;
    while(t->reg != x)
    {
        t = t->next;
    }
    cout<<"Enter name: ";
    cin>>t->name;
    cout<<"Enter branch: ";
    cin>>t->branch;
    cout<<"Enter year: ";
    cin>>t->year;
}

void del(int x)
{
    node* t = head;

    node* temp = head;
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    while(t->next->reg != x)
    {
        t = t->next;
    }
    temp = t->next;
    t->next = temp->next;
    free(temp);
}

void printify()
{
    node *t = head;
    cout<<left<<setw(15)<<"Name"<<left<<setw(19)<<"Register Number"<<left<<setw(10)<<"Branch"<<left<<setw(4)<<"Year"<<endl;

    while(t->next != NULL)
    {
        cout<<left<<setw(15)<<t->name<<left<<setw(19)<<t->reg<<left<<setw(10)<<t->branch<<left<<setw(4)<<t->year<<endl;
        t = t->next;
    }
    if(t->next == NULL){
        cout<<left<<setw(15)<<t->name<<left<<setw(19)<<t->reg<<left<<setw(10)<<t->branch<<left<<setw(4)<<t->year<<endl;
    }


}

void searchStudent(int x){
    node* temp = head;
    while(temp->reg != x){
        temp = temp -> next;
    }
    cout<<left<<setw(15)<<"Name"<<left<<setw(19)<<"Register Number"<<left<<setw(10)<<"Branch"<<left<<setw(4)<<"Year"<<endl;
    cout<<left<<setw(15)<<temp->name<<left<<setw(19)<<temp->reg<<left<<setw(10)<<temp->branch<<left<<setw(4)<<temp->year<<endl;


}

int main(){
    cout<<"STUDENT MANAGEMENT SYSTEM\n\n";
    int n;
    while(1)
    {

        cout<<"\n\nEnter 0 to exit"<<endl;
        cout<<"Enter 1 to Add a student data"<<endl;
        cout<<"Enter 2 to Modify a student data"<<endl;
        cout<<"Enter 3 to Delete a student data"<<endl;
        cout<<"Enter 4 to Display all student data"<<endl;
        cout<<"Enter 5 to Search for a student data\n\n"<<endl;
        cin>>n;
        if(n==0){
            break;
        }
        else if(n == 1)
        {
            add();
        }
        else if(n==2)
        {
            int x;
            cout<<"Enter the register number:  ";
            cin>>x;
            modify(x);
        }
        else if(n == 3)
        {
            int x;
            cout<<"Enter the register number to delete:  ";
            cin>>x;
            del(x);
        }
        else if(n==4)
        {
            printify();
        }
        else if(n == 5){
            int x;
            cout<<"Enter the register number to search:  ";
            cin>>x;
            searchStudent(x);
        }
    }


}
