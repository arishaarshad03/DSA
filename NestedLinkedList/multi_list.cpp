#include <iostream>
#include <cstdlib>
using namespace std;

struct SNode {
    string SNo;
    SNode* next;
};

struct CNode{
    string CNo;
    CNode* next;
    SNode* stu_list;
};
CNode* clist = nullptr;

void insert_course(string course){
    // check for duplicates
    CNode* check = clist;
    while (check!= nullptr){
        if (check->CNo == course){
            cout <<"course already exist\n";
            return;
        }
        check= check->next;
    }
    CNode* ctemp = new CNode;
    ctemp->CNo = course;
    ctemp->next = nullptr;
    ctemp->stu_list = nullptr;

    if (clist == nullptr){
        clist = ctemp;
        cout << "insertion successful!\n";
        return;
    }

    CNode* ccur = clist;
    while (ccur->next != nullptr){
        ccur = ccur->next;
    }

    ccur->next = ctemp;
    cout << "insertion successful!\n";
}


void insert_student(string seatno, string course){
    CNode* ccur = clist;
    while (ccur != nullptr){
        if (ccur ->CNo == course){

            // check for duplicate
            SNode* check = ccur->stu_list;
            while (check!= nullptr){
                if (check->SNo == seatno){
                    cout <<"student is already enrolled in: "<<course;
                    return;
                }
                check= check->next;
            }

            SNode* stemp = new SNode;
            stemp->SNo = seatno;
            stemp->next = nullptr;

            // adding first student
            if (ccur ->stu_list == nullptr){
                ccur ->stu_list = stemp;
                cout <<"student "<<seatno<<" added successfully\n";
                return;
            }
            // students already exist add at the end
            SNode* scur = ccur ->stu_list;
            while (scur ->next != nullptr){
                scur = scur -> next;
            }
            scur -> next = stemp;
            cout <<"student "<<seatno<<" added successfully\n";
            return;
        }
        ccur = ccur ->next;
    }
    cout<< "Course "<<course<<" is not offered\n";
}

void display_all(){
    if (clist == nullptr){
        cout<< "no courses exist\n";
        return;
    }
    CNode* ccur = clist;
    while (ccur != nullptr){
        cout<< "course number: "<< ccur->CNo <<"\n";
        if (ccur->stu_list == nullptr){
            cout<<"no students enrolled\n";
        }
        else{
            SNode* scur = ccur->stu_list;
            cout<< "Students: ";
            while (scur!= nullptr){
                cout<<scur->SNo<<" , ";
                scur= scur->next;
            }
            cout <<endl;

        }
        ccur = ccur ->next;
    }
}

void course_student_display(string cno){
    CNode* ccur = clist;
    if (clist == nullptr){
        cout <<"courses doesn't exist\n";
        return;
    }
    while (ccur != nullptr){
        if (ccur ->CNo == cno){
            SNode* scur = ccur ->stu_list;
            if (ccur ->stu_list == nullptr){
                cout <<"no students enrolled\n";
                return;
            }
            else{
                while (scur != nullptr){
                    cout << scur->SNo <<" | ";
                    scur = scur ->next;
                }

            }
            cout<< endl;
            return;
        }
        ccur = ccur ->next;
    }
    cout <<"course "<< cno<<" doesn't exist\n";
}

void search_course (string cno){
    if (clist == nullptr){
        cout << "no courses are offered\n";
        return;
    }
    else {
        CNode* ccur = clist;
        int pos = 1;
        while (ccur != nullptr){
            if (ccur ->CNo == cno){
                cout << "course found at number: "<< pos;
                return;
            }
            ccur = ccur->next;
            pos++;
        }
        cout <<"course "<< cno <<" is not in the list\n";
    }
}

void display_course(){
    if (clist == nullptr){
        cout << "no courses are available\n";
        return;
    }
    else {
        CNode* ccur = clist;
        while (ccur != nullptr){
            cout << ccur ->CNo <<endl;
            ccur = ccur ->next;
        }
    }
}

void remove_course (string cno){
    if (clist == nullptr){
        cout << "no courses available \n";
        return;
    }
    CNode* prev = nullptr;
    CNode* ccur = clist;

    while (ccur != nullptr){

        if (ccur ->CNo == cno){
            // remove head node
            if (prev == nullptr){
                clist = clist ->next;
            }
            // delete middle or last node
            else {
                prev ->next = ccur ->next;
            }
            SNode* scur = ccur ->stu_list;
            while ( scur != nullptr)
                {
                    SNode* temp = scur;
                    scur = scur ->next;
                    delete temp;
                }

            delete ccur;
            cout<< "course "<< cno<< " deleted\n";
            return;
        }
        prev = ccur;
        ccur = ccur ->next;
    }
    cout <<"course "<<cno<<" doesnt exist\n";
    
}

void remove_stu_from_course(string sno, string cno){
    if (clist == nullptr){
        cout << "no courses available \n";
        return;
    }
    CNode* ccur = clist;
    while (ccur != nullptr){
        if (ccur ->CNo == cno){
            SNode* scur = ccur ->stu_list;
            SNode* prev = nullptr;
            while (scur != nullptr)
            {
                if (scur->SNo == sno){
                    // delete head
                    if (prev == nullptr){
                        ccur ->stu_list = scur ->next;
                    }
                    // delete middle or end node
                    else{
                        prev ->next = scur ->next;
                    }
                    delete scur;
                    cout <<"student "<<sno <<" removed from course "<<cno<<"\n";
                    return;
                }
                prev = scur;
                scur = scur ->next;
            }
            cout << "student "<<sno <<" not found in course "<<cno<<"\n";
            return;
            
        }
        ccur = ccur->next;
    }
    cout <<"course "<<cno <<" doesnt exist\n";

}

void search_student_in_course (string sno, string cno){
    if (clist == nullptr){
        cout << "no courses available \n";
        return;
    }
    CNode* ccur = clist;
    while (ccur != nullptr){
        if (ccur ->CNo == cno){
            SNode* scur = ccur ->stu_list;
            int pos = 1;
            while (scur != nullptr){
                if (scur ->SNo == sno){
                    cout <<"student found at index "<<pos <<endl;
                    return;
                }
                scur = scur ->next;
                pos ++;
            }
            cout << "student "<<sno <<" doesnt exist in course "<<cno<<endl;
            return;
        }
        ccur = ccur ->next;
    }
    cout <<"course "<<cno << " doesnt exist\n";
}

void search_stu_ineverycourse(string sno){
    if (clist == nullptr){
        cout << "no courses available\n";
        return;
    }
    bool found = false;
    CNode* ccur = clist;
    while (ccur != nullptr){
        SNode* scur = ccur ->stu_list;
        int index = 1;

        while (scur!= nullptr){
            if (scur->SNo == sno){
                if (!found){
                    cout << sno << " is enrolled in following courses: \n";
                }
                found = true;
                cout << ccur->CNo <<" at index: "<<index <<endl;
                break;
            }
            scur = scur ->next;
            index++;
        }
        ccur = ccur ->next;
    }
    if (!found){
        cout <<"student "<<sno<< " is not enrolled in any course\n";
        return;
    }

}

void delete_stu_fromeverycourse(string sno){
    if (clist == nullptr){
        cout << "no courses available\n";
        return;
    }
    bool found = false;
    CNode* ccur = clist;
    while (ccur != nullptr){
        SNode* scur = ccur ->stu_list;
        SNode* prev = nullptr;
        while (scur != nullptr){
            if (scur ->SNo == sno){
                found = true;
                if (prev == nullptr){
                    ccur->stu_list = scur->next;
                }
                else{
                    prev ->next = scur ->next;
                }
                delete scur;
                break;
            }
            prev = scur;
            scur = scur->next;
        }
        ccur = ccur->next;
    }
    if (!found){
        cout <<"student "<<sno<< " is not enrolled in any course\n";
    }
    else{
        cout <<"student "<<sno<<" removed from every course\n";
    }
}


int main() {
    int choice;
    string course, sno;

    while (true) {
        cout << "\n===== COURSE MANAGEMENT SYSTEM =====\n";
        cout << "1. Insert a new course\n";
        cout << "2. Insert student into a course\n";
        cout << "3. Display all courses and students\n";
        cout << "4. Display students of a specific course\n";
        cout << "5. Search for a course\n";
        cout << "6. Display all courses\n";
        cout << "7. Remove a course\n";
        cout << "8. Remove a student from a course\n";
        cout << "9. Search student in a course\n";
        cout << "10. Search student in all courses\n";
        cout << "11. Delete student from all courses\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter course number: ";
                cin >> course;
                insert_course(course);
                break;
            case 2:
                cout << "Enter student seat number: ";
                cin >> sno;
                cout << "Enter course number: ";
                cin >> course;
                insert_student(sno, course);
                break;
            case 3:
                display_all();
                break;
            case 4:
                cout << "Enter course number: ";
                cin >> course;
                course_student_display(course);
                break;
            case 5:
                cout << "Enter course number: ";
                cin >> course;
                search_course(course);
                break;
            case 6:
                display_course();
                break;
            case 7:
                cout << "Enter course number to remove: ";
                cin >> course;
                remove_course(course);
                break;
            case 8:
                cout << "Enter student seat number: ";
                cin >> sno;
                cout << "Enter course number: ";
                cin >> course;
                remove_stu_from_course(sno, course);
                break;
            case 9:
                cout << "Enter student seat number: ";
                cin >> sno;
                cout << "Enter course number: ";
                cin >> course;
                search_student_in_course(sno, course);
                break;
            case 10:
                cout << "Enter student seat number: ";
                cin >> sno;
                search_stu_ineverycourse(sno);
                break;
            case 11:
                cout << "Enter student seat number: ";
                cin >> sno;
                delete_stu_fromeverycourse(sno);
                break;
            case 12:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
