'''
Created on 5 dec. 2018

@author: Edy
'''

from domain.eveniment import eveniment        

class evenimentService(object):
    
    def __init__(self, EvenimentRepository):
        self.EvenimentRepository = EvenimentRepository
    
    def creareEveniment(self, idEveniment, data, timp, descriere):
        
        #Am creat evenimentul
        Eveniment = eveniment(idEveniment, data, timp, descriere)
        self.EvenimentRepository.creareEveniment(Eveniment)
        return Eveniment
            
    def getEvenimente(self):
        '''
        Apelam repository
        '''
        return self.EvenimentRepository.getEvenimente()
        
    def stergEveniment(self, idEveniment):
        '''
        Apelam repository
        '''
        return self.EvenimentRepository.stergEveniment(idEveniment)
    
    def modificaEveniment(self, idEveniment, data, timp, descriere):
        '''
        Apelam repository
        '''
        return self.EvenimentRepository.modificaEveniment(idEveniment, data, timp, descriere)
    
    def cautaEveniment(self, idEveniment):
        '''
        Apelam repository
        ''' 
        return self.EvenimentRepository.cautaEveniment(idEveniment)





