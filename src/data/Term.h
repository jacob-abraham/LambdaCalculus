#ifndef __TERM_H__
#define __TERM_H__

#include <string>
#include <ostream>
#include <sstream>

#include "Application.h"
#include "Abstraction.h"
#include "Atom.h"
#include <vector>


class Abstraction;
class Application;
std::ostream& operator<<(std::ostream&, const Abstraction&);
std::ostream& operator<<(std::ostream&, const Application&);
class Term {
    private:
    int id;
    public: //the type needs to be public
    enum Type { ATOM=0, ABS, APP};
    private:
    public: //TODO: make getters and setters
    Type type;
    //whether the use decided to put parentheses around this
    bool paren;
    Atom* atom;
    Abstraction* abstraction;
    Application* application;

    public:
    Term(int, Atom*, bool);
    Term(int, Abstraction*, bool);
    Term(int, Application*, bool);
    ~Term();

    //define a copy constructor
    Term(const Term&);

    std::string toJSON();


    int ID() {return id;}
    Type getType() {return type;}

    void addParen() { paren = true; }
    bool hasParen() {return paren; }

    bool isDefinition();
    bool isBetaRedex();
    friend void applyBetaRedex(Term*&);
    friend void replaceVariable(Term*&, Variable**, Term*);

    //its a value, values are not reducible
    bool isValue() { return !this->isBetaRedex(); }


    friend std::ostream& operator<<(std::ostream& out, const Term& t) {

        if(t.paren) out << "(";

        if(t.type == ATOM) out << *(t.atom);
        else if(t.type == ABS) out << *(t.abstraction);
        else if(t.type == APP) out << *(t.application);

        if(t.paren) out << ")";

        return out;
    }

    friend bool operator==(const Term& lhs, const Term& rhs);
    friend bool operator!=(const Term& lhs, const Term& rhs);
};

#endif