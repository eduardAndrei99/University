"""
consola
Ui 
"""

from domain.entitati import Produs
from service.controler import ServiceProduse
from domain.validator import ExceptieProduse
from repository.repositoryFisierProdue import RepoError

class Consola():
    
    def __init__(self, service):
        '''
        :param service: Ui comunica cu service
        '''
        self.service = service
        
    def printUi(self):
        '''
        functie ce imi afiseaza meniul
        '''
        print("1->adaugare de produse")
        print("2->stergere de produse")
        print("3->filtrare de produse")
        print("4->afisarea produselor")
        print("5->schimba filtrul")
        print("6->doar filtrul")
    

    def afisezProdusele(self):
        '''
        functie ce imi ia produsele din fisier si afiseaza
        '''
        toateProdusele = self.service.getProduse()
        for produs in toateProdusele:
            print(produs.getDenumire(), "\t", produs.getId(), "\t", produs.getPret())
        
    
    def adaugProdus(self):
        '''
        functie pentru adaugarea unui produs
        '''
        id = input("id >> ")  
        denumire = input("denumire >> ")
        pret = input("pret >>")
        try:
            self.service.adaugProdus(id, denumire, pret)
        except ExceptieProduse as ex:
            print("Nu merge produsu asta")
        except RepoError as ex:
            print("Produsul mai exista o data")
    

    def stergProduse(self):
        '''
        functie pentru stergerea produselos
        '''
        cifra = input("cifra >> ")
        self.service.stergProduse(cifra)
    

    def schimbaFiltrul(self):
        numeFiltru = input("nume filtru >> ")
        numarFiltru = input("numar fitru >> ")
        return numeFiltru, numarFiltru
    

    def afisezCuFiltru(self, numeFiltru, numarFiltru):
        lista =  self.service.afisezCuFiltru(numeFiltru,numarFiltru)
        for produs in lista:
            print(produs.getDenumire(), "\t", produs.getId(), "\t", produs.getPret())
    
    def showUi(self):
        '''
        functie pentru a afisa ui 
        '''
        numeFiltru = ""
        numarFiltru = "-1"
        while True:
            self.printUi()
            comanda = input()
            if comanda == "1":
                self.adaugProdus()
            if comanda == "2":
                self.stergProduse()
            if comanda == "3":
                self.filtrezProduse()
            if comanda == "4":
                self.afisezProdusele()
            if comanda == "5":   
                numeFiltru,numarFiltru = self.schimbaFiltrul()
            self.afisezCuFiltru(numeFiltru,numarFiltru)    
            
                
                