'''
Created on 5 dec. 2018

@author: Edy
'''
from domain.inscriere import inscriere



class inscrieriRepository:
    
    def __init__(self):
        
        self.listaInscrieri = []

    
    def adaugInscriere(self,inscriere):
       
        if self.cautInscriere(inscriere) is None:
            self.listaInscrieri.append(inscriere)
            return inscriere
        else:
            return None
    
    def getInscrieri(self):
        return self.listaInscrieri
    
    def cautInscriere(self, Inscriere):
        
        for inscriere in self.listaInscrieri:
            if inscriere == Inscriere:
                return inscriere
        return None
    
        
        
        
        
        