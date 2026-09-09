#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Course{
    int credits;
    float grade;
};
void gpaCalc( int totalCredits, float totalGradePoints){

    if (totalCredits == 0) return;
    float gpa = totalGradePoints / totalCredits;
    
    cout << " Total Credit Hours: " << totalCredits << endl;
    cout << " GPA: " << fixed<<setprecision(2)<<gpa << endl;
    

}
int getCreditHours(){
    int creditHours;
    while(true){
        cin>>creditHours;
        if(cin.fail()){                                     //String input
            cin.clear();
            cin.ignore(10000,'\n');
            cout<<"ERROR : Please do not input data types other than integers.\n"<<"input --Credit Hours:";
        }
        else if(creditHours<0 || creditHours>6){
            
            cin.ignore(10000,'\n');                     
            cout<<"You have entered a number outside our university credit interval [0,6].\n"<<"input --Credit Hours:";
        }
        else{
            cin.ignore(10000,'\n');
            break;
        }
        }
    
return creditHours;}


float getCourseGrade() {
    float courseGrade;
    while(true){
        cin>>courseGrade;
        if(cin.fail()|| cin.peek()!='\n'){                             //string and floats inputs
            cin.clear();
            cin.ignore(10000,'\n');
            cout<<"ERROR:Please do not input Characters nor Floats.\n"<<"input numbers --Grade:";
            
        }
         else if(courseGrade<0||courseGrade>4){     //float+string inputs
            cin.ignore(10000,'\n');
            cout<<"Error: You have entered a number outside our university grade interval [0,4]\n";
        }
        else{
            cin.ignore(10000,'\n');                  //float + string inputs    
            break;  }
    }
return courseGrade;}

int getNumberofCourses(){
   int num;
while (true) {
    cin >> num;
    if (cin.fail()|| cin.peek()!='\n') {                                   //String inputs
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error: Please do not input characters.\n" << "input integer -- Number of courses taken is:";

    } else if(num<0) {                                  //Negative inputs
        cin.ignore(10000,'\n');
        cout<<"Error: Please do not input negative numbers.\n"<<"input integer -- Number of courses taken is:";
    }
        
       else{ cin.ignore(10000, '\n');                   //float inputs
        break; 
    }
}
return num;}


int main() {
    cout<<"This is SPARTAA \n";
    int semC, totC, semCHour;
    float semCGrade, totCGrade;
    int semHours = 0;
    float totSemGrade = 0;
    vector<Course> courseList;
    Course c;
    ;

    cout << "Please input the number of courses you have taken this semester:" << endl;
    semC= getNumberofCourses();
    cout << "Please input the TOTAL number of courses you have taken throughout your university years:" << endl;
    totC= getNumberofCourses();
        while(totC<semC){
            cout<<"Error: Your total courses cannot be less than your courses taken this semester\n"<<"Please input your TOTAL number of course:";
            totC= getNumberofCourses();
        }
    for (auto i = 0; i < semC; i++) {

        cout << "Please enter the credit hours of the course number " << i + 1 << " taken in your latest semester:" << endl;
        semCHour= getCreditHours();
        
        semHours += semCHour;                       //Total semester credit Hours Calculated

        cout << "Please enter your grade in this course:" << endl;
        semCGrade=getCourseGrade();
      
        totCGrade = semCHour * semCGrade;
        totSemGrade += totCGrade;                   //Total semester Grades Calculated

        c.credits=semCHour;
        c.grade= semCGrade;
        courseList.push_back(c);
       

    }
    int courseTotCredits=semHours;
    float totGrade=totSemGrade;
    
    for(auto i = semC; i<totC ; i++){

        cout<< "Please enter the credit hours of the course number " << i + 1 <<endl;
        semCHour= getCreditHours();
         

    cout << "Please enter your grade in this course:" << endl;
         semCGrade= getCourseGrade();

         
        courseTotCredits+=semCHour;                 //Total credit Hours calculated

        
        totGrade += semCGrade*semCHour;                     // Total Grade calculated

        c.credits=semCHour;
        c.grade= semCGrade;
        courseList.push_back(c);
        
    }

    cout << "\n--- Individual Course Grades ---" << endl;
    for (auto i = 0; i < courseList.size(); i++) { 
        cout << "Course " << i + 1 << " | Credits: " << courseList[i].credits<< " | Grade: " << courseList[i].grade << endl; 
    } 
 
    cout << "\n--- Semester Results ---" << endl; 
    gpaCalc(semHours, totSemGrade); 
 
    cout << "\n--- Cumulative Results ---" << endl; 
    gpaCalc(courseTotCredits, totGrade); 

}

