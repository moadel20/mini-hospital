#include <iostream>
using namespace std ; 


void addStudent (string name , int id ) ;
void addStudent_beg (string name , int id  ) ;
void deleteStudent_id (int id ) ;
void searchStudent_id (int id ) ;
void display() ;
void reversStudent () ;
void countStudent (int numOf_student) ;


struct student {
    int id ;
    string name ; 
    student* next ; 
};

student* head = NULL  ; 

void addStudent (string name , int id ) {
    student* new_student = new student ;
    new_student->name = name ; 
    new_student->id = id ; 
    new_student->next = NULL ;

    if (head == NULL )
    {
        head = new_student ;
    }else
    {
        student* last = head ; 
        while (last->next != NULL )
        {
            last = last->next ;
        }
        last->next = new_student ;
        
    } 
}

void addStudent_beg (string name , int id  ) {
    student* new_student = new student ;
    new_student->name = name ;
    new_student->id = id ; 
    new_student->next = head  ;
    head = new_student ; 
}

void deleteStudent_id (int id ) {
    if (head == NULL ) return ;
    student* prev =NULL ;
    student* current = head ;
    if (head->id == id )
    {
        head = head->next  ;
        delete current ;
        return ;
    }
    while (current != NULL && current->id != id )
    {
        prev = current ; 
        current = current->next ;
    }
    
    if (current == NULL ){ 
        cout << "student not found\n" ; 
        return ;
    }
    prev->next = current->next;
    delete current;
}

void searchStudent_id (int id ) {
    student* sear = head   ;

    while (sear != NULL){ 
    if (sear->id == id ){
    
       cout << "Student Found: " << sear->name << "\t" << sear->id << endl;

        return;
    }
    sear = sear-> next ;
}
    cout << "student not Found\n" ;
}

void display () {
 student* temp = head ;
 while (temp != NULL )
 {   
    cout << temp->name <<"\t" << temp->id<<"\t "  ;
    temp = temp->next ; 
 }
 cout << endl ; 

}

void countStudent () {
    int count = 0  ;
    student* temp = head ; 

    while (temp != NULL)
    {
        count += 1 ;
        temp = temp->next ;
 
    }
            cout << "Number of student is: " << count << endl ;
    
}

void reverseStudent() {
    student* prev = NULL;
    student* current = head;
    student* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main()
{
    int chose ;

    cout<<"1-Add Student\n2- Delete Student\n3- Search Student\n4- Display\n5- Reverse\n6- Count\n 0-Exit" << endl ;

    while (true)
    { 
    cout <<"What do you want to do :" ; 
    cin >> chose ;

    if(chose == 1){
        string name ; 
         int id ;
         cin.ignore() ;

        cout <<"Enter Name: "  ;
        getline(cin, name) ;

        cout <<"Enter Id: "  ;
        cin >> id ;
        addStudent(name , id) ;
        cout<<"Done\n" ;
    


    }else if (chose == 2)
    {
        int id ; 
        cout <<"Enter Id: " << endl ;
        cin >> id ;
        deleteStudent_id(id) ;
    }else if (chose ==3) {
        int id ; 
        cout <<"Enter Id: " << endl ;
        cin >> id ;
        searchStudent_id(id) ;
        

    }else if (chose == 4 ){
         display() ;
    }else if (chose == 5 ){
        reverseStudent() ;
        display() ;
    }else if (chose == 6 ){

        countStudent() ;
    }else if (chose == 0 )

    {
        break;
    }
    

}
    
}