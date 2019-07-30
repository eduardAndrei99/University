'''
Created on 12 ian. 2019
Backtracking -> laborator 13 -> Problema 6
@author: Edy
'''

def citesteNumar():
    '''
    Functie ce imi citeste un numar
    '''
    while(True):
        try:
            numar = input()
            numar = int(numar)
            break
        except ValueError as ex:
            print("Nu ati introdus un numar ")
    return numar


def citireNumere():
    '''
    Functie ce citeste o lista de numere
    '''
    
    numere = []
    print("Introduceti lungimea listei de numere : ")
    lungime = citesteNumar()
    for index in range(lungime):
        print(">>")
        numar = citesteNumar()
        numere.append(numar)
    return numere

def citireDivizor():
    '''
    Functie ce imi citeste numarul ce trebuie sa fie divizor
    '''
    print("Introduceti numarul : ")
    divizor = citesteNumar()
    return divizor


def solutie(numere, index1, index2, divizor):
    '''
    Functie ce verifica daca este solutie
    '''
    suma = 0
    for pozitie in range(index1, index2 + 1):
        suma += numere[pozitie]
    if suma % divizor == 0:
        return True
    return False


def afisezSolutie(numere, index1, index2):
    '''
    Functie ce afiseaza solutia index1->index2
    '''
    solutie  = ""
    for pozitie in range(index1, index2 + 1):
        numere[pozitie] = str(numere[pozitie])
        solutie += numere[pozitie]
        solutie += " "
        numere[pozitie] = int(numere[pozitie])
    print(solutie)


def backtrackingIterativ(numere, divizor):
    
    for index1 in range(0, len(numere)):
        for index2 in range(index1, len(numere)):
            if solutie(numere, index1, index2, divizor):
                afisezSolutie(numere, index1, index2)
                
def backtrackingRecursiv(numere, index1, index2, divizor):
    
    if index1 == len(numere):
        return
    if solutie(numere, index1, index2, divizor):
        afisezSolutie(numere, index1, index2)
    if index2 == len(numere) - 1:
        backtrackingRecursiv(numere, index1 + 1,index1 + 1 , divizor)
    else:
        backtrackingRecursiv(numere, index1, index2 + 1, divizor)



numere = citireNumere()
divizor = citireDivizor()
print("Lista cu numere este : ", numere)
print("Divizorul este ", divizor)
print()

backtrackingIterativ(numere, divizor)
print()
backtrackingRecursiv(numere, 0, 0, divizor)


def testSolutie():
    '''
    Functie ce imi teteaaza functia solutie
    '''
    assert solutie([1,2,3], 0, 1, 3) == True
    assert solutie([5,5,5],0 ,2 ,100) == False
    
testSolutie()




