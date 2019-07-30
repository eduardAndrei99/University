'''
Created on 5 dec. 2018

@author: Edy
'''

class eveniment:
    '''
    Entitatea eveniment
    '''


    def __init__(self, evenimentId, data, timp, descriere):
        '''
        Constructor
        '''
        self.evenimentId = evenimentId
        self.data = data
        self.timp = timp
        self.descriere = descriere
        
    def getEvenimentId(self):
        '''
        Get pentru Id
        '''
        return self.evenimentId
    
    def getData(self):
        '''
        Get pentru data
        '''
        return self.data
    
    def getTimp(self):
        '''
        Get pentru timp
        '''
        return self.timp
    
    def getDescriere(self):
        '''
        Get pentru descriere
        '''
        return self.descriere
    
    def setData(self,data):
        self.data = data
    
    def setTimp(self,timp):
        self.timp = timp
    
    def setDescriere(self, descriere):
        self.descriere = descriere
    
    def __lt__(self, eveniment2):
        '''
        Cum sa compar 2 evenimente?
        '''
        if self.descriere < eveniment2.descriere:
            return True
        if self.descriere == eveniment2.descriere:
            if self.data < eveniment2.data:
                return True
        return False
        
    def __eq__(self, eveniment2):
        '''
        Egalitatea evenimentelor
        '''
        return self.evenimentId == eveniment2.evenimentId
        if self.data == eveniment2.data and self.timp == eveniment2.timp and self.descriere == eveniment2.descriere:
            return True
        return False
            
def testEntitateEveniment():
    
    Eveniment = eveniment("1", "20.11.2018", "2 ore ", "Frumos")
    assert Eveniment.getEvenimentId() == "1"
    assert Eveniment.getData() == "20.11.2018"
    assert Eveniment.getTimp() == "2 ore "
    assert Eveniment.getDescriere() == "Frumos"
    
    Eveniment2 = eveniment("1", "20.11.2018", "2 ore ", "Frumos")
    assert Eveniment == Eveniment2
    
    Eveniment3 = eveniment("1", "20.11.2018", "2 ore ", "Zrumos")
    assert Eveniment < Eveniment3
    
testEntitateEveniment()    
        
        
    
    