#include <iostream>
#include <memory>
#include <string>
#include <sstream>

class Expression {
public:
    virtual int Evaluate() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~Expression() {}
};


using ExpressionPtr = std::shared_ptr<Expression>;

class Constanta : public Expression {
private:
    std::string str_expr;
    int evaluation;
    
public:

    Constanta(int n) : evaluation(n) {
        std::stringstream ss;
        ss << evaluation;
        str_expr = ss.str();
    }

    int Evaluate() const override {
        return evaluation;
    }

    std::string ToString() const override {
        return str_expr;
    }

};

ExpressionPtr Const(int n) {
    return std::make_shared<Constanta>(Constanta(n));
}



class Summary : public Expression {
private:
    int evaluation;
    std::string str_expr;

public:
    Summary(ExpressionPtr first, ExpressionPtr second) :
        evaluation(first->Evaluate() + second->Evaluate()),
        str_expr(first->ToString() + " + " + second->ToString()) {

    }


    int Evaluate() const override {
        return evaluation;
    }

    std::string ToString() const override {
        return str_expr;
    }
};



ExpressionPtr Sum(ExpressionPtr first, ExpressionPtr second) {
    return std::make_shared<Summary>(Summary(first, second));
}



class Multiplication : public Expression {
private:
    int evaluation;
    std::string str_expr;
public:
    Multiplication(ExpressionPtr first, ExpressionPtr second) :
        evaluation(first->Evaluate()* second->Evaluate()) {
        if (dynamic_cast<Summary*>(first.get())) {
            str_expr = '(' + first->ToString() + ") * ";
        }
        else {
            str_expr = first->ToString() + " * ";
        }

        if (dynamic_cast<Summary*>(second.get())) {
            str_expr += '(' + second->ToString() + ")";
        }
        else {
            str_expr += second->ToString();
        }
    }

    int Evaluate() const override {
        return evaluation;
    }

    std::string ToString() const override {
        return str_expr;
    }

};

ExpressionPtr Product(ExpressionPtr first, ExpressionPtr second) {
    return std::make_shared<Multiplication>(Multiplication(first, second));
}


int main() {

    ExpressionPtr ex = Const(5);
    ExpressionPtr ex1 = Sum(Product(Const(3), Const(4)), Const(5));
    std::cout << ex1->ToString() << "\n";  // 3 * 4 + 5
    std::cout << ex1->Evaluate() << "\n";  // 17

    ExpressionPtr ex2 = Product(Const(6), ex1);
    std::cout << ex2->ToString() << "\n";  // 6 * (3 * 4 + 5)
    std::cout << ex2->Evaluate() << "\n";  // 102
}