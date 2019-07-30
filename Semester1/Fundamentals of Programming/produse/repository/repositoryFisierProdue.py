'''
Created on 30 ian. 2019

@author: Edy
'''
from domain.entitati import Produs


class RepoError(Exception):
    def __init__(self,erori):
        self.erori = erori
    def getErori(self):
        return self.erori
    

class RepositoryProduse(object):
    '''
    classdocs
    '''

    def __init__(self, numeFisier):
        '''
        Constructor -> numeFisier
        '''
        self.numeFisier = numeFisier
        
        
    def getProduse(self):
        '''
        iau produsele din fisier
        '''
        produse = [] #initial lista e goala
        try:
            fisier = open(self.numeFisier)
        except IOError:
            print("Nu a fost deschis fisierul ")
            return
        
        linie = fisier.readline().strip()
        while linie != "":
            #pentru fiecare linie
            delimitator = linie.split(",")
            produs = Produs(delimitator[0], delimitator[1], delimitator[2])
            produse.append(produs)
            linie = fisier.readline().strip()
        
        return produse
    
    def verific(self, produs):
        '''
        :param produs: verificam daca id ul nu este deja aici
        '''
        toateProdusele = self.getProduse()
        for produss in toateProdusele:
            if produss.getId() == produs.getId():
                raise RepoError("Exista produsul")
    
    def storeProduse(self, toateProdusele):
        '''
        :param toateProdusele: evident
        scriem in fisier
        '''
        with open(self.numeFisier, "w") as fisier:
            for produs in toateProdusele:
                adaug = produs.getId() + ',' + produs.getDenumire() +',' + produs.getPret()
                adaug += "\n"
                fisier.write(adaug)
    
             
    def adaugProdus(self, produs):
        '''
        :param produs: produsul de adaugat
        '''
        toateProdusele = self.getProduse()
        toateProdusele.append(produs)
        self.storeProduse(toateProdusele)
    
    def stergProduse(self, cifra):
        '''
        functie pentru stergerea produselor
        :param cifra: cifra magica
        '''
        toateProdusele = self.getProduse()
        noileProduse = []
        for produs in toateProdusele:
            if cifra not in produs.getId():
                noileProduse.append(produs)
        self.storeProduse(noileProduse)
    
    def afisezCuFiltru(self,numeFiltru,numarFiltru):
        toateProdusele = self.getProduse()
        produseBune = []
        for produs in toateProdusele:
            if numeFiltru in produs.getDenumire():
                produseBune.append(produs)
            else:
                if numarFiltru in produs.getPret() or numarFiltru == -1:
                    produseBune.append(produs)
        return produseBune
    
    
def testAdaugProdus():
    f = open("teste","w")
    f.close()
    repo = RepositoryProduse("teste")
    list = repo.getProduse()
    assert len(list) == 0
    produs = Produs("3","da","dsadas")
    repo.adaugProdus(produs)
    assert len(repo.getProduse()) == 1
    
    
     
testAdaugProdus()            
            
    