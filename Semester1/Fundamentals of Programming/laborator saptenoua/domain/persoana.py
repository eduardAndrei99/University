'''
Created on 5 dec. 2018

@author: Edy
'''
from unicodedata import numeric

class persoana:
    '''
    Entitatea persoana
    '''


    def __init__(self, persoanaId, nume, adresa):
        '''
        Constructor
        '''
        self.persoanaId = persoanaId
        self.nume = nume
        self.adresa = adresa
        
    def getPersoanaId(self):
        '''
        Get pentru Id 
        '''
        return self.persoanaId
    
    def getNume(self):
        '''
        Get pentru nume
        '''
        return self.nume
    
    def getAdresa(self):
        '''
        Get pentru adresa
        '''
        return self.adresa
    
    def __eq__(self, persoana2):
        '''
        Cand 2 persoane sunt egale -> cand au acelasi id
        '''
        return self.persoanaId == persoana2.persoanaId
    
    def set_nume(self, nume):
        self.nume = nume
    
    def set_adresa(self, adresa):
        self.adresa = adresa
        
    
def testEntitatePersoana():
    Persoana = persoana("1", "Edi", "Sascut")
    assert Persoana.getPersoanaId() == "1"
    assert Persoana.getNume() == "Edi"
    assert Persoana.getAdresa() == "Sascut"
    
    Persoana2 = persoana("1", "Edi", "Sascut")
    Persoana3 = persoana("2", "Mihai", "Bucuresti")
    
    assert (Persoana == Persoana2)
    assert (Persoana != Persoana3)
    
testEntitatePersoana()    
    
    
    
    
    
        