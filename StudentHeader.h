using namespace std ;

class Student 
{
    string name ;
    int regNo ;
    public :
    static int TotalStudent ;
    Student ()
    {
        cout << "Default";
        Student::TotalStudent++;
        name = "Baun";
    }
    Student (string inputName )
    {
        cout << "Paramaterized\n";
        Student::TotalStudent++;
        name = inputName ;
    }
    ~Student ()
    {
        cout << "Destructor Called\n";
    }
    void setName (string name);
    string getName ();
    void setRegNo (int RegNo);
    int getRegNo ();
    static int getTotalStudent (){
        return Student::TotalStudent ;
    }
};

 int Student :: TotalStudent = 0 ;

void Student :: setName (string name)
{
    this->name = name ;
}

string Student :: getName ()
{
    return name ;
}

void Student :: setRegNo (int regNo )
{
    this->regNo = regNo ;
}

int Student :: getRegNo ()
{
    return regNo ;
}
