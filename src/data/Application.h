#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <string>
#include <ostream>

#include "Term.h"
#include <string>
#include <ostream>
#include <sstream>

class Term;

std::ostream& operator<<(std::ostream&, const Term&);
class Application {
    private:
    int id;
    public: //TODO make gettes and settes
    Term* a;
    Term* b;

    public:
    Application(int, Term*, Term* b);
    ~Application();

    //define a copy constructor
    Application(const Application&);


    int ID() {return id;}

    std::string toJSON();

    friend std::ostream& operator<<(std::ostream& out, const Application& a) {
        out << *(a.a) << " " << *(a.b);
        return out;
    }

    friend bool operator==(const Application& lhs, const Application& rhs);
    friend bool operator!=(const Application& lhs, const Application& rhs);
};

#endif