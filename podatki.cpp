#include <iostream>
#include <conio.h>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct podatnik{
    string imie;
    string nazwisko;
    int kwota;
    string PESEL;
    };

void dodajPod( vector<podatnik>&list );
void wyswietlData( vector<podatnik>&list );
void wyszukajPer( vector<podatnik>&list );
void wyswietlPer( podatnik &osoba );

int main() {
    podatnik osoba;
    char option;
    bool exit = false;
    string response;
    vector <podatnik> perlist;
    do {
        system("cls");
        cout << "Program Podatnik +" << endl;
        cout << "1.Dodaj podatnika" << endl;
        cout << "2.Wyszukaj podatnika po PESELU" << endl;
        cout << "3.Wyswietl wszystkich podatników" << endl;
        cout << "4.Zamknij" << endl;

        option = (char)getch();

        switch (option) {
            case '1':
                dodajPod( perlist );
                cout << "Wcisnij dowolny klawisz, aby kontynuowac...";
                getch();
                break;
            case '2':
                wyszukajPer( perlist );
                cout << "Wcisnij dowolny klawisz, aby kontynuowac...";
                getch();
                break;
            case '3':
                wyswietlData(perlist);
                cout << "Wcisnij dowolny klawisz, aby kontynuowac...";
                getch();
                break;
            case '4': exit = true;
                break;
            default:
                cout << "Brak takiej opcji!" << endl;
        }
    }while(!exit);

    return 0;
}

void dodajPod( vector<podatnik>&list ){
    podatnik osoba;
    system("cls");
    cout << "Dodawanie podatnika:" << endl;
    cout << "Podaj imie: ";
    cin >> osoba.imie;
    cout << "Podaj nazwisko: ";
    cin >> osoba.nazwisko;
    cout << "Podaj kwote podatku: ";
    cin >> osoba.kwota;
    cout << "Podaj pesel: ";
    cin >> osoba.PESEL;
    list.push_back(osoba);
}

void wyswietlData(vector<podatnik>&list){
    system("cls");
    for( int i = 0 ; i < list.size(); i++ ){
        cout << "Podatnik " << i+1 << ":" << endl;
        cout << "Imie: " << list[i].imie << endl;
        cout << "Nazwisko: " << list[i].nazwisko << endl;
        cout << "Kwota: " << list[i].kwota << endl;
        cout << "PESEL: " << list[i].PESEL << endl << endl;
    }
}

void wyszukajPer(vector<podatnik>&list){
    char option;
    int counter = 0;
    bool end = false;
    string query;
    system("cls");
    do{
        cout << "Podaj PESEL: " << endl;
        cin >> query;
                for( int i = 0; i < list.size(); i++ ){
                    if( list[i].PESEL == query ){
                        wyswietlPer( list[i] );
                        counter++;
                    }
                }
                if( counter == 0 ) cout << "Nic nie znaleziono." << endl;
                end = true;
                break;

    }while(!end);

}

void wyswietlPer( podatnik &osoba ){
    cout << endl << "Imie: " << osoba.imie << endl;
    cout << "Nazwisko: " << osoba.nazwisko << endl;
    cout << "Kwota: " << osoba.kwota << endl;
    cout << "PESEL: " << osoba.PESEL << endl;
}

