#include <iostream>

using namespace std;

int main() {
    string name = "Jose";
    int age = 24;
    double high = 1.73;
    bool isMale = true;

    //cout << "Hello my name is " << name << " and i am " << age << " years old." << endl;

    // Strings

    string course = "Engenharia Informatica";
    string str = course.substr(3, 5);

    //cout << str << endl;
    //cout << course.length() << endl; 
    //cout << course.find("Informatica", 0) << endl; 

    // Input (calculator example)

    int num1, num2;

    cout << "Insere o primeiro numero: ";
    cin >> num1;

    cout << "Insere o segundo numero: ";
    cin >> num2;

    cout << "Resultado a operaçao de soma dos dois numeros e: " << num1+num2 << endl;

    

    return 0;
}