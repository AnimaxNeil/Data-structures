// WAP to scan a polynomial using linked list and add two polynomial.

#include <iostream>
#include <string>
using namespace std;

class Term
{
public:
    int exponent, coeffecient;
    Term *next_term;

    Term(int exponent, int coeffecient)
    {
        this->exponent = exponent;
        this->coeffecient = coeffecient;
        next_term = NULL;
    }
};

class LinkedList
{
    Term *first_term;

public:
    LinkedList()
    {
        first_term = NULL;
    }

    bool isEmpty()
    {
        return first_term == NULL;
    }

    void insert_desc(int exponent, int coeffecient)
    {
        if (first_term == NULL || first_term->exponent < exponent)
        {
            Term *new_term = new Term(exponent, coeffecient);
            new_term->next_term = first_term;
            first_term = new_term;
            return;
        }
        Term *term = first_term;
        while (term->next_term != NULL && term->next_term->exponent >= exponent)
        {
            term = term->next_term;
        }
        Term *old_term = term->next_term;
        term->next_term = new Term(exponent, coeffecient);
        term->next_term->next_term = old_term;
    }

    Term *getFirstTerm()
    {
        return first_term;
    }
};

class Polynomial
{
    LinkedList terms;

public:
    void input()
    {
        int numOfTerms;
        int exponent, coeffecient;
        cout << "Number of terms : ";
        cin >> numOfTerms;
        for (int i = 1; i <= numOfTerms; i++)
        {
            cout << "Coeffecient of term " << i << " : ";
            cin >> coeffecient;
            cout << "Exponent of term " << i << " : ";
            cin >> exponent;
            terms.insert_desc(exponent, coeffecient);
        }
    }

    string output()
    {
        string *s = new string();
        if (terms.isEmpty())
        {
            s->append("0");
            return *s;
        }
        for (Term *term = terms.getFirstTerm(); term != NULL; term = term->next_term)
        {
            if (term != terms.getFirstTerm() && term->coeffecient >= 0)
            {
               s->append("+");
            }
            s->append(to_string(term->coeffecient) + "(x^" + to_string(term->exponent) + ")");
        }
        return *s;
    }

    Polynomial add(Polynomial &poly)
    {
        Polynomial *result = new Polynomial();
        Term *term = terms.getFirstTerm();
        Term *poly_term = poly.terms.getFirstTerm();
        while (term != NULL || poly_term != NULL)
        {
            if (term == NULL)
            {
                result->terms.insert_desc(poly_term->exponent, poly_term->coeffecient);
                poly_term = poly_term->next_term;
            }
            else if (poly_term == NULL)
            {
                result->terms.insert_desc(term->exponent, term->coeffecient);
                term = term->next_term;
            }
            else if (term->exponent == poly_term->exponent)
            {
                result->terms.insert_desc(term->exponent, term->coeffecient + poly_term->coeffecient);
                term = term->next_term;
                poly_term = poly_term->next_term;
            }
            else if (term->exponent > poly_term->exponent)
            {
                result->terms.insert_desc(term->exponent, term->coeffecient);
                term = term->next_term;
            }
            else if (term->exponent < poly_term->exponent)
            {
                result->terms.insert_desc(poly_term->exponent, poly_term->coeffecient);
                poly_term = poly_term->next_term;
            }
        }
        return *result;
    }

    Polynomial operator+(Polynomial &poly)
    {
        return add(poly);
    }
};

int main()
{
    Polynomial p1, p2, p3;
    cout.precision(4);
    cout << "Input 1st polynomial.\n";
    p1.input();
    cout << "1st polynomial = " << p1.output() << "\n\n";
    cout << "Input 2nd polynomial.\n";
    p2.input();
    cout << "2nd polynomial = " << p2.output() << "\n\n";
    p3 = p1 + p2;
    cout << "Addition of the two polynomials = " << p3.output() << "\n\n";
    return 0;
}