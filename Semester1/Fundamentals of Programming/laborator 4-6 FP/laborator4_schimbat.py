"""
Meniul principal
"""
from modulcautare import *

def meniul():
    #Functie ce afiseaza meniul
    print ("Apasati 1 pentru adaugare ")
    print ("Apasati 2 pentru stergere ")
    print ("Apasati 3 pentru cautari ")
    print ("Apasati 4 pentru rapoarte ")
    print ("Apasati 5 pentru filtru ")
    print ("Apasati 6 pentru refacerea ultimei operatii ")
    print ("Apasati 7 pentru iesire ")
    print ()

def Citesc_Apartamentu():
    #Functie ce citeste un apartament
    print("Introduceti cheltuiala de apa ")
    Apa = CitesteNumar()
    print("Introduceti cheltuiala de canal ")
    Canal = CitesteNumar()
    print("Introduceti cheltuiala de incalzire ")
    Incalzire = CitesteNumar()
    print("Introduceti cheltuiala de gaz ")
    Gaz = CitesteNumar()
    print("Introduceti alte cheltuieli ")
    Altele = CitesteNumar()
    print ()
    return Apa, Canal, Incalzire, Gaz, Altele

def Modific_Apartamentu():
    print("Introduceti apartamentul pe care doriti sa il modificati ")
    Apartament = CitesteNumar()
    print("Introduceti cheltuiala de apa ")
    Apa = CitesteNumar()
    print("Introduceti cheltuiala de canal ")
    Canal = CitesteNumar()
    print("Introduceti cheltuiala de incalzire ")
    Incalzire = CitesteNumar()
    print("Introduceti cheltuiala de gaz ")
    Gaz = CitesteNumar()
    print("Introduceti alte cheltuieli")
    Altele = CitesteNumar()
    print()
    return Apartament, Apa, Canal, Incalzire, Gaz, Altele


def Adaug_cheltuiala_apartament(Bloc, Apa, Canal, Incalzire, Gaz, Altele):
    #Functie ce imi adauga apartament in bloc
    Lista_adaugat = [Apa, Canal, Incalzire, Gaz, Altele]
    Bloc.append(Lista_adaugat)
    return Bloc

def Modific_cheltuiala_apartament(Bloc, Apartament, Apa, Canal, Incalzire, Gaz, Altele):
    #Functie ce imi modifica cheltuiala unui apartament
    Bloc[Apartament][0] = Apa
    Bloc[Apartament][1] = Canal
    Bloc[Apartament][2] = Incalzire
    Bloc[Apartament][3] = Gaz
    Bloc[Apartament][4] = Altele
    return Bloc

def Test_adaugare_cheltuiala_apartament():
    #Functie de testare a adaugarii unui nou apartament
    assert Adaug_cheltuiala_apartament([[1, 2, 3, 4, 5],[1, 2, 3, 4, 5]], 5, 4, 3, 2, 1) == [[1, 2, 3, 4, 5],[1, 2, 3, 4, 5],[5, 4, 3, 2, 1]]
    assert Adaug_cheltuiala_apartament([[1, 2, 2, 2, 2]], 1, 2, 3, 4, 4) == [[1, 2, 2, 2, 2],[1, 2, 3, 4, 4]]
    assert Adaug_cheltuiala_apartament([], 1, 1, 1, 1, 1) == [[1, 1, 1, 1, 1]]

def Test_modificare_cheltuiala():
    #Functie de testare a modificarii unui apartament
    assert Modific_cheltuiala_apartament([[1, 2, 3, 4, 5],[1, 2, 3, 4, 5],[5, 4, 3, 2, 1]], 2, 1, 1, 1, 1, 1) == [[1, 2, 3, 4, 5],[1, 2, 3, 4, 5],[1, 1, 1, 1, 1]]
    assert Modific_cheltuiala_apartament([[1, 2, 3, 4, 12]], 0, 90, 90, 90, 90,90) == [[90, 90, 90, 90, 90]]
    assert Modific_cheltuiala_apartament([[0, 0, 0, 0, 0], [1, 1, 1, 1, 1], [1, 2, 3, 4, 5]], 1, 0, 0, 0, 0, 0) == [[0, 0, 0, 0, 0], [0, 0, 0, 0, 0], [1, 2, 3, 4, 5]]

def Sterg_Toate_Cheltuielile(Bloc, Apartament_Nr):
    #Functie de sters cheltuilelile de la apartamentul: Apartament_Nr
    Bloc[Apartament_Nr][0] = 0
    Bloc[Apartament_Nr][1] = 0
    Bloc[Apartament_Nr][2] = 0
    Bloc[Apartament_Nr][3] = 0
    Bloc[Apartament_Nr][4] = 0
    return Bloc

def Citesc_Apartamentul():
    print("Introduceti apartamentul ")
    Apartament = CitesteNumar()
    return Apartament

def Citesc_Intervalul():
    print("Introduceti primul apartament ")
    Inceput = CitesteNumar()
    print("Introduceti ultimul apartament ")
    Sfarsit = CitesteNumar
    return Inceput, Sfarsit

def Test_Sterg_Cheltuielile():
    #Functie de testare a stergerii tuturor cheltuielilor
    assert Sterg_Toate_Cheltuielile([[1, 2, 3, 4, 4], [1, 2, 2, 2, 23]],1) == [[1, 2, 3, 4, 4],[0, 0, 0, 0, 0]]
    assert Sterg_Toate_Cheltuielile([[2, 2, 2, 2, 2]], 0) == [[0, 0, 0, 0, 0]]
    assert Sterg_Toate_Cheltuielile([[2, 2, 2131, 32, 21], [1, 2, 3, 4,5], [2,1,2,2,1]], 1) == [[2, 2, 2131, 32, 21], [0, 0, 0, 0,0], [2,1,2,2,1]]

def Sterg_Anumite_Apartamente(Bloc, Inceput, Sfarsit):
    #Stergerea unui interval de apartamente
    while Inceput <= Sfarsit:
        Sterg_Toate_Cheltuielile(Bloc, Inceput)
        Inceput += 1
    return Bloc

def Test_Sterg_Consecutive():
    #Testarea stergerii de apartamente consecutive
    assert Sterg_Anumite_Apartamente([[1,2,3,3,4], [2,1,1,3,4], [1,1,1,1,1], [1,3,2,3,1]],1,3) == [[1,2,3,3,4], [0,0,0,0,0], [0,0,0,0,0], [0,0,0,0,0]]
    assert Sterg_Anumite_Apartamente([[1,2,3,3,4], [2,1,1,3,4], [1,1,1,1,1], [1,3,2,3,1]],1,2) == [[1,2,3,3,4], [0,0,0,0,0], [0,0,0,0,0], [1,3,2,3,1]]

def Sterg_Un_Tip(Bloc, Tip):
    for i in Bloc:
        i[Tip] = 0
    return Bloc

def Test_Sterg_Tip():
    assert Sterg_Un_Tip([[1,2,3,3,4], [2,1,1,3,4], [1,1,1,1,1], [1,3,2,3,1]], 1) == [[1,0,3,3,4], [2,0,1,3,4], [1,0,1,1,1], [1,0,2,3,1]]
    assert Sterg_Un_Tip([[1,2,3,3,4], [2,1,1,3,4], [1,1,1,1,1], [1,3,2,3,1]], 2) == [[1,2,0,3,4], [2,1,0,3,4], [1,1,0,1,1], [1,3,0,3,1]]

Test_Sterg_Tip()
Test_Sterg_Consecutive()
Test_Sterg_Cheltuielile()
Test_adaugare_cheltuiala_apartament()
Test_modificare_cheltuiala()
Bloc = []
optiune = 0
while optiune != 7:
    meniul()
    optiune = CitesteNumar()
    if optiune < 1:
        print("Incorect")
    elif optiune >7:
        print("Incorect")
    elif optiune == 1:
        print ("Apasati 1 pentru adaugarea unui apartament nou ")
        print ("Apasati 2 pentru modificarea unui apartament existent")
        ce_fac = CitesteNumar()
        print ()
        if ce_fac == 1:
            Apa, Canal, Incalzire, Gaz, Altele = Citesc_Apartamentu()
            Adaug_cheltuiala_apartament(Bloc, Apa, Canal, Incalzire, Gaz, Altele)
        elif ce_fac == 2:
            Apartament, Apa, Canal, Incalzire, Gaz, Altele = Modific_Apartamentu()
            Modific_cheltuiala_apartament(Bloc, Apartament, Apa, Canal, Incalzire, Gaz, Altele)
    elif optiune == 2:
        print ("Apasati 1 pentru stergerea cheltuielilor de la un apartament ")
        print ("Apasati 2 pentru stergerea cheltuielilor de la un interval de apartamente ")
        print ("Apasati 3 pentru stergerea unui tip de cheltuiala de la toate apartamentele ")
        ce_fac = CitesteNumar()
        if ce_fac == 1:
            Apartament_De_Sters = Citesc_Apartamentul()
            Sterg_Toate_Cheltuielile(Bloc, Apartament_De_Sters)
        elif ce_fac == 2:
            Inceput, Sfarsit = Citesc_Intervalul()
            Sterg_Anumite_Apartamente(Bloc, Inceput, Sfarsit)
        elif ce_fac ==3:
            print ("Apasati 0 pentru stergerea cheltuielilor de apa ")
            print ("Apasati 1 pentru stergerea cheltuielilor de canal ")
            print ("Apasati 2 pentru stergerea cheltuielilor de incalzire ")
            print ("Apasati 3 pentru stergerea cheltuielilor de gaz ")
            print ("Apasati 4 pentru stergerea altor cheltuieli ")
            ce_sterg = CitesteNumar()
            Sterg_Un_Tip(Bloc, ce_sterg)
    elif optiune == 3:
        ce_fac = Meniu_Cautare()
        if ce_fac == 1:
            Suma = Citesc_Suma()
            Tiparesc_mai_mari(Bloc, Suma)            
        if ce_fac == 2:
            tip = Citesc_tipul()
            Tiparesc_tipul(Bloc, tip)
        
        


