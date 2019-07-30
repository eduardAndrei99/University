"""
Programul afiseaza cea mai lunga secventa
Cu proprietatea ca in oricare 3 elemente consecutive
Exista o valoare care se repeta
Evident, lungimea listei trebuie sa fie un numar natural > 0
In cazul in care lungimea listei este 1, se va afisa el
In cazul in care lungimea listei este 2, se vor afisa cele doua valori
In cazul in care nu exista o secventa > 2 cu proprietatea ceruta
Se vor afisa primele 2 elemente
In cazul in care exista mai multe secvente cu proprietatea ceruta
De lungime maxima, se va afisa prima gasita
Complexitatea algoritmului este O (n ^ 2)
Variabila i reprezinta primul element al secventei
Variabila j reprezinta ultimul element al secventei
Daca nu e bun, iesim din bucla lui j
Daca e bun, crestem j ul si verificam
In cazul in care lungimea curenta este mai mare decat lungimea
Maxima de pana acum
Actualizam secventa ( inceput, sfarsit, lungime_maxima_noua)

Teste :
Lungime lista = 1, Lista = [1] -> afisam 1
Lungime lista = 2, Lista = [1 ,3] -> afisam 1 3
Lungime lista = 3, Lista = [1, 2, 3] -> afisam 1 2
Lungime lista = 5, Lista = [1, 2, 3, 4, 5] -> afisam 1 2
Lungime lista = 6, Lista = [1, 1, 1, 1, 1, 1] -> afisam 1 1 1 1 1 1
Lungime lista = 5, Lista = [2, 3, 2, 3, 2] -> afisam 2 3 2 3 2
Lungime lista = 6, Lista = [1, 4, 3, 2 ,2 ,2] -> afisam 3 2 2 2

Testele construite acopera scenarii de rulare ( toate elementele egale sau
niciun element egal sau n < 3 etc )

Analog la problema 10 , doar functia de testare diferita !!

Teste:
Lungime lista = 8, Lista = [2, 3, 1, 6, 4, 20, 17, 21] -> afisam 2 3 1 6 4 20 17 21
Lungime lista = 6, Lista = [5, -1, 14, -19, -20, 7] -> afisam 5, -1, 14, -19
Lungime lista = 8, Lista = [2, 3, 4, 6, 6, 5, 7, 4] -> afisam 6 5 7 4

"""

def Citire_Lista(lista):
    # Functie ce citeste o lista de numere intregi
    # Lungimea listei trebuie sa fie > 0
    
    lungime_lista = input("Introduceti numarul de elemente a listei ")
    lungime_lista = int(lungime_lista)
    
    for i in range(0, lungime_lista):
        element_de_citit = input("Introduceti elementul: ")
        element_de_citit = int(element_de_citit)
        lista.append(element_de_citit)

def E_bun_noua(element, lista):
    #Functie ce returneaza daca elementul are proprietatea ceruta
    
    if lista[element] == lista[element - 1]:
        return True
    elif lista[element] == lista[element -2]:
            return True
    elif lista[element - 1] == lista[element -2]:
            return True
    return False

def E_bun_zece(element, lista):
    #Functie ce returneaza daca elementul are proprietatea ceruta
    if (lista[element + 1] - lista[element]) == 0:
        return False
    if (lista[element + 2] - lista[element + 1]) == 0:
        return False
    if (lista[element + 1] - lista[element] > 0) and (lista[element + 2] - lista[element +1] < 0):
        return True
    if (lista[element + 1] - lista[element] < 0 )and (lista[element + 2] - lista[element +1] > 0):
        return True
    return False
#Citim lista

print("Introduceti 1 pentru a citi o lista ")
print("Introduceti 2 pentru prima proprietate ( 9 ) ")
print("Introduceti 3 pentru a doua proprietate ( 10 )")
print("Introduceti 4 pentru a iesi din program")

am_iesit = False
Lista = []
while (am_iesit == False):
    comanda = input("Dati numarul comenzii ")
    comanda = int (comanda)
    if comanda == 4:
        am_iesit = True
    elif comanda == 1:
        Lista = []
        Citire_Lista(Lista)
    elif comanda == 2:
    #Variabile
        Lungime_secventa_maxim = 0
        inceput = 0
        sfarsit = 0
        Lungime_secventa_curenta = 0

        #Luam toate secventele posibile si le verificam
        for i in range(1, len(Lista)):
            Lungime_secventa_curenta = 2
            for j in range(i + 1, len(Lista)):
                if E_bun_noua(j, Lista):
                    Lungime_secventa_curenta += 1
                    if Lungime_secventa_maxim < Lungime_secventa_curenta:
                        Lungime_secventa_maxim = Lungime_secventa_curenta
                        inceput = i - 1
                        sfarsit = j
                elif E_bun_noua(j, Lista) == False:
                    if Lungime_secventa_maxim < Lungime_secventa_curenta:
                        Lungime_secventa_maxim = Lungime_secventa_curenta
                        inceput = i - 1
                        sfarsit = j - 1
                    break

        #Cazul particular in care lungimea listei este 1
        if len(Lista) == 1:
            print ("Secventa este", Lista[0])

        #Cazul particular in care nu am gasit nicio secventa
        #Cu proprietatea data
        elif inceput == 0 and sfarsit == 0:
            print ("Secventa este",Lista[0],Lista[1])
        #Cazul in care am gasit cea mai lunga secventa, vom construi variabila
        #Tiparire, pentru a putea afisa secventa liniar, cu spatii intre valori
        else:
            tiparire = ""
            for i in range(inceput, sfarsit + 1):
                Lista[i] = str(Lista[i])
                spatiu = " "
                tiparire += Lista[i]
                tiparire += spatiu

            print ("Secventa este", tiparire)
#Zecele:
    elif (comanda == 3):
        #Variabile
        Lungime_secventa_maxim = 0
        inceput = 0
        sfarsit = 0
        Lungime_secventa_curenta = 0
    
        for i in range(0, len(Lista)-2):
            if E_bun_zece(i,Lista):
                Lungime_secventa_curenta = 1
                for j in range(i+1, len(Lista) - 2):
                    if E_bun_zece(j, Lista):
                        Lungime_secventa_curenta += 1
                        if Lungime_secventa_maxim < Lungime_secventa_curenta:
                            Lungime_secventa_maxim = Lungime_secventa_curenta
                            inceput = i
                            sfarsit = j + 2 
                    elif E_bun_zece(j, Lista) == False:
                        if Lungime_secventa_maxim < Lungime_secventa_curenta:
                            Lungime_secventa_maxim = Lungime_secventa_curenta
                            inceput = i
                            sfarsit = j + 1
                        break
        #Cazul particular in care lungimea listei este 1
        if len(Lista) == 1:
            print ("Secventa este", Lista[0])

        #Cazul particular in care nu am gasit nicio secventa
        #Cu proprietatea data
        elif inceput == 0 and sfarsit == 0:
            print ("Secventa nu exista")
        #Cazul in care am gasit cea mai lunga secventa, vom construi variabila
        #Tiparire, pentru a putea afisa secventa liniar, cu spatii intre valori
        else:
            #print(inceput)
            #print(sfarsit)
            tiparire = ""
            for i in range(inceput, sfarsit + 1):
                Lista[i] = str(Lista[i])
                spatiu = " "
                tiparire += Lista[i]
                tiparire += spatiu

            print ("Secventa este", tiparire)
