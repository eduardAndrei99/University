'''
Created on 5 dec. 2018

@author: Edy
'''
from domain.inscriere import inscriere
#from domain.eveniment import eveniment
        
class inscriereService:
    
    
    def __init__(self, InscriereRepository):
        self.InscriereRepository = InscriereRepository
        
    def creareInscriere(self, idPersoana, idEveniment):
        
        Inscriere = inscriere(idPersoana, idEveniment)
        return self.InscriereRepository.adaugInscriere(Inscriere)
        
    def getInscrieri(self):
        return self.InscriereRepository.getInscrieri()
    
    def getEvenimenteUneiPersoane(self, idPersoana):
        listaEvenimente = []
        for Inscriere in self.getInscrieri():
            if Inscriere.getPersoanaId() == idPersoana:
                listaEvenimente.append(Inscriere.getEvenimentId())
        if len(listaEvenimente) == 0:
            return None
        else:
            return listaEvenimente
    
    def getCatePersoaneEveniment(self, idEveniment):
        numar = int(0)
        for Inscriere in self.getInscrieri():
            if Inscriere.getEvenimentId() == idEveniment:
                numar += 1
        return numar
    
    def afisezPrimele20(self):
        '''
        Functie ce returneaza o lista in care o sa am
        Pe pozitiile impare id ul evenimentului
        Iar pe pozitiile pare cate persoane s au inscris la eveniment
        '''
        listaDeReturnat = []
        Inscrieri = self.getInscrieri()
        for Inscriere in Inscrieri:
            okey = True
            for contor in range(0, len(listaDeReturnat), 2):
                if listaDeReturnat[contor] == Inscriere.getEvenimentId():
                    okey = False
            if okey == True:
                   
                listaDeReturnat.append(Inscriere.getEvenimentId())
                numar = self.getCatePersoaneEveniment(Inscriere.getEvenimentId())
                listaDeReturnat.append(numar)
        
        return listaDeReturnat
    '''
    def sortezPrimele20(self, listaEvenimente):
        
     #Shake sort
        
        lungime = len(listaEvenimente)
        #print(listaEvenimente)
        for k in range(lungime -1 , 1, -2):
            swapped = False
            for i in range(k, 1, -2):
                if listaEvenimente[i]>listaEvenimente[i-2]:
                    listaEvenimente[i], listaEvenimente[i-2] = listaEvenimente[i-2], listaEvenimente[i]
                    listaEvenimente[i-3], listaEvenimente[i-1] = listaEvenimente[i-1], listaEvenimente[i-3]
                    swapped = True
            for i in range(1,k,2):
                if listaEvenimente[i] < listaEvenimente[i+2]:
                    listaEvenimente[i], listaEvenimente[i+2] = listaEvenimente[i+2], listaEvenimente[i]
                    listaEvenimente[i-1], listaEvenimente[i+1] = listaEvenimente[i+1], listaEvenimente[i-1]
                    swapped = True
            if swapped == False:
                return listaEvenimente
    '''
        
    def sortezPrimele20(self, listaEvenimente):
        
        #Lg = lungimea listei de evenimente
        #voi face o sortare O (n ^ 2) 
        #selection sort
    
        lungime = len(listaEvenimente)
        for i in range(1, lungime-2, 2):
            for j in range(i+2, lungime, 2):
                if listaEvenimente[i] < listaEvenimente[j]:
                    listaEvenimente[i], listaEvenimente[j] = listaEvenimente[j],listaEvenimente[i]
                    listaEvenimente[i-1], listaEvenimente[j-1] = listaEvenimente[j-1],listaEvenimente[i-1]
        return listaEvenimente
    
    def sortezLista(self, listaEvenimente):
        '''
        Lg = lungimea listei de evenimente
        voi face o sortare O (n ^ 2) 
        lista arata : id data descriere  id2 data2 descriere2
        '''
        
        lungime = len(listaEvenimente)
        for i in range(1, lungime - 3 , 3):
            for j in range(i+3, lungime, 3):
                if listaEvenimente[i] < listaEvenimente[j]:
                    listaEvenimente[i], listaEvenimente[j] = listaEvenimente[j],listaEvenimente[i]
                    listaEvenimente[i-1], listaEvenimente[j-1] = listaEvenimente[j-1],listaEvenimente[i-1]
                    listaEvenimente[i+1], listaEvenimente[j+1] = listaEvenimente[j-1],listaEvenimente[i+1]
                elif listaEvenimente[i] == listaEvenimente[j] and listaEvenimente[i+1] > listaEvenimente[j+1]:
                    listaEvenimente[i], listaEvenimente[j] = listaEvenimente[j],listaEvenimente[i]
                    listaEvenimente[i-1], listaEvenimente[j-1] = listaEvenimente[j-1],listaEvenimente[i-1]
                    listaEvenimente[i+1], listaEvenimente[j+1] = listaEvenimente[j-1],listaEvenimente[i+1]
        return listaEvenimente

    
    def persoaneActive(self):
        '''
        Functie ce returneaza lista cu persoane inscrise la cele mai multe evenimente
        '''
        dictionarPersoane = {}
        listaInscrieri = self.getInscrieri()
        for inscriere in listaInscrieri:
            if inscriere.getPersoanaId() in dictionarPersoane:
                dictionarPersoane[inscriere.getPersoanaId()] += 1
            else:
                dictionarPersoane[inscriere.getPersoanaId()] = 1
        
        persoaneMaxim = 0
        for persoana in dictionarPersoane.values():
            if persoana > persoaneMaxim:
                persoaneMaxim = persoana
        
        listaInscrieri = []
        for persoana in dictionarPersoane:
            if dictionarPersoane[persoana] == persoaneMaxim:
                listaInscrieri.append(persoana)
                
        return listaInscrieri
        
        
        
        
        
        
        
        
                
    

