'''
Created on 9 dec. 2018

@author: Edy
'''

from domain.persoana import persoana
from repository.persoaneRepository import persoaneRepository,\
    persoaneRepositoryExceptie
from domain.validator import *
from domain.eveniment import eveniment
from repository.evenimenteRepository import evenimentRepositoryExceptie
from domain.inscriere import inscriere

class fileEvenimenteRepository():
    
    def __init__(self, fisierEvenimente):
        '''
        Initializarea repository ului de evenimente
        fisierEvenimente = numele fisierului
        '''
        self.fisierEvenimente = fisierEvenimente
        
    def iauDinFisier(self):
        '''
        Iau evenimentele din fisier
        '''
        try:
            fisier = open(self.fisierEvenimente,"r")
        except IOError:
            print("Nu exista")
            return
        
        linie = fisier.readline().strip()
        evenimente = []
        while linie != "":
            delimitare = linie.split(",")
            Eveniment = eveniment(delimitare[0], delimitare[1], delimitare[2], delimitare[3])
            evenimente.append(Eveniment)
            linie = fisier.readline().strip()
        fisier.close()
        return evenimente
    
    def getEvenimente(self):
        '''
        Sa fie numele la fel 
        '''
        return self.iauDinFisier()
    
    def stochezEvenimentele(self, toateEvenimentele):
        '''
        Pun evenimentele in fisier
        '''
        with open(self.fisierEvenimente, "w") as fisier:
            for eveniment in toateEvenimentele:
                adaug = eveniment.getEvenimentId() + ',' + eveniment.getData() + ',' +eveniment.getTimp() + ',' +eveniment.getDescriere()
                adaug += '\n'
                fisier.write(adaug)
                
    def creareEveniment(self, eveniment):
        '''
        Functie pentru crearea unui eveniment
        ma uit daca acesta exista deja ( id ul)
        daca nu , adaug
        in fisier
        '''
        toateEvenimentele = self.iauDinFisier()
        if eveniment in toateEvenimentele:
            raise evenimentRepositoryExceptie
        toateEvenimentele.append(eveniment)
        self.stochezEvenimentele(toateEvenimentele)
    
    def cautRecursiv(self, idEveniment, toateEvenimentele, iterator):
        
        if iterator == -1:
            return -1
        if toateEvenimentele[iterator].getEvenimentId() == idEveniment:
            return iterator
        return self.cautRecursiv(idEveniment, toateEvenimentele, iterator - 1)
    
    
    def stergEveniment(self, idEveniment):
        '''
        iau toate elementele si daca il gasesc il sterg
        '''
        toateEvenimentele = self.iauDinFisier()
        '''
        pozitie = -1
        for i in range(len(toateEvenimentele)):
            if toateEvenimentele[i].getEvenimentId() == idEveniment:
                pozitie = i  
        if pozitie == -1:
            return None
        '''
        pozitie = self.cautRecursiv(idEveniment, toateEvenimentele,len(toateEvenimentele)-1)
        if pozitie == -1:
            return None
        del toateEvenimentele[pozitie]
        self.stochezEvenimentele(toateEvenimentele)   
    
    def modificaEveniment(self, idEveniment, data, timp, descriere):  
        '''
        modificare eveniment
        il sterg iar apoi
        il adaug cu noile upgrade uri
        '''
        toateEvenimentele = self.iauDinFisier()
        self.stergEveniment(idEveniment)
        Eveniment = eveniment(idEveniment, data, timp, descriere)
        toateEvenimentele.append(Eveniment)
        self.creareEveniment(Eveniment)
    
    def cautaEveniment(self, idEveniment):
        ''''
        caut evenimentul
        si il returnez daca il gasesc
        in caz contrar returnez none
        '''
        toateEvenimentele = self.iauDinFisier()
        for eveniment in toateEvenimentele:
            if eveniment.getEvenimentId() == idEveniment:
                return eveniment
        return None
            
                

class filePersoaneRepository():
    
    def __init__(self, fisierPersoane):
        '''
        Initializarea repository ului de persoane
        fisierPersoane = numele fisierului
        '''
        self.fisierPersoane = fisierPersoane
    
    def iauDinFisier(self):
        '''
        Iau persoanele din fisier
        '''
        try:
            fisier = open(self.fisierPersoane, "r")
        except IOError:
            #Fisierul nu exista
            print("Nu exista")
            return
        
        '''
        Iau cate o persoana
        Care e pe cate o linie
        '''
        
        linie = fisier.readline().strip()
        persoane = []
        
        while linie != "":
            delimitare = linie.split(",")
            #Delimitarea se face dupa virgula
            Persoana = persoana(delimitare[0], delimitare[1], delimitare[2])
            persoane.append(Persoana)
            linie = fisier.readline().strip()
        fisier.close()
        return persoane
    
    def getPersoane(self):
        return self.iauDinFisier()
     
    def stochezPersoanele(self, toatePersoanele):
        '''
        Pun toate persoanele in fisier
        '''
        with open(self.fisierPersoane, "w") as fisier:
            for persoana in toatePersoanele:
                adaug = persoana.getPersoanaId() + ',' +persoana.getNume() + ',' +persoana.getAdresa()
                adaug += "\n"
                fisier.write(adaug)
     
    def crearePersoana(self, persoana):
        
        toatePersoanele = self.getPersoane()
        if persoana in toatePersoanele:
            raise persoaneRepositoryExceptie
        toatePersoanele.append(persoana)
        self.stochezPersoanele(toatePersoanele)
    
    def cautRecursiv(self, idPersoana, toatePersoanele, iterator):
        
        if iterator == -1:
            return -1
        if toatePersoanele[iterator].getPersoanaId() == idPersoana:
            return iterator
        return self.cautRecursiv(idPersoana, toatePersoanele, iterator - 1)
    
      
    def stergPersoana(self, idPersoana):
        '''
        Sterg o persoana 
        folosind id ul ei
        '''
        toatePersoanele = self.iauDinFisier()
        pozitie = -1
        pozitie = self.cautRecursiv(idPersoana, toatePersoanele, len(toatePersoanele)- 1) 
        if pozitie == -1:
            return None
        PersoanaDeSters = toatePersoanele[pozitie]
        del toatePersoanele[pozitie]
        self.stochezPersoanele(toatePersoanele)
    
    def modificaPersoana(self, idPersoana, nume, adresa):
        '''
        Modific persoana
        '''
        toatePersoanele = self.iauDinFisier()
        self.stergPersoana(idPersoana)
        Persoana = persoana(idPersoana,nume,adresa)
        self.crearePersoana(Persoana)
    
    def cautPersoana(self,idPersoana):
        '''
        caut o persoana in fisier
        '''
        toatePersoanele = self.iauDinFisier()
        for Persoana in toatePersoanele:
            if Persoana.getPersoanaId() == idPersoana:
                return Persoana
        return None
      
   
   
class fileInscriereRepository:
    
    def __init__(self, fisierInscrieri):
        self.fisierInscrieri = fisierInscrieri
        
    
    def iauDinFisier(self):
        '''
        Iau inscrierile din fisier
        '''
        try:
            fisier = open(self.fisierInscrieri, "r")
        except IOError:
            #Fisierul nu exista
            print("Nu exista")
            return
        
        '''
        Iau cate o inscriere
        Care e pe cate o linie
        '''
        
        linie = fisier.readline().strip()
        inscrieri = []
        
        while linie != "":
            delimitare = linie.split(",")
            #Delimitarea se face dupa virgula
            Inscriere = inscriere(delimitare[0],delimitare[1])
            inscrieri.append(Inscriere)
            linie = fisier.readline().strip()
        fisier.close()
        return inscrieri   
    
    def getInscrieri(self):
        return self.iauDinFisier()


