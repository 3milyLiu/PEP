#ifndef STACK_H
#define STACK_H

#include <vector>
using std::vector;
#include <string>
using std::string;
// TODO: Your code goes here

class Stack {
private:
    vector<double> s;
public:
    Stack() {}
    bool empty() {
        return s.empty();
    }

    double pop() {
        double x = s.back();
        s.pop_back();
        return x;
    };

    void push(const double &d){//insert
        s.push_back(d);
    };
};

double evaluate(const string s){
    Stack theStack;
    string theString;
    for(char c : s){
        if (c == ' ' && theString != "") {
            theStack.push(stod(theString));
            theString = "";
        } 
        else if(c == '+'){
            double second = theStack.pop();
            double first = theStack.pop();
            double result = second + first;
            theStack.push(result);
        } 
        else if(c == '-'){
            double second = theStack.pop();
            double first = theStack.pop();
            double result = first - second;
            theStack.push(result);
        }
        else if(c == '*'){
            double second = theStack.pop();
            double first = theStack.pop();
            double result = second * first;
            theStack.push(result);
        }
        else if(c == '/'){
            double second = theStack.pop();
            double first = theStack.pop();
            double result = first/second;
            theStack.push(result);
        }
        else{
            theString = theString + c;
        }
    }
    double const result = theStack.pop();
    return  result;
};

// Do not write anything below this line

#endif
