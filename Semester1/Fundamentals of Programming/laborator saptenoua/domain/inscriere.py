'''
Created on 5 dec. 2018

@author: Edy
'''

class inscriere:
    '''
    Inscriem persoana la eveniment
    '''


    def __init__(self, persoanaId, evenimentId):
        '''
        Constructor
        '''
        self.persoanaId = persoanaId
        self.evenimentId = evenimentId
        
    def getPersoanaId(self):
        '''
        Get pentru id ul persoanei
        '''
        return self.persoanaId
    
    def getEvenimentId(self):
        '''
        Get pentru id ul evenimentului
        '''
        return self.evenimentId
    
    def __eq__(self, inscriere2):
        '''
        Egalitatea
        '''
        if self.persoanaId == inscriere2.persoanaId and self.evenimentId == inscriere2.evenimentId:
            return True
        return False
    
def testEntitateInscirere():
    Inscriere = inscriere("1", "2")
    assert Inscriere.getPersoanaId() == "1"
    assert Inscriere.getEvenimentId() == "2"
    
testEntitateInscirere()
    
        
    
        