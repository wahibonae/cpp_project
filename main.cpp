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
// continue from line ...
// TODOs:
//      1) continue fonct 4 b9a fiha ghir chwiya
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
#include <algorithm>
#include <ctime>
#include <cmath>
#include <list>
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

        // void ajouterStock(Stock s){
        //     stocks.push_back(s);
        // }

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

        void ajouterProduit(Produit& p){
            produits.push_back(p);
        }

        int getNbProduits() const{
            return produits.size();
        }

        bool operator<(const Stock& other) const {
            // Compare based on stock reference
            return reference < other.reference;
        }

        bool operator==(int ref) const {
            return reference == ref;
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

        vector <Fournisseur> getFournisseurs() const{
            return fournisseurs;
        }

        void setStock(Stock* s){
            stock = s;
        }

        bool fournisseur_existe(int id){
            auto it = find(fournisseurs.begin(), fournisseurs.end(), id);
            return it != fournisseurs.end();
        }

        void supprimerFournisseur(int id){
            auto it = find(fournisseurs.begin(), fournisseurs.end(), id);
            if(it != fournisseurs.end()){
                fournisseurs.erase(it);
            }
        }

        vector <Paiement> getPaiements() const{
            return paiements;
        }

        bool operator==(int p_ref) const {
            return reference == p_ref;
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

        bool operator==(int f_id) const {
            return id == f_id;
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
        Paiement(int i=0, double m=0, date d=date(), Fournisseur* f=nullptr):
            id(i),
            montant(m),
            date_paiement(d),
            fournisseur(f){}
        
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

        date getDatePaiement() const{
            return date_paiement;
        }

        string getDatePaiementMessage() const{
            return "Date paiement: "
                + to_string(date_paiement.jour) + "/"
                + to_string(date_paiement.mois) + "/"
                + to_string(date_paiement.annee);
        }

        void fiche_paiement(){
            vector<Produit>::iterator it; // Itérateurs pour parcouir le vecteur de produits

            cout << "- Identifiant paiement: " << id << "\t\t\t- Date paiement: " << getDatePaiementMessage() << endl
                << "- Identifiant fournisseur: " << fournisseur->getId()
                << "- Liste produits: " << endl
                << "Reference produit\t\tDesignation\tQuantite\t\tPrix" << endl;
            
            for(it=produits.begin(); it!=produits.end(); it++){
                cout << it->getReference() << "\t\t"
                    << it->getDesignation() << "\t\t"
                    << it->getQuantite() << "\t\t"
                    << it->getPrixHT() << endl;
            }

            cout << "- Total à payer: " << montant << endl;
        }

        void setFournisseur(Fournisseur* f){
            fournisseur = f;
        }

        void ajouterProduit(Produit p){
            produits.push_back(p);
        }

        vector <Produit> getProduits() const{
            return produits;
        }

        bool operator==(int p_id) const {
            return id == p_id;
        }

        void supprimerProduit(int ref_p){
            auto it = find(produits.begin(), produits.end(), ref_p);
            if(it != produits.end()){
                produits.erase(it);
            }
        }
};


bool tri_alpha(Fournisseur f1, Fournisseur f2){
    return f1.getNom() < f2.getNom();
}

void fonct1(set <Stock>& stocks) {
    int choix;
    string desc;
    Stock S;
    set <Stock>::iterator it;

    while(true){
        system("cls");
        cout << "------ 1 - Gestion Stock ------" << endl;
        cout << "\t1. Remplir les stocks" << endl
            << "\t2. Afficher le nombre des produits de chaque stock" << endl
            << "\t3. Manipuler le stock" << endl
            << "\t4. Retour" << endl
            << "Votre choix: ";
        std::cin >> choix;
        // Vérifier si l'utilisateur n'a pas encore rempli les stocks
        if(choix != 1 && choix!=4 && stocks.empty()){
            cout << endl << "Veuillez remplir les stocks d'abord!" << endl << endl;
        }
        else if(choix == 1){
            // Cas 1 - Remplir les stocks
            int nb_stock, nb_produit;
            system("cls");
            cout << "------- Gestion Stock -------" << endl;
            cout << "Nombre de stocks a remplir? ";
            std::cin >> nb_stock;
            cout << endl << "Veuillez remplir les informations des stocks:" << endl << endl;
            for(int i=0; i<nb_stock; i++){
                int ref_stock;
                string des_stock;
                cout << "Stock " << i+1 << endl;
                cout << "\tReference (int): ";
                std::cin >> ref_stock;
                cout << "\tDescription: ";
                cin.ignore();
                getline(std::cin, des_stock);
                Stock s(ref_stock, des_stock);
                // Remplissage des produits à l'intérieur du stock dans vector<Produit> produits
                cout << "\t Nombre de produits à remplir? ";
                std::cin >> nb_produit;
                cout << endl << "\tVeuillez remplir les informations des produits:" << endl << endl;
                for(int j=0; j<nb_produit; j++){
                    int ref_prod;
                    string des_prod;
                    int qte_prod;
                    double prix_prod;
                    cout << "\tProduit " << j+1 << endl;
                    cout << "\t\tReference: ";
                    std::cin >> ref_prod;
                    cout << "\t\tDescription: ";
                    std::cin >> des_prod;
                    cout << "\t\tQuantite: ";
                    std::cin >> qte_prod;
                    cout << "\t\tPrix: ";
                    std::cin >> prix_prod;
                    Produit p(ref_prod, des_prod, qte_prod, prix_prod);
                    s.ajouterProduit(p);
                    cout << endl;
                }
                stocks.insert(s);
                cout << endl;
            }
            cout << "Tapez un bouton pour retourner au MENU... ";
            std::cin.ignore();
            std::cin.get();
        }
        else if(choix == 2){
            // Cas 2 - Afficher le nombre des produits de chaque stock
            system("cls");
            cout << "------- Gestion Stock -------" << endl;
            cout << "Nombre de produits dans chaque stock:" << endl;
            for(it=stocks.begin(); it!=stocks.end(); it++){
                cout << "\tStock " << it->getReference()
                    << " - " << it->getNbProduits() << " produits" << endl;
            }
            cout << "Tapez un bouton pour retourner au MENU... ";
            std::cin.ignore();
            std::cin.get();
        }
        else if(choix == 3){
            // Cas 3 - Manipuler le stock
            int ref_stock, choix2;
            while(true){
                system("cls");
                cout << "------- Gestion Stock -------" << endl;
                cout << "\t1. Ajouter stock" << endl
                    << "\t2. Modifier stock" << endl
                    << "\t3. Supprimer stock" << endl
                    << "\t4. Retour" << endl
                    << "Votre choix: ";
                std::cin >> choix2;
                if(choix2 == 1){
                    // Cas 3.1 - ajouter stock
                    system("cls");
                    cout << "------- Gestion Stock -------" << endl;
                    cout << "Entrez les informations du stock a ajouter:" << endl;
                    cout << "\tReference: ";
                    std::cin >> ref_stock;
                    cout << "\tDescription: ";
                    std::cin >> desc;
                    S.setReference(ref_stock);
                    S.setDescription(desc);
                    stocks.insert(S);
                    cout << endl << "Stock ajoute avec succes!" << endl << endl;
                    cout << "Tapez un bouton pour retourner au MENU... ";
                    std::cin.ignore();
                    std::cin.get();
                }
                else if(choix2 == 2){
                    // Cas 3.2 - modifier stock
                    system("cls");
                    cout << "------- Gestion Stock -------" << endl;
                    cout << "Entrez la reference du stock a modifier: ";
                    std::cin >> ref_stock;
                    cout << endl;
                    if(stocks.find(ref_stock) == stocks.end()){
                        cout << "Stock introuvable!" << endl << endl;
                    }
                    else{
                        cout << "Entrez les nouvelles informations du stock:" << endl;
                        cout << "\tReference: ";
                        std::cin >> ref_stock;
                        cout << "\tDescription: ";
                        std::cin >> desc;
                        Stock stock_modifie = *it;
                        stock_modifie.setReference(ref_stock);
                        stock_modifie.setDescription(desc);
                        stocks.erase(it);
                        stocks.insert(stock_modifie);
                        cout << endl << "Stock modifie avec succes!" << endl << endl;
                    }
                    cout << "Tapez un bouton pour retourner au MENU... ";
                    std::cin.ignore();
                    std::cin.get();
                }
                else if(choix2 == 3){
                    // Cas 3.3 - supprimer stock
                    system("cls");
                    cout << "------- Gestion Stock -------" << endl;
                    cout << "Entrer la reference  du stock a supprimer :";
                    std::cin >> ref_stock;
                    cout << endl;
                    if(stocks.find(ref_stock) == stocks.end()){
                        cout << "Stock introuvable!" << endl << endl;
                    }
                    else{
                        stocks.erase(ref_stock);
                        cout << "Stock supprime avec succes!" << endl;
                    }
                    cout << "Tapez un bouton pour retourner au MENU... ";
                    std::cin.ignore();
                    std::cin.get();
                }
                else if(choix2 == 4){
                    // Cas 3.4 - Retour
                    break;
                }
                else{
                    cout << "Choix invalide. ";
                    cout << "Tapez un bouton pour retourner au MENU... ";
                    std::cin.ignore();
                    std::cin.get();
                }
                
            }
        }
        else if(choix == 4){
            // Cas 4 - Retour
            break;
        }
        else{
            cout << "Choix invalide. ";
            cout << "Tapez un bouton pour retourner au MENU... ";
            std::cin.ignore();
            std::cin.get();
        }
    } 
}

void fonct2(deque <Fournisseur>& fournisseur){
    int choix, id, nb_fournisseur;
    string nom, contact;
    bool found;

    while(true){
        system("cls");
        cout << "------ 2 - Gestion Fournisseur ------" << endl;
        cout << "\t1. Remplir les fournisseurs" << endl 
            << "\t2. Supprimer un fournisseur" << endl 
            << "\t3. Afficher les produits inferieurs a 100dhs" << endl
            << "\t4. Trier les fournisseurs (alphabetique)" << endl
            << "\t5. Retour" << endl
            << "Votre choix: ";
        std::cin >> choix;
        if(choix != 1 && choix!=6 && fournisseur.empty()){
            cout << endl << "Veuillez remplir les fournisseurs d'abord!" << endl << endl;
        }
        else if(choix == 1){
            // Cas 1 - Remplir les fournisseurs
            system("cls");
            cout << "------ 2 - Gestion Fournisseur ------" << endl;
            cout << "Nombre de fournisseurs à remplir: ";
            std::cin >> nb_fournisseur;
            cout << endl;
            for(int i=0; i<nb_fournisseur; i++){
                // cout << "Fournisseur " << distance(fournisseur.begin(), it) + 1 << endl;
                cout << "Fournisseur " << i+1 << endl;
                cout << "\tIdentifiant: ";
                std::cin >> id;
                cout << "\tNom: ";
                std::cin >> nom;
                cout << "\tContact: ";
                std::cin >> contact;
                Fournisseur f(id, nom, contact);
                fournisseur.push_back(f);
            }
        }
        else if(choix == 2){
            // Cas 2 - Supprimer un fournisseur
            system("cls");
            cout << "------ 2 - Gestion Fournisseur ------" << endl;
            cout << "Identifiant du fournisseur à supprimer: ";
            std::cin >> id;
            cout << endl;
            auto it = find(fournisseur.begin(), fournisseur.end(), id);
            if(it != fournisseur.end()){
                fournisseur.erase(it);
                cout << "Fournisseur supprime avec succes!"<< endl;
            }
            else{
                cout << "Fournisseur introuvable!" << endl;
            }
        }
        else if(choix == 3){
            // Cas 3 - Afficher les produits dont le prix est inferieur a 100dhs
            vector <Produit> produits;
            system("cls");
            cout << "Entrer l'identifiant du fournisseur: ";
            std::cin >> id;
            cout << endl;
            auto it = find(fournisseur.begin(), fournisseur.end(), id);
            if(it != fournisseur.end()){
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
            }
            else{
                cout << "Fournisseur introuvable!" << endl;
            }
        }
        else if(choix == 4){
            // Cas 4 - Trier les fournisseurs (alphabetiquement) 
            system("cls");
            cout << "------ 2 - Gestion Fournisseur ------" << endl;
            sort(fournisseur.begin(), fournisseur.end(), tri_alpha);
            cout << "Trie effectue avec succes!" << endl << endl;
        }
        else if(choix == 5){
            // Cas 5 - Retour
            break;
        }
        else{
            cout << "Choix invalide. ";
        }
        cout << "Tapez un bouton pour retourner au MENU... ";
        std::cin.ignore();
        std::cin.get();
    }
}


void fonct3(map <int, Produit>& m, deque <Fournisseur>& fournisseur, set <Stock>& stocks){
    int choix;
    bool found;

    while(true){
        system("cls");
        cout << "------ 3 - Gestion Produits ------" << endl;
        cout << "\t1. Remplir les produits" << endl
            << "\t2. Ajouter un fournisseur" << endl
            << "\t3. Modifier un fournisseur" << endl
            << "\t4. Supprimer un fournisseur" << endl
            << "\t5. Afficher le nombre des produits avec date_paiement > 2 mois" << endl
            << "\t6. Réduire le prix du produit de 10% (si qt > 200)" << endl
            << "\t7. Retour" << endl
            << "Votre choix: ";
        std::cin >> choix;
        if(choix != 1 && m.empty()){
            cout << endl << "Veuillez remplir les produits d'abord!" << endl << endl;
        }
        else if(choix == 1){
            // Cas 1 - Remplir les produits
            int nb_produit;
            system("cls");
            cout << "------ 3 - Gestion Produits ------" << endl;
            cout << "Nombre de produits a remplir: ";
            std::cin >> nb_produit;
            cout << endl;
            for(int i=0; i<nb_produit; i++){
                int ref, qte, id_fournisseur, ref_stock, type;
                string des;
                double prix;
                Fournisseur f;
                Stock s;
                Produit* p;
                // On ajoute le produit
                cout << "Produit " << i+1 << endl;
                cout << "\tReference: ";
                std::cin >> ref;
                cout << "\tDesignation: ";
                std::cin >> des;
                cout << "\tQuantite: ";
                std::cin >> qte;
                cout << "\tPrix: ";
                std::cin >> prix;
                cout << "\tType(1: Normal, 2: Electronique): ";
                cin >> type;
                if(type == 1){
                    p = new Produit(ref, des, qte, prix);
                }
                else{
                    double vm, vl;
                    cout << "\tVersion materiel: ";
                    cin >> vm;
                    cout << "\tVersion logiciel: ";
                    cin >> vl;
                    p = new ProduitElectronique(ref, des, qte, prix, vm, vl);
                }
                // On ajoute les fournisseurs
                int nb_fournisseur;
                cout << "\tNombre de fournisseurs: ";
                std::cin >> nb_fournisseur;
                cout << endl;
                for(int j=0; j<nb_fournisseur; j++){
                    int id_fournisseur;
                    cout << "\tFournisseur " << j+1 << endl;
                    cout << "\t\tIdentifiant: ";
                    std::cin >> id_fournisseur;
                    // Vérifier si le fournisseur existe dans deque (it1), et s'il n'est pas encore ajouté dans le vecteur de fournisseurs de Produit
                    auto it = find(fournisseur.begin(), fournisseur.end(), id_fournisseur);
                    if(it != fournisseur.end() && !p->fournisseur_existe(id_fournisseur)){
                        f = *it;
                        p->ajouterFournisseur(f); // On ajoute le fournisseur au produit
                        f.ajouterProduit(*p); // On ajoute le produit au fournisseur
                    }
                    else if(it == fournisseur.end()){
                        cout << "\tFournisseur introuvable!" << endl << endl;
                    }
                    else if(p->fournisseur_existe(id_fournisseur)){
                        cout << "\tFournisseur deja ajoute!" << endl << endl;
                    }
                }
                // Lier le stock au produit si la référence du stock existe
                while(true){
                    cout << "\tReference du stock: ";
                    std::cin >> ref_stock;
                    auto it3 = find(stocks.begin(), stocks.end(), ref_stock);
                    if(it3 != stocks.end()){
                        // Stock existe dans le set
                        s = *it3;
                        s.ajouterProduit(*p);
                        p->setStock(&s); // On met à jour le stock du produit
                        break;
                    }
                    else{
                        cout << "Stock introuvable!" << endl << endl;
                    }
                }
                m.insert(pair<int, Produit>(ref, *p));
                cout << "Produit ajoute avec succes! " << endl << endl;
            }
        }
        else if(choix == 2){
            // Cas 2 - Ajouter un fournisseur
            int ref;
            system("cls");
            cout << "------ 3 - Gestion Produits ------" << endl;
            cout << "Reference du produit: ";
            std::cin >> ref;
            if(m.find(ref) == m.end()){
                cout << "Produit introuvable! " << endl << endl;
            }
            else{
                Produit& p = m[ref];
                int id;
                Fournisseur f;
                cout << endl << "Identifiant du fournisseur: ";
                std::cin >> id;
                // Vérifier si le fournisseur existe dans deque (it1), et s'il n'est pas encore ajouté dans le vecteur de fournisseurs de Produit (it2)
                auto it = find(fournisseur.begin(), fournisseur.end(), id);
                if(it != fournisseur.end() && !p.fournisseur_existe(id)){
                    f = *it;
                    p.ajouterFournisseur(f); // On ajoute le fournisseur au produit
                    f.ajouterProduit(p); // On ajoute le produit au fournisseur
                }
                else if(it == fournisseur.end()){
                    cout << "\tFournisseur introuvable! " << endl << endl;
                }
                else if(p.fournisseur_existe(id)){
                    cout << "\tFournisseur deja ajoute! " << endl << endl;
                }
            }
        }
        else if(choix == 3){
            // Cas 4 - Modifier un fournisseur
            int ref;
            system("cls");
            cout << "------ 3 - Gestion Produits ------" << endl;
            cout << "Reference du produit: ";
            std::cin >> ref;
            if(m.find(ref) == m.end()){
                cout << "Produit introuvable! " << endl << endl;
            }
            else{
                Produit& p = m[ref];
                int id;
                string nom, contact;
                Fournisseur f;
                cout << endl << "Identifiant du fournisseur: ";
                std::cin >> id;
                // Vérifier si le fournisseur existe dans deque (it1), et s'il n'est pas encore ajouté dans le vecteur de fournisseurs de Produit (it2)
                auto it = find(fournisseur.begin(), fournisseur.end(), id);
                if(it != fournisseur.end() && !p.fournisseur_existe(id)){
                    f = *it;
                    // Modifier les informations du fournisseur
                    system("cls");
                    cout << "------ 3 - Gestion Produits ------" << endl;
                    cout << "Nouvelle id: ";
                    std::cin >> id;
                    cout << endl << "Nouveau nom: ";
                    std::cin >> nom;
                    cout << endl << "Nouveau contact: ";
                    std::cin >> contact;
                    f.setId(id);
                    f.setNom(nom);
                    f.setContact(contact);
                    // Modifier le fournisseur dans le deque des fournisseurs
                    fournisseur.erase(it);
                    fournisseur.push_back(f);
                    cout << endl << "Modifie avec succes! " << endl << endl;
                }
                else if(it == fournisseur.end()){
                    cout << "\tFournisseur introuvable! " << endl << endl;
                }
            }
        }
        else if(choix == 4){
            // Cas 5 - Supprimer un fournisseur
            int ref;
            system("cls");
            cout << "------ 3 - Gestion Produits ------" << endl;
            cout << "Reference du produit: ";
            std::cin >> ref;
            if(m.find(ref) == m.end()){
                cout << "Produit introuvable! " << endl << endl;
            }
            else{
                Produit& p = m[ref];
                int id;
                Fournisseur f;
                cout << endl << "Identifiant du fournisseur: ";
                std::cin >> id;
                // Vérifier si le fournisseur existe dans deque (it1), et s'il n'est pas encore ajouté dans le vecteur de fournisseurs de Produit (it2)
                auto it = find(fournisseur.begin(), fournisseur.end(), id);
                if(it != fournisseur.end() && !p.fournisseur_existe(id)){
                    // Suppression du fournisseur du vecteur fournisseurs dans produit
                    p.supprimerFournisseur(id);
                    // Suppression du fournisseur dans le deque 
                    fournisseur.erase(it);
                    cout << endl << "Supprime avec succes! " << endl << endl;
                }
                else if(it == fournisseur.end()){
                    cout << "\tFournisseur introuvable! " << endl << endl;
                }
            }
        }
        else if(choix == 5){
            // Cas 6 - Afficher le nombre des produits avec date_paiement > 2 mois
            int s = 0;
            time_t tempsActuel = time(nullptr); // Récupèrer le temps actuel
            tm* pre_dateActuel = localtime(&tempsActuel); // temps actuel -> date
            date dateActuel(pre_dateActuel->tm_mday, pre_dateActuel->tm_mon + 1, pre_dateActuel->tm_year+1900); // date actuelle
            
            //
            for(auto it=m.begin(); it!=m.end(); it++){
                vector <Paiement> paiements = it->second.getPaiements();
                for(int i=0; i<paiements.size(); i++){
                    // Calcule si la date de paiement > 2 mois
                    if((dateActuel.annee - paiements[i].getDatePaiement().annee) > 0){
                        // plusieurs années de différence, donc > 2 mois
                        s++;
                    }
                    else if((dateActuel.annee - paiements[i].getDatePaiement().annee) == 0
                        && (dateActuel.mois - paiements[i].getDatePaiement().mois) > 2){
                        // plus de 2 mois de différence
                        s++;
                    }
                }
            }
            // Affichage
            system("cls");
            cout << "------ 3 - Gestion Produits ------" << endl;
            cout << "Nombre des produits avec date_paiement > 2 mois: " << s << endl << endl;
        }
        else if(choix == 6){
            // Cas 7 - Réduire le prix du produit de 10% (si qt > 200)
            for(auto it=m.begin(); it!=m.end(); it++){
                if(it->second.getQuantite() > 200){
                    double nv_prix = it->second.getPrixHT() * 0.9;
                    it->second.setPrixHT(nv_prix);
                }
            }
            system("cls");
            cout << "------ 3 - Gestion Produits ------" << endl;
            cout << "Prix réduit avec succes !!" << endl << endl;
        }
        else if(choix == 7){
            // Cas 8 - Retour
            break;
        }
        else{
            cout << "Choix invalide. ";
        }
        cout << "Tapez un bouton pour retourner au MENU... ";
        std::cin.ignore();
        std::cin.get();
    }
}


void fonct4(list <Paiement>& paiements, map <int, Produit>& m, deque <Fournisseur>& fournisseur, set <Stock>& stocks){
    int choix;
    int nb_paiements;
    
    while(true){
        cout << "------ 4 - Gestion Paiement ------" << endl;
        cout << "\t1. Remplir la liste des paiements" << endl
            << "\t2. Ajouter 15.5% de TVA sur les produits de chaque paiement" << endl
            << "\t3. Modifier le fournisseur d'un paiement" << endl
            << "\t4. Ajouter un produit d'un paiement" << endl
            << "\t5. Supprimer un produit d'un paiement" << endl
            << "\t6. Afficher pour chaque paiement la fiche de paiement" << endl
            << "\t7. Retour" << endl
            << "Votre choix: ";
        std::cin >> choix;
        if(choix == 1 && paiements.empty()){
            cout << endl << "Veuillez remplir les paiements d'abord!" << endl << endl;
        }
        else if(choix == 1){
            // Cas 1 - Remplir la liste des paiements
            system("cls");
            cout << "------ 4 - Gestion Paiement ------" << endl;
            cout << "Donnez le nombre des paiements à remplir: ";
            std::cin >> nb_paiements;
            for(int i=0; i< nb_paiements; i++){
                int id;
                double montant;
                date d;
                int id_fournisseur;
                int nb_produits;
                cout << "Paiement " << i+1 << endl;
                cout << "\tIdentifiant: ";
                std::cin >> id;
                cout << "\tMontant: ";
                std::cin >> montant;
                cout << "\tDate paiement: ";
                std::cin >> d.jour >> d.mois >> d.annee;
                Paiement p(id, montant, d); // Initialisation du paiement
                while(true){
                    cout << endl << "\tFournisseur: ";
                    std::cin >> id_fournisseur;
                    // Vérifier si le fournisseur existe dans deque (it)
                    auto it = find(fournisseur.begin(), fournisseur.end(), id_fournisseur);
                    if(it != fournisseur.end()){
                        Fournisseur& f = *it;
                        p.setFournisseur(&f);
                        cout << "Donnez le nombre des produits à ajouter: ";
                        std::cin >> nb_produits;
                        for(int i=0; i<nb_produits; i++){
                            int ref;
                            cout << "Produit " << i+1 << endl;
                            cout << "\tReference: ";
                            std::cin >> ref;
                            // Vérifier si le produit existe dans map (it2)
                            auto it2 = m.find(ref);
                            if(it2 != m.end()){
                                Produit prod;
                                prod = it2->second;
                                p.ajouterProduit(prod);
                            }
                            else{
                                cout << "Produit introuvable! " << endl << endl;
                            }
                        }
                        break;
                    }
                    else if(it == fournisseur.end()){
                        cout << "\tFournisseur introuvable! " << endl << endl;
                    }
                }
            }
        }
        else if(choix == 2){
            // Cas 2 - Ajouter 15.5% de TVA sur les produits de chaque paiement
            for(auto it=paiements.begin(); it!=paiements.end(); it++){
                auto produits = it->getProduits();
                for(int i=0; i<produits.size(); i++){
                    double nv_prix = produits[i].getPrixHT();
                    produits[i].setPrixHT(nv_prix * 1.155);
                }
            }
            system("cls");
            cout << "------ 4 - Gestion Paiement ------" << endl;
            cout << "TVA ajoutée avec succes! " << endl << endl;
        }
        else if(choix == 3){
            // Cas 3 - Modifier le fournisseur d'un paiement
            int id_paiement, id_fournisseur;
            string nom, contact;
            system("cls");
            cout << "------ 4 - Gestion Paiement ------" << endl;
            while(true){
                cout << "Identifiant du paiement: ";
                std::cin >> id_paiement;
                // On vérifie si le paiement existe
                auto it = find(paiements.begin(), paiements.end(), id_paiement);
                if(it != paiements.end()){
                    cout << "Nouvel identifiant du fournisseur: ";
                    std::cin >> id_fournisseur;
                    // On vérifie si le fournisseur existe
                    auto it2 = find(fournisseur.begin(), fournisseur.end(), id_fournisseur);
                    if(it2 != fournisseur.end()){
                        Fournisseur& f = *it2;
                        it->setFournisseur(&f);
                        cout << "Fournisseur modifié avec succes! " << endl << endl;
                        break;
                    }
                    else{
                        cout << "Fournisseur introuvable! " << endl << endl;
                    }
                }
                else{
                    cout << "Paiement introuvable! " << endl << endl;
                }
            }   
        }
        else if(choix == 4){
            // Cas 4 - Ajouter un produit d'un paiement
            int id_paiement, ref_produit;
            system("cls");
            cout << "------ 4 - Gestion Paiement ------" << endl;
            while(true){
                cout << "Identifiant du paiement: ";
                std::cin >> id_paiement;
                // On vérifie si le paiement existe
                auto it = find(paiements.begin(), paiements.end(), id_paiement);
                if(it != paiements.end()){
                    cout << "Reference du produit: ";
                    std::cin >> ref_produit;
                    // On vérifie si le produit existe
                    auto it2 = m.find(ref_produit);
                    if(it2 != m.end()){
                        Produit prod = it2->second;
                        it->ajouterProduit(prod);
                        cout << "Produit ajouté avec succes! " << endl << endl;
                        break;
                    }
                    else{
                        cout << "Produit introuvable! " << endl << endl;
                    }
                }
                else{
                    cout << "Paiement introuvable! " << endl << endl;
                }
            }
        }
        else if(choix == 5){
            // Cas 5 - Supprimer un produit d'un paiement
            int id_paiement, ref_produit;
            system("cls");
            cout << "------ 4 - Gestion Paiement ------" << endl;
            while(true){
                cout << "Identifiant du paiement: ";
                std::cin >> id_paiement;
                // On vérifie si le paiement existe
                auto it = find(paiements.begin(), paiements.end(), id_paiement);
                if(it != paiements.end()){
                    cout << "Reference du produit: ";
                    std::cin >> ref_produit;
                    // On vérifie si le produit existe
                    auto it2 = m.find(ref_produit);
                    if(it2 != m.end()){
                        it->supprimerProduit(ref_produit);
                        cout << "Produit supprimé avec succes! " << endl << endl;
                        break;
                    }
                    else{
                        cout << "Produit introuvable! " << endl << endl;
                    }
                }
                else{
                    cout << "Paiement introuvable! " << endl << endl;
                }
            }
        }
        else if(choix == 6){
            // Cas 6 - Afficher pour chaque paiement la fiche de paiement
            system("cls");
            cout << "------ 4 - Gestion Paiement ------" << endl;
            for(auto it=paiements.begin(); it!=paiements.end(); it++){
                it->fiche_paiement();
                cout << endl;
            }
        }
        else if(choix == 7){
            // Cas 7 - Retour
            break;
        }
        else{
            cout << "Choix invalide. ";
        }
        cout << "Tapez un bouton pour retourner au MENU... ";
        std::cin.ignore();
        std::cin.get();
    }
}



int main(){
    set <Stock> stocks;
    deque <Fournisseur> fournisseur;
    map <int, Produit> m;
    list <Paiement> paiements;
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
            fonct1(stocks);
        }
        else if(choix == 2){
            // Cas 2 - Gestion Fournisseur
            fonct2(fournisseur);
        }
        else if(choix == 3){
            // Cas 3 - Gestion Produits
            fonct3(m, fournisseur, stocks);
        }
        else if(choix == 4){
            // Cas 4 - Gestion Paiement
            fonct4(paiements, m, fournisseur, stocks);
        }
        else if(choix == 5){
            // Cas 5 - Quitter
            break;
        }
        else{
            // Cas invalide
            cout << "Choix invalide. ";
            cout << "Tapez un bouton pour retourner au MENU... ";
            cin.ignore();
            cin.get();
        }
        
    }

}