#include<iostream>
using namespace std;


struct Poly{
    int coef , power;
    Poly *next , *prev;
};


class polynomial{
    Poly *head;


    public:
    polynomial(){
        head = NULL;
    }
    void addterm(int co , int po){
        if(co == 0) return;
        Poly *np = new Poly;
        Poly *t = head;
        np->coef = co;
        np->power = po;
        np->next = NULL;
        np->prev = NULL;
        if(!head){
            head = np;
            return;
        }
        if(po > head->power){
        np->next = head;
        head->prev = np;
        head = np;
        return;
        }
        while(t->next && t->next->power >= po){
            t = t->next;
        }
        if(t->power == po){
            t->coef += co;
            delete np;
        }else if(t->power < po){
            np->next = t;
            np->prev = t->prev;
            if(t->prev) t->prev->next = np;
            t->prev = np;
            if(t == head) head = np;
        }else{
            np->next = t->next;
            if(t->next) t->next->prev = np;
            t->next = np;
            np->prev = t;
        }
    }


    void displaypoly(){
        Poly *ptr = head;
        if(!head){
            cout<<"0"<<endl;
            return;
        }
        while(ptr){
            cout<<ptr->coef<<"X^"<<ptr->power;
            if(ptr->next){
                if(ptr->next->coef){
                    cout<<" + ";
                }else{
                    cout<<" ";
                }
            }
            ptr = ptr->next;
        }
        cout<<endl;
    }


    polynomial operator + (polynomial &p2){
        polynomial result;
        Poly *a = head , *b = p2.head;
        while(a && b){
            if(a->power == b->power){
                result.addterm(a->coef + b->coef , a->power);
                a = a->next;
                b = b->next;
            }else if(a->power > b->power){
                result.addterm(a->coef , a->power);
                a = a->next;
            }else{
                result.addterm(b->coef , b->power);
                b = b->next;
            }
        }
        while(a){
            result.addterm(a->coef , a->power);
            a = a->next;
        }
        while(b){
            result.addterm(b->coef , b->power);
            b = b->next;
        }
        return result;
    }


    polynomial operator - (polynomial &p2){
        polynomial res;
        Poly *a = head , *b = p2.head;
         while(a && b){
            if(a->power == b->power){
                res.addterm(a->coef - b->coef, a->power);
                a = a->next; b = b->next;
            }else if (a->power > b->power) {
                res.addterm(a->coef, a->power);
                a = a->next;
            }else {
                res.addterm(-b->coef, b->power);
                b = b->next;
            }
        }
        while(a){
            res.addterm(a->coef, a->power);
            a = a->next;
        }
        while(b){
            res.addterm(-b->coef, b->power);
            b = b->next;
        }
        return res;
    }
};
int main(){
    polynomial p1,p2;
    p1.addterm(12,256);
    p1.addterm(9,123);
    p1.addterm(1,25);
    p1.addterm(2,23);
    p1.addterm(32,6);
    p2.addterm(4,3);
    p2.addterm(5,25);
    p2.addterm(6,13);
    p2.addterm(22,56);
    p2.addterm(8,45);
    cout<<"p1 = ";
    p1.displaypoly();
    cout<<"p2 = ";
    p2.displaypoly();
    polynomial sum = p1 + p2;
    cout<<"Sum of p1 & p2 = ";
    sum.displaypoly();
    polynomial diff = p1 - p2;
    cout<<"Difference b/w p1 & p2 = ";
    diff.displaypoly();
    return 0;
}
