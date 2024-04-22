// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// continue from line 103
// TODOs:
//      - add the needed methods to the classes having relations
//      - continue adding the relations
//      - complete the fiche_paiement() method
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1

typedef struct date {
    int jour;
    int mois;
    int annee;
}date;

class Depot {
    private:
        int id;
        string adresse;
        int capacite;
        // Dépôt – Stock (composition 1 à *): un dépôt contient plusieurs stocks
        vector <Stock> stocks;
    public:
        Depot(int i=0, string a="", int c=0):
            id(i),
            adresse(a),
            capacite(c){}
        
        Depot(const Depot& d){
            id = d.id;
            adresse = d.adresse;
            capacite = d.capacite;
        }
        
        void setId(int i){
            id = i;
        }

        void setAdresse(string a){
            adresse = a;
        }

        void setCapacite(int c){
            capacite = c;
        }

        int getId(){
            return id;
        }

        string getAdresse(){
            return adresse;
        }

        int getCapacite(){
            return capacite;
        }
};


class Stock{
    private:
        int reference;
        string description;
        // Stock – Produit (1 à *): un stock contient plusieurs produits
        vector <Produit> produits;
        // Stock – Dépôt (* à 1): chaque stock est lié à un dépôt
        Depot* depot;
    public:
        Stock(int r=0, string d=""):
            reference(r),
            description(d){}
        
        Stock(const Stock& s){
            reference = s.reference;
            description = s.description;
        }
        
        void setReference(int r){
            reference = r;
        }

        void setDescription(string d){
            description = d;
        }

        int getReference(){
            return reference;
        }

        string getDescription(){
            return description;
        }
};


class Produit{
    protected:
        int reference;
        string designation;
        int quantite;
        double prixHT;
        // Produit – Stock (* à 1): chaque produit fait partie d’un stock
        Stock* stock;
        // Produit- Fournisseur (* à *) : un produit est fourni par plusieurs fournisseurs (on le met ici), et un fournisseur fournit plusieurs produits (on le met dans la classe Fournisseur)
        vector <Fournisseur> fournisseurs;
    public:
        Produit(int r=0, string d="", int q=0, double p=0):
            reference(r),
            designation(d),
            quantite(q),
            prixHT(p){}
        
        Produit(const Produit& p){
            reference = p.reference;
            designation = p.designation;
            quantite = p.quantite;
            prixHT = p.prixHT;
        }
        
        void setReference(int r){
            reference = r;
        }

        void setDesignation(string d){
            designation = d;
        }

        void setQuantite(int q){
            quantite = q;
        }

        void setPrixHT(double p){
            prixHT = p;
        }

        int getReference(){
            return reference;
        }

        string getDesignation(){
            return designation;
        }

        int getQuantite(){
            return quantite;
        }

        double getPrixHT(){
            return prixHT;
        }
};


class ProduitElectronique: public Produit{
    private:
        double version_materiel;
        double version_logiciel;
};


class Fournisseur{
    private:
        int id;
        string nom;
        string contact;
        // Produit- Fournisseur (* à *) : un produit est fourni par plusieurs fournisseurs (on le met dans la classe Produit), et un fournisseur fournit plusieurs produits (on le met ici)
        vector <Produit> produits;
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

        int getId(){
            return id;
        }

        string getNom(){
            return nom;
        }

        string getContact(){
            return contact;
        }
};


class Paiement{
    private:
        int id;
        double montant;
        date date_paiement;
    public:
        Paiement(int i=0, double m=0, date d):
            id(i),
            montant(m),
            date_paiement(d){}
        
        Paiement(const Paiement& p){
            id = p.id;
            montant = p.montant;
            date_paiement = p.date_paiement;
        }
        
        void setId(int i){
            id = i;
        }

        void setMontant(double m){
            montant = m;
        }

        void setDatePaiement(date d){
            date_paiement = d;
        }

        int getId(){
            return id;
        }

        double getMontant(){
            return montant;
        }

        string getDatePaiement(){
            return "Date paiement: "
                + to_string(date_paiement.jour) + "/"
                + to_string(date_paiement.mois) + "/"
                + to_string(date_paiement.annee);
        }

        void fiche_paiement(){
            cout << "Identifiant paiement: " << id << "\t\t\t" << getDatePaiement() << endl
                << "Identifiant fournisseur: "; // continue here
        }
};

int main(){
    Paiement p1(1, 100, {1, 1, 2021});
    
}