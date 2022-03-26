#include <bits/stdc++.h>

using namespace std;

class Card{

protected:
    string nrCard, NumeDetinator, data_expirare; // numar card, nume detinator, data expirare card
    int cvv; // cod de 3 cifre de pe spatele cardului
    double credit; // valoarea totala de bani care se afla in card

    static int no_of_cards;

public:
    Card(); // constructor de initializare
    Card(string, string, string, int, double); // constructor in care se initializeaza numarul cardului, 
    //numele detinatorului, data expirarii, cvv-ul si suma totala din acel cont
    Card(const Card& ); // constructor de copiere

    virtual ~Card(); // destructor

    // Getters and Setters
    
    string GetNrCard(); // returneaza numarul cardului
    string GetNumeDetinator(); // returneaza numele detinatorului cardului
    string GetDataExpirare(); // returneaza data expirarii cardului
    int GetCvv(); // returneaza cvv-ul
    double GetCredit(); // returneaza suma care se afla in acel cont
    static int GetNoOfCard(); // returneaza numarul de carduri


    void SetNrCard(string); // seteaza numarul cardului
    void SetNumeDetinator(string); // seteaza numele detinatorului cardului
    void SetDataExpirare(string); // seteaza data de expirare a cardului
    void SetCvv(int); // seteaza cvv-ul
    void SetCredit(double); // seteaza valoarea creditului de pe card

    Card& operator= (const Card& card) // supraincarcarea operatorului = 
    {
        no_of_cards = no_of_cards + 1;
        nrCard = card.nrCard;
        NumeDetinator = card.NumeDetinator;
        data_expirare = card.data_expirare;
        cvv = card.cvv;
        credit = card.credit;
        return *this;
    }

    friend istream& operator>> (istream&, Card&);
    friend ostream& operator<< (ostream&, const Card&);

    // Metoda de withdraw

    virtual void Withdraw(double money){}

};

int Card::no_of_cards = 0;

class CardStandard: public Card{
protected:
    int withdrawalLimit; // limita extragere de pe card
    double commission; // comision depasire limita

public:

    CardStandard(); // constructor de initializare
    CardStandard(string, string, string, int, double, int, double); // constructor parametrizat
    CardStandard(const CardStandard&); // constructor de copiere
    ~CardStandard(); // destructor

    // Getters & Setters

    int GetWithdrawalLimit();
    double GetCommission();

    void SetWithdrawalLimit(int);
    void SetCommission(double);

    CardStandard& operator= (const CardStandard& card){
        nrCard = card.nrCard;
        NumeDetinator = card.NumeDetinator;
        data_expirare = card.data_expirare;
        cvv = card.cvv;
        credit = card.cvv;
        withdrawalLimit = card.withdrawalLimit;
        commission = card.commission;
        return *this;
    }

    friend istream& operator>>(istream&, CardStandard&);
    friend ostream& operator<<(ostream&, const CardStandard&);

    // Metoda

    void Withdraw(double);
};

class CardPremium: public CardStandard{

protected:
    double cashback;

public:
    CardPremium(); // constructor de initializare
    CardPremium(string, string, string, int, double, int, double, double); // constructor parametrizat
    CardPremium(const CardPremium&); // constructor de copiere

    ~CardPremium(); // destructor

    //Getters & Setters

    double GetCashback();
    void SetCashback(double);

    CardPremium& operator= (const CardPremium& card) // supraincarcarea lui =
    {
        nrCard = card.nrCard;
        NumeDetinator = card.NumeDetinator;
        data_expirare = card.data_expirare;
        cvv = card.cvv;
        credit = card.cvv;
        withdrawalLimit = card.withdrawalLimit;
        commission = card.commission;
        cashback = card.cashback;
        return *this;
    }

    friend istream& operator>>(istream& in, CardPremium& card)
    {
        
        cout<<"Numarul cardului: ";
        in.get();
        getline(in, card.nrCard);
        cout<<endl;

        cout<<"Numele detinatorului: ";
        getline(in, card.NumeDetinator);
        cout<<endl;

        cout<<"Data expirare card: ";
        getline(in, card.data_expirare);
        cout<<endl;

        cout<<"Cod Cvv: ";
        in>>card.cvv;
        cout<<endl;

        cout<<"Credit card: ";
        in>>card.credit;
        cout<<endl;

        cout<<"Limita extragere: ";
        in>>card.withdrawalLimit;
        cout<<endl;

        cout<<"Comision pentru depasirea limitei (valoare procentuala): ";
        in>>card.commission;
        cout<<endl;

        cout<<"Cashback: ";
        in>>card.cashback;
        cout<<endl;

        return in;
    }
    friend ostream& operator<<(ostream& out, const CardPremium& card){
        out<<"Numarul cardului : "<<card.nrCard<<endl;
        out<<"Numele detinatorului cardului : "<<card.NumeDetinator<<endl;
        out<<"Data de expirare : "<<card.data_expirare<<endl;
        out<<"CVV-ul cardului : "<<card.cvv<<endl;
        out<<"Creditul cardului : "<<card.credit<<endl;
        out<<"Limita extragere: "<<card.withdrawalLimit<<endl;
        out<<"Comision depasire limita extragere (valoare procentuala): "<<card.commission<<endl;
        out<<"Cashback: "<<card.cashback<<endl;
        return out;
    }

    // Metoda

    void Withdraw(double);
};

#pragma region Card

Card::Card(){
    nrCard = "";
    NumeDetinator = "";
    data_expirare = "";
    cvv = 0;
    credit = 0;
    no_of_cards = no_of_cards + 1;
}

Card::Card(string nrCard, string NumeDetinator, string data_expirare, int cvv, double credit)
{
    this->nrCard = nrCard;
    this->NumeDetinator = NumeDetinator;
    this->data_expirare = data_expirare;
    this->cvv = cvv;
    this->credit = credit;
    no_of_cards = no_of_cards + 1;
}

Card::Card(const Card& card)
{
    nrCard = card.nrCard;
    NumeDetinator = card.NumeDetinator;
    data_expirare = card.data_expirare;
    cvv = card.cvv;
    credit = card.credit;
}

Card::~Card()
{
    nrCard = "";
    NumeDetinator = "";
    data_expirare = "";
    cvv = 0;
    credit = 0;
    no_of_cards = no_of_cards - 1;
}

string Card::GetNrCard()
{
    return nrCard;
}

string Card::GetNumeDetinator(){
    return NumeDetinator;
}

string Card::GetDataExpirare()
{
    return data_expirare;
}

int Card::GetCvv(){
    return cvv;
}

double Card::GetCredit(){
    return credit;
}

int Card::GetNoOfCard()
{
    return no_of_cards;
}

void Card::SetNrCard(string nrCard)
{
    this->nrCard = nrCard;
}

void Card::SetNumeDetinator(string NumeDetinator)
{
    this->NumeDetinator = NumeDetinator;
}

void Card::SetDataExpirare(string data_expirare)
{
    this->data_expirare = data_expirare;
}

void Card::SetCvv(int cvv)
{
    this->cvv = cvv;
}

void Card::SetCredit(double credit)
{
    this->credit = credit;
}

istream& operator>>(istream& in, Card& card){

    cout<<"Numarul cardului: ";
    in.get();
    getline(in, card.nrCard);
    cout<<endl;

    cout<<"Numele detinatorului: ";
    getline(in, card.NumeDetinator);
    cout<<endl;

    cout<<"Data expirare card: ";
    getline(in, card.data_expirare);
    cout<<endl;

    cout<<"Cod Cvv: ";
    in>>card.cvv;
    cout<<endl;

    cout<<"Credit card: ";
    in>>card.credit;
    cout<<endl;

    return in;

}

ostream& operator<<(ostream& out, const Card& card)
{
    out<<"Numarul cardului : "<<card.nrCard<<endl;
    out<<"Numele detinatorului cardului : "<<card.NumeDetinator<<endl;
    out<<"Data de expirare : "<<card.data_expirare<<endl;
    out<<"CVV-ul cardului : "<<card.cvv<<endl;
    out<<"Creditul cardului : "<<card.credit<<endl;

    return out;
}

#pragma endregion

#pragma region CardStandard

CardStandard::CardStandard(){
    withdrawalLimit = 0;
    commission = 0;
}

CardStandard::CardStandard(string nrCard, string NumeDetinator, string data_expirarii, int cvv, double credit,int withdrawalLimit, double commission)
{
    Card(nrCard, NumeDetinator, data_expirare, cvv, credit);
    this->withdrawalLimit = withdrawalLimit;
    this->commission = commission;
}

CardStandard::CardStandard(const CardStandard& card)
{
    nrCard = card.nrCard;
    NumeDetinator = card.NumeDetinator;
    data_expirare = card.data_expirare;
    cvv = card.cvv;
    credit = card.credit;
    withdrawalLimit = card.withdrawalLimit;
    commission = card.commission;
}

CardStandard::~CardStandard(){
    nrCard = "";
    NumeDetinator = "";
    data_expirare = "";
    cvv = 0;
    credit = 0;
    withdrawalLimit = 0;
    commission = 0;
}

int CardStandard::GetWithdrawalLimit(){
    return withdrawalLimit;
}

double CardStandard::GetCommission(){
    return commission;
}

void CardStandard::SetWithdrawalLimit(int withdrawalLimit){
    this->withdrawalLimit = withdrawalLimit;
}

void CardStandard::SetCommission(double commission){
    this->commission = commission;
}

istream& operator>>(istream& in, CardStandard& card)
{
    cout<<"Numarul cardului: ";
    in.get();
    getline(in, card.nrCard);
    cout<<endl;

    cout<<"Numele detinatorului: ";
    getline(in, card.NumeDetinator);
    cout<<endl;

    cout<<"Data expirare card: ";
    getline(in, card.data_expirare);
    cout<<endl;

    cout<<"Cod Cvv: ";
    in>>card.cvv;
    cout<<endl;

    cout<<"Credit card: ";
    in>>card.credit;
    cout<<endl;

    cout<<"Limita extragere: ";
    in>>card.withdrawalLimit;
    cout<<endl;

    cout<<"Comision pentru depasirea limitei (valoare procentuala): ";
    in>>card.commission;
    cout<<endl;

    return in;
}

ostream& operator<< (ostream& out, const CardStandard& card)
{
    out<<"Numarul cardului : "<<card.nrCard<<endl;
    out<<"Numele detinatorului cardului : "<<card.NumeDetinator<<endl;
    out<<"Data de expirare : "<<card.data_expirare<<endl;
    out<<"CVV-ul cardului : "<<card.cvv<<endl;
    out<<"Creditul cardului : "<<card.credit<<endl;
    out<<"Limita extragere: "<<card.withdrawalLimit<<endl;
    out<<"Comision depasire limita extragere (valoare procentuala): "<<card.commission<<endl;

    return out;
}

void CardStandard::Withdraw(double money)
{
    double creditWithCommission = credit - money - commission/100 * money;
    if(credit < money)
    {
        cout<<"Fonduri insuficiente pe cardul "<<nrCard<<endl;
        return;
    }
    else if(money < withdrawalLimit){
        credit = credit - money;      
    }
    else if(withdrawalLimit <= money && credit > money && creditWithCommission>=0)
    {
        credit = creditWithCommission;
    }
    cout<<"Creditul actual de pe cardul "<<nrCard<<" : "<<credit<<endl;
}

#pragma endregion

#pragma region CardPremium

CardPremium::CardPremium(){
    CardStandard();
    cashback = 0;
}

CardPremium::CardPremium(string nrCard, string NumeDetinator, string data_expirarii, int cvv, double credit, int withdrawalLimit, double commission, double cashback){
    CardStandard(nrCard, NumeDetinator, data_expirarii, cvv, credit, withdrawalLimit, commission);
    this->cashback = cashback;
}

CardPremium::CardPremium(const CardPremium& card){
    nrCard = card.nrCard;
    NumeDetinator = card.NumeDetinator;
    data_expirare = card.data_expirare;
    cvv = card.cvv;
    credit = card.credit;
    withdrawalLimit = card.withdrawalLimit;
    commission = card.commission;
    cashback = card.cashback;
} 

CardPremium::~CardPremium(){
    nrCard = "";
    NumeDetinator = "";
    data_expirare = "";
    cvv = 0;
    credit = 0;
    withdrawalLimit = 0;
    commission = 0;
    cashback = 0;
}

double CardPremium::GetCashback(){
    return cashback;
}

void CardPremium::SetCashback(double cashback){
    this->cashback = cashback;
}

void CardPremium::Withdraw(double money)
{
    double new_cashback;
    if(credit < money)
    {
        cout<<"Credit insuficient"<<endl;
        return;
    }
    else{
        credit = credit - money;
        new_cashback = (cashback/100)*money;
        SetCredit(credit + new_cashback);
    }
    cout<<"Extragere reusita! Cashback-ul obtinut in urma tranzatiei este "<<new_cashback<<endl;
    cout<<"Creditul curent: "<<credit<<endl;
}

#pragma endregion

void Menu()
{
    CardStandard *CardS, *CardS_aux;
    CardPremium *CardP, *CardP_aux;
    CardS = CardS_aux = nullptr;
    CardP = CardP_aux = nullptr;
    int no_of_S_Cards, no_of_P_cards;
    no_of_S_Cards = no_of_P_cards = 0;
    int command = -1;
    while(command != 0)
    {
        cout<<endl;
        cout<<"Introduceti numarul comenzii: "<<endl;
        cout<<"0. Iesire"<<endl;
        cout<<"1. Citire si memorare a N carduri"<<endl;
        cout<<"2. Afisarea detaliilor unui card"<<endl;
        cout<<"3. Extragerea creditului de pe un card"<<endl;
        cout<<"4. Introducere carduri"<<endl;
        cin>>command;
        if(command == 0)
            break;
        else if(command == 1)
        {
            int tip = 0;
            cout<<"Ce tip de carduri doriti sa introduceti? "<<endl;
            cout<<"1. Card Standard"<<endl;
            cout<<"2. Card Premium"<<endl;

            while(tip < 1 || tip > 2)
            {
                cout<<"Comanda: ";
                cin>>tip;
                if(tip < 1 || tip > 2)
                {
                    cout<<"Tip de card invalid. Va rugam sa reincercati"<<endl;
                }
            }

            if(tip == 1)
            {
                cout<<"Numarul de carduri este: ";
                cin>>no_of_S_Cards;
                CardS = new CardStandard[no_of_S_Cards];

                cout<<"Detaliile cardurilor"<<endl;

                for(int i=0;i<no_of_S_Cards;i++)
                {
                    cout<<"Cardul curent este: "<<i+1<<endl;
                    cin>>CardS[i];
                }

                cout<<"Au fost inregistrate "<<Card::GetNoOfCard()<<" carduri"<<endl;
            }
            else{
                cout<<"Numarul de carduri este: ";
                cin>>no_of_P_cards;
                CardP = new CardPremium[no_of_P_cards];

                cout<<"Detaliile cardurilor"<<endl;

                for(int i=0;i<no_of_P_cards;i++)
                {
                    cout<<"Cardul curent este: "<<i+1<<endl;
                    cin>>CardP[i];
                }

                cout<<"Au fost inregistrate "<<Card::GetNoOfCard()<<" carduri"<<endl;
                
            }
        }
        else if(command == 2)
        {
            int cardIndex;
            char tipCard;
            cout<<"Alegeti cardul pentru care vreti sa vedeti detaliile"<<endl;
            if(CardS)
            {
                cout<<"a. Carduri standard:"<<endl;
                for(int i=0;i<no_of_S_Cards;i++)
                {
                    cout<<i+1<<". ";
                    cout<<CardS[i].GetNumeDetinator()<<endl;
                }
            }
            if(CardP)
            {
                cout<<"b. Carduri premium:"<<endl;
                for(int i=0;i<no_of_P_cards;i++)
                {
                    cout<<i+1<<". ";
                    cout<<CardP[i].GetNumeDetinator()<<endl;
                }
            }
            cout<<"Tipul cardului (litera): ";
            cin>>tipCard;
            while(tipCard <'a' || tipCard > 'b')
            {
                cout<<"Tipul cardului (litera): ";
                cin>>tipCard;
                if(tipCard < 'a' || tipCard > 'b')
                {
                    cout<<"Comanda invalida"<<endl;
                }
            }

            cout<<"Indexul cardului pe care doriti sa-l afisati: ";
            cin>>cardIndex;

            while(cardIndex < 1)
            {
                cout<<"Introduceti indexul cardului pe care doriti sa-l afisati: ";
                cin>>cardIndex;
                if(cardIndex < 1)
                {
                    cout<<"Comanda invalida"<<endl;
                }
            }

            if(tipCard == 'a')
            {
                if(cardIndex > no_of_S_Cards)
                {
                    cout<<"Index invalid"<<endl;
                }
                else{
                    cout<<"Detaliile cardului sunt: "<<endl;
                    cout<<CardS[cardIndex - 1];
                }
            }
            else{
                if(cardIndex > no_of_P_cards)
                {
                    cout<<"Index invalid"<<endl;
                }
                else{
                    cout<<"Detaliile cardului sunt: "<<endl;
                    cout<<CardP[cardIndex - 1];
                }
            }
        }
        else if(command == 3)
        {
            int cardIndex;
            char tipCard;
            double moneyExtract = 0;
            cout<<"Alegeti cardul din care doriti sa efectuati tranzactia: "<<endl;
            if(CardS)
            {
                cout<<"a. Carduri Standard"<<endl;
                for(int i=0;i<no_of_S_Cards;i++)
                {
                    cout<<i+1<<". ";
                    cout<<CardS[i].GetNumeDetinator()<<endl;
                }
            }
            if(CardP)
            {
                cout<<"b. Carduri Premium"<<endl;
                for(int i=0;i<no_of_P_cards;i++)
                {
                    cout<<i+1<<". ";
                    cout<<CardP[i].GetNumeDetinator()<<endl;
                }
            }

            cout<<"Tipul cardului (litera): ";
            cin>>tipCard;
            while(tipCard <'a' || tipCard >'b')
            {
                cout<<"Tipul cardului (litera): ";
                cin>>tipCard;
                if(tipCard < 'a' || tipCard > 'b')
                {
                    cout<<"Comanda invalida"<<endl;
                }
            }
            
            cout<<"Indexul cardului de pe care vreti sa scoateti bani: ";
            cin>>cardIndex;
            while(cardIndex < 1)
            {
                cout<<"Indexul cardului de pe care vreti sa scoateti bani:";
                cin>>cardIndex;
                if(cardIndex < 1)
                {
                    cout<<"Comanda invalida"<<endl;
                }
            }

            cout<<"Introduceti suma pe care doriti sa o extrageti: ";
            cin>>moneyExtract;
            if(toupper(tipCard) == 'A')
            {
                if(cardIndex > no_of_S_Cards)
                {
                    cout<<"Index invalid"<<endl;
                }
                else{
                    CardS->Withdraw(moneyExtract);
                }
            }
            else{
                if(cardIndex > no_of_P_cards)
                {
                    cout<<"Index invalid"<<endl;
                }
                else{
                    CardP->Withdraw(moneyExtract);
                }
            }
        }
        else if(command == 4)
        {
            int tipCard = 0;
            cout<<"Introduceti tipul de carduri pe care doriti sa le alegeti: "<<endl;
            cout<<"1. Card Standard"<<endl;
            cout<<"2. Card Premium"<<endl;
            while(tipCard < 1 || tipCard > 2)
            {
                cout<<"Comanda: ";
                cin>>tipCard;
                if(tipCard < 1|| tipCard > 2)
                {
                    cout<<"Comanda invalida"<<endl;
                }
            }
            if(tipCard == 1)
            {
                int no_of_S_Cards_aux = no_of_S_Cards;
                cout<<"Introduceti numarul de carduri pe care doriti sa le alegeti: ";
                cin>>no_of_S_Cards;
                CardS_aux = new CardStandard[no_of_S_Cards + no_of_S_Cards_aux];
                for(int i=0;i<no_of_S_Cards_aux;i++)
                {
                    CardS_aux[i] = CardS[i]; // punem element cu element in aux, mai raman astfel no_of_S_Cards elemente
                }
                delete []CardS;

                CardS = new CardStandard[no_of_S_Cards + no_of_S_Cards_aux];

                cout<<"Introduceti detaliile cardurilor "<<endl;
                for(int i=no_of_S_Cards_aux;i<no_of_S_Cards + no_of_S_Cards_aux;i++)
                {
                    cout<<"Cardul curent "<<i+1<<endl;
                    cin>>CardS[i];
                }

                for(int i=0;i<no_of_S_Cards_aux;i++)
                {
                    CardS[i] = CardS_aux[i];
                }

                delete []CardS_aux;
                no_of_S_Cards = no_of_S_Cards + no_of_S_Cards_aux;
                cout<<"Au fost inregistrate "<<no_of_S_Cards<<" carduri"<<endl;
            }
            else{
                int no_of_P_cards_aux = no_of_P_cards;
                cout<<"Introduceti numarul de carduri pe care doriti sa le alegeti: ";
                cin>>no_of_P_cards;
                CardP_aux = new CardPremium[no_of_P_cards + no_of_P_cards_aux];
                for(int i=0;i<no_of_P_cards_aux;i++)
                {
                    CardP_aux[i] = CardP[i]; // punem element cu element in aux, mai raman astfel no_of_P_cards elemente
                }
                delete []CardS;

                CardP = new CardPremium[no_of_P_cards + no_of_P_cards_aux];

                cout<<"Introduceti detaliile cardurilor "<<endl;
                for(int i=no_of_P_cards_aux;i<no_of_P_cards + no_of_P_cards_aux;i++)
                {
                    cout<<"Cardul curent "<<i+1<<endl;
                    cin>>CardP[i];
                }

                for(int i=0;i<no_of_P_cards_aux;i++)
                {
                    CardP[i] = CardP_aux[i];
                }

                delete []CardP_aux;
                no_of_P_cards = no_of_P_cards + no_of_P_cards_aux;
                cout<<"Au fost inregistrate "<<no_of_P_cards<<" carduri"<<endl;

            }
        }
        else{
            cout<<"Comanda invalida"<<endl;
        }
    }
    cout<<"Iesire program";
}

int main()
{
    char command;
    cout<<"Introduceti y pentru a porni sau n pentru a iesi: ";
    cin>>command;
    while(toupper(command) != 'Y')
    {
        if(toupper(command) == 'N')
            return 0;
        else{
            cout<<"Comanda invalida"<<endl;
        }
        cout<<"Introduceti y pentru a porni sau n pentru a iesi: ";
        cin>>command;
    }
    Menu();
    return 0;
}       