// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// INFOs:
//      - Use les itérateurs pour parcourir les vecteurs
//          exemple:
//             vector<Produit>::iterator it;
//             for(it=produits.begin(); it!=produits.end(); it++){
//                ...
//             }
//
//      - Use les algorithmes de la STL pour manipuler les vecteurs (ex: sort, find, ...)
//          exemple:
//             sort(produits.begin(), produits.end());
//
//
// continue from line 368
// TODOs:
//      1) Continue working on Fonctionnalité 1: gestion Stock
//      2) add the needed methods to the classes having relations
//
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
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

        void ajouterProduit(Produit p){
            produits.push_back(p);
        }

        int getNbProduits(){
            return produits.size();
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
        // Paiement – Produit (* à *): un paiement concerne plusieurs produits, et un produit est concerné par plusieurs paiements
        vector <Paiement> paiements;
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
    public:
        ProduitElectronique(int r=0, string d="", int q=0, double p=0, double vm=0, double vl=0):
            Produit(r, d, q, p),
            version_materiel(vm),
            version_logiciel(vl){}
        
        ProduitElectronique(const ProduitElectronique& pe):
            Produit(pe),
            version_materiel(pe.version_materiel),
            version_logiciel(pe.version_logiciel){}
        
        void setVersionMateriel(double vm){
            version_materiel = vm;
        }

        void setVersionLogiciel(double vl){
            version_logiciel = vl;
        }
};


class Fournisseur{
    private:
        int id;
        string nom;
        string contact;
        // Produit- Fournisseur (* à *) : un produit est fourni par plusieurs fournisseurs (on le met dans la classe Produit), et un fournisseur fournit plusieurs produits (on le met ici)
        vector <Produit> produits;
        // Fournisseur – Paiement(1 à *): un fournisseur peut avoir plusieurs paiements
        vector <Paiement> paiements;
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
        // Paiement – Fournisseur (* à 1)
        Fournisseur* fournisseur;
        // Paiement – Produit (* à *): un paiement concerne plusieurs produits, et un produit est concerné par plusieurs paiements
        vector <Produit> produits;
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
            vector<Produit>::iterator it; // Itérateurs pour parcouir le vecteur de produits

            cout << "- Identifiant paiement: " << id << "\t\t\t- Date paiement: " << getDatePaiement() << endl
                << "- Identifiant fournisseur: " << fournisseur->getId()
                << "- Liste produits: " << endl
                << "Reference produit\tDesignation\tQuantite\tPrix" << endl;
            
            for(it=produits.begin(); it!=produits.end(); it++){
                cout << it->getReference() << "\t\t\t"
                    << it->getDesignation() << "\t\t"
                    << it->getQuantite() << "\t\t"
                    << it->getPrixHT() << endl;
            }

            cout << "- Total à payer: " << montant << endl;
            
        }
};


void gestionStock(set<Stock>& stocks) {
    int nb_stock, nb_produit;
    system("cls");
    cout << "------ 1 - Gestion Stock ------" << endl << endl;
    cout << "Nombre de stocks à remplir? " << endl;
    cin >> nb_stock;
    cout << endl << "Veuillez remplir les informations des stocks:" << endl << endl;
    // Remplissage des stocks
    for(int i=0; i<nb_stock; i++){
        int ref_stock;
        string des_stock;
        cout << "Stock " << i+1 << endl;
        cout << "\tReference: ";
        cin >> ref_stock;
        cout << "\tDescription: ";
        cin >> des_stock;
        Stock s(ref_stock, des_stock);
        // Remplissage des produits à l'intérieur du stock dans vector<Produit> produits
        cout << "\t Nombre de produits à remplir? " << endl;
        cin >> nb_produit;
        for(int j=0; j<nb_produit; j++){
            int ref_prod;
            string des_prod;
            int qte_prod;
            double prix_prod;
            cout << "\tProduit " << j+1 << endl;
            cout << "\t\tReference: ";
            cin >> ref_prod;
            cout << "\t\tDescription: ";
            cin >> des_prod;
            cout << "\t\tQuantite: ";
            cin >> qte_prod;
            cout << "\t\tPrix: ";
            cin >> prix_prod;
            Produit p(ref_prod, des_prod, qte_prod, prix_prod);
            s.ajouterProduit(p);
        }
        stocks.insert(s);
    }
    // Affichage du nombre de produits dans chaque stock

}


int main(){
    set <Stock> stocks;
    int choix;

    // MENU and functionalities    
    while(true){
        system("cls");
        cout << "\t1. Gestion Stock" << endl
            << "\t2. Gestion Fournisseur" << endl
            << "\t3. Gestion Produits" << endl
            << "\t4. Gestion Paiement" << endl
            << "\t5. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choix;
        switch(choix){
            case 1:
                // ** Fonctionnalité 1 : gestion Stock **
                gestionStock(stocks);
                
                break;
            case 2:
                // ** Fonctionnalité 2 : Gestion Fournisseur **

                break;
            case 3:
                // ** Fonctionnalité 3 : Gestion Produits **
                
                break;
            case 4:
                // ** Fonctionnalité 4 : Gestion Paiement **
                
                break;
            case 5:
                return 0;
            default:
                cout << "Choix invalide\n";
        }
    }

}