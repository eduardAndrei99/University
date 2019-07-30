'''
Created on 5 dec. 2018

@author: Edy
'''

from domain.persoana import persoana
from domain.validator import persoanaValidator

class persoaneRepositoryExceptie(Exception):
    pass


class persoaneRepository:
    '''
    Crud ul pentru persoane
    '''
    
    def __init__(self, validatorPersoane):
        '''
        Constructor
        '''
        self.listaPersoane = {}
        self.validatorPersoane = validatorPersoane
        
    def crearePersoana(self, persoana):
        '''
        Introduc persoana in repository
        Daca este valida
        '''
        
        if(persoana.getPersoanaId() in self.listaPersoane):
            raise persoaneRepositoryExceptie
        
        self.validatorPersoane.validate(persoana)
        self.listaPersoane[persoana.getPersoanaId()] = persoana
        
    def getPersoane(self):
        '''
        Functia pentru get persoane
        '''
        return list(self.listaPersoane.values())
    
    def stergPersoana(self, idPersoana):
        
        gasit = False
        if idPersoana in self.listaPersoane:
            gasit = True
        
        if gasit == False:
            raise persoaneRepositoryExceptie
        
        del self.listaPersoane[idPersoana]
       
    def modificaPersoana(self, idPersoana, nume, adresa):
        
        gasit = False
        if idPersoana in self.listaPersoane:
            gasit = True
        if gasit == False:
            raise persoaneRepositoryExceptie
        
        self.listaPersoane[idPersoana].set_nume(nume)
        self.listaPersoane[idPersoana].set_adresa(adresa)
    
    def cautPersoana(self, idPersoana):
        gasit = False
        if idPersoana in self.listaPersoane:
            gasit = True
        if gasit == False:
            return None
        return self.listaPersoane[idPersoana]
    
    def __len__(self):
        return len(self.listaPersoane)
    
def testRepositoryPersoane():
    
    validatorPersoana = persoanaValidator()  
    repositoryPersoane = persoaneRepository(validatorPersoana)
    Persoana = persoana("1", "edy", "sascut")
    repositoryPersoane.crearePersoana(Persoana)
    assert repositoryPersoane.__len__() == 1
    Persoana2 = persoana("2","mihai","sascut")
    repositoryPersoane.crearePersoana(Persoana2)
    assert repositoryPersoane.__len__() == 2
        
testRepositoryPersoane()
        
    
    
    
    
    