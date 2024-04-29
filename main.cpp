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
// continue from line 637
// TODOs:
//      1) start fonctionnalité 3
//      2) 
//      3) 
//
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <deque>
#include <cstdlib>
#include <map>
using namespace std;

// forward declaration: on évite les erreurs de compilation
class Stock;
class Produit;
class Fournisseur;
class Paiement;


typedef struct date {
    int jour;
    int mois;
    int annee;
    // Constructeur par défaut pour initialiser la date dans Paiements
    date(int j=1, int m=1, int a=2024):
        jour(j),
        mois(m),
        annee(a){}
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

        int getId() const{
            return id;
        }

        string getAdresse() const{
            return adresse;
        }

        int getCapacite() const{
            return capacite;
        }
        void ajouterStock(Stock s){
            stocks.push_back(s);
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
            prixHT(p),
            stock(nullptr){}
        
        Produit(const Produit& p){
            reference = p.reference;
            designation = p.designation;
            quantite = p.quantite;
            prixHT = p.prixHT;
            stock = p.stock;
            fournisseurs = p.fournisseurs;
            paiements = p.paiements;
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

        int getReference() const{
            return reference;
        }

        string getDesignation() const{
            return designation;
        }

        int getQuantite() const{
            return quantite;
        }

        double getPrixHT() const{
            return prixHT;
        }

        void ajouterFournisseur(const Fournisseur& f){
            fournisseurs.push_back(f);
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

        double getVersionMateriel() const{
            return version_materiel;
        }

        double getVersionLogiciel() const{
            return version_logiciel;
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
            description(d),
            depot(nullptr){}
        
        Stock(const Stock& s){
            reference = s.reference;
            description = s.description;
            depot = s.depot;
            produits = s.produits;
        }
        
        void setReference(int r){
            reference = r;
        }

        void setDescription(string d){
            description = d;
        }

        int getReference() const {
            return reference;
        }

        string getDescription() const{
            return description;
        }

        void ajouterProduit(Produit p){
            produits.push_back(p);
        }

        int getNbProduits() const{
            return produits.size();
        }

        bool operator<(const Stock& other) const {
            // Compare based on stock reference
            return reference < other.reference;
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
            produits = f.produits;
            paiements = f.paiements;
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

        vector <Produit> getProduits() const{
            return produits;
        }

        void ajouterProduit(Produit p){
            produits.push_back(p);
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
        Paiement(int i=0, double m=0, date d=date()):
            id(i),
            montant(m),
            date_paiement(d),
            fournisseur(nullptr){}
        
        Paiement(const Paiement& p){
            id = p.id;
            montant = p.montant;
            date_paiement = p.date_paiement;
            fournisseur = p.fournisseur;
            produits = p.produits;
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

        int getId() const{
            return id;
        }

        double getMontant() const{
            return montant;
        }

        string getDatePaiement() const{
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


void fonct1(set <Stock>& stocks) {
    int choix;
    string desc;
    Stock S;
    set <Stock>::iterator it;

    while(true){
        system("cls");
        cout << "------ 1 - Gestion Stock ------" << endl << endl;
        cout << "\t1. Remplir les stocks" << endl
            << "\t2. Afficher le nombre des produits de chaque stock" << endl
            << "\t3. Manipuler le stock" << endl
            << "\t4. Retour" << endl
            << "Votre choix: ";
        cin >> choix;
        // Vérifier si l'utilisateur n'a pas encore rempli les stocks
        if(choix != 1 && stocks.empty()){
            cout << endl << "Veuillez remplir les stocks d'abord!" << endl << endl;
        }
        else if(choix == 1){
            // Cas 1 - Remplir les stocks
            int nb_stock, nb_produit;
            system("cls");
            cout << "------- Gestion Stock -------" << endl << endl;
            cout << "Nombre de stocks à remplir? ";
            cin >> nb_stock;
            cout << endl << "Veuillez remplir les informations des stocks:" << endl << endl;
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
                cout << endl << "Veuillez remplir les informations des produits:" << endl << endl;
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
                    cout << endl;
                }
                stocks.insert(s);
                cout << endl;
            }
        }
        else if(choix == 2){
            // Cas 2 - Afficher le nombre des produits de chaque stock
            system("cls");
            cout << "------- Gestion Stock -------" << endl << endl;
            cout << "Nombre de produits dans chaque stock:" << endl;
            for(it=stocks.begin(); it!=stocks.end(); it++){
                cout << "\tStock " << it->getReference()
                    << " - " << it->getNbProduits() << " produits" << endl;
            }
        }
        else if(choix == 3){
            // Cas 3 - Manipuler le stock
            int ref_stock, choix2;
            while(true){
                system("cls");
                cout << "------- Gestion Stock -------" << endl << endl;
                cout << "\t1. Ajouter stock" << endl
                    << "\t2. Modifier stock" << endl
                    << "\t3. Supprimer stock" << endl
                    << "\t4. Retour" << endl
                    << "Votre choix: ";
                cin >> choix2;
                if(choix2 == 1){
                    // Cas 3.1 - ajouter stock
                    system("cls");
                    cout << "------- Gestion Stock -------" << endl << endl;
                    cout << "Entrez les informations du stock a ajouter:" << endl;
                    cout << "\tReference: ";
                    cin >> ref_stock;
                    cout << "\tDescription: ";
                    cin >> desc;
                    S.setReference(ref_stock);
                    S.setDescription(desc);
                    stocks.insert(S);
                    cout << endl << "Stock ajoute avec succes!" << endl << endl;
                }
                else if(choix2 == 2){
                    // Cas 3.2 - modifier stock
                    system("cls");
                    cout << "------- Gestion Stock -------" << endl << endl;
                    cout << "Entrez la reference du stock a modifier: ";
                    cin >> ref_stock;
                    cout << endl;
                    if(stocks.find(ref_stock) == stocks.end()){
                        cout << "Stock introuvable!" << endl << endl;
                    }
                    else{
                        cout << "Entrez les nouvelles informations du stock:" << endl;
                        cout << "\tReference: ";
                        cin >> ref_stock;
                        cout << "\tDescription: ";
                        cin >> desc;
                        Stock stock_modifie = *it;
                        stock_modifie.setReference(ref_stock);
                        stock_modifie.setDescription(desc);
                        stocks.erase(it);
                        stocks.insert(stock_modifie);
                        cout << endl << "Stock modifie avec succes!" << endl << endl;
                    }
                }
                else if(choix2 == 3){
                    // Cas 3.3 - supprimer stock
                    system("cls");
                    cout << "------- Gestion Stock -------" << endl << endl;
                    cout << "Entrer la reference  du stock a supprimer :";
                    cin >> ref_stock;
                    cout << endl;
                    if(stocks.find(ref_stock) == stocks.end()){
                        cout << "Stock introuvable!" << endl << endl;
                    }
                    else{
                        stocks.erase(ref_stock);
                        cout << "Stock supprime avec succes!" << endl;
                    }
                }
                else if(choix2 == 4){
                    // Cas 3.4 - Retour
                    break;
                }
                else{
                    cout << "Choix invalide. ";
                }
                cout << "Tapez un bouton pour retourner au MENU... ";
                cin.ignore();
                cin.get();
            }
        }
        else if(choix == 4){
            // Cas 4 - Retour
            break;
        }
        else{
            cout << "Choix invalide. ";
        }
        cout << "Tapez un bouton pour retourner au MENU... ";
        cin.ignore();
        cin.get();
    } 
}

void fonct2(deque <Fournisseur>& fournisseur){
    int choix, id, nb_fournisseur;
    string nom, contact;
    bool found;

    while(true){
        system("cls");
        cout << "------ 2 - Gestion Fournisseur ------" << endl << endl;
        cout << "\t1. Remplir les fournisseurs" << endl 
            << "\t2. Supprimer un fournisseur" << endl 
            << "\t3. Afficher les produits inferieurs a 100dhs" << endl
            << "\t4. Retour" << endl
            << "Votre choix: ";
        cin >> choix;
        if(choix != 1 && fournisseur.empty()){
            cout << endl << "Veuillez remplir les fournisseurs d'abord!" << endl << endl;
        }
        else if(choix == 1){
            // Cas 1 - Remplir les fournisseurs
            system("cls");
            cout << "------ 2 - Gestion Fournisseur ------" << endl << endl;
            cout << "Nombre de fournisseurs à remplir: ";
            cin >> nb_fournisseur;
            cout << endl;
            for(int i=0; i<nb_fournisseur; i++){
                // cout << "Fournisseur " << distance(fournisseur.begin(), it) + 1 << endl;
                cout << "Fournisseur " << i+1 << endl;
                cout << "\tIdentifiant: ";
                cin >> id;
                cout << "\tNom: ";
                cin >> nom;
                cout << "\tContact: ";
                cin >> contact;
                Fournisseur f(id, nom, contact);
                fournisseur.push_back(f);
            }
        }
        else if(choix == 2){
            // Cas 2 - Supprimer un fournisseur
            system("cls");
            cout << "------ 2 - Gestion Fournisseur ------" << endl << endl;
            cout << "Identifiant du fournisseur à supprimer: ";
            cin >> id;
            cout << endl;
            found = false;
            for(auto it=fournisseur.begin(); it!=fournisseur.end(); it++){
                if(it->getId() == id){
                    fournisseur.erase(it);
                    cout << "Fournisseur supprimé avec succès!" << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Fournisseur introuvable!" << endl << endl;
            }
        }
        else if(choix == 3){
            // Cas 3 - Afficher les produits dont le prix est inferieur a 100dhs
            vector <Produit> produits;
            system("cls");
            cout << "Entrer l'identifiant du fournisseur: ";
            cin >> id;
            cout << endl;
            found = false;
            for(auto it=fournisseur.begin(); it!=fournisseur.end(); it++){
                if(it->getId() == id){
                    cout << "Produits dont le prix est inferieur a 100dhs: " << endl;
                    produits = it->getProduits();
                    for(int i=0; i<produits.size(); i++){
                        if(produits[i].getPrixHT() < 100){
                            cout << "Produit " << i+1 << endl
                                << "\tReference: " << produits[i].getReference() << endl
                                << "\tDesignation: " << produits[i].getDesignation() << endl
                                << "\tQuantite: " << produits[i].getQuantite() << endl
                                << "\tPrix: " << produits[i].getPrixHT() << endl << endl;
                        }
                    }
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Fournisseur introuvable!" << endl << endl;
            }
        }
        else if(choix == 4){
            // Cas 4 - Retour
            break;
        }
        else{
            cout << "Choix invalide. ";
        }
        cout << "Tapez un bouton pour retourner au MENU... ";
        cin.ignore();
        cin.get();
    }
}


void fonct3(map <int, Produit>& m, deque <Fournisseur>& fournisseur, set <Stock>& stocks){
    int choix;
    bool found;

    while(true){
        system("cls");
        cout << "------ 3 - Gestion Produits ------" << endl << endl;
        cout << "\t1. Remplir les produits" << endl
            << "\t2. Trier la liste des fournisseurs de chaque produit par leurs prix"
            << "\t3. Ajouter un fournisseur" << endl
            << "\t4. Modifier un fournisseur" << endl
            << "\t5. Supprimer un fournisseur" << endl
            << "\t6. Afficher le nombre des produits avec date_paiement > 2 mois" << endl
            << "\t7. Réduire le prix du produit de 10% (si qt > 200)" << endl
            << "\t8. Retour" << endl;
        if(choix == 1){
            // Cas 1 - Remplir les produits
            int nb_produit;
            system("cls");
            cout << "------ 3 - Gestion Produits ------" << endl << endl;
            cout << "Nombre de produits à remplir: ";
            cin >> nb_produit;
            cout << endl;
            for(int i=0; i<nb_produit; i++){
                int ref, qte, id_fournisseur, ref_stock;
                string des;
                double prix;
                Fournisseur f;
                Stock s;
                cout << "Produit " << i+1 << endl;
                cout << "\tReference: ";
                cin >> ref;
                cout << "\tDesignation: ";
                cin >> des;
                cout << "\tQuantite: ";
                cin >> qte;
                cout << "\tPrix: ";
                cin >> prix;
                Produit p(ref, des, qte, prix);
                // On ajoute les fournisseurs
                int nb_fournisseur;
                cout << "\tNombre de fournisseurs: ";
                cin >> nb_fournisseur;
                for(int j=0; j<nb_fournisseur; j++){
                    int id_fournisseur;
                    cout << "\tFournisseur " << j+1 << endl;
                    cout << "\t\tIdentifiant: ";
                    cin >> id_fournisseur;
                    for(auto it=fournisseur.begin(); it!=fournisseur.end(); it++){
                        if(it->getId() == id_fournisseur){
                            f = *it;
                            f.ajouterProduit(p);
                            p.ajouterFournisseur(f);
                            found = true;
                            break;
                        }
                    }
                    if(found == false){
                        cout << "\tFournisseur introuvable! " << endl << endl;
                    }
                }
                // Ajouter le produit au fournisseur
                for(auto it=fournisseur.begin(); it!=fournisseur.end(); it++){
                    if(it->getId() == id_fournisseur){
                        f = *it;
                        f.ajouterProduit(p);
                        break;
                    }
                }
                // Ajouter le produit au stock
                cout << "\tReference du stock: ";
                cin >> ref_stock;
                for(auto it=stocks.begin(); it!=stocks.end(); it++){
                    if(it->getReference() == ref_stock){
                        s = *it;
                        s.ajouterProduit(p);
                        break;
                    }
                }
                m.insert(pair<int, Produit>(ref, p));
                cout << "Produit ajoute avec succes!" << endl;
            }
        }
        else if(choix == 2){
            // Cas 2 - Trier la liste des fournisseurs de chaque produit par leurs prix
            for(auto it=m.begin(); it!=m.end(); it++){
                sort(it->second.fournisseurs.begin(), it->second.fournisseurs.end());
            }
            cout << "Liste des fournisseurs de chaque produit triee avec succes!" << endl;
        }
        else if(choix == 3){
            // Cas 3 - Ajouter un fournisseur
            int id;
            string nom
        }
    
    //     cout << "\t1. Ajouter un produit" << endl
    //         << "\t2. Modifier un produit" << endl
    //         << "\t3. Supprimer un produit" << endl
    //         << "\t4. Retour" << endl
    //         << "Votre choix: ";
    //     cin >> choix;
    //     if(choix == 1){
    //         // Cas 1 - Ajouter un produit
    //         int ref, qte, id_fournisseur, ref_stock;
    //         string des;
    //         double prix;
    //         Produit p;
    //         Fournisseur f;
    //         Stock s;
    //         cout << "Entrez les informations du produit a ajouter:" << endl;
    //         cout << "\tReference: ";
    //         cin >> ref;
    //         cout << "\tDesignation: ";
    //         cin >> des;
    //         cout << "\tQuantite: ";
    //         cin >> qte;
    //         cout << "\tPrix: ";
    //         cin >> prix;
    //         p.setReference(ref);
    //         p.setDesignation(des);
    //         p.setQuantite(qte);
    //         p.setPrixHT(prix);
    //         cout << "Entrez l'identifiant du fournisseur: ";
    //         cin >> id_fournisseur;
    //         cout << "Entrez la reference du stock: ";
    //         cin >> ref_stock;
    //         // Ajouter le produit au fournisseur
    //         for(int i=0; i<fournisseur.size(); i++){
    //             if(fournisseur[i].getId() == id_fournisseur){
    //                 f = fournisseur[i];
    //                 f.produits.push_back(p);
    //                 break;
    //             }
    //         }
    //         // Ajouter le produit au stock
    //         for(auto it=stocks.begin(); it!=stocks.end(); it++){
    //             if(it->getReference() == ref_stock){
    //                 s = *it;
    //                 s.ajouterProduit(p);
    //                 break;
    //             }
    //         }
    //         m.insert(pair<int, Produit>(ref, p));
    //         cout << "Produit ajoute avec succes!" << endl;
    //     }
    //     else if(choix == 2){
    //         // Cas 2 - Modifier un produit
    //         int ref, choix2;
    //         cout << "Entrez la reference du produit a modifier: ";
    //         cin >> ref;
    //         cout << endl;
    //         cout << "Entrez les nouvelles informations du produit:" << endl;
    //         cout << "\tDesignation: ";
    //         cin >> des;
    //         cout << "\tQuantite: ";
    //         cin >> qte;
    //         cout << "\tPrix: ";
    //         cin >> prix;
    //         Produit modifiedProduit = m[ref];
    //         modifiedProduit.setDesignation(des);
    //         modifiedProduit.setQuantite(qte);
    //         modifiedProduit.setPrixHT(prix);
    //         m[ref] = modifiedProduit;
    //         cout << "Produit modifie avec succes!" << endl;

    // }

}


int main(){
    set <Stock> stocks;
    int choix;

    // MENU and functionalities    
    while(true){
        system("cls");
        cout << "------------ MENU ------------" << endl
            << "\t1. Gestion Stock" << endl
            << "\t2. Gestion Fournisseur" << endl
            << "\t3. Gestion Produits" << endl
            << "\t4. Gestion Paiement" << endl
            << "\t5. Quitter" << endl;
        cout << "Votre choix: ";
        cin >> choix;
        if(choix == 1){
            // Cas 1 - Gestion Stock
            
        }
        else if(choix == 2){
            // Cas 2 - Gestion Fournisseur

        }
        else if(choix == 3){
            // Cas 3 - Gestion Produits

        }
        else if(choix == 4){
            // Cas 4 - Gestion Paiement

        }
        else if(choix == 5){
            // Cas 5 - Quitter
            break;
        }
        else{
            // Cas invalide
            cout << "Choix invalide. ";
        }
        cout << "Tapez un bouton pour retourner au MENU... ";
        cin.ignore();
        cin.get();
    }

}