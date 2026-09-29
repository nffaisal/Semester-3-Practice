#include<iostream>
#include<cstring>
using namespace std;
/* Task: Create a Student struct with int id and float marks[3]. Dynamically allocate an array of $N$ students. Write a function to update the $j$-th mark of the student with ID $X$.Concepts Tested: Nested struct-array access through array pointers.
Hint: Find student index first using ID search, then modify arr[studentIndex].marks[markIndex]. */
struct Student{
    int id;
    string name;
    float marks[3];
};
void Details(Student *arr,int size){
    int total_size = sizeof(arr[0].marks)/sizeof(arr[0].marks[0]);
    if(arr !=NULL){
        for(int i =0;i<size;i++){
            cout<<"Enter ID: "; cin>>arr[i].id;
            cout<<"\nEnter name: "; cin.ignore(); getline(cin,arr[i].name);
            cout<<"\nEnter Marks: ";
            for(int j=0;j<total_size; j++){
                cin>>arr[i].marks[j];
            }
        }
    }
}
void find(Student *arr, int size, int studnetno, int marksno, int newmarks){
       int total_size = sizeof(arr[0].marks)/sizeof(arr[0].marks[0]);
     if(arr !=NULL){
        for(int i =0;i<size;i++){
            if(arr[i].id == studnetno){
            for(int j=0;j<total_size; j++){
                 if(arr[i].marks[j] ==marksno){
                    arr[i].marks[j] =newmarks;
                    break;
                 }
            }
        }
        }
    }
}
int main(){
    Student *students =new Student[4];
    Details(students,4);

}