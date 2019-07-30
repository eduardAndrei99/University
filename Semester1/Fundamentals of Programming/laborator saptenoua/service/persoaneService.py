'''
Created on 5 dec. 2018

@author: Edy
'''

from domain.persoana import persoana  
 
class persoanaService:
    '''
    Service pentru persoane
    '''
    
    def __init__(self, persoanaRepository):
        '''
        Service ul contine repository
        '''
        self.persoanaRepository = persoanaRepository
        
    def crearePersoana(self, persoanaId, nume, adresa):
        '''
        Creez o persoana
        '''
        Persoana = persoana(persoanaId, nume, adresa)
        self.persoanaRepository.crearePersoana(Persoana)
        return Persoana

    def getPersoane(self):
        return self.persoanaRepository.getPersoane()
    
    def stergPersoana(self, idPersoana):
        return self.persoanaRepository.stergPersoana(idPersoana)
    
    def modificaPersoana(self, idPersoana, nume, adresa):
        return self.persoanaRepository.modificaPersoana(idPersoana, nume, adresa)
    
    def cautPersoana(self, idPersoana):
        return self.persoanaRepository.cautPersoana(idPersoana)