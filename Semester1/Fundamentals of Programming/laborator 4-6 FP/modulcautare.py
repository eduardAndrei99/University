"""
Modul pentru cautari
"""

def CitesteNumar():
    while True:
        try:
            numar = int(input())
            return numar
        except ValueError:
            print ("Datele introduse nu sunt valide!")

def Meniu_Cautare():
    print ("Introduceti 1 pentru a tipari cheltuielile mai mari decat o suma ")
    print ("Introduceti 2 pentru a tipari cheltuielile de un anumit tip ")
    print ("Introduceti 3 pentru a tipari cheltuielile efectuate inainte de o zi si mai mari decat o suma ")
    ce_fac = CitesteNumar()
    ce_fac = int(ce_fac)
    return ce_fac

def Citesc_Suma():
    print ("Introduceti suma")
    Suma = CitesteNumar()
    Suma = int(Suma)
    return Suma

def Tiparesc_mai_mari(Bloc, Suma):
    contor = -1
    for i in Bloc:
        contor += 1
        suma = i[0]
        suma = int(suma)
        suma += i[1]
        suma += i[2]
        suma += i[3]
        suma += i[4]
        if suma > Suma:
            print (contor)

def Citesc_tipul():
    print ("Apasati 0 pentru tiparirea cheltuielilor de apa ")
    print ("Apasati 1 pentru tiparirea cheltuielilor de canal ")
    print ("Apasati 2 pentru tiparirea cheltuielilor de incalzire ")
    print ("Apasati 3 pentru tiparirea cheltuielilor de gaz ")
    print ("Apasati 4 pentru tiparirea altor cheltuieli ")
    tip = CitesteNumar()
    tip = int(tip)
    return tip

def Tiparesc_tipul(Bloc, tip):
    for i in Bloc:
        print(i[tip])
        




