#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

class Fournisseur{
    private:
        int id;
        string nom;
        string contact;
    public:
        Fournisseur(int i=0, string n="", string c=""):
            id(i),
            nom(n),
            contact(c){}
        
        Fournisseur(const Fournisseur& f){
            id = f.id;
            nom = f.nom;
            contact = f.contact;
        }
        
        void setId(int i){
            id = i;
        }

        void setNom(string n){
            nom = n;
        }

        void setContact(string c){
            contact = c;
        }

        int getId() const{
            return id;
        }

        string getNom() const{
            return nom;
        }

        string getContact() const{
            return contact;
        }

        bool operator==(int f_id) const {
            return id == f_id;
        }
};

bool trierFournisseur(const Fournisseur& f1, const Fournisseur& f2){
    return f1.getNom() < f2.getNom();
}

int main(){
    deque <Fournisseur> fournisseurs;
    Fournisseur f1(1, "simo", "C1");
    Fournisseur f2(2, "zney", "C2");
    Fournisseur f3(3, "abk", "C2");
    Fournisseur f4(4, "bro", "C2");
    fournisseurs.push_back(f1);
    fournisseurs.push_back(f2);
    fournisseurs.push_back(f3);
    fournisseurs.push_back(f4);

    // fournisseurs.push_back(f2);
    // auto it = find(fournisseurs.begin(), fournisseurs.end(), 2);
    // if(it != fournisseurs.end())
    //     cout << it->getNom() << endl;
    // else
    //     cout << "Not found" << endl;
    sort(fournisseurs.begin(), fournisseurs.end(), trierFournisseur);
    for(auto it=fournisseurs.begin(); it!=fournisseurs.end(); it++)
        cout << it->getNom() << endl;
    
}