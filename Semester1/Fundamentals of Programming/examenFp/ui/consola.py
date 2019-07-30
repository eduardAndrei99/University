from domain.validator import ExceptieTraducere
from repository.repository import RepoError
class Consola():

    def __init__(self, service):
        '''
        Ui comunica cu service ul 
        '''
        self.service = service


    def printUi(self):
        '''
        functie de afisare a Ui 
        '''
        
        print("1 -> Adauga in dictionar")
        print("2 -> Vizualizare traduceri")
        print("3 -> Traducerea unui text")
        print("4 -> Cauta tranzitiv cuvintele")
        print("5 -> Afisare dictionar")
        print()
        
        
    def afisezDictionarul(self):
        '''
        functie ce afiseaza dictionarul de traduceri
        '''
        traduceri = self.service.getTraduceri()
        for traducere in traduceri:
            print(str(traducere))
        print()
    

    def adaugaTraducere(self):
        '''
        functie ce adauga o traducere
        '''
        limbaSursa = input("Limba sursa >> ")
        cuvant = input("Cuvantul >> ")
        limbaDestinatie = input("Limba destinatie >> ")
        traducereCuvant = input("Traducerea cuvantului >> ")
        try:
            self.service.adaugaTraducere(limbaSursa, cuvant, limbaDestinatie, traducereCuvant)
        except ExceptieTraducere:
            print("Nu ati introdus bine")
        except RepoError:
            print("Un cunvant nu poate avea 2 traduceri")
    
    
    def vizualizareTraduceri(self):
        '''
        functie ce imi afiseaza traducerile pentru o limba
        sortate alfabetic dupa cuvantul din limba sursa
        '''
        limba = input("Introduceti limba ")
        traduceri = self.service.vizualizareTraduceri(limba)
        for traducere in traduceri:
            print(str(traducere))
    
    
    def traducereText(self):
        '''
        functie ce imi citeste numele fisierului, limbile si traduce 
        '''
        fisierIntrare = input("Numele fisierului de intrare : ")
        limbaText = input("Limba in care este scris textul : ")
        limbaDeTradus = input("Limba in care se va traduce : ")
        fisierIesire = input("Numele fisierului de iesire : ")
        
        try:
            self.service.traducereText(fisierIntrare,limbaText,limbaDeTradus,fisierIesire)
        except ExceptieTraducere as ex:
            print("Nu e bine")
    
    
    def showUi(self):
        '''
        run
        '''
        
        while True:
            
            self.printUi()
            comanda = input()
            if comanda == "1":
                self.adaugaTraducere()
            if comanda == "5":
                self.afisezDictionarul()
            if comanda == "2":
                self.vizualizareTraduceri()
            if comanda == "3":
                self.traducereText()
        
                
            print()
        
        
    
    
    
    