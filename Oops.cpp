

#include <iostream>

using namespace std;
/* ---------------------------------------------
------------Abstract Class----------------------
----------------------------------------------*/
class AbstractEmployee{
public:
    virtual ~AbstractEmployee() = default;
private:
    virtual void askForPromotion() = 0;
};

/*---------------------------------------------
------------Employee Class----------------------
-----------------------------------------------*/
class employee : AbstractEmployee{
    string name;
    string company;
    string position;
    int age;
public:
    /* ------------------------------------------
    -------------Constructor method--------------
    -------------------------------------------*/
    employee(string empName, string empCompany, string empPosition, int empAge){
        name = empName;
        company = empCompany;
        position = empPosition;
        age = empAge;
    }


    /* ------------------------------------------
    --------------Destructor method--------------
    -------------------------------------------*/
    ~employee() = default;


    /* ------------------------------------------
    -----------Introduce Yourself method---------
    --------------------------------------------*/
    void introduceYourself(){
        cout << "Name: " << name << endl;
        cout << "Company: " << company << endl;
        cout << "Position: " << position << endl;
        cout << "Age: " << age << endl;
    }
    /* ------------------------------------------
    ----Setters and Getters (encapsulation)------
    --------------------------------------------*/
    void setName(string empName){
        name = empName;
    }
    string getName(){
        return name;
    }
    void setCompany(string empCompany){
        company = empCompany;
    }
    string getCompany(){
        return company;
    }
    void setPosition(string empPosition){
        position = empPosition;
    }
    string getPosition(){
        return position;
    }
    void setAge(int empAge){
        if(empAge >= 18){
            age = empAge;
        }
        else{
            cout << "Age must be at least 18." << endl;
        }
    }
    int getAge(){
        return age;
    } 
    /*-------------------------------------------
    ----Abstract method implementation----------
    --------------------------------------------*/
    void askForPromotion(){
        if(age > 30){
            cout << name << " got promoted!" << endl;
        }
        else{
            cout << name << ", sorry no promotion for you." << endl;
        }
    }
};

int main(){
    employee emp1 = employee("Alice", "TechCorp", "Developer", 29);
    employee emp2 = employee("Bob", "BizInc", "Manager", 35);
    
    emp1.introduceYourself();
    emp1.askForPromotion();
    emp2.askForPromotion();
    emp1.setAge(16);
    cout << emp1.getAge() << endl;
    cout<< emp1.getCompany() << endl;
    system("pause");
    return 0;

}