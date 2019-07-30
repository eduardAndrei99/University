'''
Created on 5 dec. 2018

@author: Edy
'''
from domain.validator import evenimentValidator
from domain.eveniment import eveniment


class evenimentRepositoryExceptie(Exception):
    pass

class evenimenteRepository(object):
    
    
    def __init__(self, EvenimentValidator):
        '''
        '''
        
        self.EvenimentValidator = EvenimentValidator
        self.listaEvenimente = {}
    
    def creareEveniment(self, eveniment):
        '''
        Crearea unui eveniment
        
        '''
        if eveniment.getEvenimentId() in self.listaEvenimente:
            raise evenimentRepositoryExceptie
        
        self.EvenimentValidator.validate(eveniment)
        self.listaEvenimente[eveniment.getEvenimentId()] = eveniment
    
    def getEvenimente(self):
        '''
        Get ul pentru evenimente
        '''
        return list(self.listaEvenimente.values())
        
    def stergEveniment(self, idEveniment):
        '''
        Sterg evenimentul
        '''
        
        ok = False
        if idEveniment in self.listaEvenimente:
            ok = True
        if ok == False:
            raise evenimentRepositoryExceptie
        del self.listaEvenimente[idEveniment]
        
    def modificaEveniment(self, idEveniment, data, timp, descriere):
        
        ok = False
        if idEveniment in self.listaEvenimente:
            ok = True
        
        if ok == False:
            raise evenimentRepositoryExceptie
        
        self.listaEvenimente[idEveniment].setData(data)
        self.listaEvenimente[idEveniment].setTimp(timp)
        self.listaEvenimente[idEveniment].setDescriere(descriere)
        
    def cautaEveniment(self, idEveniment):
        
        ok = False
        if idEveniment in self.listaEvenimente:
            ok = True
        
        if ok == False:
            return None
        return self.listaEvenimente[idEveniment]
    
    def __len__(self):
        return len(self.listaEvenimente)
    
def testRepositoryEvenimente():
    
    ValidatorEveniment = evenimentValidator()
    EvenimenteRepository = evenimenteRepository(ValidatorEveniment)
    Eveniment1 = eveniment("1","2","3","4")
    EvenimenteRepository.creareEveniment(Eveniment1)
    assert EvenimenteRepository.__len__() == 1
    EvenimenteRepository.stergEveniment(Eveniment1.getEvenimentId())
    assert EvenimenteRepository.__len__() == 0
    
testRepositoryEvenimente()    

